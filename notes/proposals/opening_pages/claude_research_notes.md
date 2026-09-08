# NP004 opening pages, research notes (agent: claude)

Prepared 2026-09-07 for `claude_pages_1_2.md`. Independent research; no other agent's draft was read before this was written. Evidence labels follow the filing outline: **Verified** = read in the cited repo file or live page on 2026-09-07; **not retrieved** = cited from a search snippet or secondary copy only.

---

## 1. Mapping of the user's two headings to the Navy Volume 2 template

The user headings are drafting labels. The controlling headings are the Open Topics Volume 2 template (`docs/F/F5_Navy_Volume_2_and_5_templates_2026-09-07.md`, lines 39–62). Do not change template headings in the filed document.

| User heading (this exercise) | Navy Volume 2 section | What the template asks for | How the draft maps |
|---|---|---|---|
| Page 1: Identification and Significance of the Problem / Operational Need | **1.0 Description of Proposed Phase I Technical Effort** (first half) | "demonstrate an understanding of the Navy requirement described in the topic and present the technical approach. Describe the innovation" | Paragraphs 1–4 of page 1 (operator problem, currency of need, decision-under-uncertainty framing, hypothesis) |
| same | **1.4 Defense Need** | "knowledge of prospective end-user(s)/customer(s) and their most reasonable use-case… differentiation from current customer alternatives… breadth of applicability" | ETV end user, GPNTS transition target and destroyer-strait use case, fragmented-display alternative, the [S8] GPNTS growth argument. Breadth of applicability is **not** in page 1 and must be added in 1.4 or 3.0 |
| Page 2: Phase I Technical Objectives & KPPs | **1.1 Phase I Technical Objectives** | "Enumerate the specific objectives… including the questions the research and development effort will try to answer to determine the feasibility" | O1–O5 each phrased as a feasibility question; the KPP table supplies acceptance evidence |

Note: the template has no "KPP" heading. KPP is a program-management term; in the filed volume, keep the table but title it "Feasibility measures" or fold it under 1.1. The layout plan (`notes/NP004_volume2_layout.md`) budgets pages 1–2 for 1.0 and page 3 for 1.1, so page 1 here maps to 1.0 and page 2 to 1.1; the 1.4 material would be a short cross-reference at page 7.

Evaluation criteria that these pages must satisfy (Navy v2 p. 5; CSO preface §4.2): technical merit most important, then key-personnel qualifications and commercialization potential of equal importance; "soundness, technical merit, and innovation of the proposed approach and its incremental progress toward topic… solution". Proposals are not compared to one another. (Verified: `docs/F/F1_NAVY_SBIR_26BX_R5_v2_2026-09-07.md` lines 220–225; `docs/F/F4_DOW_CSO_R5_PREFACE_2026-09-07.md` lines 1128–1144.)

---

## 2. Sources

### Controlling solicitation documents (Verified, repo)

