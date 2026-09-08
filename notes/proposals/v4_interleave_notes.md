# v4 interleave notes (Grok, 2026-09-07)

**Wrote:** `notes/proposals/submission_draft_v4.md` (4,897 words after comment strip; ~10.2 estimated pages in 10-point proportional type *before* embedded figures). Claude’s paste was 7,061 words. At PDF time keep Figure 1 readable, Figure 4 as the existing table, and Figures 2/3/5 small — or cut another ~400 words.
**Claude source saved:** `notes/proposals/claude_synthesized_acme_v2.md`
**Did not modify:** `submission_draft.md`, `submission_draft_v2.md`, `submission_draft_v3.md`, `acme_comparison_grok.md`, official templates, shared opening-pages files.

## Spine (Claude)

ACME sub-structure inside Navy 1.0–3.0: 1.0.1 team/buyer intro, 1.0.2 problem, 1.0.3 opportunity, 1.0.4 contractor experience, 1.0.5 innovative approach; 1.1 six numbered objectives + gate table; 1.2.1–1.2.10 tasks with feasibility-analysis and reporting; 1.3.1–1.3.7 named reuse blocks; 2.1–2.5 formal personnel / consultants / IP / prior support; 3.1–3.6 transition, dual-use, honest “no customers,” milestones. No O4 / SME HCD. Option tasks stay **O1–O3** because base objectives are now 1–6 (no collision with Grok v3’s OP1–OP3 workaround).

## Grok patches folded in

- Latency **defined once** in 1.1 (monotonic clock, queueing, actual frame, ≥100 ms fails, uncertainty overlapping 100 ms is not a pass, Government under one second reported separately, failed offeror gate is a limitation not a waiver). 1.0 names the offer; later sections say “latency gate (Section 1.1).”
- Topic Q&A 1 Sep 2026 is **not** a human-research exemption.
- Iron Bank: packaging on an Iron Bank base is hardening-ready; whether the Phase I **demonstration** must run on an Iron Bank image is a Government question; secured-runtime gate applies regardless.
- Architecture one-liner from v3: sources → bus → rules → screen; simulator/truth outside the product; integrity-unavailable feeds never drive a decision; keyed lookup unmeasured.
- 1.3 reuse sentence: container + retrieval + display driver are the start; adapters, compiled rules, frozen harness, and measured evidence are new.
- TPOC review at Month 2 is a **review**, not a CSO-required hold point.
- Figure captions argue; **no repo paths** in the volume body.
- [8] IMO MSC.302(87) (17 May 2010) and [9] DHS Resilient PNT CF v2.0 (2022) kept; verified against `docs/B/B5_MSC.302(87)_Bridge_Alert_Management.md` and `docs/C/C3_DHS_Resilient_PNT_Conformance_Framework_v2.0.md`. Drafting “verify citation” notes removed from the filed reference list.

## Cuts vs Claude’s paste (page budget)

Claude 7,061 words would overflow ten pages even in 10-point proportional type. v4 trims: NAVCEN/OPNAV/GAO detail lives in 1.4 not twice; 1.3.5–1.3.6 point at 2.0 instead of reprinting resumes; B3 refers to the 1.0.5 loop instead of restating all four steps; dual-use keeps the first three segments and collapses the rest; 1.0.4 bios stay short.

## Figures (not in the filed volume body)

- **Figure 1.** Notional console. Preferred still: `notes/hmi-mockups/apnt-console.html`. Alternate sketch: `notes/hmi-mockups/remarkable/fig_console_sketch-8.png`. Do not use `hmi-0*_DO-NOT-USE.png`.
- **Figure 2.** Architecture (to produce): sources → bus → rules → screen; keyed retrieval and optional model off the hot path; Iron Bank container boundary; simulator outside.
- **Figure 3.** Combative-training loop (to produce): generator with held truth → development-environment model → cited rules and tests → human review → compiled rules shipped. Frozen held-out set outside the loop.
- **Figure 4.** Schedule table already in Section 1.2; optional Gantt.
- **Figure 5.** Evidence trace (to produce): INDETERMINATE alert → supporting observations → rule version and guidance clause → named cross-check.

## Still open (company)

PI designation and primary employment; hours; Clint title/start; foreign person; degrees; performance location/equipment; consultants or “None”; Volume 5 IP; CUI/Iron Bank Government questions; official P-40 citation; disclosure legend. Interface code name is **SEXTANT** (offeror designation, not a Navy program name; no backronym claimed). Applied in `submission_draft_v4.md` first use and product mentions; mockup chrome in `notes/hmi-mockups/apnt-console.html` and `deploy/index.html`. HTML filename unchanged. Figures 2, 3, and 5 still need to be drawn. Typeset in 10-point proportional type; keep figures compact.
