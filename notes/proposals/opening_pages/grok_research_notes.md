# Grok research notes — NP004 opening pages (independent draft)

**Author:** Grok (this session).  
**Date:** 2026-09-07.  
**Companion:** `grok_pages_1_2.md`.  
**Constraint honored:** other agents’ drafts in this directory were not read for authorship. A filename listing showed other `*_pages_1_2.md` files exist; those bodies were not opened for this update.

**2026-09-07 user clarification (firm gates):** “has to be done air gapped, secured and be sub second.” ASSIGNMENT.md updated: entire stack including AI/UI local; explicit secured-runtime gate; no percentile allowance for ≥1 s initial-alert/COA events. Prior independent K2 p95 scoring is **withdrawn**.

Evidence labels used here: **Verified** = read in the cited file or live page this session; **Inferred** = reasoned from verified facts; **Unverified** = not checked, or company/account state unknown.

---

## 1. Mapping of user headings to Navy Volume 2

Controlling template (verified): `docs/F/F5_Navy_Volume_2_and_5_templates_2026-09-07.md`, extracted 2026-09-07 from `corpus/F/templates/DON_SBIR_Phase_I_OPEN_TOPICS_Technical_Volume_2_Template_2026-0304.docx`. Navy v2 instructions take precedence (`docs/F/F1_NAVY_SBIR_26BX_R5_v2_2026-09-07.md`, Version 2, downloaded 2026-09-07).

| User heading (this exercise) | Navy Open Topic Volume 2 heading | Notes |
|---|---|---|
| 1. Identification and Significance of the Problem / Operational Need | **1.0** Description of Proposed Phase I Technical Effort (problem/approach half) **and 1.4** Defense Need | Template 1.0: “demonstrate an understanding of the Navy requirement … present the technical approach.” Template 1.4: end-user, use-case, differentiation, breadth. Layout plan (`notes/NP004_volume2_layout.md`) budgets pages 1–2 for 1.0 and the second half of page 7 for 1.4. This exercise’s page 1 is **not** a substitute for 1.4’s transition-owner paragraph in the eventual 10-page PDF. |
| 2. Phase I Technical Objectives & KPPs | **1.1** Phase I Technical Objectives | Template 1.1: “enumerate the specific objectives … questions the R&D effort will try to answer to determine feasibility.” The official template does **not** require a KPP table. KPPs here are an offeror structure. Preferred Government metrics live in Q&A, not in a numbered KPP annex. |

Do not modify official template headings or `PHASE1_BUILD_PLAN.md` for this exercise (assignment).

Volume 2 constraints (verified, Navy v2 pp. 3–5 and template): ≤10 pages regardless of content; single column; single-spaced; US Letter; 1-inch margins; ≥10-point font; base and option both inside the 10 pages; base exactly 6 months / ≤$200,000; option exactly 6 months / ≤$115,000. Template allows smaller type in figures/tables; v2 states 10-point minimum without that exception — recommendation remains: keep table text ≥10-point in the filing PDF. These opening pages are markdown drafts; pagination is **not** verified.

---

## 2. Live source check (2026-09-07)

| Source | What was done | Result |
|---|---|---|
| https://www.navysbir.com/n26_5/DON26BX05-NP004.htm | `web_fetch` + `grub-crawler__crawl_url` via `http://host.docker.internal:6792` (local `grubcrawler:6792` failed to connect) | Topic text and Q&A match the 2026-09-07 repo capture. Newest visible answers **1 September 2026**. Page still self-labels as unofficial and points to DSIP. |
| https://www.navysbir.com/topics26_5.htm | `web_fetch` | Close **23 September 2026, 12:00pm ET**; Open Topics CSO instructions `NAVY_SBIR_26BX_R5_v2.pdf` dated 8/31/26. |
| https://www.navcen.uscg.gov/gps-problem-report-status | `web_fetch` | Live GUIDE tool. Disclaimer: reports do **not** validate constellation degradation. Marine closed reports used below. |
| DSIP controlling topic copy | Not retrieved (login) | Unverified against authenticated DSIP. |
| Company SAM/DSIP/SBC/CMMC SPRS | Not inspected | Unverified. |