- **[S1] Topic DON26BX05-NP004 and Q&A.** `docs/F/F2_DON26BX05-NP004_topic_2026-09-07.md` (navysbir.com mirror, self-labelled unofficial; DSIP controlling copy not retrieved). URL: https://www.navysbir.com/n26_5/DON26BX05-NP004.htm. Clauses used:
  - Description: "This fragmented environment increases cognitive workload, complicates training, and slows decision-making" (line 35); "does not seek development of new PNT or APNT sensing technologies, navigation algorithms, timing sources, or hardware systems" (line 43).
  - Q&A 7/1/26: Phase I "limited to presenting informational decision aids" (line 345).
  - Q&A 8/8/26: intended user ETV; "Operators currently monitor several fragmented displays" (line 363); single destroyer-strait use case preferred (line 367); "low to medium fidelity software demonstration running on representative simulated data" (line 369); containerized PoC "highly encouraged", Iron Bank referenced (line 373); metrics "speed to decision, accuracy of the operator's understanding of the degradation, decision accuracy and transfer of training" (line 365).
  - Q&A 8/19/26: auditable decision trace "highly desirable" (line 337); Phase I analysis limited to APNT-source data (line 341).
  - Q&A 8/20/26: rationale, composite confidence, evidence expected, "minimum subset of information initially presented" (line 321); "must run entirely locally and 100% air-gapped" (line 323); "3 to 8 simultaneous PNT sources updating at 1 Hz to 10 Hz" (line 325); "sub-second end-to-end processing and rendering latency" (line 327); baseline "the current environment of monitoring multiple fragmented physical displays"; scenario "Destroyer… GPS-degraded or spoofed strait" (line 329); ECDIS conventions for transfer of training (line 331); short-term replay desirable (line 333).
  - Q&A 8/21/26: "expected to do both" (visualize source-level and derive composite) (line 291); triage fault/jamming/spoofing and fallback decisions (line 293).
  - Q&A 8/25/26: rules acceptable, advanced methods encouraged "provided they are explainable and can run in the constrained edge environment" (line 243); sub-second applies "from data ingestion to the presentation of alerts and initial recommended courses of action" (line 245); progressive disclosure (line 247); Phase I may use "representative, unclassified, simulated, or synthetic data" (line 271); "no reliance on connectivity" (line 273).
  - Q&A 8/26/26: performers may define representative rules/TTPs; GFI and SMEs post-award (line 205); GPNTS primary integration target; no shore-side interface (line 209).
  - Q&A 8/28/26: "All NP004 Phase I data and activity is controlled unclassified information… vendors may use synthetic data that adheres to open-source standards (ASPN/pntOS)" (line 183); ECDIS similarity "is a UX familiarity target" (line 191).
  - Q&A 8/31/26: adapted commercial data-integration/decision-support platform "is responsive" (line 179).
  - Q&A 9/1/26: "the Government does not expect any human research to be performed under this SBIR" (line 175); no facility clearance expected for Phase II (line 171).
- **[S2] Navy Phase I Open Topics instructions v2** (`docs/F/F1_NAVY_SBIR_26BX_R5_v2_2026-09-07.md`): 10-page limit, 10-point minimum, base exactly 6 months ≤ $200,000, option exactly 6 months ≤ $115,000 (lines 121–137); evaluation order (lines 220–225).
- **[S3] DoW SBIR/STTR CSO Release 5 preface** (`docs/F/F4_DOW_CSO_R5_PREFACE_2026-09-07.md`): §4.2 criteria (lines 1128–1144); "human use" protocol criteria (lines 1910–1915).
- **[S4] Volume 2 Open Topic template** (`docs/F/F5_...`, lines 39–87): section headings quoted in §1 above.

### Topic-cited references (Verified, repo)

- **[S5] OPNAVINST 9420.1C, Positioning, Navigation and Timing Policy, 30 Sep 2019.** `docs/F/F3_OPNAVINST_9420.1C_PNT.md`, PDF p. 5, ¶5a(11): "New PNT systems in procurement should have the ability to indicate degradation of service to the operator due to interference (i.e., jamming, multipath, weather, terrain, or spoofing)…". Also ¶5a(9) resilience and system integrity (p. 5) and ¶5e(2) NAVWAR definition of contested/congested environments (p. 9). Original URL as listed in the topic references.
- **[S6] GAO-21-320SP, Defense Navigation Capabilities, 2021.** `docs/F/F3_GAO-21-320SP_Defense_Navigation.md`, highlights p. 3: DOD keeps GPS at the core; relative PNT "require another PNT technology to correct errors that can accumulate"; absolute PNT "rely on the availability of those external sources"; challenges in establishing clear PNT performance requirements. https://www.gao.gov/assets/720/714196.pdf
- **[S20] Summary of the JADC2 Strategy, March 2022.** `docs/F/F3_JADC2_Strategy_Summary.md`, p. 4 (sense, make sense, act; "degraded and contested electromagnetic spectrum environments") and p. 10 ("operate with minimum guidance within a degraded or contested C2 environment… where adversary intentions are ambiguous").
- Topic reference 3 (IS4S, ION GNSS+ 2023, ASPN and pntOS) is paywalled; abstract only (`corpus/gaps.md`). Not cited in the pages.

