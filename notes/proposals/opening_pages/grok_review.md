# Grok peer challenge — NP004 opening pages

**Date:** 2026-09-07  
**Inputs read:** `claude_pages_1_2.md`, `antigravity_pages_1_2.md`, `codex_pages_1_2.md`, `grok_pages_1_2.md`, `codex_review.md`.  
**Not used as authority:** `shared_pages_1_2.md`, `shared_evaluation_protocol.md`, other agents’ reviews. Filename listing showed they exist; they did not drive this file.  
**Original Grok draft preserved:** `grok_pages_1_2.md` is not edited in this round.

Class labels: **S** = topic/Q&A; **P** = offeror/user proposed gate; **A** = unverified. User firm constraints (air-gap, secured runtime, any ≥1 s fails) are **P** tightening of **S** bounds, not Government-published pass marks.

---

## 1. Strongest point from each draft

**Claude.** The three operator questions—what is known, which assumption failed, what independent evidence would settle it—are the cleanest operational statement of the topic. Revision 2 correctly conditions coherent-bias diagnosis on a source with a distinct error dependency that is present and accurate enough, and otherwise requires INDETERMINATE plus “cross-family verification unavailable.” IMO MSC.401(95) / MSC.1/Circ.1575 and DHS CF v2.0 (detection is probabilistic; untrustworthy ≠ always wrong) are the best standards grounding among the four. Paint-event (not queued render) for latency is the right measurement boundary.

**Antigravity.** Tightest product-versus-simulator split and the most concrete two-tier analytic (intra-family plausibility vs cross-family agreement) plus progressive disclosure. The secured-runtime control list (non-root, read-only rootfs, dropped capabilities, no SSH) is specific enough to test. Zero-miss latency *intent* after the user clarification is correct even where the table’s sample unit is not.

**Codex.** Best product thesis: a unified display is more useful than aggregation only if it shows *why a decision is supportable and what evidence is missing when it is not*. Observation-equivalent worlds (identical visible inputs must not yield different diagnoses because the evaluator knows different ground truth) is the load-bearing evaluation hygiene. Frozen observation model, evaluator-only truth, development cases separate from holdout, and a declared threat model with negative security tests are the right protocol bones. Codex’s own concession that 60 / 18-of-20 / 12-task numbers are budget, not evidence, is the honest framing those numbers need.

**Grok (this draft).** Government maritime sources (MARAD 2026-008; closed NAVCEN marine reports, constellation not at fault) without treating commercial vessel-counts as Navy-validated. Explicit **S/P/A** labels. No invented 30–180 s / 60 s baseline. Split scoring: triage *when evidence is in the inputs*, abstention on no-win, anti-abstention on nominal. Documented retraction of p95.

---

## 2. Counterarguments

### 2.1 Antigravity

1. **Invented baselines (reject).** “Manual cross-check 30 to 180 seconds,” “~60 s task completion,” “high false-alarm rate,” “1–2 independent GPS/INS displays” are not in the topic or Q&A. Fragmentation is **S**; those numbers are **A** presented as fact. Remove. Do not replace with a new estimate.

2. **Unconditioned 100% coherent-spoof detection (reject).** KPP-3 “100% detection of coherent GNSS regional bias” / “Fail: coherent spoofing misclassified as Nominal/Assured” does not require that discriminating evidence be *observable in the inputs*. Independent evidence may be absent, stale, correlated, or too inaccurate. Residual disagreement is not proof that a named source is compromised. **No guaranteed detection without observable evidence.** Required output when the independent family is missing or stale is INDETERMINATE + named gap, not a forced spoof label.

3. **“Non-RF” independence is false.** eLoran is RF. Distinct *error families / dependencies* (GNSS RF geometry vs INS drift vs radar fix vs clock holdover), not a RF/non-RF binary. Optical tracking and eLoran as installed DDG inventory are **A**.

4. **ECDIS-conformant / MIL-STD-1472H / MSC.302(87) as Phase I implementation.** Q&A 8/28: ECDIS-like is a **UX familiarity target**, not S-57/S-52/NMEA (or BAM certification). Keep chosen design practices; drop conformance claims.

5. **N = 10,000 consecutive epochs is the wrong latency denominator.** The **S** bound is ingest → rendered alert **and initial COA** on operational-state changes, not every 1–10 Hz message. A soak of 10,000 quiet epochs can pass while a burst onset fails, or fail as a message-processing SLA the Q&A did not write. Measure: (a) every injected onset in the frozen suite; (b) a declared soak/burst at 8×10 Hz; (c) warm and cold start separately. **Any ≥1 s or drop fails.** Report the distribution; do not use it as the pass rule.

