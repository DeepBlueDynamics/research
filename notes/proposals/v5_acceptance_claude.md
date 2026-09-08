# Claude acceptance of v5, document retrieval and provenance track

Date: 2026-09-07. Reviewed `submission_draft_v5.md` (5,670 words by `wc -w`) and `v5_synthesis_notes.md` against `v4_forward_documents_claude.md` as corrected after Codex's review. The draft was not modified.

## Decision: ACCEPT. No blocking fixes.

Every item from the corrected review is present, in the right place, with no overclaim:

- **1.0.5 "Documents and provenance"** (line 49): text index plus separately evaluated page-image index; existing encoder as baseline; replacements chosen on development queries, licensing suitability, and declared hardware; manifest pins documents, page anchors, model revision, dimensions, preprocessing, normalization, index version, and license; incompatible change rebuilds; mismatched sealed package fails validation; authoritative and generated collections separate; only authoritative passages cited; source change invalidates dependent annotations; acquisition and generation in development only; no runtime fetch. Matches review §5, §6, and change (a).
- **1.0.5 "Compiled tools"** (line 43): the lookup-only target is stated as "under 30 microseconds is a lookup-only design target, not a measurement." Correct framing.
- **1.0.5 "Bounded analogue fallback"** (line 45) and **Figure 2** (line 55): first frame including fallback and abstention cases must meet Section 1.1; timeouts stay in the denominator; no language model or document embedder composes the initial recommendation. Consistent with the strict gate.
- **1.1 gate table** (line 83): document retrieval row uses at least 60 final held-out triggers frozen in B1, recall@1/3/5/10 and reciprocal rank per family for lexical, dense, and hybrid, a separate figure-bearing subset for page images, and development queries for selection. Fail conditions are the critical-trigger miss at rank 5 and hybrid below lexical; the 0.90 mean recall@5 is labelled a proposed target. Telemetry similarity (line 84) is a separate row. Matches corrections 1–3.
- **1.2 B1** (line 108): family-separated training/validation/final partitions; final query and scenario sets frozen before tuning; thresholds chosen on validation only. **B2** (line 111): development retrieval queries and a separately held-out set of at least 60 page-anchored triggers; source hashes and licenses preserved. **B3** (line 114): document and page-image retrieval evaluated on development queries; models, thresholds, manifests, and bindings frozen before final testing; only authoritative passages citable. **B4** (line 117): final held-outs only; mean per-trigger recall and reciprocal rank with family-stratified uncertainty; correlated clusters accounted for; binomial intervals only for binary outcomes; development results reported separately. Matches changes (d)–(f) and corrections 1–2.
- **1.3.2** (line 148): locally served text encoder, manifests, collection separation, optional visual-page indexing, final held-out recall measurements, and "these existing assets do not establish Section 1.1 performance." Matches change (g).
- **Facilities** (line 246): target execution profile declared in B1; shipboard GPU availability not assumed; candidate models must fit declared resources and "permit the intended distribution and use." Matches correction 5 and covers licensing without naming vendors.
- No model names, vendor benchmarks, or the Jina question appear in the volume. Correct; they stay in the research notes.

## One non-blocking suggestion (exact text, optional)

The review's change (f) asked for drill-down retrieval latency to be reported per representation, separately from the gate, because a page-image query on a CPU-only host may take seconds and a reviewer should see that number rather than infer it. v5 B4 does not say it. If page budget allows, append to B4 after "Report development results separately.":

> Report drill-down retrieval latency per representation on the declared target profile and on the development host, separately from the latency gate.

If page budget does not allow, the protocol document carries it and nothing in the volume is wrong.

## Outside this track, noted only

Word count is 5,670 against a ten-page limit that already needed proportional type at 4,900. Page fit is now the risk, not content. Company facts, the official P-40 citation, DSIP clarifications, figures, and typesetting remain open as the synthesis notes say.