### Current external sources (retrieved 2026-09-07 via WebFetch unless noted)

- **[S7] GAO-22-106010, GPS Alternatives: DOD Is Developing Navigation Systems but Is Not Measuring Overall Progress, 5 Aug 2022.** Verified at https://www.gao.gov/products/gao-22-106010: "the Navy had incomplete business cases for its four alternative PNT efforts"; the PNT Oversight Council "has no strategic objectives or metrics to measure progress on the alternative efforts"; threats listed as anti-satellite weapons, jamming, spoofing, cyber. Newer than the topic's 2021 GAO reference.
- **[S8] Department of the Navy, Exhibit P-40 Budget Line Item Justification, PB 2025, Other Procurement Navy (1810N) BA 02/BSA 7, Line Item 2657 "NAVSTAR GPS Receivers (Space)", dated March 2024, pp. 1–2.** Verified by reading the PDF at the mirror https://gemini-custom-report.s3.amazonaws.com/2025/PROC_NAVY_2657.pdf (official justification book copy not located on a .mil URL this session; treat the mirror as a secondary copy of an unclassified official exhibit). Quotes: "The GPS-based PNT Service (GPNTS) system is the primary PNT system for the Navy to ensure reliable PNT capability and interoperability insertion… in a denied environment"; "GPNTS is an Open Architecture (OA) development"; "GPNTS will host the US Space Force developed Military GPS User Equipment (MGUE) card… M-Code"; "provide a path for the integration of advanced navigation systems and sensors"; FY2025 procures "GPNTS Enhancements for M-GUE and NoGAPSS Upgrades… to include Military Code (M-Code) GPS User Equipment (MGUE) Upgrade Kits and Non-GPS Aided Positioning for Surface and Subsurface (NoGAPSS) Upgrade Kit"; "FY 2025 procurements for NAVWAR, GPNTS, and GPNTS Upgrade Kits will be installed in FY 2026." The PEO C4I PMW 170 tear sheet (2025) and program page returned HTTP 403 and were **not retrieved**; the search snippet ("Navy's lead platform for GPS M-Code integration") is not used in the pages.
- **[S9] Windward, "GPS Jamming Disrupts 1,100 Ships in the Middle East Gulf", 1 Mar 2026.** https://windward.ai/blog/gps-jamming-disrupts-1100-ships-in-the-middle-east-gulf/ Verified: "More than 1,100 vessels experienced GPS and AIS interference across the Middle East Gulf within 24 hours"; "at least 21 new AIS jamming clusters"; ships falsely positioned at Al Hamra airport and the Barakah Nuclear Power Plant. Method: AIS-derived analysis by a commercial firm, so this measures reported-position anomalies, not receiver-level GNSS state. Cite as an indicator of scale, not as a receiver-performance measurement.
- **[S10] France 24 (AFP), "Surge in GPS interference around Strait of Hormuz increases shipping risks", 6 Mar 2026.** https://www.france24.com/en/middle-east/20260306-surge-gps-interference-strait-hormuz-increases-shipping-risks Verified: repeats the Windward 1,100-vessel/24-hour figure; JMIC raised threat level to critical; tanker transits "90% lower than the preceding week" as of 4 March (Kpler). The 90 percent figure is a commercial-traffic effect of the whole conflict, not of GNSS interference alone; page 1 words it as a co-occurring effect. Consider dropping if challenged.
- **[S11] Inside GNSS, "GNSS Interference Complicates Navigation as Hormuz Shipping Disruption Deepens", 2 Mar 2026.** https://insidegnss.com/gnss-interference-complicates-navigation-as-hormuz-shipping-disruption-deepens/ Verified: spoofed positions displaced onto airports, inland Iran, a nuclear plant; mitigations "treat GNSS-based position as advisory rather than authoritative", alternative positioning sources, heightened radar and visual watchkeeping. This trade-press mitigation list mirrors the COA set in the build plan.
- **[S12] Joint IMO/ICAO/ITU statement on satellite navigation interference, 25 Mar 2025.** https://www.imo.org/en/mediacentre/pressbriefings/pages/joint-imo-icao-itu-statement-satellite-interference.aspx Verified: "grave concern"; five actions including strengthening resilience of RNSS-dependent systems, maintaining conventional navigation infrastructure for contingency, and interference reporting; IMO Secretary-General: interference "could cause collisions and grounding".
- **[S13] IMO MSC.1/Circ.1644, Deliberate Interference with the United States Global Positioning System (GPS) and Other GNSS, 18 Oct 2021.** Date and title verified from a secondary PDF copy hosted by RNT Foundation (search result); IMO docs portal copy **not retrieved**. Urges member states to minimise interference, issue warnings/advisories, and prevent unauthorised transmissions.
- **[S14] U.S. Maritime Advisory 2026-008, Global, U.S. Maritime Advisory Updates, Resources, and Contacts.** `docs/C/C8_MARAD_Advisory_2026-008.md` (Verified, repo). "GPS disruption affects maritime navigation in various parts of the world… Develop plans for responding to GPS disruptions… prior to getting underway"; report outages to NAVCEN. Expires 21 Oct 2026, so re-check before filing. Advisory 2026-004 (Persian Gulf/Hormuz Iranian attacks) returned HTTP 403 and was **not retrieved**.

