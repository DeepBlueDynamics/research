# Claude peer review of the four NP004 opening-page drafts

Date: 2026-09-07. Inputs read: `antigravity_pages_1_2.md`, `codex_pages_1_2.md`, `grok_pages_1_2.md`, `claude_pages_1_2.md` (own), `codex_review.md`, `codex_research_notes.md`, updated `ASSIGNMENT.md`. No other research-notes files were present for Antigravity or Grok at review time (`antigravity_research_notes.md` exists but was not needed for the points below; `grok_research_notes.md` was not in the directory).

Verification performed for this review (2026-09-07): OPNAVINST 9420.1C ¶5a(3) text (corpus, PDF p. 4); NAVCEN GPS Problem Report Status page (live); DHS Conformance Framework v2.0 §5.5 (corpus); NIST IR 8323r1 pages 18–23 and GAO-21-320SP page 12 (corpus, for the Antigravity citations). Numbers below are Wilson 95 percent intervals computed by hand; they are approximate.

The user's firm constraints govern every recommendation here: entire stack local and air-gapped including inference and UI; an explicit secured-runtime gate with no accreditation claim; strictly under one second from ingress to rendered alert and initial COA, with no percentile allowance.

---

## 1. Strongest point in each draft (keep these)

**Antigravity.** The most complete secured-runtime articulation: NIST SP 800-190 controls named (unprivileged execution, read-only root filesystem, dropped capabilities, no remote daemons) plus a pre-execution gate (SBOM, vulnerability scan, egress check, Iron Bank readiness) while explicitly disclaiming ATO and CMMC. It also states plainly that local vector search and local LLM rationale run inside the air gap, which matches the user's clarification that inference and UI belong inside the boundary. Its KPP-2 already carries "zero percentile miss allowance".

**Codex.** The observational-indistinguishability principle: two simulated worlds with identical visible inputs must not receive different diagnoses because the evaluator knows different truths. This is the cleanest statement of "no guaranteed detection without observable evidence" in any draft, and it yields a concrete truth-leakage test (observation-equivalent case pairs). Two supporting design choices follow from it and should be adopted: unavailable metadata stays unavailable rather than being inferred, and dependency metadata is treated as an assumption, not guaranteed GPNTS data. The three-arm comparison (fragmented surrogate, unified-only, full explanatory) is the only design that separates the value of aggregation from the value of explanation. Its secured-runtime row is the only one with negative tests (deny unauthorized access, reject modified packages).

**Grok.** Discipline: every KPP row is tagged S/P/A, nothing is pre-claimed as a percentage, and the "not claimed" list at the end is explicit. Two evidence finds that the shared draft should adopt, both verified by me today: OPNAVINST 9420.1C ¶5a(3) requires "at least one DoD approved alternate means… from a source independent of the primary PNT source (i.e., GPS-independent)", which is a stronger policy hook than ¶5a(11) alone; and the NAVCEN GPS Problem Report entries for June–August 2026 (Red Sea jamming and spoofing, Fujairah anchorage with multiple vessels, Baltic), each closed with no constellation anomaly, which is Government-sourced currency evidence rather than a commercial count.

**Claude (own).** Dated, verified external evidence for page 1 (Windward 1 Mar 2026; IMO/ICAO/ITU 25 Mar 2025; MSC.1/Circ.1644 2021; GAO-22-106010 2022; the Navy P-40 exhibit showing GPNTS fielding M-code and non-GPS-aided positioning kits with FY2026 installs), and explicit sample-size arithmetic tied to fail lines. The calibration and risk-coverage framing gives the uncertainty KPP a reporting form that does not collapse to one tuned number.

---

## 2. Specific counterarguments by draft

### Antigravity