6. **Render callback ≠ presented frame.** Agree with Codex: validate paint/capture, not work queued to WebGL.

7. **KPP-5 SUS ≥ 80, N = 10 SME walkthroughs, “No IRB required per Q&A 9/1.”** The 1 September answer is that the Government does **not expect** human research. It is **not** an IRB exemption and not permission to run timed participant trials or surveys. Remove SUS/NASA-TLX/timed walkthroughs from Phase I. Rebranding them as walkthroughs does not change their status.

8. **≥ 90% overall accuracy (reject as headline).** A system that never emits spoof can still hit 90% if spoof is rare. Per-class, held-out, observation-conditioned. Critical cases fail **independently** of the aggregate.

9. **Hot-path contamination.** Local LLM rationale and `lume serve` must not sit on the <1 s path (Q&A progressive disclosure). State that in the KPP, not only in architecture prose.

10. **Iron Bank readiness as a Phase I pass.** Q&A 8/28 did not answer whether an Iron Bank base image is required in Phase I. Hardening checklist **P**; Iron Bank approval **unresolved**. Do not fail the demo for lacking an Iron Bank image; do fail for missing declared runtime controls.

11. **0.01% frame-loss allowance** conflicts with lossless source-field preservation. Pick one: capability demonstration with zero silent field loss on the scored suite, plus a separately reported drop log.

12. **Build plan is not a source.** PHASE1_BUILD_PLAN.md is internal design, not Navy evidence of coherent-spoof phenomenology or operator timings.

### 2.2 Claude

1. **Original K2 percentiles.** `p99.9 > 1,000 ms; target p95 ≤ 500 ms` allowed ≥1 s events. Revision 2 correctly rewrites to any event ≥1,000 ms or drop fails, with percentiles informational. **Concession to Claude Rev 2** on this row. The original row must not be the shared text.

2. **“Existing standards define per-source integrity only.”** Contradicted by Claude’s own MSC.1/Circ.1575 citation (cross-source consistency, protection levels). Say: many fielded *interfaces* still present per-source integrity; some *standards* already grade cross-source consistency. The operator still lacks a unified APNT workflow. That is the topic.

3. **Commercial incident counts.** Windward 1,100 vessels / Hormuz tanker-traffic drop remain in Rev 2 page 1. They are not Navy-validated and the 90% traffic figure is not GNSS-only. Prefer MARAD 2026-008 + NAVCEN closed reports (which Claude Rev 2 already added). Drop or one-clause-as-context the commercial count.

4. **Wilson ±0.10 at 35/class.** Not valid without a specified proportion. Worst-case binomial width is larger. Do not print a precision claim that the sample cannot support.

5. **“Follow first alarm” baseline** is a constructed weak comparator. Use a fragmented-display **surrogate** with identical inputs, labeled as such, not as the fleet.

6. **ECE / probability calibration** on ordinal assurance levels (Assured / Inconsistent / Unassured) requires a defined probability. Risk/coverage analysis is fine; ECE as a Phase I fail criterion is not, unless a probability is defined and held out.

7. **K7 “> 3 interactions.”** Invented UX threshold. Evidence-completeness is the real fail; interaction count is a descriptive proxy only.

8. **DeepBlue Dynamics named in Rev 2.** Grok treated platform ownership as **A**. Naming the company in Volume 2 prose is a filing fact, not established by these drafts. Shared text should keep a placeholder or confirmed legal name only after corporate verification.

9. **Original unconditioned coherent-bias miss.** Rev 2 fixed this. Shared K3 must keep the Rev 2 condition, not the original “missed in any held-out instance.”

10. **“Measurably improves”** in the hypothesis can be read as a result. Keep “we hypothesize”; do not let it leak into KPP fail rows.

### 2.3 Codex — including 60-case / 90% / workflow-proxy

Codex’s self-critique is directionally right and still too gentle on the numbers as they will be read in a 10-page proposal.

1. **60-case holdout (20/20/20) is a budget, not a coverage design.** Equal strata do not specify fault vs jam vs spoof, progressive degradation, stale data, missing metadata, recovery transitions, or observation-equivalent pairs. Twenty recoverable cases can hide a 2-case spoof cell. **Do not freeze 60 as if it were statistically powered.** A finite engineering suite is acceptable if (a) coverage dimensions are enumerated before freeze, (b) holdout is separate from development, (c) intervals are printed next to rates, (d) **critical-case oracles fail independently of 18/20**.