### Standards and frameworks (Verified, repo)

- **[S15] IMO Resolution MSC.401(95), Performance standards for multi-system shipborne radionavigation receivers.** `docs/B/B8_MSC.401(95)_Multi-system_Radionav_Receivers.md`, PDF p. 6, ¶3.11 "An alert should be provided when such assessment cannot be determined"; ¶3.12 caution after 3 s (conventional vessels) if performance cannot be assessed; ¶3.13–3.14 output last valid fix "with the explicit indication of the state so that no ambiguity can exist". Also ¶1.9 footnote 4: multi-source integrity monitoring "is envisioned to be a cross-check between independent PVT sources".
- **[S16] IMO MSC.1/Circ.1575, Guidelines for shipborne PNT data processing.** `docs/B/B7_MSC.1-Circ.1575.md`, ¶34 resilience definition (p. 12) and ¶47 integrity levels None / Low (single-source plausibility) / Medium (cross-source consistency with uncorrelated errors) / High (protection level) (pp. 12–13). Basis for the composite-confidence ladder and for the "cross-family" argument.
- **[S17] IMO Resolution MSC.302(87), Bridge Alert Management.** `docs/B/B5_MSC.302(87)_Bridge_Alert_Management.md`, ¶1.4 (reduces cognitive load by minimizing information presented), §6 four priorities (emergency alarm, alarm, warning, caution), §7.3 alarm states. Basis for K7 alert conventions.
- **[S18] DHS Resilient PNT Conformance Framework v2.0.** `docs/C/C3_DHS_Resilient_PNT_Conformance_Framework_v2.0.md`, §5.2 (PDF p. 15): "detection of a problem is generally probabilistic… It may be necessary to choose a threshold that balances the false-positive and non-detection rates"; Level 2 (p. 15): "'untrustworthy' does not always mean the current solution is incorrect". Basis for the indeterminate class and the calibration KPP.
- **[S19] NIST IR 8323r1, Foundational PNT Profile, Jan 2023.** `docs/C/C2_NIST_IR_8323r1.md`: Detect (DE.AE Anomalies and Events), Respond and Recover "in a timely, effective, and resilient manner" (lines 298–300, 494–495). Used only as structure for the build plan; not cited on the pages.
- **[S21] EO 13905, 12 Feb 2020.** `docs/C/C1_EO_13905_Responsible_Use_of_PNT.md`: definitions of "responsible use" and "PNT profile". Not cited on the pages; available for 1.4 breadth-of-applicability.
- **[S22] UK MCA MGN 379 Amendment 1 (2024).** `docs/C/C9_MGN379_Amendment1_2024.md`, §4.5: "An ECDIS will only alarm when the position of the vessel fed to its system is in danger and has no way of monitoring the actual vessel position if this feed is incorrect"; §5.7.1 alarm fatigue. Civil guidance, used as corroboration for why an ECDIS-like display alone does not solve the problem. Not cited on the pages to save space; strong candidate for 1.4.
- **[S24] MIL-STD-1472H, Department of Defense Design Criteria Standard: Human Engineering, 15 Sep 2020.** Date from search results (everyspec listing); document **not in corpus** (category D gap in `PHASE1_BUILD_PLAN.md` §7). Not cited on the pages.

