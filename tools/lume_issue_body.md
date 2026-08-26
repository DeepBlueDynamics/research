## Summary

During `lume index -s -o` over a real corpus, index checkpointing rewrites the **entire** JSON state repeatedly and **non-atomically**. Two consequences:

1. **Torn reads** — a concurrent `lume search` against the same `--db` dies with a JSON parse error when it catches a checkpoint mid-write.
2. **O(n²) write amplification ("slow append")** — appending each batch of new entities/sections costs a full re-serialization of the ever-growing files, so total bytes written grow quadratically with corpus size. On our corpus the entity graph alone was observed being rewritten whole as it grew 32 B → 13 MB → 108 MB (pretty-printed), with `state.json` (16–20 MB) rewritten continuously alongside it.

## Environment

- lume v0.12.0 @ 867c8db5ee959ee0110bb099fc47dd5e3bd26916
- Windows 11 host, `cargo build --release`
- Corpus: 197 markdown/text files, 9,581 sections (~15 MB text)
- Command: `lume index -s -o docs --db .lume-index` (Ollama entity extraction, 10 workers)

## Observed

Concurrent search during indexing:

```
Error: Failed to parse JSON from .lume-index\state.json: EOF while parsing a string at line 3780 column 15
```

File growth by repeated full rewrites during one indexing run (mtimes advancing every checkpoint):

```
entity_graph.json   32 B  -> 13 MB -> 108 MB
state.json          16 MB -> 20 MB (rewritten continuously)
```

## Root cause (code)

`src/main.rs:30` — `save_json` truncates the destination in place and streams pretty JSON into it; there is no temp-file + rename, so readers can observe a partially written file:

```rust
fn save_json<T: Serialize>(path: &Path, val: &T) -> Result<(), String> {
    let file = File::create(path)...;            // truncates existing file in place
    let writer = io::BufWriter::new(file);
    serde_json::to_writer_pretty(writer, val)... // long window while file is partial
}
```

Checkpoint call sites: `src/main.rs:837-839` (bm25/spelling/entity_graph), `:1064`, `:1266`, and the in-loop periodic checkpoint at `:1214`, which re-serializes the full state each time **and discards errors**:

```rust
let _ = save_json(&db_path.join("state.json"), &temp_state);
```

## Impact

- Search is unusable against a db that is being indexed (torn reads), which defeats "search while the long entity pass runs".
- Checkpoint I/O grows quadratically; on this ~9.6k-section corpus the graph checkpoints alone wrote on the order of gigabytes across the run. Larger corpora will spend more time serializing JSON than extracting entities.
- A crash mid-checkpoint loses the file outright — the previous good version has already been truncated.

## Suggested fixes

1. **Atomic replace**: write to `<file>.tmp` in the same directory, then `std::fs::rename` over the target (atomic on POSIX; on Windows, rename-over-existing via `ReplaceFileW` semantics or remove+rename). Readers then only ever see complete files, and a mid-write crash preserves the previous version.
2. **Compact serialization** for machine-read state: `to_writer` instead of `to_writer_pretty` (~30–50% smaller at the 100 MB scale, faster to write and parse).
3. **Incremental checkpointing** for the growing structures: an append-only journal or size-segmented files, compacted at completion — turns O(n²) checkpoint I/O into O(n).
4. **Surface checkpoint errors** instead of `let _ =` — a silently failed checkpoint currently looks identical to a successful one.

(1) and (4) are small, independent changes and fix the correctness issues; (2)/(3) address the performance curve.

## Repro

1. Index a corpus large enough that the entity pass runs for minutes: `lume index -s -o <dir> --db .lume-index`
2. While it runs, loop `lume search -a 0 "anything" --db .lume-index`
3. Within a few attempts the search exits with `Failed to parse JSON from state.json: EOF while parsing ...`; watching the db directory shows `entity_graph.json`/`state.json` being rewritten whole at each checkpoint.

---
Filed from a live indexing run on the NP004 research corpus (DeepBlueDynamics/research).
🤖 Generated with [Claude Code](https://claude.com/claude-code)