Repo capture used as working text: `docs/F/F2_DON26BX05-NP004_topic_2026-09-07.md` and `corpus/F/F2_DON26BX05-NP004_topic_2026-09-07.md` (retrieved_date_utc 2026-09-07; latest_QA_date_visible 2026-09-01). August 26 capture retained for comparison; not used as current Q&A.

---

## 3. Source register (URLs, editions, clauses)

### 3.1 Topic and Q&A (controlling for this topic; unofficial mirror)

- **Topic page (unofficial Navy mirror):** https://www.navysbir.com/n26_5/DON26BX05-NP004.htm  
  Verified live 2026-09-07. Pre-release 8/5/26; opens 8/26/26; closes 9/23/26 12:00pm ET. NAVWAR. CMMC Level 2 (Self). CTA: Applied Artificial Intelligence. Component priorities: HMI; Integrated Network Systems-of-Systems; Integrated Sensing and Cyber.

- **Official DSIP solicitation documents:** https://www.dodsbirsttr.mil/submissions/solicitation-documents/active-solicitations  
  Not logged in this session.

**Topic clauses used (verified):**

- Objective: software-enabled capabilities that improve operator understanding of APNT status, confidence, threats, and recovery options across diverse systems/providers.
- Fragmented interfaces → workload, training, slower decisions.
- GPNTS + ASPN + pntOS named.
- COP / “single pane of glass” / decision-support allowed.
- **Does not** seek new PNT/APNT sensing, navigation algorithms, timing sources, or hardware. Seeks software architecture, data integration, information management, UX, HMI, analytics, visualization, decision-support.
- Containerization for on-prem isolated runtimes named.
- Commercial adaptation in-scope.
- Phase I: establish feasibility via use cases, integration approach, expected operator-effectiveness improvements, Navy-environment path; Final Report + Initial Phase II proposal.
- Phase I base deliverables: Kick-Off, Progress Report, Final Report, Initial Phase II Proposal.

**Q&A used (verified on live page; dates as posted, two-digit year 26):**

