# V4 forward: document retrieval and provenance review (Claude, 2026-09-07)

Scope per `v4_forward_architecture_brief.md`, representation 1 (text corpus and visual documents), derived documentation, manifests and reindexing, and the retrieval recall@k metric. Base text: `submission_draft_v4.md`. v4 and earlier drafts are untouched. Nothing here has been built or measured; every number labelled "estimate" is arithmetic from the model card, not a run.

---

## 1. Findings in one screen

1. **One of the three user candidates is excluded absent a suitable commercial license.** Jina Embeddings v4 is under the Qwen Research License, which permits use "FOR NON-COMMERCIAL PURPOSES ONLY" and says commercial users "shall request a license" from Alibaba. A Government deliverable built by a for-profit firm is commercial use. It is not categorically unusable: if the firm obtains a written commercial license from Alibaba (and, for the Jina fine-tune, whatever terms Jina attaches), it becomes a candidate again. Until then it is out, and the same condition applies to ColQwen2.5 (adapter MIT, base Qwen2.5-VL-3B under the same license).
2. **The other two candidates are clean.** Qwen3-Embedding-0.6B (Apache-2.0, text) and Qwen3-VL-Embedding-2B (Apache-2.0, text plus page images) are adoptable. The 8B visual variant is also Apache-2.0; its bf16 weights exceed the 12 GB development workstation GPU, which says nothing about shipboard hardware (unknown) and only that build-time use here would need quantization or a larger build host.
3. **The text index we have today is not broken.** shivvr embeds with gtr-t5-base (Apache-2.0, 768-d, 0.1B). Replacing it is a measured decision, not a stated one: the golden set in section 6 decides, and any replacement forces a full dense reindex under a new manifest.
4. **Visual-page indexing is a drill-down feature, not a hot-path one.** Our authoritative documents are already extracted page by page to markdown with real tables and per-page links back to the PDF. A page-image index adds value for symbology charts, figures, and scanned pages, costs a 2B model in the sealed image, and never touches the 100 ms path. Propose it as an evaluated option in B3 with its own recall@k, not as a commitment.
5. **The repo already has the provenance skeleton.** `corpus/manifest.csv` carries sha256, license, retrieval time, supersedes/superseded-by, and a demo-corpus flag; `tools/index_manifest.py` writes a per-file sha256 manifest and an append-only index history and flags drifted sources as VERIFY or INVALID. What is missing is the model and preprocessing pin, the representation split, and the authoritative-versus-generated collection field. Section 5 specifies them.
6. **Two dev-time leak risks to close in the text.** The vendored lume README defaults to a cloud-backed generation model, and BUILDING.md's entity-extraction step names an Ollama model. Both are fine on the pre-award public corpus and wrong for anything controlled. The proposal should say generation and extraction run on local models under the same manifest rules.

---

## 2. Candidate model verification (primary sources, read 2026-09-07)

| Model | License (card) | Params | Output dims | Context | Modalities | Card benchmarks (vendor-reported) | bf16 weight estimate | Verdict |
|---|---|---|---|---|---|---|---|---|
| sentence-transformers/gtr-t5-base (current shivvr embedder) | Apache-2.0 | 0.1B (T5-base encoder) | 768 | not stated on card (T5 encoder; treat as 512 tokens until measured) | text | trained "for the task of semantic search" | ~0.2 GB | Keep as Phase I baseline; measure against the golden set |
| Qwen/Qwen3-Embedding-0.6B | Apache-2.0 | 0.6B (Qwen3-0.6B-Base) | 32–1024, user-defined (MRL) | 32k | text, 100+ languages | MTEB multilingual mean 64.33, retrieval 80.83; MTEB English v2 70.70; card dated 5 Jun 2025 | ~1.2 GB | Adoptable candidate for the text index; instruction prefixes change vectors, so the prefix is part of the pin |
| jinaai/jina-embeddings-v4 | **Qwen Research License** (card notes it was first posted as CC-BY-NC-4.0 "in error"; both are non-commercial) | ~4B (Qwen2.5-VL-3B-Instruct base) | single-vector 2048, MRL 128–2048; multi-vector 128/token | 32k | text, images, visually rich documents | Jina-VDR, MTEB references; report arXiv 2506.18902 | ~8 GB | **Excluded absent a suitable commercial license**; re-enters as a candidate if one is obtained in writing |
| Qwen/Qwen3-VL-Embedding-2B | Apache-2.0 | 2B (Qwen3-VL-2B-Instruct base) | 64–2048 (MRL) | 32k | text, images, screenshots, video | MMEB-V2 73.2; MMTEB 63.87; card dated 8 Jan 2026; requires transformers ≥ 4.57, torch 2.8.0 | ~4 GB plus vision tower | Adoptable candidate for the page-image index |
| Qwen/Qwen3-VL-Embedding-8B | Apache-2.0 | 8B | 64–4096 (MRL) | 32k | as above | MMEB-V2 77.9; MMTEB 70.58 | ~16 GB | Exceeds the 12 GB development workstation GPU in bf16; usable there only quantized (unmeasured). No inference about shipboard hardware |
| vidore/colqwen2.5-v0.2 (comparison) | adapter MIT, base Qwen Research License | 3B | 128/token, late interaction | n/a | page images | none on card | ~6 GB | Excluded on base-model license absent a commercial license; ColQwen2 on the Apache-2.0 Qwen2-VL-2B base is the only late-interaction option worth checking, not verified here |