2. **18/20 = “90%” useful decisiveness (challenge).**  
   - Observed 18/20 has a wide interval (order of 0.70–0.97 at 95%, Wilson); it cannot distinguish 90% from 75%.  
   - A 90% *headline* lets a system pass while missing an entire critical class.  
   - 18/20 is not a Navy threshold.  
   **Shared rule:** if a floor per stratum is kept, write “18 of 20 in this frozen suite,” report every miss, and **never** say “90% accuracy” in prose. Critical observable cases (e.g. coherent bias with a fresh distinct-family source in the inputs) are pass/fail **outside** the 18/20 arithmetic.

3. **Zero unsupported diagnoses in 20 unresolved cases** is a legitimate **demo gate**, not a reliability proof. Codex already said this. Shared prose must say “finite suite; no universal zero-failure claim.”

4. **12 tasks / 9-of-12 fewer view changes (reject as a benefit claim).** View-count can reward crowding (put everything on one screen). It is a workflow **proxy**, not workload, not speed-to-decision, not transfer-of-training. Pair with evidence-completeness and a legibility/design check. Do **not** use 9/12 as a human-performance result. Do **not** treat it as a substitute for Q&A-named operator metrics that Phase I cannot measure without participant research.

5. **Three full interfaces.** Agree with Codex self-critique: fragmented surrogate + full explanatory UI; if a third arm is needed, **feature-disable** the same UI (explanations off). Do not build three products in a six-month base.

6. **Latency envelope incomplete.** Four corners (3 and 8 sources × 1 and 10 Hz) miss mixed rates and 4–7 sources. Add a declared sweep. Ingress timestamp ≠ injection onset; declare both. Security hardening **on** during latency tests (Codex review is right; Grok K2 did not say this explicitly—concession below).

7. **Page 1 experiment-heavy.** Agree. Shared page 1 should sell the operator product; protocol detail belongs in page 2 / notes.

8. **Isolation language.** “External networking blocked” is the right idea. Pair with **offline functional completeness** (the suite finishes) and an inventory that UI/AI are inside the boundary. A failed curl is not sufficient.

### 2.4 Grok — corrections and concessions (own draft)

These are concessions. `grok_pages_1_2.md` is left unchanged; they bind the shared draft.

1. **Opening “The Navy does not lack PNT sources.”** Overstates a universal condition. Codex is right. Shared: operators face a **growing number** of sources; any given case may lack a particular family. Do not imply every listed alternate is present.

2. **K1 fail “admitted source outside 1–10 Hz.”** Misreads a **capability envelope** as a prohibition. Shared: demonstrate 3–8 concurrent sources at 1–10 Hz. Extra capacity or safely handled off-envelope inputs are not automatic fails. Testing one 10-minute nominal run does **not** establish the envelope—concession that Grok’s K1 method was too thin.

3. **24 scored + 4 holdout is too thin for final gates.** Agree. Development runs must not be the scored gate. Score **frozen holdouts only**. Grok’s N≥24 mixed the two.

4. **K6 “independent evidence was in the inputs” is underspecified.** Presence of a second family ≠ identifiable fault/jam/spoof. Stale, low-accuracy, mixed-cause, and missing-metadata cases still fail a naive confusion matrix. Shared: freeze an **observation model** (what is visible, age, declared accuracy, dependency tags) and score labels only when that model says the class is identifiable. Otherwise the required output is INDETERMINATE.

5. **K4 “unauthorized egress.”** Codex is right: “unauthorized” permits authorized remote dependencies. Shared: **zero external communication** plus offline completeness. Declare the internal network. No phone-home, no model API, no map tiles, no “approved” cloud.

6. **Iron Bank “Phase II path.”** Over-certain. Q&A did not settle Phase I Iron Bank. Shared: unresolved; do not require the image; do not claim a waiver.

7. **K2 denominator.** After dropping p95, Grok still tied zero-miss to “labeled onsets, start N≥24.” That is too few for a soak and the wrong single unit. Shared latency sample = onsets **and** envelope soak, hardening enabled, paint verified.

8. **K8 anti-abstention on nominal only.** Recoverable false-abstention belongs with Codex “useful decisiveness” / Claude K4(b), not only Grok K8.

