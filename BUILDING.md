# Building the engine and ingesting the corpus index

End-to-end runbook: build lume, regenerate `docs/` from `corpus/`, run the full
ingest (lexical + dense embeddings + entity graph), and verify retrieval.
Timings and pitfalls below are from a real run on this corpus (2026-08-26,
Windows 11 host, 24-thread CPU).

## 1. Prerequisites

| Component | Version used | Purpose |
|---|---|---|
| Rust / cargo | 1.96+ | build `lume/` (release profile) |
| Ollama | 0.33+ | entity extraction (`-o`); default model `gpt-4o-mini:latest` must exist in `ollama list` (override: `--ollama-model`) |
| Shivvr | serving on `http://localhost:8085` | dense embeddings (`-s`), 768-d GTR-T5 |
| Python 3.10+ | 3.11 used | `search_repl.py`, `tools/build_docs.py` |
| pymupdf, pymupdf4llm | 1.27 / 1.28 | PDF → markdown extraction (`pip install pymupdf pymupdf4llm`) |

Check Shivvr before ingesting: `Invoke-WebRequest http://localhost:8085/ -UseBasicParsing`
must return 200. Without it, `-s` semantic ingest fails.

## 2. Build the engine

```powershell
cd lume
cargo build --release          # binary at lume\target\release\lume.exe
```

**Pitfall (seen live):** on a memory-pressured Windows host the build can die with
`os error 1455: The paging file is too small` plus a rustc stack overflow.
Fix: limit parallelism — `cargo build --release -j 2`. Build then completes
normally (~90 crates).

Sanity check: `.\target\release\lume.exe --help` lists `index / search / eval / serve …`

## 3. Regenerate docs/ (only when corpus/ changes)

`docs/` is the all-text indexing target derived from `corpus/`:

```bash
python3 tools/build_docs.py     # rebuilds docs/ from scratch, deterministic
```

- PDFs → markdown with real tables (pymupdf4llm) + per-page links back to the
  source PDF (`--- [page N](../../corpus/...pdf#page=N) ---`) + provenance header
  (source path, SHA-256, page/char counts)
- Zips → text members extracted (`_source.md` provenance stub per zip)
- `docs/README.md` = generated extraction report; low-text (scanned) PDFs get flagged

## 4. Full ingest

From the repo root (paths matter — index target is `docs`, db is `.lume-index`):

```powershell
.\lume\target\release\lume.exe index -s -o docs --db .lume-index
```

Flags: `-s` dense vectors via Shivvr, `-o` entity graph via Ollama, `-f` to force
full re-index. `LUME_EXTRACT_WORKERS` (default 10) sets extraction concurrency —
lower it if your Ollama is bound by `OLLAMA_NUM_PARALLEL`.

**Measured on this corpus** (44 documents → 197 files → 9,581 sections, ~15 MB text):

| Stage | Result |
|---|---|
| Chunking | 197 files → 9,581 sections (seconds) |
| Semantic ingest | 9,581 sections → Shivvr @ ~15 chunks/s (~11 min) |
| Entity extraction | 9,581/9,581, 0 failed @ 3.16 chunks/s, 10 workers (~51 min) |
| Index write | 226 s |
| **Total** | **~63 min** |
| Graph | 48,261 nodes, 552,034 edges |
| On disk | ~225 MB: bm25 77.5 MB · entity_graph 119.3 MB · spelling 8 MB · state 20.1 MB |

**Do not search the db while indexing runs.** Checkpoints rewrite `state.json` /
`entity_graph.json` whole and non-atomically; a concurrent search can catch a
torn file and fail with `Failed to parse JSON … EOF while parsing`. Tracked
upstream as [lume#3](https://github.com/DeepBlueDynamics/lume/issues/3).

## 5. Verify

```powershell
# scored benchmark (12 ground-truthed Q&A; expect Hit@10 ≈ 92%, MRR ≈ 0.9)
.\lume\target\release\lume.exe eval --db .lume-index -k 10 --compare tests\qna_sample.json

# interactive
python3 search_repl.py          # :help for commands; :index re-runs the full ingest
```

Reference numbers from this corpus: Hit@10 91.7% (11/12), MRR 0.92 (jaccard) /
0.88 (relatedness), nDCG@10 0.84. Known miss: the Table 20-I af2 question — table
cell tokens are wrapped in `<sup>` markup (`2<sup>-55</sup>`), which costs BM25 the
literal match. Fix path: normalize `<sup>` to plain text in `build_docs.py`, rebuild
docs, re-index.

## 6. Prebuilt index (skip the 63-minute ingest)

A snapshot of the fully built index ships in the repo:

```powershell
tar -xzf dist\lume-index-2026-08-26.tar.gz    # unpacks .lume-index/ at repo root
```

Then go straight to step 5 (verify). Rebuild from scratch (step 4) whenever
`docs/` changes; the snapshot is frozen at the 2026-08-26 corpus state.

## 7. Container vs host

The n8 container mounts the repo at `/workspace/navy` (host:
`C:\Users\kordl\Code\research\navy`). Build and ingest run on the **host**
(cargo, Ollama, Shivvr live there); extraction (`build_docs.py`) runs in the
**container** (pymupdf lives there). The `.lume-index/` output is visible from
both sides; it is gitignored — every clone rebuilds its own index with the
commands above. If you ever serve `lume serve` from inside a container, bind
`0.0.0.0`, not `127.0.0.1`.