License text quoted from the Qwen Research License Agreement (release 19 Sep 2024): "non-exclusive, worldwide, non-transferable and royalty-free limited license ... FOR NON-COMMERCIAL PURPOSES ONLY" and "If you are commercially using the Materials, you shall request a license from us." No procedure, price, or contact is given.

Benchmark numbers above are the vendors' own. They are not evidence for this proposal; the golden-set recall@k in section 6 is.

---

## 3. Text versus visual-page indexing

**What the corpus is.** `docs/` holds 247 files, 14.8 MB of text rendered from `corpus/` with pymupdf4llm: real tables, a provenance header, and a per-page marker that links to the source PDF at that page. The retrieval engine (vendored lume, commit 867c8db, 2026-06-27) indexes it three ways: BM25 lexical, dense vectors through shivvr, and an entity graph. The index on disk is 77 MB BM25, 119 MB graph, 20 MB state.

**Where text indexing is enough.** Procedures, alert-priority tables (MSC.302), integrity-level definitions (MSC.1/Circ.1575 ¶47), conformance-framework requirement lists (DHS CF v2.0), OPNAVINST paragraphs. These are the passages the citation panel will show, and they extract cleanly.

**Where it is not.** S-52 symbology and colour tables, figure-heavy pages (DHS CF reference architectures, NIST profile figures), scanned or two-column PDFs where the extractor scrambles reading order, and any Phase II GFI that arrives as images. For those, a page-image index answers "which page shows this" better than extracted text.