| Key | Date | Clause used |
|---|---|---|
| QA-701 | 7/1/26 | Phase I limited to **informational decision aids**. |
| QA-808 (scope) | 8/8/26 | Essential interface contents: health, nav confidence, threats/degradations, operational impacts, recommended recovery actions. Unify multiple systems, do not replace one legacy system. Metrics: speed to decision, accuracy of degradation understanding, decision accuracy, transfer of training. **Deep focus on one shipboard use case** (e.g. Destroyer GPS-degraded-strait). End of Phase I: design concepts + feasibility evidence + **low-to-medium fidelity** demo on simulated data. Platform-independent modular architecture sufficient. Containerized isolated PoC **highly encouraged**; Iron Bank referenced. ETV user; ECDIS-type familiarity to reduce training. Phase I may use unclassified simulated/synthetic data. |
| QA-808 (openness) | 8/8/26 | Multiple software approaches responsive if they deliver unified “single pane of glass.” Answer 2 on that cluster **repeats the question** (garbled). Primary problem: one cohesive workflow; translate status/confidence/degradation into impacts and actionable recovery options. |
| QA-819 | 8/19/26 | Auditable history highly desirable. Phase I analysis limited primarily to APNT-source data on a navigation display; larger mission-phase data not available to ingest. |
| QA-820 | 8/20/26 | Explainability with **minimum subset first**. **100% air-gapped**, all UI/analytics/AI local; no remote Navy DC, shore, or external cloud. 3–8 sources, 1–10 Hz. Sub-second end-to-end processing and rendering; alerts and recommended COAs near-real-time. Preferred metrics: speed to decision, threat comprehension accuracy, decision accuracy, reduced cognitive workload. Baseline = fragmented physical displays. Representative scenario = Destroyer GPS-degraded/spoofed strait. Either modular-into-existing-presentation **or** standalone companion; follow Navy ECDIS conventions for ET/ETSW transfer of training. Short-term replay highly desirable. |
| QA-821 | 8/21/26 | Visualize source-level confidence/health **and** derive composite. Mission-impact mapping desired but detail still under review; general Phase I approach sufficient. Accelerate anomaly triage (fault vs jam vs spoof) and fallback (alternate source, INS-only, degraded-ops). Phase II: GPNTS ICDs as necessary. |
| QA-825 (cluster 1) | 8/25/26 | Both source visualization **and** composite from underlying patterns. Correlate across disparate sources. Rules-based acceptable for Phase I; advanced/statistical/ML encouraged if explainable and edge-runnable. Sub-second applies ingest → alerts **and initial recommended COAs**. Full evidence package **not** in the same interval; progressive disclosure. **Numbering mismatch:** the posted A.4 answers the latency question (Q.5); A.5 answers the evidence-timing question. Q.4 (who supplies TTPs) is **not answered in this cluster**. |
| QA-825 (cluster 2) | 8/25/26 | Award count subject to funding/quality. Phase I: open-source streams adhering to standards. Same 3–8 / 1–10 Hz / post-award versions. Operator-effectiveness metrics critical. Phase I synthetic/unclassified OK; no live Navy tactical systems. Air-gap restated. Transition owner = GPNTS PoR. |
| QA-826 | 8/26/26 | Phase I performers may define representative rules/TTPs; GFI/SMEs post-award and Phase II. Most valuable: anomaly triage + fallback in **one workflow**. Primary integration = shipboard GPNTS; standalone interface following ECDIS conventions; **no** shore/mission-support interface. 3–8 sources, 1–10 Hz restated. **Numbering mismatch:** posted A.1–A.4 do not line up one-for-one with Q.1–Q.4 (Q.1 extra-data vs A.1 TTPs). Treat as a garbled cluster; do not over-claim a Government extra-data requirement. |
| QA-826 (analysis) | 8/26/26 | Phase I analysis limited primarily to APNT-source data on a navigation-style display; broader mission data not planned; modularity for future sources is competitive. |
| QA-828 | 8/28/26 | **All NP004 Phase I data and activity is CUI.** No higher classification planned. Synthetic ASPN/pntOS allowed. Iron Bank-in-Phase-I question answered only with synthetic-data guidance — **unresolved**. ECDIS-like = **UX familiarity target**; ET trained on those standards. Any ASPN/pntOS-conformant synthetic data acceptable; GPNTS message types in Phase II. |
| QA-831 | 8/31/26 | Commercially derived data-integration and decision-support platform **confirmed responsive**. |
| QA-901 | 9/1/26 | **No facility clearance expected for Phase II.** **No human research expected** under this SBIR. |

Q&A close for new questions: 9 September 2026, noon ET (preface and topic notice). Not submitted anything this session.

### 3.2 Solicitation / template

- Navy v2: `docs/F/F1_NAVY_SBIR_26BX_R5_v2_2026-09-07.md` / `corpus/F/F1_NAVY_SBIR_26BX_R5_v2_2026-09-07.pdf`. NAVWAR PM: Mr. Shadi Azoum, info@navwarsbir.com. Technical merit most important; qualifications and commercialization equal second. Prototype OT for Phase I. One proposal per company per open topic.
- CSO preface: `docs/F/F4_DOW_CSO_R5_PREFACE_2026-09-07.md`. Volume 2 = one unencrypted unlocked PDF; consecutive pages; company/topic/proposal number in headers; virus check; page count after DSIP upload (§3.7(b) cited in filing outline).
- Filing outline (internal, 2026-09-07): `notes/NP004_filing_outline_2026-09-07.md`.
- Layout plan (internal): `notes/NP004_volume2_layout.md`.

### 3.3 Policy / defense-need sources (topic references and related)