### Method references

- **[S23] Geifman, Y. and El-Yaniv, R., "Selective Classification for Deep Neural Networks", arXiv:1705.08500, 2017.** Verified abstract at https://arxiv.org/abs/1705.08500: selective classifiers "reject instances as needed, to grant the desired risk"; coverage = fraction of instances not rejected; selective risk = error on accepted instances. Basis for reporting K4 as a risk-coverage trade-off rather than a single accuracy number.
- **[S25] Card, S. K., Moran, T. P., and Newell, A., The Psychology of Human-Computer Interaction, 1983 (Keystroke-Level Model).** Standard reference, not fetched. Basis for the analytic interaction count in K7, chosen because it needs no human participants.

### Internal working documents

- **[S26] `PHASE1_BUILD_PLAN.md`** §0 thesis (the glass is the deliverable), §2 contracts (assurance levels, anomaly-state key, COA set CONTINUE / CROSS-CHECK-VERIFY / SELECT-ALTERNATE-SOURCE / CONFIRM-INS-ONLY / INITIATE-DEGRADED-OPS / SERVICE-ADVISORY), §3 latency law, §4 coherent regional bias case, §8 graded metrics. Internal, not citable in the filed proposal; its claims (for example lume Hit@10 91.7%) are unverified repo statements and are **not** used on the pages.
- **`notes/NP004_filing_outline_2026-09-07.md`** and **`notes/NP004_volume2_layout.md`**: page budget and evidence-label conventions followed here.

---

## 3. Assumptions made in the draft (each must be confirmed or replaced)

| # | Assumption | Where used | Status |
|---|---|---|---|
| A1 | "[Company]" owns a commercially derived data-integration/decision-support platform that is being adapted (Q&A 8/31 makes this responsive) | Page 1 ¶4 | **Unverified.** The repo shows research/design assets, not a fielded product. The layout plan flags the same issue. If the platform claim cannot be supported, reword to "proposes to develop". |
| A2 | The ETV workstation is the sole target user and the Q&A description of the station (manned during navigation issues or contested transits) is current | Page 1 ¶1 | From Q&A 8/8 only; confirm with Government SMEs post-award. |
| A3 | Coherent regional bias (two receivers agree, both wrong) is representative of real spoofing in straits | Page 1 ¶3 | Consistent with [S9]–[S11] reporting of displaced positions across many ships, but the mechanism on a given Navy receiver pair is an inference. Keep as scenario design rationale. |
| A4 | A software "fragmented emulation" (per-source panels, no composite, scripted follow-first-alarm policy) is an acceptable Phase I stand-in for the Government's stated baseline of multiple fragmented physical displays | K3, K4 baseline column | **Unverified assumption**, labelled UA in the table. Raise with the TPOC post-award; do not present the emulation as the fleet baseline. |
| A5 | Harness measurement with a scripted decision policy plus SME design walkthroughs is not "human research" under DoDI 3216.02 | O4, K7, "will not claim" paragraph | Inference from CSO preface human-use criteria (interaction "that would not be occurring… but for this research") and the 9/1 Q&A. **Needs Government clarification**; the filing outline already lists a DSIP question on this. |
| A6 | Iron Bank base image is not required in the Phase I demo; a rebasing plan suffices | K6 | The 8/28 Iron Bank question was answered only with synthetic-data guidance. Unresolved. |
| A7 | 8 sources × 10 Hz = 80 msg/s is the worst-case load and 60 minutes is a sufficient soak | K1, K2 | Envelope is source-stated; the multiplication and soak length are ours. |
| A8 | Phase I CUI handling can be scoped so that a pre-existing public repo and synthetic demo are not themselves CUI | Page 1 ¶5 | The 8/28 answer says all Phase I data/activity is CUI; scope must be confirmed. The pages say "handling scope will be confirmed at kickoff". |
| A9 | Recommended informational COAs match the Q&A's named fallback decisions (select alternate source, confirm INS-only, initiate degraded operations) | O4, K7 | Source-stated set plus offeror additions (cross-check-verify, service-advisory). Representative rules per Q&A 8/26; authoritative TTPs are GFI post-award. |