**Cost of the visual index.** Build time: every page rendered and embedded once, offline, on the development GPU; thousands of pages is hours, not days (estimate). Runtime: the query side of a page-image retriever is the same 2B model, so a drill-down query on a CPU-only shipboard host could take seconds. That is acceptable only because the alert path never calls it. Storage: single-vector MRL at 512 dims is ~1 KB per page; late-interaction at 128 dims per token is ~190 KB per page (estimate from the ColQwen card's 755-token document example), which is why single-vector is the practical choice inside a sealed image.

**Recommendation.** Phase I commits to the text index with page-anchored citations and evaluates the page-image index as an option on a figure-bearing query subset. Adopt Qwen3-VL-Embedding-2B for that evaluation because of its license. Do not name Jina in the volume.

**Counterargument, kept in the notes.** A reviewer could say a single multimodal embedder for both text and pages is simpler than two models and two indices. True, and it is what Qwen3-VL-Embedding-2B offers. Against it: a 2B model on every text query is four times the weight of the 0.6B text model for no measured gain on our text, and the text index already exists. The golden set settles it; the prose should say "one or two embedders, decided in B3 by measurement."

---

## 4. Local hardware fit

- Development host (measured): NVIDIA GeForce RTX 3060, 12,288 MiB, driver 595.71; 24-thread CPU (BUILDING.md). Shivvr reports GPU active. This is the build-time reference for index construction here and nothing more; it is one workstation, not a fleet or a cluster.
- Shipboard host: unknown. The Q&A says compute-platform-independent and 100 percent local. The proposal must neither assume nor rule out a GPU at sea, and must not derive memory or throughput limits from the development workstation. Declaring the target hardware profile is a B1 item and an open question for the Government.
- Consequences: the text embedder is sized to run on CPU with acceptable drill-down latency as the conservative case (0.6B fp32 on CPU is plausible; unmeasured), and uses a GPU if one is present; the page-image model is optional and GPU-preferred; whether the 8B model can ship depends on the declared target, not on this workstation; all embedding of the corpus happens at build time so the sealed image carries indices, not build jobs.
- State the hot-path independence plainly: the keyed lookup that feeds the 100 ms gate reads a precomputed table; no embedder runs on that path.

---

## 5. Manifests, pinning, and reindexing

**What exists.** `corpus/manifest.csv` (id, title, issuing body, edition, date, license, URL, sha256, retrieved_at, supersedes, superseded_by, demo_corpus, notes) and `corpus/gaps.md` (restricted and paid items recorded, not fetched). `tools/index_manifest.py` writes `docs_manifest.json` (sha256, bytes, mtime per file, manifest fingerprint) and `index_history.jsonl`, and `verify` tags drifted hits VERIFY or INVALID at query time. The last snapshot: run idx-2d82003f711d, 2026-08-27, 247 files.

**What to add (proposed manifest schema, one record per index).**

```
index_id, representation (text-lexical | text-dense | page-image | telemetry),
corpus_fingerprint (docs_manifest sha256),
embedder: {hf_repo, revision (commit hash), license, dims_used, dtype, instruction_prefix, chunker + params, normalization},
index_format_version, built_at, built_by (tool version), host (gpu/cpu),
golden_set_version, recall_at_k_results (or "unmeasured")
```

**Rules.**
1. A change in embedder repo, revision, dims, dtype, instruction prefix, or chunker is incompatible and forces a full rebuild of that representation's index. Mixed-vintage vectors are never allowed in one index.
2. A change in the corpus (any sha256) forces a rebuild of every representation that includes that file; until rebuilt, hits from that file are served with the VERIFY tag and the citation panel says so.
3. Every index build appends to `index_history.jsonl` with the manifest above; the sealed container carries the manifest and refuses to start if the index fingerprint does not match.
4. Model weights are pinned by commit hash and stored in the offline package mirror with their license text; the SBOM lists them.
5. Restricted or paid documents stay recorded-not-fetched (as now); Government-furnished material in Phase II gets its own collection under its handling rules and is never merged into the public index.

---

## 6. Authoritative versus generated collections, and citation

**Authoritative:** published standards, instructions, advisories, and Government documents with sha256, license, and page anchors. Only these appear in the citation panel, and only as page-anchored passages.

**Generated:** postmortems from training runs, rule rationales, synthesized query-answer pairs (lume ships a Q&A generator), scenario summaries. Each record carries: generator model and revision, prompt version, source passage ids, review state (unreviewed, reviewed, approved), reviewer, date. Generated records may guide retrieval (query expansion, routing, nearest-analogue hints) but never appear as a citation. If a generated record's source passage drifts (rule 2 above), the record is marked stale.

**Fetching:** development only, under the corpus collection rules already in README (public and unclassified only; paid and restricted recorded, not fetched). No fetch capability exists in the runtime image.

**Dev-time models:** generation, entity extraction, and rule synthesis run on local models pinned like embedders. The lume default of a cloud-backed generation model and any cloud extraction model are disabled in the project configuration. Pre-award public material is not treated as CUI; whether any Phase I working data is, remains the open Q&A question, and the training loop is designed to run entirely local so the answer does not change the architecture.

---

## 7. Retrieval recall@k protocol

**What it measures.** Document retrieval for the drill-down path only: given a trigger, does the engine return the authoritative passages a reviewer marked relevant. It does not measure the keyed lookup, which is an exact table read covered by the latency and evidence-fidelity gates, and it does not measure the telemetry nearest-scenario fallback, which retrieves labelled scenario analogues in the situation-vector space and has its own protocol in the telemetry review (representation 2 of the brief). Keep the two apart in the volume; a good document recall says nothing about analogue quality.

**Two golden sets, not one.** (a) A development/validation golden set, used to choose chunker, embedder, fusion weights, dimensions, and any threshold. (b) A final held-out golden set, frozen in B1 alongside the scenario held-outs, never opened until the B4 evaluation and never used for any selection. Choosing a model on the set you then report is evaluation leakage; the final numbers come from (b) only, and the report states which set produced every figure.

**Trigger set.** One trigger per reachable anomaly state and procedure need (for example: GPS A degraded with INS available; two GNSS agree with no independent family; jamming signature with recovery; timing holdover exceeded). Target ≥ 60 triggers in the final set and a comparable development set, stratified by triage class and by information need (procedure, alert-priority rule, integrity definition, symbology). Triggers within a family share documents and are not independent draws; that matters for the statistics below.

**Golden set.** For each trigger, the authoritative passages a reviewer marks relevant, by document id and page anchor, ≥ 2 per trigger, with a relevance grade (required, supporting). Built from the corpus in B2, versioned, and after the freeze never used to tune chunking, prompts, or thresholds.

**Metrics and aggregation.** Per trigger: recall@k for k in {1, 3, 5, 10} as the fraction of that trigger's required passages retrieved in the top k, and reciprocal rank of the first required passage. Aggregate as the mean over triggers, reported per family and overall. Because per-trigger recall is a fraction and triggers cluster by family, uncertainty on the means comes from a family-stratified (cluster) bootstrap over triggers, not from a binomial interval. A separate binary outcome, "all required passages found at k = 5," is a per-trigger success count, and only there is a Wilson 95 percent interval appropriate. Report lexical-only, dense-only, and hybrid (the engine's fusion) so the contribution of each representation is visible. For the page-image index, a separate golden set of figure-bearing triggers with page-level relevance, same metrics and aggregation.