| Key | Document | Edition / date | URL or repo path | Clauses used |
|---|---|---|---|---|
| OPNAV | OPNAVINST 9420.1C, Positioning, Navigation and Timing Policy | 30 Sep 2019 | https://www.secnav.navy.mil/doni/Directives/09000%20General%20Ship%20Design%20and%20Support/09-400%20Command%20and%20Surveillance%20Systems%20Support/9420.1C.pdf ; `docs/F/F3_OPNAVINST_9420.1C_PNT.md` | 5.a.(2) 100% availability via combination of technical and operational solutions; **5.a.(3)** primary + at least one independent alternate; 5.a.(4) GPS primary; 5.a.(5)–(6) alternate position/time lists (INS, radar, LOP, celestial, bathymetry, SOO; clocks, NTP, HF, TWSTT); **5.a.(8)** standardize interfaces; **5.a.(11)** new PNT systems should indicate degradation due to interference (jamming, multipath, weather, terrain, **spoofing**); 5.b.(9) dead-reckoning capability and proficiency. |
| GAO-21-320SP | Defense Navigation Capabilities: DOD is Developing PNT Technologies to Complement GPS | 10 May 2021 | https://www.gao.gov/assets/720/714196.pdf ; https://www.gao.gov/products/gao-21-320sp ; `docs/F/F3_GAO-21-320SP_Defense_Navigation.md` | Highlights: GPS remains core; complementary/alternative when GPS degraded/unavailable; relative (INS/clocks) vs absolute (celestial, LF, LEO); “no single PNT system is capable of supporting all DOD PNT requirements” (body §2.1, quoting 2020 PNT S&T Roadmap); complementary sources check accuracy of each source including GPS. Topic reference 1. |
| JADC2 | Summary of the Joint All-Domain Command and Control Strategy | Mar 2022 | https://media.defense.gov/2022/Mar/17/2002958406/-1/-1/1/SUMMARY-OF-THE-JOINT-ALL-DOMAIN-COMMAND-AND-CONTROL-STRATEGY.pdf ; `docs/F/F3_JADC2_Strategy_Summary.md` | Sense / make-sense / act; decision advantage at speed of relevance; C2 resilient in degraded/contested EMS (guiding principle 4). Topic reference 4. Not a GPNTS spec. |
| NIST | NIST IR 8323r1, Foundational PNT Profile | Jan 2023 (approved 2023-01-20); supersedes Feb 2021 IR 8323 | https://doi.org/10.6028/NIST.IR.8323r1 ; `docs/C/C2_NIST_IR_8323r1.md` | Voluntary profile implementing EO 13905: identify PNT-using systems and data sources; **detect disruption and manipulation**; manage risk. CSF Identify/Protect/Detect/Respond/Recover. |
| DHS-CF | Resilient PNT Conformance Framework v2.0 | 26 Apr 2022 | https://www.dhs.gov/publication/st-resilient-pnt-conformance-framework ; `docs/C/C3_DHS_Resilient_PNT_Conformance_Framework_v2.0.md` | Outcome-based UE behaviors; Prevent / Respond / Recover; four resilience levels; **common-mode** called out; framework is for PNT user equipment that **outputs** PNT solutions, not for downstream consumers — cited as integrity-behavior context, **not** as a claim that the operator console is PNT UE under the CF. |
| EO-13905 | Strengthening National Resilience Through Responsible Use of PNT Services | 12 Feb 2020 | https://www.federalregister.gov/documents/2020/02/18/2020-03337/strengthening-national-resilience-through-responsible-use-of-positioning-navigation-and-timing | Context for NIST profile. Not quoted at length in the pages. |
| ION ASPN | IS4S, “ASPN and pntOS: An Open-Source Ecosystem…” ION GNSS+ 2023, pp. 1121–1132 | 2023 | https://www.ion.org/publications/abstract.cfm?articleID=17172 | Topic reference 3. Abstract only checked this session (paywalled paper). **Unverified** full-text claims. |

### 3.4 Current maritime GNSS-disruption evidence (2026)