---

## 4. KPP rationale

Design rules applied: every KPP names its basis (SR / PT / UA), a measurement boundary, a denominator or a plan to fix it, a baseline or an explicit "none", a test method, and a fail criterion. No measured improvement is asserted anywhere.

- **K1 Ingest fidelity.** The Q&A requires faithful visualization of source-level confidence and health (8/21, 8/25). The only honest baseline is the emitted stream itself, so the KPP is self-referential by design. The 288,000-message denominator is 80 msg/s × 3,600 s. Risk: SignalK-origin inputs cannot carry integrity fields (build plan §2.1); such sources are tagged integrity-unavailable and the KPP applies to fields the source actually emitted.
- **K2 Hot-path latency.** "Sub-second" is source-stated but not numerically defined beyond the ingestion-to-initial-COA boundary (Q&A 8/25 item 4). We propose p95 ≤ 500 ms as the target and p99.9 ≤ 1,000 ms as the fail line so that a single one-second miss on a tail epoch fails the KPP, which is stricter than a mean. Clock: monotonic, non-GPS, per build plan §2.6. The ≥1,000 anomaly onsets figure is a plan, set by the scenario library size at Stage 0.
- **K3 Triage correctness.** Recall floors: 0.80 fail / 0.90 target per class, chosen so that a 95 percent Wilson interval on 35 held-out cases (half-width ≈ 0.10 at p = 0.9) can distinguish the target from the fail line; ≈140 cases per class would tighten this to ±0.05. The held-out fraction (≥30 percent) and N are frozen and published before any threshold tuning to prevent leakage. The coherent-bias fail rule (miss in any held-out instance) is deliberately absolute because that case is the design's load-bearing claim. The baseline row exists to show the deficiency of per-source alarms, not to claim a fair head-to-head against the fleet's physical displays (A4).
- **K4 Uncertainty behavior.** This operationalises the user's "Kobayashi Maru" concept. Case classes: **no-win** (the evidence window cannot resolve fault/jam/spoof, for example coherent bias with the only independent family unavailable), **recoverable** (an independent family or a later epoch resolves it), **nominal** (no anomaly; guards against rewarding abstention). Measures: (a) inappropriate-commitment rate penalises forcing a single confident COA on no-win cases; (b) false-abstention rate penalises permanent abstention; (c) resolving-evidence hit rate tests whether the "verify" recommendation names evidence that actually resolves the case when the scenario supplies it; (d) expected calibration error checks that composite confidence tracks ground-truth correctness. Reporting as a risk-coverage curve [S23] shows the trade-off rather than a single tuned point. Thresholds (≤ 0.05 target / > 0.10 fail; ECE ≤ 0.10 / > 0.15) are our proposals with no Government acceptance basis. Ground truth is written by the Arena generator and never enters the system input stream (build plan §2.5).
- **K5 Explainability and audit.** Source-stated expectations (Q&A 8/19, 8/20). Replay-diff (identical triage sequence from the trace) is the determinism test; it also guards the latency law by proving no LLM sits in the decision path.
- **K6 Air-gapped runtime.** Source-stated (Q&A 8/20, 8/25). Zero-egress is observable from the host firewall log; the disconnected two-stage build is from build plan §5-W5. Iron Bank status is A6.
- **K7 Familiar UX proxy.** ECDIS similarity is a UX familiarity target, not a certification (Q&A 8/28). The conformance annex makes the claim auditable element by element. The KLM-style interaction count is an analytic, participant-free proxy for transfer of training; the "≤ 3 interactions to reach deciding evidence" bound is ours and should be reviewed by an HCD practitioner. Participant instruments (NASA-TLX, SUS, SAGAT) are deferred to Phase II and not named on the pages.