**Fail criteria (offeror-proposed).** Any critical-procedure trigger whose required passages have recall@5 = 0 fails the gate outright. Target: mean recall@5 on required passages ≥ 0.90 on the final held-out set, and hybrid not worse than lexical-only on any family. The 0.90 is a proposal, and the bootstrap interval is reported beside it.

**Baseline.** Lexical-only retrieval on the same index is the baseline; the hybrid must not be worse on any family. The old repository figure (Hit@10 on a different query set) is not cited anywhere.

**Latency reporting.** Drill-down retrieval latency is reported per representation on the declared hardware, CPU and GPU, separately from the 100 ms gate.

---

## 8. Exact proposed prose changes to v4

**(a) 1.0.5, replace the "Keyed retrieval" paragraph with:**

> **Keyed retrieval, then evidence.** Before seal, every reachable anomaly state is mapped to its recommendation, procedure, and evidence layout; at runtime the screen reads that table (design target under 30 microseconds, unmeasured). No embedder or model runs on that path. Evidence for drill-down comes from two indices built at development time and sealed into the image: a text index over the authoritative reference documents (lexical, dense, and graph), and, if Task B3 shows it earns its place, a page-image index for symbology charts and figures. Each index carries a manifest that pins the corpus fingerprint, the embedding model and its revision, dimensions, preprocessing, and license; a change to any of them forces a rebuild, and the container refuses to start on a mismatched index. Two collections are kept apart: authoritative documents, which alone may be cited, with page anchors; and generated material from training runs, which may guide retrieval but is never shown as a citation. Every assessment resolves to its evidence and rule version (Figure 5). A local bus is the only path between components. The image is built from pinned, hash-verified packages with an SBOM; a failed security control fails the build. Whether the Phase I demonstration must run on an Iron Bank image is a Government question; an isolated containerized demonstration is highly encouraged. [1] [3]

**(b) 1.1, add a row to the gate table after "Evidence fidelity and replay":**

> | Document retrieval recall (drill-down path only) | ≥ 60 held-out triggers, frozen in B1 and never used for model or chunker selection, with reviewer-marked authoritative passages; per-trigger recall@1/3/5/10 and reciprocal rank, averaged per family with a family-stratified bootstrap interval; lexical, dense, and hybrid reported; page-image index scored on its own figure-bearing subset if built. Selection decisions use a separate development set. | Any critical-procedure trigger with recall@5 = 0 on its required passages; hybrid worse than lexical-only on any family. Target mean recall@5 ≥ 0.90 is offeror-proposed and reported with its interval. The telemetry nearest-scenario fallback is scored under its own gate, not this one. |

**(c) 1.1, objective 2, append one sentence:**

> Embedding models are candidates until measured: the current 768-dimension text embedder is the baseline, and any replacement or added page-image embedder is Apache-2.0 or equivalently licensed, pinned by revision, and adopted only on golden-set results.

**(d) 1.2 B2, append:**

> Build two retrieval golden sets of page-anchored authoritative passages: a development set for choosing chunker, embedder, and fusion, and a final held-out set of ≥ 60 triggers frozen with the scenario held-outs and not opened until B4. Record every reference document's source, hash, license, and retrieval date in the corpus manifest; restricted or paid items are recorded, not fetched.

**(e) 1.2 B3, replace "Key the retrieval index by anomaly state; measure keyed-lookup latency against the 30-microsecond target (unmeasured until B4)." with:**

> Key the retrieval table by anomaly state; measure keyed-lookup latency against the 30-microsecond target (unmeasured until B4). Build the text index and, as an evaluated option, a page-image index, each under a pinned-model manifest; decide on the development golden set whether one embedder or two ships, and report only the final held-out set in B4. Separate authoritative and generated collections; only authoritative passages are citable.

**(f) 1.2 B4, append to the evaluation list:**