| Key | Document | Date / status | URL | What it actually says |
|---|---|---|---|---|
| MARAD | U.S. Maritime Advisory 2026-008 | Active; supersedes 2025-014; auto-expires **21 Oct 2026** | https://www.maritime.dot.gov/msci/2026-008-global-us-maritime-advisory-updates-resources-and-contacts ; `docs/C/C8_MARAD_Advisory_2026-008.md` | “GPS disruption affects maritime navigation in various parts of the world.” Develop GPS-disruption response plans. Report to NAVCEN. AIS open/unencrypted/unprotected; can be spoofed; **never solely relied upon** for collision avoidance or navigational decision-making. |
| NAVCEN | GPS Problem Report Status (GUIDE) | Retrieved 2026-09-07; default last 30 days plus closed table | https://www.navcen.uscg.gov/gps-problem-report-status | **Disclaimer (verified):** reports do not validate constellation degradation; heatmap not real-world impact area. Closed marine examples used: **#1003** 14 Aug 2026 Baltic Sea, GPS interference ~0330–0710 LT, cause Unknown Interference, constellation/control OK; **#1000** 29 Jun 2026 SE of Sweden, GPS failure, Unknown Interference; **#996, #994, #992** 20 / 7 / 2 Jul 2026 Fujairah UAE, GPS disruption (994: “all the vessels at FUJAIRAH W anchorage”), Unknown Interference; **#990** 18 Jun 2026 Red Sea, GPS position spoofing far from actual, Unknown Interference; **#988** 14 Jun 2026 Red Sea, GPS jamming, Unknown Interference. |

**Not used as Navy-validated statistics (deliberate):** Windward AI 2026-06-23 blog (Q1 2026 Hormuz-share figures); Scientific American 2026-03-12 Hormuz feature; Foreign Policy 2026-06-01; Bloomberg 2025-06-29. Those describe a real public debate but are commercial/journalistic. If later drafts want a theater example, prefer MARAD + NAVCEN + the Q&A’s own “Destroyer … GPS-degraded or spoofed strait” example, labeled as a **feasibility scenario**, not a classified theater claim.

### 3.5 CMMC / CUI (context for pages; not a KPP)

- Topic: PROJECTED CMMC LEVEL REQUIREMENT: **Level 2 (Self)**.
- 32 CFR §170.16 (eCFR current as of 2026-09-03): Level 2 self-assessment scored per NIST SP 800-171A Jun2018; results in SPRS; every three years; annual affirmation. 32 CFR Part 170 IBR is **NIST SP 800-171 Revision 2** (Feb 2020, updates 28 Jan 2021), not Rev 3.
- Filing outline (verified against Navy v2 p. 8 and preface §2.6): CMMC requirements due at award; current NIST assessment in SPRS to be considered for award. July 2026 CMMC-rollout Phase II suspension is **not** SBIR Phase II and does not waive self-assessment. **Do not claim a SPRS score or CMMC status not held.** Company SPRS: **unverified**.
- 8/28 Q&A: all Phase I data/activity is CUI **and** synthetic ASPN/pntOS allowed. These two sentences are both on the page. They do **not** by themselves classify the pre-existing public repo as CUI, nor do they make a synthetic demo unrestricted. Handling categories, markings, and when the CUI environment must exist: **unresolved**. Prepared DSIP questions in the filing outline were not sent this session.

---

## 4. Kobayashi Maru / decision-uncertainty concept — origin, use, and limits

**Origin.** User assignment, 2026-09-07: explore a Kobayashi Maru-style evaluation of problem-solving under progressive PNT degradation. The name is a cultural reference to a no-win training scenario; it is **not** a Navy, GPNTS, or topic term. It must not appear as a Government requirement.

**What the pages claim (P):** an **evaluation hypothesis** for scoring the unified interface.

**Four scenario families (P):**

1. **Nominal** — sources consistent with held-out truth. Correct behavior: CONTINUE / no alert storm. Exists so “always abstain” cannot win.
2. **Recoverable** — independent evidence is **in the system inputs** to distinguish fault vs jam vs spoof and to justify an informational COA (SELECT-ALTERNATE, CONFIRM-INS-ONLY, INITIATE-DEGRADED-OPS, CROSS-CHECK-VERIFY, SERVICE-ADVISORY). These are the Q&A “most valuable” decisions, labeled as such (**S** capability, **P** scoring).
3. **Progressive degradation** — sources fail or diverge in sequence. The interface must show what is still known, which dependencies failed, and what would resolve the remainder.
4. **No-win (Kobayashi Maru)** — remaining sources are correlated or otherwise insufficient; ground truth is that **no unique COA is justified**. Correct behavior: INDETERMINATE + named failed assumption/dependency + named independent evidence that would resolve ambiguity. Forcing a unique COA fails the run.

**Evaluation hygiene (P, assignment-driven):**