9. **K9 “baseline.”** Must say **surrogate**, not fleet. No invented timings (Grok did not invent timings—keep that discipline).

10. **Missing from Grok table, adopt from peers:** observation-equivalent pairs (Codex); paint-vs-queue (Claude Rev 2 / Codex); negative security tests and scanner/DB dates (Codex review); hot-path exclusion of retrieval/LLM (Antigravity architecture, Q&A).

11. **Page 1 length.** Still long for a 10-page Volume 2. Shared page 1 should cut JADC2/NIST/DHS to one sentence if space requires; keep MARAD+NAVCEN as the currency evidence.

---

## 3. Positions on the four mandated issues

| Issue | Grok position for the shared draft |
|---|---|
| **Strict sub-second** | **S** bound is ingest → **presented** alert **and** initial informational COA < 1.0 s. **P** (user): **any event ≥ 1.0 s fails; any drop fails.** Percentiles are reported, never a miss allowance. Hardening on. Retrieval/LLM off the hot path. Q&A did not forbid percentiles; the user/offeror gate does. |
| **Secured air-gap** | **S**: entire stack including UI, analytics, any AI, 100% local, no remote DC/shore/cloud. **P**: zero external packets + offline suite completion + frozen control checklist (least privilege, access control, pinned/scanned deps, protected data/config, audit) with negative tests. **Not** CMMC, ATO, 800-171 assessment, or Iron Bank approval. |
| **No guaranteed detection without observable evidence** | Reject Antigravity 100% coherent-spoof and any unconditioned “missed any spoof instance.” Diagnosis is licensed only by the frozen observation model. Hidden ground truth must not leak (observation-equivalent pairs). |
| **No invented baseline; no human-research exemption** | No 30–180 s, 60 s, 50% faster, SUS 80. Fragmented **surrogate**, identical inputs, descriptive comparison only. Q&A 9/1 ≠ IRB exemption. No timed SME trials, surveys, NASA-TLX, SAGAT in Phase I. |

---

## 4. Concrete shared KPP recommendations

Propose these **gates** for the synthesis. All are Phase I demonstration gates on synthetic data. None is a Government acceptance threshold except where the bound is quoted from Q&A (**S**).

### G0 — Source envelope (**S** capability)
Demonstrate concurrent operation at 3, 4, 6, and 8 sources and at 1, 5, and 10 Hz, plus one mixed-rate point. Preserve source identity, timestamps, and provided health/confidence, or display their absence. **Fail:** cannot run a declared envelope point; silent field loss on the scored suite. **Not a fail:** additional unused capacity.

### G1 — Hard sub-second (**S** bound, **P** zero-miss)
- Clock: monotonic, non-GPS.  
- Start: bus-ingress receive.  
- End: alert banner **and** initial informational COA **frame presented** (capture/paint, not queue).  
- **Fail:** any measured event ≥ 1.0 s; any dropped event.  
- Report every event, max, p50/p95/p99 (diagnostic).  
- Sample: all injected onsets in frozen holdout **and** a declared 8×10 Hz soak with bursts; warm vs cold start reported.  
- Hardening from G3 **enabled**. Hot path has no retrieval, embedding, or LLM.  
- **Reject:** p95/p99.9 as pass; N=10,000 quiet epochs as the sole sample.

### G2 — Full-stack air-gap (**S**)
Zero external communication; UI, analytics, and any inference inside the boundary; holdout suite completes offline. Internal compose network declared. **Fail:** any outbound attempt; any remote call; suite cannot finish offline. A curl probe alone is insufficient.

### G3 — Secured runtime (**P** user firm; not accreditation)
Freeze threat model + checklist before test. Mandatory: non-root; least privilege / dropped caps; no inbound SSH; authenticated role-limited access; pinned hash-verified offline packages + SBOM; vulnerability scan with disposition **and scanner/database dates**; protected data, keys, configuration; audit of access/config that persists across restart. Negative tests: unauthorized access denied; tampered package rejected. **Fail:** missing mandatory control; unresolved critical/high without written disposition; claiming CMMC/ATO/Iron Bank as achieved. Iron Bank-in-Phase-I remains **unresolved**.

### G4 — Source + composite visibility (**S**)
Per-source state never collapsed. Composite separately displayed and linked to input IDs + rule/config version. Unavailable metadata stays unavailable.