1. **Invented baselines.** "Manual cross-check & diagnosis (30 to 180 seconds)", "Baseline task completion time: ~60 s", "High false-alarm rate; frequent misclassification of spoofing as fault", "1–2 independent GPS/INS displays; no unified bus". None has a source; the topic substantiates fragmentation, not timings or error rates. Remove, do not estimate (Codex made the same point; I concur).
2. **Guaranteed detection.** "100% detection of coherent GNSS regional bias" is a guarantee that cannot be honoured when no source with a distinct error dependency is present, or when it is stale or too coarse. Replace with the conditional rule in §4 below.
3. **Overall accuracy on N=100 Monte Carlo runs.** "≥ 90% accuracy overall" hides per-class behaviour (a system that never says spoof can still score 90 percent if spoof cases are a minority). Report per-class recall and precision on held-out cases; state how the 100 runs are stratified and which are held out.
4. **KPP-5 is human research by another name.** Timed task completion "from anomaly onset to SME decision confirmation", "≥ 50% reduction", "SUS score ≥ 80", "N=10 SME walkthrough sessions", and "No IRB required per Q&A 9/1/26". The 1 September answer says the Government does not expect human research; it is not a determination that a timed, surveyed session is exempt. Strike the row and the "no IRB" language.
5. **"ECDIS-Conformant UX/HMI" (Objective 3).** Contradicts the 28 August answer that ECDIS similarity is a familiarity target. Use "ECDIS-familiar".
6. **"Error-independent non-RF navigation sources (e.g., INS, eLoran, radar fixes, OCXO)".** eLoran and radar are RF. The correct concept is distinct error dependency (Codex's "dependency" framing; DHS CF §5.5 "common mode"), not modality.
7. **Egress test.** A `curl`/`ping` probe proves only that the probe failed. The gate should be the entire holdout suite completing with networking blocked at the host and zero outbound attempts in the host firewall log (Codex's isolation row plus my K6).
8. **"HMI alert render callback"** must be a frame-presented event, not work queued to a renderer.
9. **Citations that do not verify.** "NIST IR 8323r1 p.18" and "p.22" for coherent capture and cross-family comparison: pages 18–23 of the corpus rendering contain no such text. "DHS PNT CF v2.0 §3.2": common mode is §5.5. "GAO-21-320SP p.12" for a source list including "optical tracking": not on that page. "MIL-STD-1472H §5.2" and "OPNAVINST 9420.1C Encl 2": not verifiable from the corpus. Either re-cite to the right locations or drop.
10. **Length.** Both pages appear well over budget; the table alone is dense enough to be illegible at 10-point.

### Codex

1. **60-case holdout, 20 per stratum.** As an engineering budget this is reasonable, but the arithmetic should be stated so nobody reads it as evidence. An 18/20 gate observed at exactly 18/20 gives a 95 percent interval of roughly 0.70 to 0.97, so it cannot distinguish 90 percent performance from 75 percent. Zero violations in 20 unresolved cases leaves an upper 95 percent bound of about 16 percent on the violation rate. Recommendation: keep 20 as the floor per stratum, stratify recoverable cases by class (fault, jam, spoof, ≥ 10 each, so recoverable ≥ 30), add ≥ 10 progressive-degradation cases and observation-equivalent pairs, publish the interval next to every gate, and grow toward ≥ 35 per class if the base budget allows. Codex's own concession that the strata lack anomaly diversity is right; this fixes it.
2. **"90%" as 18/20.** Fine as a demonstrator gate; wrong as a headline. Never write "90 percent accuracy" in prose; write "18 of 20 held-out recoverable cases, interval 0.70–0.97".
3. **Workflow proxy: 12 tasks, 9 of 12 with fewer view changes than the surrogate.** Three objections. (a) 9/12 is arbitrary and the comparison is against an invented surrogate, so "fewer than the surrogate" is not a property of the prototype. (b) View-change counts reward crowding (Codex concedes). (c) It still reads as a workload claim. Recommendation: make the prototype-only criteria absolute (evidence completeness for every task; interaction count from alert to deciding evidence ≤ 3; a legibility and density checklist), and report the surrogate comparison as descriptive text with no gate attached.
4. **Third arm cost.** Agree with the concession: a feature-disabled build of the same interface, not a third product.
5. **Latency corners.** Four 30-minute corners miss intermediate loads and the long tail. Add a 60-minute soak at 8 × 10 Hz with bursts and a 4/6-source sweep at 5 Hz, report warm and cold start separately, and define "ingress" as the bus receive timestamp on the monotonic clock, distinct from simulated onset. Codex already concedes most of this; it should be in the shared table, not the notes.
6. **Page 1 has no currency or policy grounding beyond the topic.** Technical merit is judged from the volume alone (Navy v2: reviewers "will base their conclusions only on information contained in the proposal"). Add two or three sentences with dated Government sources (OPNAVINST ¶5a(3), NAVCEN 2026 reports, the P-40 GPNTS exhibit) so the need does not rest on the topic text alone. I accept the counter-risk Codex names (too much evaluator mechanics makes it read like a simulator proposal) and would cut mechanics before cutting evidence.
7. **"DeepBlue Dynamics proposes… adapt the repository's retrieval foundation and interface concepts."** Correct company name; I adopt it. The adaptation claim still depends on confirming what the company owns and its maturity (my assumption A1). The sentence "the repository does not establish an integrated, validated APNT capability" is the right hedge and should survive into the shared draft.

### Grok

1. **K2 is internally inconsistent.** The bound is "95th percentile over labeled onsets" but the failure is "any onset > 1.0 s". Under the user's constraint the bound must be the maximum, and the fail line is ≥ 1,000 ms, not > 1.0 s.
2. **Sample plan too small for any rate.** 24 scored runs plus 4 held-out, with 4 no-win cases: no rate can be reported from 4 cases, and a 4-case held-out set cannot detect tuning leakage. Adopt the merged plan in §4.
3. **K6 counts INDETERMINATE as a failure "when independent evidence was in the inputs".** Good anti-abstention rule, but "sufficient" must be defined in a frozen observation model (accuracy, age, dependency) before testing, or the evaluator decides it after the fact.
4. **No secured-runtime gate.** Written before the clarification; K4 air-gap is right but incomplete. Adopt the merged K6.
5. **NAVCEN quotation.** "All the vessels" was not visible in my fetch of the page; the 7 July Fujairah entry reads "multiple vessels affected". Keep the citation, soften the quote unless the exact text is captured.
6. **Length and density.** Page 1 is long and the standards paragraph reads like a bibliography; the S/P/A discipline is the part to keep.

### Claude (own): corrections and concessions

1. **K2 allowed p99.9 ≤ 1,000 ms.** That is a percentile allowance and is withdrawn. Revision 2: any single event ≥ 1,000 ms or any drop fails; p95 ≤ 500 ms is an internal design target only.
2. **No secured-runtime gate.** Added in Revision 2 (checklist frozen before test, negative tests, no accreditation claim).
3. **"Coherent-bias case missed in any held-out instance fails"** was a guaranteed-detection claim. Revision 2 conditions it on an observable independent source under the frozen observation model and requires INDETERMINATE otherwise (Codex's principle).
4. **"SME design walkthrough (non-research)"** asserted a status I cannot determine. Withdrawn; now "design review, scope pending Government determination; no timing, surveys, or participant measures".
5. **Fragmented "emulation" baseline.** I labelled it UA but still used it as a comparison arm. Now labelled a synthetic surrogate, descriptive only, no gate attached to the comparison.
6. **Page 1 length** was 765 words against a 550 ceiling; trimmed in Revision 2. The 90 percent tanker-transit figure was a whole-conflict effect, not attributable to interference, and is dropped.
7. **Evidence quality.** The Windward count is AIS-derived and commercial (Grok's point); Revision 2 leads with the NAVCEN Government reports and keeps Windward as a secondary indicator.
8. **"[Company]"** replaced with DeepBlue Dynamics, following Codex; the platform-adaptation claim remains an open assumption.

---

## 3. Positions on the four mandated cross-cutting points

**Strict sub-second (any ≥ 1 s fails).** All four drafts now agree in principle; Antigravity and Codex wrote it first. Shared wording: boundary is bus-ingress receive time (monotonic, non-GPS) to alert banner and initial COA card frame presented; every event reported with maximum, p50/p95/p99 and drops; any single event ≥ 1,000 ms or any dropped event fails the tested envelope; hardware, payload sizes, event rates, and warm/cold treatment declared. Detailed rationale and evidence are asynchronous per the 25 August answer and are excluded from the boundary.

**Secured air-gap gate.** Merge Antigravity's control list, Codex's negative tests, and the whole-suite-offline requirement. Local retrieval, inference, and UI are inside the boundary. Checklist frozen before testing: non-root, read-only root filesystem, dropped capabilities, no remote shells, least privilege between services, authenticated role-limited access, pinned hash-verified offline packages with SBOM, vulnerability scan with written disposition, protected stored data/keys/configuration, audit of access and configuration changes persisting across restart. Fail on any outbound attempt, any failed mandatory control, or any unresolved critical/high finding. State in one sentence that no ATO, CMMC, or Iron Bank accreditation is claimed and that Iron Bank rebasing is a documented path whose Phase I necessity is unresolved.

**No guaranteed detection without observable evidence.** Adopt Codex's indistinguishability principle as a design rule and a test. Rule: a diagnosis or COA may only cite evidence present in the inputs; unavailable metadata is displayed as unavailable; sources are not assumed independent by default. Tests: observation-equivalent case pairs must yield identical outputs; coherent-bias cases are scored as "must detect" only when an independent source with sufficient accuracy is in the inputs under the frozen observation model, and as "must report INDETERMINATE with cross-family verification unavailable" otherwise. Strike "100% detection" everywhere.

**No invented baseline or human-research exemption.** Strike every timing, error-rate, and display-count baseline (Antigravity KPP-2/3/5 baseline column; my emulation numbers had none, but the arm is now descriptive only). The fragmented-display surrogate is synthetic, is labelled so, and carries no gate. No timed sessions, no SUS/NASA-TLX/SAGAT, no "no IRB required" language anywhere in Phase I; SME involvement is design review whose scope is confirmed with the Government (the filing outline already holds the DSIP question, due before 9 September noon ET).

---

## 4. Concrete shared KPP recommendations

Proposed merged table for the synthesis. Basis codes: S = source-stated, P = offeror-proposed, A = assumption, F = firm user constraint.

| # | Parameter | Basis | Boundary and measure | Denominator / plan | Fail if |
|---|---|---|---|---|---|
| 1 | Hot-path latency | S, F | Bus-ingress receive time → alert + initial COA frame presented, monotonic clock, in container | Sweep 3/4/6/8 sources × 1/5/10 Hz; 60-min soak at 8 × 10 Hz with bursts; every event; warm/cold separate; hardware declared | Any event ≥ 1,000 ms or any drop |
| 2 | Air-gapped secured runtime | S, F, P (checklist) | Whole holdout suite completes with host networking blocked; zero outbound attempts logged; frozen control checklist; negative tests | 100% of images/services; entire demo | Any outbound attempt; any failed mandatory control; any unresolved critical/high finding; any accreditation claim |
| 3 | Evidence preservation | S | Every source-provided field displayed or shown absent; no silent inference; composite and COA linked to input IDs and rule version | All held-out cases; all messages in the soak | Any silent loss or unsupported link |
| 4 | Triage when evidence exists | S capability, P scoring | Per-class recall/precision on held-out recoverable cases; onset-to-correct-class time | ≥ 10 per class (fault, jam, spoof) at freeze, target ≥ 35; intervals published | Class recall < 0.80 (target 0.90); coherent-bias miss when an independent source is observable |
| 5 | Appropriate uncertainty | P (hypothesis) | On unresolved cases: no unsupported definitive diagnosis or prerequisite-violating COA; named missing evidence must be a valid discriminator under the observation model | ≥ 20 unresolved cases; count assertions and cases | One violation; interval reported |
| 6 | Useful decisiveness | P | On nominal and recoverable cases: recommendation within the predeclared acceptable set; no blanket abstention | ≥ 20 nominal; recoverable as in row 4 | Below 18/20 per stratum at floor; blanket abstention |
| 7 | Truth-leakage and determinism | P | Observation-equivalent pairs yield identical outputs; three repeats reproduce states and recommendation IDs | ≥ 10 pairs; all held-out runs × 3 | Any pair divergence; any unexplained mismatch |
| 8 | Explainability and audit | S | Every alert/COA carries drivers, thresholds, config version; hash-chained trace verifies; replay reproduces the triage sequence | 100% of runs | Any unverifiable or non-reproducible run |
| 9 | Familiar UX proxy | S target, P proxy | Familiarity annex (ECDIS/BAM convention or offeror-added) for every element; per-task evidence completeness; interaction count ≤ 3 to deciding evidence; density/legibility checklist | 100% of elements; ≥ 8 tasks balanced across conditions; surrogate comparison descriptive only | Any unmapped element; incomplete evidence; count > 3 |
| 10 | Informational-only COA | S | No actuation or action routing | Design inspection and runtime check | Any control output |

**Shared sample plan.** Freeze the library with a hash and date before tuning: ≥ 20 nominal, ≥ 30 recoverable (≥ 10 each fault/jam/spoof, including common-dependency, stale-input, and missing-metadata variants), ≥ 20 unresolved, ≥ 10 progressive-degradation, ≥ 10 observation-equivalent pairs. Cases are distinct configurations and seeds; variants of one seed are reported clustered. Hold out at least half; development cases are separate. Report every gate with its interval and every failure individually. This reconciles Codex's 60 (20/20/20) with class coverage at about 90 scored cases; if the base budget cannot carry that, cut progressive-degradation before cutting the per-class floors.

**Reporting rules.** No percentage improvement in prose; no Government acceptance thresholds; no operator-effectiveness measurement claimed; failed gates reported and used to bound Phase II claims (Codex's sentence, adopt verbatim).

---

## 5. What I expect to accept or reject in the synthesis

Accept if present: the merged latency and secured-runtime rows above; the indistinguishability rule and pair test; the surrogate labelled synthetic with no gate; the class-stratified sample plan with intervals; Grok's ¶5a(3) and NAVCEN evidence on page 1; DeepBlue Dynamics with the hedge sentence on repository maturity.

Reject if present: any percentile allowance; any timing or error-rate baseline without a source; "100% detection"; "ECDIS-conformant"; any SUS/NASA-TLX/timed-session commitment or "no IRB required"; any statement that synthetic performance implies public releasability; any CMMC, ATO, or Iron Bank status claim.
