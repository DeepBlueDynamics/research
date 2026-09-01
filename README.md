# navy — DON26BX05-NP004 research corpus

Public, unclassified document corpus and retrieval system for the Navy SBIR topic
**DON26BX05-NP004** (assured-PNT operator awareness; proposal closes 2026-09-23).

## Start here: `docs/`

**`docs/` is the indexing and retrieval target.** It is the all-text rendition of the
corpus, organized by the spec-list categories:

| dir | category |
|---|---|
| `docs/A/` | PNT data & interface standards (ASPN, pntOS, GPS ICDs, Signal K, NTP) |
| `docs/B/` | Navigation display, symbology, alerting (S-52/S-57, IMO ECDIS/BAM, Bowditch) |
| `docs/C/` | Resilient-PNT policy & tools (NIST IR 8323r1, DHS CF v2.0, PNT-Integrity, advisories) |
| `docs/E/` | Deployment & security compliance (SP 800-190, SP 800-171r3) |
| `docs/F/` | SBIR/topic compliance (topic + Q&A, BAA, topic references) |

Properties of every file in `docs/`:

- **PDFs are converted to markdown** with real tables (pymupdf4llm), a provenance
  header (source path, source SHA-256, page/char counts), and per-page markers that
  **hyperlink to the source PDF at that page** — `--- [page N](../../corpus/...pdf#page=N) ---` —
  so retrieval hits can cite and open the original.
- **Zips are expanded to their text members** (ASPN YAML data model, pntOS-C API,
  PNT-Integrity library sources), each with a `_source.md` provenance stub.
- **Web captures keep their grub crawl headers** (`crawl_url`, `crawl_ts`).
- `docs/README.md` is the generated per-file extraction report.

Regenerate at any time with `python3 tools/build_docs.py` (container) — it rebuilds
`docs/` from `corpus/` deterministically.

## Retrieval: lume + REPL

[`lume/`](lume/UPSTREAM.md) is the vendored hybrid search engine (BM25 + dense
vectors + semantic knowledge graph; Rust). Build with `cargo build --release` in
`lume/`. It later becomes the system's MCP server (`lume serve`).

Test retrieval from the repo root:

```
python3 search_repl.py         # queries .lume-index built from docs/
lume> :index                   # full indexing: semantic vectors + entity graph
lume> gps spoofing detection
lume> :alpha 0.8               # lean semantic; :graph 0 disables SKG boost
lume> :verify                  # is the index stale vs docs/? (see below)
lume> :history                 # index build history
```

## Index provenance (staleness flagging)

An index is a frozen snapshot of `docs/`; a hit from a since-changed source can be
silently wrong. `tools/index_manifest.py` records what was indexed and flags drift:

```
python3 tools/index_manifest.py snapshot   # record docs/ state after `lume index`
python3 tools/index_manifest.py verify     # diff docs/ vs manifest (exit 1 on drift)
python3 tools/index_manifest.py history    # the append-only index-run trail
```

It writes `docs_manifest.json` + `index_history.jsonl` into the index dir. The REPL
runs `verify` at startup and **tags each search hit** whose source drifted:
`⚠ VERIFY` (source modified since index) or `⚠ INVALID` (source removed). `:index`
auto-records a new snapshot.

## Browse the docs

```
python3 tools/docs_browser.py            # http://localhost:7070/
```
A zero-dependency doc browser: collapsible `docs/` tree on the left, click a file to
read it rendered (markdown, tables, code) on the right; per-page markers link back to
the source PDF at that page. Binds `0.0.0.0` so it works from a container.

## Everything else

- `corpus/` — original fetched documents (PDF/zip/md) + `manifest.csv|json`,
  `gaps.md`, `changes.md` (provenance and collection state; manifest backfill pending)
- `crawl_cache/` — raw grub crawl captures
- `NP004_spec_list_and_research_agent_plan.md` — the A–G spec list and collection plan
- `notes/`, `tools/` — working notes and build scripts

Collection rules: public/unclassified only (no CUI/FOUO/ITAR/Dist B–F); paid standards
recorded but not fetched; full-text marking scan of docs/ is clean (only Distribution
Statement A on the GPS ICDs).
# navy