> Run the document retrieval recall@k protocol on the final held-out golden set (development set results reported separately and labelled as such) and report drill-down latency per representation on the declared target hardware and on the development host, separately from the latency gate. The telemetry nearest-scenario fallback is evaluated under its own protocol.

**(g) 1.3.2, replace with:**

> **1.3.2 Hybrid retrieval engine (internally funded).** Vendored lexical/vector/graph search with an index manifest and drift check (sources changed since indexing are flagged at query time). Current text embedder: an Apache-2.0 768-dimension sentence encoder served locally. Phase I adapts the engine to keyed anomaly-state lookup (30 µs target, unmeasured) and to semantic drill-down, adds pinned-model manifests, and measures recall@k on a frozen golden set. Not yet measured under the Section 1.1 latency gate. Period: [to confirm].

**(h) Facilities/Equipment, append one sentence:**

> Development index builds use a workstation GPU with 12 GB of memory. The shipboard hardware profile is declared in Task B1 and is neither assumed to include nor to exclude a GPU; the text embedder is sized to run on CPU as the conservative case, and the page-image embedder, if adopted, is used only for drill-down.

**(i) Do not add** model names or vendor benchmark scores to the volume. Keep them in the evaluation plan and this note. If a model must be named, name it as a candidate with its license.

---

## 9. Counterarguments and open questions

1. **"Why not one multimodal embedder?"** Answered in section 3: possible with Qwen3-VL-Embedding-2B; decided by measurement, not asserted.
2. **"Why keep a 2022-era 768-d text embedder?"** Because it exists, it is licensed, and its recall on our corpus is unmeasured either way. Swapping it costs a full reindex and a manifest change; the golden set makes that a cheap decision.
3. **"Late-interaction retrieval is more accurate for pages."** Often true on ViDoRe-style benchmarks. It costs roughly 200 times the storage per page and a heavier query path, and the only late-interaction models checked carry the non-commercial base license. Not for a sealed shipboard image in Phase I.
4. **"Vendor benchmarks show Qwen3-Embedding beats gtr-t5."** They are vendor-reported on public benchmarks, not on this corpus. Cite none of them.
5. **Open:** shipboard hardware class (needed to size the CPU fallback); whether Phase II GFI arrives as text or images (decides whether the page-image index becomes mandatory); the exact CUI scope from the Q&A; whether ColQwen2 on the Apache-2.0 Qwen2-VL-2B base is worth a look (not verified here).
6. **Blocker for the synthesis:** none. Jina v4 is excluded only for want of a commercial license, and it has an Apache-2.0 substitute.

## 11. Revision log

- 2026-09-07, after Codex review: (1) split the golden queries into a development/validation set for model and chunker selection and a final held-out set that is never used for selection; (2) corrected the statistics: per-trigger recall@k and reciprocal rank averaged per family with a family-stratified bootstrap, Wilson intervals only for the binary "all required passages found at k = 5" outcome; (3) removed the telemetry nearest-scenario fallback from this protocol and pointed to the telemetry review; (4) reworded Jina v4 as excluded absent a suitable commercial license rather than unable to ship; (5) removed any inference about shipboard GPU availability or cluster limits from the single development workstation. v4 untouched.

---

## 10. Sources

- Qwen/Qwen3-Embedding-0.6B model card, https://huggingface.co/Qwen/Qwen3-Embedding-0.6B (read 2026-09-07).
- jinaai/jina-embeddings-v4 model card, https://huggingface.co/jinaai/jina-embeddings-v4 (read 2026-09-07).
- Qwen Research License Agreement, https://huggingface.co/Qwen/Qwen2.5-VL-3B-Instruct/blob/main/LICENSE (read 2026-09-07).
- Qwen/Qwen3-VL-Embedding-2B and -8B model cards, https://huggingface.co/Qwen/Qwen3-VL-Embedding-2B, https://huggingface.co/Qwen/Qwen3-VL-Embedding-8B (read 2026-09-07).
- vidore/colqwen2.5-v0.2 model card, https://huggingface.co/vidore/colqwen2.5-v0.2 (read 2026-09-07).
- sentence-transformers/gtr-t5-base model card, https://huggingface.co/sentence-transformers/gtr-t5-base (read 2026-09-07).
- Repo: `README.md`, `BUILDING.md`, `lume/UPSTREAM.md`, `lume/README.md`, `tools/index_manifest.py`, `.lume-index/docs_manifest.json`, `.lume-index/index_history.jsonl`, `corpus/manifest.csv`, `corpus/manifest.json`, `corpus/gaps.md`; `nvidia-smi` on the development host.