- Reproducible seeded scenarios.
- Ground truth **separate** from system inputs (the system cannot read labels).
- Held-out cases.
- Identical inputs to fragmented-display baseline and prototype.
- Product = unified APNT operator awareness; simulator = feasibility/evaluation infrastructure.
- No new sensors, navigation algorithms, or autonomous ship control.
- Initial recommendations informational (**S**, QA-701).

**Why this is responsive to the topic (inferred from verified Q&A):** Q&A already requires source-level **and** composite confidence, anomaly triage, fallback aids, sub-second initial COA, later evidence, and operator trust/explainability. It does **not** require a forced unique COA when evidence is insufficient. A forced-label scorer would be misaligned with “minimum subset” and with common-mode spoofing (correlated GNSS agree while wrong). A always-INDETERMINATE scorer would be misaligned with recoverable triage. The two-set rule is the evaluation’s load-bearing idea.

**What is not claimed:** that the Navy trains Kobayashi Maru; that INDETERMINATE is a GPNTS enumeration; that abstention is always correct; that the sim is the product; that we have already run the library.

**Coherent-bias case (inferred, from physics + Q&A composite-across-sources + DHS common-mode):** two GNSS receivers can agree and both be wrong if they share geometry/capture. Cross-receiver agreement is not independent evidence. Independent-family comparison (e.g. GNSS vs INS/DR, radar fix, clock holdover) is the kind of “independent evidence” the no-win rubric asks the interface to **name when missing**. This is an evaluation-design inference, not a measured result and not a new navigation algorithm.

---

## 5. KPP rationale (class, bound, method, failure)

Every row in the page-2 table is argued here so a later convergence pass can attack the bound without attacking the class.

| ID | Why this bound | What would be dishonest |
|---|---|---|
| K1 | **S** verbatim: “3 to 8 simultaneous PNT sources updating at 1 Hz to 10 Hz” (QA-820, QA-825, QA-826). | Treating 8 as a minimum; treating 10 Hz as a latency SLA (it is an update-rate envelope). |
| K2 | **S** bound: sub-second ingest → alerts **and initial recommended COAs** (QA-825 A.4 in the mismatched cluster; QA-820). Evidence path explicitly excluded (QA-825 A.5). Q&A did **not** specify a percentile. User clarification 2026-09-07 makes **zero misses** the offeror acceptance gate (**P**): any labeled onset ≥ 1.0 s fails. Clock must not be the GPS being degraded (**A**). N frozen after library freeze is **P**. **Retracted:** earlier p95 wording in this draft. | Folding retrieval/LLM into the hot path; using GPS time as the audit clock; treating p95/p99 as a pass if any event is ≥1 s; claiming the Government forbade percentiles (it did not; the user/offeror did). |
| K3 | **S** “faithfully visualizing source-level confidence and health … while also … composite” (QA-821, QA-825). “Source never collapsed” is **P** wording of that dual requirement. | Showing only a fused fix. |
| K4 | **S** 100% air-gapped, no remote DC/shore/cloud; “including all UI rendering, analytics, and any AI/ML inference” (QA-820, QA-825). User clarification restates this as a firm gate covering the entire stack. | Calling a laptop demo “air-gapped” without an egress check; leaving a model API or map-tile fetch outside the air-gap; claiming Iron Bank is a Phase I mandate (QA-828 did not answer that). |
| K5 | **S** Phase I informational aids only (QA-701). | Workflow automation that routes actions; autonomous ship control. |
| K6 | **S** most-valuable = triage fault/jam/spoof and fallback (QA-821, QA-826). Scoring rule is **P**. Denominator = recoverable runs only, so no-win cases are not punished here. | Reporting a single accuracy % that mixes no-win and recoverable; claiming a Government pass/fail %. |
| K7 | **P** assignment. Rubric is qualitative by necessity until SMEs (post-award GFI, QA-826) confirm wording. | Treating INDETERMINATE as always correct. |
| K8 | **P** assignment: include nominal/recoverable so abstention is not a dominant strategy. | Dropping nominal cases from the library. |
| K9 | **S** preferred metrics vs fragmented-display baseline (QA-820). Pairing protocol is **P**. **No pre-claimed improvement %.** | Inventing “X% faster.” |
| K10 | **S** UX familiarity target (QA-828). Checklist is **P**. Not human research (QA-901). Not S-52 certification. | “ECDIS-certified prototype.” |
| K11 | **S** highly desirable (QA-819, QA-820). Completeness of the chain is **P**. | Claiming a certified audit log / 800-171 control implementation as already done. |
| K12 | **P** user/assignment firm gate. Controls: least privilege, controlled access, pinned/scanned dependencies, protected data/configuration, audit. Verification is a fail-closed checklist on the Phase I isolated demo. Maps to topic containerization language and Q&A air-gap; **does not** assert CMMC Level 2 (Self), SPRS score, NIST SP 800-171 implementation, Iron Bank approval, or ATO. NIST SP 800-190 is a **design catalog** for container hardening, not a claimed assessment result. | “Hardened-ready” as if accredited; citing CMMC as achieved; skipping scan/pin because “it’s only Phase I.” |