### G5 — Observable-evidence triage (**P** scoring of **S** capability)
- Recoverable holdout: observation model says discriminating evidence **is** in the inputs. Score **per class** {fault, jam, spoof}.  
- **Critical-case oracles** (each independently fatal): e.g. coherent-bias with a fresh distinct-family source present → must not output Assured/Nominal/CONTINUE-as-healthy; same bias with that source absent or stale → INDETERMINATE + “cross-family verification unavailable”; a confident diagnosis there **fails**.  
- **Reject:** 100% unconditioned detection; “≥90% overall accuracy.”

### G6 — Appropriate uncertainty and anti-abstention (**P**)
- Unresolved: zero unsupported definitive diagnoses or prerequisite-violating recommendations; name missing discriminating evidence or that none is accessible. One violation fails the stratum.  
- Nominal: no alert storm; no blanket INDETERMINATE.  
- Recoverable: no false abstention when the observation model licenses a class.  
- Observation-equivalent pairs: identical visible inputs → identical analytical state/recommendation IDs (timestamps excluded). Mismatch = truth leakage = fail.

### G7 — Informational COA only (**S**)
No actuation, auto-route, or ship control. **Fail:** any control output.

### G8 — Comparison, not a fake fleet baseline (**P**)
Fragmented-display **surrogate** + prototype on **identical** inputs. Optional third arm: same UI with explanations disabled. Report paired outcomes **descriptively**. **Fail:** incomparable inputs; any invented legacy time or “X% faster / SUS 80.” Workflow proxies (views, KLM steps) only with evidence-completeness + legibility; never as operator-effectiveness.

### G9 — ECDIS familiarity (**S** as UX target)
Annex: each element ECDIS/BAM-like **or** offeror-added. **Fail:** claiming S-52/S-57/BAM certification; participant timing/surveys.

### G10 — Audit / short replay (**S** highly desirable)
Condition → source data → recommendation → any operator action; replay reproduces analytical sequence. **Fail:** broken chain on a scored run.

### Holdout sizing (recommendation, not a reliability sample)

| Stratum | Floor for freeze | Notes |
|---|---|---|
| Nominal | ≥ 20 | Anti-abstention / no alert storm |
| Recoverable | ≥ 10 fault + ≥ 10 jam + ≥ 10 spoof | Evidence licensed by observation model |
| Unresolved / no-win | ≥ 10 | Zero unsupported definitive claims |
| Progressive degradation | ≥ 10 | May overlap other strata; declare overlap |
| Observation-equivalent pairs | ≥ 4 pairs | Coverage items, **not** independent statistical draws |

Development cases are separate and **unscored**. Publish hashes of holdout + observation model + rule version **before** tuning. Print counts and all failures. If 18/20 is kept as a **demonstrator floor** on nominal and on recoverable **separately**, it does not waive G5 critical oracles or G6 unresolved zero-violation.

**Do not use:** 60 as a magic powered N; 90% accuracy prose; 100% spoof detection without evidence; 9/12 view-change benefit; 10,000-epoch-only latency; 24+4 as the final gate; participant SUS/TLX; invented 30–180 s baselines.

---

## 5. Shared page-1 substance (for the synthesizer; not a rewrite of Grok’s file)

Keep: ETV / GPNTS / fragmentation as stated in the topic; no new sensors or ship control; informational COAs; ECDIS familiarity not certification; CUI scope unresolved; synthetic ≠ public performance; Kobayashi Maru as **evaluation hypothesis**; product = console, sim = infrastructure; MARAD 2026-008 + NAVCEN (not commercial counts as Navy fact); decision under uncertainty including correlated agreement and insufficient evidence.

Drop from shared prose: invented timings; unconditioned 100% detection; ECDIS certification; company-name unless verified; long experiment protocol; JADC2/NIST as if they were GPNTS ICDs (one policy sentence is enough).

---

## 6. What Grok will accept vs reject in synthesis

**Accept if the synthesis includes:** any ≥1 s fails; full-stack air-gap with zero external comms; secured-runtime checklist without accreditation claim; observation-conditioned triage; no invented baseline; no human-research exemption; holdout/coverage honesty; product vs simulator.

**Reject if the synthesis includes:** percentile miss allowance; 90% accuracy as the story; 100% coherent-spoof without observable evidence; 30–180 s or SUS/TLX Phase I commitments; “unauthorized egress” as the air-gap test; CMMC/ATO achieved; Kobayashi Maru as a Navy requirement.

Ready for Codex synthesis. Original `grok_pages_1_2.md` unchanged.