Dropped candidates: an "operator speed-to-decision" KPP (requires participants); a "false-alarm rate per hour" KPP (subsumed by K3 precision and K4(b)); a "Hit@10 retrieval" KPP (internal benchmark, unverified, and retrieval is drill-down only).

---

## 5. Uncertainty and unresolved issues

1. **Human-research boundary.** The 9/1 answer says no human research is expected; the template says Phase I proposals requiring human subjects will not be accepted; Navy v2 describes a conditional process. The pages therefore contain no participant study. Whether SME walkthroughs with Government-provided SMEs are permissible design review must be confirmed (DSIP question already drafted in the filing outline; Q&A closes 9 Sep noon ET).
2. **CUI scope.** All Phase I data/activity is CUI per 8/28, yet synthetic open-standard data are allowed. The pages avoid claiming public releasability of results. Handling environment and CMMC L2 self-assessment (NIST SP 800-171 Rev 2, per filing outline) are award-time obligations, not addressed on these pages.
3. **Iron Bank in Phase I.** Unresolved (A6).
4. **Baseline validity.** A software emulation of fragmented displays is not the fleet baseline (A4). Any comparative statement must say "against a fragmented-display emulation".
5. **Company/platform claim.** A1 must be settled before the opening sentence of page 1 ¶4 is used.
6. **Page-1 length.** The draft runs long (see word count in the terminal report). Cut candidates, in order: the GAO-22-106010 clause in ¶2; the 90 percent transit figure in ¶2 (a whole-conflict effect, not attributable to interference alone); the JADC2 sentence in ¶3; the EO/MGN material is already excluded.
7. **Secondary copies.** [S8] and [S13] were verified from mirrors, not primary .mil/.imo URLs; [S14] 2026-004 and the PEO C4I pages returned 403. Before filing, obtain primary copies or cite the primary URL with the mirror as access note.
8. **Terminology.** "ETV" is the Q&A's abbreviation for electronics technician (navigation); "ET/ETSW" appears elsewhere in the Q&A. Use one form consistently in the filed volume.
9. **Kobayashi Maru label.** Useful shorthand internally; in the filed volume consider "no-win evaluation cases" so reviewers do not read it as a gimmick. The concept must stay framed as the offeror's hypothesis and evaluation design, never as a Navy requirement.

---

## 6. Retrieval log

- 2026-09-07: repo files read: README.md, PHASE1_BUILD_PLAN.md, notes/NP004_filing_outline_2026-09-07.md, notes/NP004_volume2_layout.md, docs/F/F1, F2 (09-07), F3 (GAO, OPNAVINST, JADC2), F4 (§4.2, §2.10, Appendix B human-use), F5, docs/B/B5, B7, B8, B9, docs/C/C1, C2, C3, C6, C8 (both), C9, corpus/gaps.md.
- 2026-09-07: web verified: GAO-22-106010 product page; Windward blog (1 Mar 2026); France 24 (6 Mar 2026); Inside GNSS (2 Mar 2026); IMO joint statement (25 Mar 2025); arXiv 1705.08500 abstract; Navy P-40 LI 2657 PDF (mirror) pp. 1–3.
- 2026-09-07: not retrieved (HTTP 403): MARAD Advisory 2026-004; PEO C4I PMW 170 tear sheet and program page; CNBC 26 Mar 2026 article. Search-snippet only: MSC.1/Circ.1644 date (RNTF copy), MIL-STD-1472H date.
- No DSIP login, no external messages, no submissions.