**COA set used as labels (P, bounded, representative — QA-826 allows Phase I to define representative rules/TTPs):** CONTINUE; CROSS-CHECK-VERIFY; SELECT-ALTERNATE-SOURCE; CONFIRM-INS-ONLY; INITIATE-DEGRADED-OPS; SERVICE-ADVISORY; plus INDETERMINATE. These are **informational**. They are not Navy TTPs and will be aligned post-award with GFI/SMEs.

**Baseline definition (S):** “the current environment of monitoring multiple fragmented physical displays” (QA-820). Phase I implementation of that baseline is a **second viewer** fed the same synthetic streams without correlation/composite/COA — not a claim that we have instrumented a real CIC.

**Not KPPs (on purpose):**

- NASA-TLX / SUS / SAGAT — named in the internal build plan; **withdrawn as Phase I commitments** given QA-901. Revisit only after the Government clarifies acceptable non-research evaluation.
- Hit@10 / MRR retrieval numbers in `lume/` — repo retrieval-test claims; **not** operator-performance evidence; not re-run this session.
- Iron Bank image in the Phase I demo — encouraged architecture, not a verified Phase I mandate.
- Mission-impact scoring — QA-821: detail still under review; general approach sufficient.
- Live GPNTS ICD conformance — Phase II GFI.

---

## 6. Assumptions (explicit)

| ID | Assumption | Kind | What would check it |
|---|---|---|---|
| A1 | A commercially derived integration/decision-support platform exists and can be adapted by the filing company | Unverified company fact | Corporate ownership / maturity evidence before Volume 2 uses product names |
| A2 | Synthetic ASPN/pntOS streams can represent health, integrity, confidence, and enough measurement-level pattern for composite (QA-825 “both”) | Inferred from Q&A; schema versions post-award | Pin public ASPN YAML + pntOS plugin versions in the base SOW; keep adapters |
| A3 | At least one error-independent family can be present in the 3–8 sources (else common-mode GNSS cannot be diagnosed) | Inferred | Ingest contract: if no independent family, cap composite and surface “cross-family verification unavailable” |
| A4 | Local monotonic non-GPS clock available for latency/audit | Unverified demo-environment | Name the clock source in facilities |
| A5 | Representative (not authoritative) TTP/COA labels are acceptable in Phase I | Verified allowed (QA-826); content unverified | Post-award GFI/SME alignment |
| A6 | Destroyer / ETV / ECDIS-familiar strait transit is the right single deep use case | Verified as Government **example/preference**, not a unique mandate | Do not treat other platforms as in-scope for Phase I |
| A7 | SME design-review checklists are not “human research” | Inferred; QA-901 is not an IRB determination for an arbitrary study | Ask DSIP/PM before any participant task |
| A8 | CUI handling for a pre-existing public codebase + synthetic demo can be scoped without blocking Phase I feasibility work | Unresolved | The filing-outline DSIP question on CUI categories/markings |
| A9 | Containerized isolated PoC on a commercial runtime is acceptable if architecture is Iron Bank-ready | Unresolved (QA-828 non-answer) | Same DSIP question. K12 still applies on a commercial runtime. |
| A11 | Phase I can demonstrate the K12 controls (non-root, dropped caps, no inbound SSH, pinned/scanned images, volume-isolated state) without holding CMMC/ATO | Inferred from assignment + Q&A containerization | Show the checklist evidence; never equate it to accreditation |
| A10 | No facility clearance in Phase II implies unclassified GPNTS ICD GFI is planned | Partial: QA-901 says no facility clearance expected; does **not** say no CUI and does not exempt personnel-clearance questions | Do not infer a CUI or personnel-clearance exemption |

---

## 7. Uncertainties and unresolved issues

1. **CUI scope (high).** QA-828 vs public synthetic-data permission. Do not claim the demo is unrestricted. Do not silently reclassify the public corpus.
2. **Human-research boundary (high).** QA-901 vs template language on human subjects and vs Q&A-named operator-effectiveness metrics. Pages commit to **instrumented system measurements + design-review checklists**, not participant studies.
3. **Q&A numbering mismatches (medium).** 8/25 cluster (Q4 TTPs unanswered in that cluster; A4/A5 shifted) and 8/26 cluster (A.n ≠ Q.n). 8/8 answer 2 repeats the question. Unofficial page may be garbled vs DSIP. **Do not cite misaligned A.n as if it answered Q.n.** Prefer the sentence, not the number.
4. **Iron Bank in Phase I (medium).** Asked; not answered.
5. **Authoritative TTPs/thresholds (medium).** Phase I may define representative rules; alignment is post-award. Do not invent Navy confidence thresholds.
6. **Mission-impact data (low/medium).** Desired; not available for Phase I ingest.
7. **ASPN/pntOS/GPNTS versions (medium).** Post-award. Architect for modularity.
8. **DSIP vs unofficial mirror (medium).** Live unofficial Q&A matched the 9/7 capture through 1 Sep answers. Authenticated DSIP copy not pulled. Recheck before filing; Q&A questions close 9 Sep noon ET.
9. **Company eligibility/CMMC/SAM (out of scope for these pages; blocking for filing).** Unverified.
10. **Build-plan overreach.** `PHASE1_BUILD_PLAN.md` is useful architecture; several items (NASA-TLX, S-52 certification tone, Hit@10 as operator evidence, CMMC = 800-171r3) are **not** copied into the pages. The coherent-bias scenario is retained only as evaluation-design inference.
11. **Latency statistic (resolved for this draft).** First Grok pass used p95 as an offeror statistic. User clarification forbids any ≥1 s miss. Bound remains Q&A sub-second (**S**); zero-miss scoring is the offeror/user gate (**P**).

---

## 8. What the pages deliberately do not say

- Any measured speed-to-decision, accuracy, or workload percentage.
- Government acceptance thresholds or “will be accepted if …”
- Operational endorsement, named Navy customer commitment, or “transition owner agrees.”
- That synthetic performance equals shipboard/GPNTS performance or is publicly releasable.
- That the prototype is ECDIS-certified or S-52/S-57/NMEA-compliant.
- New sensors, new navigation/fusion algorithms as the claimed innovation, or autonomous control.
- Human-subjects usability study as a Phase I task.
- That Kobayashi Maru is a Navy requirement.
- That the scenario driver is the product.
- That CMMC, ATO, Iron Bank approval, or NIST SP 800-171 assessment is already achieved.
- That Q&A forbade percentile latency statistics (it did not; this draft now uses a zero-miss offeror gate).

---

## 9. Word-count / pagination note

Markdown drafting target was 450–550 words per page. Page 1 was trimmed after a first pass ran long. Tables on page 2 reduce required prose. **PDF pagination was not verified.** A later typesetting pass against the 10-page Volume 2 budget (layout plan: ~2 pages for 1.0, ~1 page for 1.1) will rebalance.

---

## 10. Recheck list before any filing use

- Re-pull DSIP topic/Q&A after 9 Sep close and immediately before 23 Sep submit.
- Confirm no new answers after 1 Sep 2026.
- Company platform ownership sentence (A1).
- CUI/Iron Bank/human-research questions if still unanswered.
- Do not paste these markdown headings into the official template; remap to 1.0 / 1.1 / 1.4.