---

## 7. Revision 2 additions (2026-09-07, after user clarification and peer reading)

### New and re-verified sources

- **[S27] USCG NAVCEN, GPS Problem Report Status.** https://www.navcen.uscg.gov/gps-problem-report-status Verified 2026-09-07 (via WebFetch). Marine entries June–August 2026: 14 Jun Red Sea GPS jamming; 18 Jun Red Sea spoofing "with indicated position far from actual location"; 29 Jun SE of Sweden GPS failure off Olands Sodre Grund TSS; 2, 7, 20 Jul Fujairah anchorage disruptions ("multiple vessels affected" on 7 Jul); 14 Aug Baltic Sea interference; plus 3 Aug Savannah GA and 10 Aug Los Angeles CA. Each closed with "no known anomalies that might affect GPS signal integrity". Page shows no last-updated date. First surfaced by the Grok draft; the phrase "all the vessels" quoted there was not visible in the fetched summary, which reads "multiple vessels affected". Government-sourced; preferred over commercial AIS-derived counts for page 1.
- **[S5] OPNAVINST 9420.1C ¶5a(3), PDF p. 4** (re-verified): "Every platform and user with a validated PNT requirement must have both a DoD approved primary means of position and precise time determination and at least one DoD approved alternate means which determines position and precise time from a source independent of the primary PNT source (i.e., GPS-independent)." First cited by the Grok draft; adopted in Revision 2 page 1.
- **[S18] DHS Resilient PNT Conformance Framework v2.0 §5.5 Common Mode (PDF p. 11)** (re-verified): "resilience behavior that relies on source diversity assumes that the sources are resilient to common mode threats"; Level 4 requirement 8 "diversity of PNT source technology to mitigate common mode threats". Used in Revision 2 page 1 in place of the non-RF framing.

### Peer-citation checks performed for the review

- Antigravity cites "NIST IR 8323r1 p.18; DHS PNT CF v2.0 §3.2" for coherent regional bias capture and "NIST IR 8323r1 p.22" for cross-family comparison. Grep of `docs/C/C2_NIST_IR_8323r1.md` pages 18–23 finds no coherent/capture/cross-family text; DHS CF has no §3.2 on this subject (common mode is §5.5). Antigravity cites "GAO-21-320SP p.12" for a source list including "optical tracking"; page 12 of the corpus rendering contains no such list. "MIL-STD-1472H §5.2" and "OPNAVINST 9420.1C Encl 2" not verifiable from the corpus. These are flagged in `claude_review.md`, not asserted as errors in the standards themselves.

### Changes to my own draft (recorded in `claude_pages_1_2.md` Revision 2)

- K2: percentile allowance removed; any single ≥ 1,000 ms event or any drop fails; boundary redefined to frame-presented; sweep and soak specified.
- K6: converted to an air-gapped secured-runtime gate with a frozen checklist and negative tests; no accreditation claims.
- K3: coherent-bias detection conditioned on an observable independent source under a frozen observation model; INDETERMINATE required otherwise; surrogate baseline labelled synthetic and descriptive only; held-out fraction raised to ≥ 50%.
- K7: SME activity described as design review pending Government determination; the earlier "(non-research)" assertion withdrawn.
- Page 1: trimmed; 90 percent transit figure dropped (whole-conflict effect); NAVCEN reports and ¶5a(3) added; "[Company]" replaced by DeepBlue Dynamics per the Codex draft, with A1 still open.
- Word counts (bash `wc -w`, heading line and bracketed source markers included): original page 1 = 765; Revision 2 page 1 = 585 after two trims (about 560 words of prose once markers and the heading are excluded). The shared synthesis v1 measures 493 (page 1) and 549 (page 2 including table) by the same method.
