<!-- Provenance: Claude synthesized ACME draft, pasted 2026-09-07.
     Saved by Grok for v4 interleave. Not the filed volume. -->

# DeepBlue Dynamics | DON26BX05-NP004 | Phase I Technical Proposal — Synthesized Draft v2

**Editorial note.** Structure adapted from the ACME comparison reference. Outer headings follow the DON Open Topic template (1.0–3.0, Facilities/Equipment, References) so the volume stays template-compliant; the sub-structure — team/buyer introduction, problem and opportunity, innovative-approach overview, feasibility-analysis criteria, reporting, program-style related-work blocks, formal personnel blocks, consultants/IP/prior-support, and customer evidence — is imported from the ACME sample. Square brackets mark items to confirm before submission. Where the ACME sample asserts capability ("easily adapted," "confident we can deliver"), this draft keeps the hedged language of the prior DeepBlue draft: nothing is claimed as demonstrated until it is measured.

---

## 1.0 DESCRIPTION OF PROPOSED PHASE I TECHNICAL EFFORT

### 1.0.1 Introduction

DeepBlue Dynamics [together with consultants — none currently proposed; confirm] is pleased to submit this proposal to develop a unified assured positioning, navigation, and timing (APNT) awareness and decision-support interface, referred to below as the APNT Awareness Console [working name to confirm], in response to Department of the Navy Open Topic DON26BX05-NP004, "NAVWAR Open Topic for Unified Assured Positioning, Navigation, and Timing Operational Awareness and Decision Support." [1]

The background of our team maps to what the topic asks for — data integration, analytics, and decision-support expertise — rather than new navigation algorithms. The Principal Investigator, Mr. Kord Campbell [PI designation to confirm], founded DeepBlue Dynamics in September 2019 and previously founded and operated two commercial search and time-series data companies (Grub, Inc., acquired by LookSmart; Loggly) and served as Chief AI Officer at FeatureBase, applying machine learning to a high-throughput database. Mr. Clint Robison [title to confirm] brings full-stack delivery on Python, PostgreSQL, Linux, Docker, and CI/CD in four product organizations, earlier Department of Defense programming work, and U.S. Navy sea service aboard USS Kalamazoo (AOR-6). The intended Government customer is NAVWAR; the Topic Q&A names the GPNTS program of record as the primary integration target and transition owner. [1] That is the intended path, not a claim that GPNTS has selected or endorsed this firm.

### 1.0.2 Identification of the Problem

Consider a destroyer transit through a GPS-degraded strait. The electronics technician–navigation (ETV) is looking at several physical displays, each reporting on one positioning or timing source. Two feeds agree. A third disagrees, then goes stale. The technician must decide, in minutes, what information is still credible, which assumption has failed, and what evidence would justify the next response. DON26BX05-NP004 identifies exactly this condition — fragmented APNT displays — as an obstacle to timely understanding and decisions, and asks for a coherent assessment with an understandable basis rather than one more isolated indicator. [1]

The condition is current, not hypothetical. U.S. Maritime Advisory 2026-008 alerts mariners to worldwide GPS disruption and directs them to plan responses before departure. [2] The U.S. Coast Guard Navigation Center's closed GPS Problem Reports for June–August 2026 include Red Sea jamming and spoofing, a multi-vessel disruption off Fujairah, Baltic interference, and a GPS failure southeast of Sweden; each closed with no constellation anomaly — the disruption was in the signal environment, not the satellites. [7] Navy policy already anticipates this: OPNAVINST 9420.1C requires a DoD-approved primary and a GPS-independent alternate (paragraph 5a(3)) and requires new PNT systems to indicate degradation from jamming, multipath, weather, terrain, or spoofing (paragraph 5a(11)). [4] GAO reported in 2022 that Navy alternative-PNT business cases were incomplete and that the responsible oversight council had no progress metrics. [6]

Three specific failures make the fragmented-display problem harder than aggregation. First, agreement is not corroboration: two sources can agree because they share a compromised dependency, and a display that averages them reports false confidence. Second, the available observations often cannot distinguish a receiver fault from jamming from spoofing; a display that forces a diagnosis will sometimes be confidently wrong. Third, data ages and goes missing; a display that silently drops a stale field removes the evidence the operator needs to judge the rest. Current fragmented displays leave all three burdens on the technician.

Within the context of NAVWAR's requirement, the desired tool keeps individual source health visible, adds a transparent composite assessment whose basis can be inspected, names the evidence that is missing, and offers informational recovery options with their prerequisites — without adding sensors, replacing the navigation solution, or actuating any ship control. [1]

### 1.0.3 The Opportunity

The intent of this Phase I SBIR is to research and develop a software interface that presents source health, a separately explained composite assessment, and prerequisite-bound informational recommendations for 3–8 simultaneous PNT sources at 1–10 Hz, running air-gapped and secured, with a proposed initial response under 100 milliseconds. [1]

Our central hypothesis is that making dependencies and unresolved uncertainty visible will help operators find decision-relevant evidence more effectively than aggregation alone. Phase I tests the technical feasibility of that design and produces the evidence needed to justify an appropriately authorized operator-effectiveness evaluation later. Human workload, comprehension, and decision-time improvements are outcomes to be established in that later evaluation; no operator-performance gain is claimed until it is measured.

The proposal deliberately changes what counts as success. A confident answer unsupported by the available evidence fails, even when it happens to match hidden truth. Permanent uncertainty fails cases where a useful response is supported. Nominal, recoverable, and unresolved scenarios are therefore tested together, with evaluator truth isolated from operational inputs, and recovery transitions test whether the interface updates its recommendation when credible evidence returns.

**Scope boundaries.** The work develops no new PNT sensors, timing sources, hardware, or ownship-fix/navigation-solution algorithms. It integrates, assesses, and presents existing-source information and is not a replacement navigator. The simulator is feasibility infrastructure; the delivered capability is the interface and its explainable integration service. [1]

### 1.0.4 Contractor Experience

DeepBlue Dynamics brings four existing assets to Phase I. They are development assets, not evidence of a fielded APNT product, a certified navigation display, or a measured operator result.

1. A provenance-tracked public library of PNT interface material, including ASPN and pntOS documentation, the topic text, the Topic Q&A, and the CSO. It is the intended Phase I standards source, not Government-furnished information.
2. A vendored hybrid retrieval engine (lexical, vector, graph) available for operator drill-down after the initial alert and recommendation are displayed.
3. A prototyped container, built in the firm's nemesis8 tooling on an Iron Bank base image, that packages the retrieval tools, reference data, and display driver. This is hardening-ready packaging, not an accredited or fielded system.
4. A notional console layout (alert banner with acknowledge, resolution options, chart area, source roster, event log), shown in Figure 1. It is design reference only — not certified ECDIS and not real chart data.

Mr. Campbell's career has been building and operating systems that turn high-volume machine data into something an operator can act on: a distributed web crawler (Grub), developer advocacy for enterprise machine-data search (Splunk), SaaS time-series log search (Loggly), and machine-learning applications over a high-throughput database (FeatureBase). Mr. Robison has delivered production data pipelines, workflow systems, and portals in product-owner-facing roles, including a revenue-cycle clearinghouse workflow connecting 340,000 healthcare providers; his Navy sea service gives shipboard context for the interface work but is not presented as GPNTS or APNT-specific expertise. Details are in Section 2.0.

### 1.0.5 Innovative Approach Overview

The APNT Awareness Console is a trainable, retrieval-augmented pipeline that drives an operator display. It ships as one container image built on an Iron Bank base, carrying the retrieval tools, the reference-document base, the retrieval index, and the compiled decision rules. Figure 2 shows the high-level architecture. Five design choices distinguish it from an aggregating dashboard.

**Evidence-preserving composite.** The pipeline normalizes each incoming source while retaining source identity, health, confidence, data age, known dependencies, and explicit missingness. The composite assessment is derived separately and explained separately: the display shows which observations support it, how old they are, and which dependencies they share. Unknown dependencies remain marked unknown. An ordinal confidence label is never presented as a calibrated probability.

**Deterministic alert path, explanation on demand.** A bounded, deterministic code path presents the alert and initial informational recommendation with a proposed target of under 100 milliseconds from input receipt at the system boundary to the first displayed frame containing both, with security controls enabled. No language model participates in that path. If a local model is present, it composes drill-down explanation after the alert is displayed; if it is absent or fails, the initial response is unchanged.

**Rules derived from guidance, produced by "combative training."** The decision rules are deterministic code derived from guidance documents: the public PNT interface standards, IMO alert and integrity guidance, resilient-PNT frameworks, and the representative procedures the Q&A permits performers to define. [1][8][9] They are produced by a development-time training loop (Figure 3):

1. A scenario generator produces failure scenarios — fault, jamming, spoofing, shared dependency, stale or missing data, recovery — with evaluator-held truth.
2. A language model, running only in the development environment, exercises the pipeline's own tools against each scenario: it queries the local retrieval service over the document base, inspects what is returned, and writes candidate rule code and test cases. Each rule carries the citation of the guidance clause it embodies.
3. Rule code is human-reviewed, versioned, and regression-tested. Only compiled rules, the index, the reference data, and versioned procedures ship.
4. Training produces a labelled dataset of scenario runs, tool returns, rule versions, and outcomes that serves as regression evidence. Training scenarios are kept separate from the frozen held-out evaluation cases, so the no-win and recoverable cases score rules that never saw them.

Agents are used only on training scenarios, simulated in Phase I, never in the shipboard runtime. Audit records of alerts, evidence, recommendations, and operator acknowledgements are collected in a form that can feed later offline retraining under whatever handling rules apply, with representative Government data expected only in Phase II.

**Explicit unresolved state.** When the observations cannot discriminate among fault, jamming, and spoofing, the rules produce INDETERMINATE rather than a forced diagnosis. The console states that the cause is not determined, names the accessible cross-check that would resolve it, and offers an acknowledge action recorded in the audit trail. If no discriminating evidence is accessible, it states that limit and presents appropriately bounded degraded-operation information. No-win scenarios reward this behaviour; nominal and recoverable scenarios penalize abstention when the evidence supports a response.

**Keyed retrieval.** The local hybrid search is keyed by anomaly state so that the procedure and evidence for a displayed alert are fetched by a precomputed key, with a design target of under 30 microseconds per keyed lookup. Semantic search is reserved for operator drill-down, so retrieval never threatens the 100 ms gate. This is a target to be measured, not a result.

Every assessment and recommendation the console displays resolves to its input evidence and to the rule version that produced it, giving the operator — and later the Government evaluator — a reasoning trail rather than an assertion (Figure 5).

---

## 1.1 PHASE I TECHNICAL OBJECTIVES

The six-month base period will answer three questions: can the interface preserve and explain multi-source evidence; can it distinguish supported recommendations from unresolved alternatives; and can it do so within a secured, air-gapped execution envelope with a proposed response time below 100 ms? DeepBlue Dynamics has identified the following technical objectives to give NAVWAR a complete assessment of the feasibility of the APNT Awareness Console. The prototype will, at a minimum:

1. **Model the source data.** Normalize synthetic ASPN/pntOS-compatible inputs from 3–8 simultaneous sources at 1–10 Hz, retaining source identity, health, confidence, data age, known dependencies, and explicit missingness for every field. [1]
2. **Build the rule library from guidance.** Produce cited, versioned, human-reviewed deterministic rules through the combative-training loop, compiled into the runtime, including rules that yield INDETERMINATE when evidence cannot support a conclusion.
3. **Derive a separately explained composite.** Compute a composite confidence and triage assessment (fault versus jamming versus spoofing) that resolves to its input evidence and rule version and that distinguishes agreement from independent corroboration.
4. **Support decisions.** Present versioned informational recommendations with prerequisites and traceable evidence; recognize missing corroboration; name the accessible cross-check that would resolve an unresolved case; update the recommendation when credible evidence returns.
5. **Run secured and air-gapped.** Package the entire stack — ingestion, analytics, UI, retrieval, optional local inference, replay — for offline cold start on an Iron Bank-based image with least privilege, role-limited access, verified offline packages and SBOM, protected data and keys, and tamper-evident audit. [3]
6. **Establish measured feasibility against controls.** Exercise the secured stack on frozen held-out scenarios against an identical-input synthetic fragmented-display surrogate and an explanation-disabled unified view. The surrogate is a test control, not a validated fleet baseline.

DeepBlue Dynamics will augment these objectives with specific information available after award, including any interface documents the Government provides.

### Proposed feasibility gates

The source envelope (3–8 sources at 1–10 Hz), sub-second response, air-gapped operation, and secured runtime are fixed Government constraints. [1] The <100 ms gate, control checklist, case counts, and other numerical thresholds below are offeror-proposed engineering targets. Before any tuning, the threat model, hardware profile, payload and load assumptions, test oracle, and held-out cases will be frozen.

| Gate | Measurement | Fails if |
|---|---|---|
| **Response time** (proposed <100 ms) | In the hardened configuration, monotonic-clock interval from input receipt at the system boundary to the first displayed frame containing both alert and initial recommendation. Test 3/8-source × 1/10-Hz corners, intermediate and mixed rates, and local-model failure. Report all events, maximum, distribution, and drops. | Any missing response or any measured interval ≥100 ms. Uncertainty overlapping 100 ms does not establish a pass. The Government's <1 s requirement is reported separately. |
| **Air-gapped operation** | Cold-start and complete ingestion, UI, analytics, retrieval, inference, and replay with external interfaces disconnected and dependencies preloaded; permit only declared internal communications. | Any attempted external communication or any offline functional failure. |
| **Secured runtime** | Inspect effective controls; exercise denied access, modified packages, and audit tampering. [3] | Any mandatory-control failure or unremediated applicable high/critical vulnerability. |
| **Evidence fidelity and replay** | Across all held-out cases and three repeats, every assessment and recommendation must resolve to its input evidence and rule version; required emitted fields are preserved or explicitly marked missing. | Any silent loss, unsupported citation, or unexplained analytical replay mismatch. |
| **Useful, bounded recommendations** | 60 frozen held-out cases: 20 nominal, 20 recoverable, 20 unresolved, spanning fault/jam/spoof indicators, shared dependencies, missing/stale data, and recovery transitions; at least six recoverable cases per fault, jamming, and spoofing class. Report each stratum and every failure. | Any unsupported definitive claim or prerequisite violation in an unresolved case; fewer than 18/20 acceptable responses in the nominal or recoverable strata; any predeclared critical case failing its evidence-based oracle; any case claiming assurance contradicted by observable evidence. |
| **Information access** | On 12 frozen tasks, required evidence must be reachable and complete with no critical legibility or priority defect under a predefined design checklist. Views and interactions are counted against the fragmented surrogate and the explanation-disabled view. | Any unreachable or incomplete required evidence, or any critical checklist defect. Counts are reported as workflow proxies without a promised percentage improvement. |

A failed proposed gate is a reported feasibility limitation, not a requirement waiver. These case counts support feasibility testing, not fleet reliability claims.

Participant research is not included in the base period. The CUI handling scope and any evaluation activity requiring a Government determination must be resolved with the Government; synthetic data do not establish public releasability. Whether an Iron Bank image is required for the Phase I demonstration remains an open Government question; the secured-runtime gate applies regardless. [1]

---
## 1.2 PHASE I (BASE AND OPTION) STATEMENT OF WORK

DeepBlue Dynamics has developed the Phase I work plan to achieve the technical objectives in Section 1.1. The six-month base plan is designed to give NAVWAR sufficient design and feasibility evidence to evaluate a Phase II effort and to retire schedule and technical risk early: the evaluation plan is frozen before tuning, the secured runtime is built early enough to be measured rather than promised, and existing firm software (Section 1.3) is reused where it fits. All tasks will be performed by DeepBlue Dynamics personnel at [U.S. performance location to confirm], in a company-controlled development and test environment. Evaluation uses synthetic inputs and automated replay; the base effort requires no human-subject research, shipboard access, or Government-furnished equipment. Figure 4 shows the schedule.

**Figure 4 (table form). Phase I base schedule.**

| Task | M1 | M2 | M3 | M4 | M5 | M6 |
|---|:-:|:-:|:-:|:-:|:-:|:-:|
| B1 Requirements, architecture, evaluation plan | ■ | ■ | | | | |
| B2 Source ingestion and scenario simulation | ■ | ■ | ■ | | | |
| B3 Rule library, explainable interface, local decision support | | ■ | ■ | ■ | | |
| B4 Secured runtime and measured evaluation | | | ■ | ■ | ■ | ■ |
| B5 Findings and Phase II preparation | | | | | ■ | ■ |
| Reviews | Kickoff | Eval plan to TPOC | Progress review | | | Final demo and report |

### BASE PERIOD: SIX MONTHS FROM AWARD

#### 1.2.1 Task B1 — Requirements, architecture, and evaluation plan (Months 1–2)

A requirements-to-test matrix drafted before any tuning is the basis of every measurement in this proposal. In B1, DeepBlue Dynamics will translate the topic, the Q&A, and the objectives in Section 1.1 into that matrix: each requirement is paired with the test that will exercise it and the pass/fail rule that will score it. The task defines source interfaces, evidence dependencies, the threat model, failure states, and the secured offline runtime; separates development scenarios from a frozen held-out evaluation set; specifies expected outcomes and critical-case failure rules; and documents the hardware profile, workloads, timestamp boundaries, and measurement uncertainty.

DeepBlue Dynamics will provide the architecture and evaluation plan to the Government Technical Point of Contact (TPOC) for review at the end of Month 2 and will adopt recommendations and address concerns before the held-out set is frozen. **Deliverables:** kickoff briefing (Month 1), architecture document, evaluation plan and requirements-to-test matrix.

#### 1.2.2 Task B2 — Source ingestion and scenario simulation (Months 1–3)

The console must first construct a coherent picture from what the sources emit. B2 implements adapters for synthetic ASPN/pntOS-compatible inputs and a repeatable simulator for 3–8 sources at 1–10 Hz, preserving source identity, health, confidence, and data age, including missing fields. The simulator generates nominal, recoverable, and unresolved cases spanning faults, jamming, spoofing, stale data, and shared dependencies; simulator truth is kept outside the operational inference path. B2 also generates the combative-training scenarios and their evaluator-held truth as a dataset separate from the frozen held-out set. **Deliverables:** interface schema, versioned scenario fixtures, replay harness.

#### 1.2.3 Task B3 — Rule library, explainable interface, and local decision support (Months 2–4)

B3 builds the unified display, the evidence-based confidence and triage logic, and the prerequisite-bound recommendations, and reports INDETERMINATE when the evidence cannot support a definitive conclusion. The initial alert and recommendation are implemented in a deterministic path independent of language-model generation; retrieval, optional inference, and detailed explanations run locally, and initial functionality is retained if the local model fails.

B3 also runs the rule-synthesis loop described in Section 1.0.5: model-assisted rule and test generation from guidance documents and tool returns in the development environment; human review; versioned, cited rules compiled into the runtime. The retrieval index is keyed by anomaly state, and keyed-lookup latency is measured against the 30 µs target.

At the Month 3 progress review, DeepBlue Dynamics will report status, demonstrate the functional capabilities available at that point, and solicit Government feedback for incorporation into the remaining schedule. **Deliverables:** integrated feasibility prototype, evidence-linked traces, rule provenance table (rule → guidance clause).

#### 1.2.4 Task B4 — Secured runtime and measured evaluation (Months 3–6)

B4 packages the full stack for offline cold start and verifies least privilege, access controls, protected configuration and data, verified offline updates, dependency inventory, and tamper-evident audit, exercising unauthorized access, package tampering, and audit failure. [3]

Performance testing measures the proposed <100 ms gate with security enabled, including queueing and actual frame presentation: four 30-minute source/rate corners, a 30-minute intermediate/mixed-rate sweep, and a 60-minute maximum-load soak with bursts, covering at least 1,000 scored event transitions. The topic's <1 s requirement is reported separately. Evaluation then runs the frozen 60-case set, critical-case checks, repeated replays, and the 12 information-access tasks against the fragmented-display surrogate and the explanation-disabled configuration. Every miss, uncertainty, and unsupported conclusion is reported; fleet reliability and operator performance are not inferred from these tests. **Deliverables:** test evidence, security findings, feasibility assessment, training dataset, rule provenance, regression results.

#### 1.2.5 Task B5 — Findings and Phase II preparation (Months 5–6)

B5 demonstrates the prototype, assesses each objective against recorded evidence, identifies remaining technical risks, interface dependencies, and corrective work, and prepares the final report and initial Phase II proposal with integration milestones and a transition plan. **Deliverables:** final demonstration, final technical report, initial Phase II proposal.

#### 1.2.6 Feasibility analysis

DeepBlue Dynamics will evaluate feasibility against six criteria and combine them into the feasibility assessment delivered under B4 and B5:

- **Expected system performance** — the six gates in Section 1.1, scored on the frozen held-out set with every failure reported.
- **Security posture** — results of the secured-runtime inspection and adversarial tests, with unremediated findings listed.
- **Development risk** — maturity of each component (reused, adapted, new), complexity of the Phase II GPNTS integration, and any dependency on Government-furnished interface documents.
- **Extensibility** — how modularly the source adapters, rule library, and display map to GPNTS message formats and to other PNT-dependent domains, and what a new source or rule set costs to add.
- **User acceptability** — deferred. Phase I reports information-access counts as workflow proxies only; operator comprehension, workload, and decision time are reserved for an appropriately authorized later evaluation.
- **Cost** — addressed in Volume 3 and reconciled with the Phase II estimate in B5.

The configuration that best satisfies these criteria forms the basis of the Phase II proposal. Where alternatives score equivalently, DeepBlue Dynamics will solicit the TPOC's input before recommending one.

#### 1.2.7 Reporting

In addition to informal contact with the TPOC, DeepBlue Dynamics will hold a kickoff in Month 1, deliver a progress report and review in Month 3, and deliver the final demonstration and report in Month 6. Each report section corresponds to a task in this plan and is drafted as the task completes; a draft final report will be submitted three weeks before the end of the base period. Final products include the prototype package, interface documentation, scenario/replay package, training dataset, rule provenance, and evaluation evidence, with applicable data-rights markings.

### OPTION PERIOD: SIX MONTHS FROM OPTION EXERCISE

The option advances Phase II preparation and bridges the funding gap. Exercise is contingent on Government action following Phase II selection. Option work does not depend on access to a ship or an operational system.

#### 1.2.8 Task O1 — Resolve feasibility findings (Option Months 1–2)

Address prioritized base-period deficiencies and extend scenario coverage. Preserve the original evaluation results unchanged; measure changes with separately versioned regression and new challenge sets. **Deliverables:** updated prototype, issue disposition, regression evidence.

#### 1.2.9 Task O2 — Prepare integration and deployment (Option Months 2–4)

Refine the GPNTS-facing interface plan using available authorized specifications, explicitly identifying assumptions where specifications remain unavailable. Exercise interface emulators, offline installation and update procedures, and resource budgets on the declared test platform. **Deliverables:** interface-control draft, deployment package, dependency register.

#### 1.2.10 Task O3 — Establish Phase II readiness (Option Months 4–6)

Repeat performance and security checks after option changes. Refine the Phase II integration schedule, verification criteria, and transition risks. If later operator research is proposed, prepare the determination and approval plan required before that work begins. **Deliverables:** option demonstration, updated evidence package, final option report, Phase II execution plan.

Option reviews: kickoff in Option Month 1; progress report in Option Month 3; final review and report in Option Month 6. Accreditation, ECDIS certification, and operational deployment are outside this SOW.

---

## 1.3 RELATED WORK

The Open Topic template requires related work by the PI, the firm, consultants, or others. What exists is a public unclassified corpus, reusable software, and design tooling — not a GPNTS-integrated product, not a certified navigation display, and not a measured operator result. Each item below states what it demonstrates and what it does not.

### 1.3.1 PNT Interface Reference Corpus (DeepBlue Dynamics, internally funded)

**Classification:** Unclassified (public sources). **Period:** [start to confirm]–present.

A provenance-tracked library of public PNT interface material, including ASPN and pntOS documentation, the DON26BX05-NP004 topic text, the Topic Q&A, and the CSO. Every document carries source, retrieval date, and version. It is the intended Phase I standards source and the document base for the combative-training loop. It is not Government-furnished information and does not include Phase II ICDs.

### 1.3.2 Hybrid Retrieval Engine (DeepBlue Dynamics, internally funded)

**Classification:** Unclassified. **Period:** [start to confirm]–present.

A vendored local search engine combining lexical, vector, and graph retrieval. In Phase I it is adapted to keyed lookup by anomaly state (30 µs target) for the alert path and to semantic search for operator drill-down after the initial alert. It runs without network access. It has not been benchmarked under the Phase I latency gate; that measurement is Phase I work.

### 1.3.3 nemesis8 Container Prototype (DeepBlue Dynamics, internally funded)

**Classification:** Unclassified. **Period:** [start to confirm]–present.

A container built on an Iron Bank base image that packages the retrieval tools, reference data, and display driver. It is existing firm work and hardening-ready packaging; it is not an accredited or fielded system, and building on an Iron Bank base is not accreditation. Phase I adapts and measures this packaging under the secured-runtime gate.

### 1.3.4 Notional Console Layout (Figure 1)

A design sketch of the operator display: alert banner with acknowledge, resolution options, chart area, source roster, and event log, in an ECDIS-inspired layout used as a familiarity target for the ETV. It is design reference only — not certified ECDIS, not real chart data, and not an S-57/S-52/NMEA conformance claim.

### 1.3.5 Principal Investigator — prior commercial work

Mr. Campbell's prior work is in commercial search and data systems rather than navigation: Grub, Inc. (2000–2003), an open-source distributed web crawler acquired by LookSmart in 2004; Splunk (2007–2009), developer advocacy for time-series machine-data search; Loggly (2009–2012), a SaaS time-series log search service he founded and led; FeatureBase (2022–2023), machine-learning applications for a high-throughput database. Relevance: each is a system that ingests high-rate, heterogeneous machine data and presents it for operator decision. None is a PNT or Navy program. Publications: "Building Self-Aware Machines," Lucidworks Activate 2018; IETF Internet-Draft, "Agentic Hypercall Protocol (AHP)," 2026 [authorship and draft name to confirm].

### 1.3.6 Software Lead — prior work

Mr. Robison delivered a revenue-cycle clearinghouse workflow connecting 340,000 providers (Cognizant, 2018–2019); pipelines, internal workflow, and customer/partner portals on AWS, Python, and Postgres (Apkudo, 2022–2024); cloud operations, CI/CD, and UI/UX in a product-owner role (Incyte Studios, 2020–2022); and served as Lead Software Engineer at Behold Business Intelligence (2024–2025). Earlier he performed an Ada-to-C++ conversion as a Department of Defense computer scientist (2002–2003) and served as an Electrician's Mate aboard USS Kalamazoo (AOR-6), 1993–1996. Relevance: production data pipelines and operator-facing interfaces, plus shipboard context. Not presented as GPNTS or APNT-specific expertise.

### 1.3.7 Consultants

[None currently proposed. If a consultant is added, list prior work here and effort share in Section 2.3.]

No prior, current, or pending Government support for similar work is claimed; if any exists, the client, point of contact, and dates will be listed in Volume 5.

---

## 1.4 DEFENSE NEED

**Transition owner and integration path.** The Topic Q&A names the GPNTS program of record as transition owner, Phase II ICDs as Government-furnished information, no shore interface, and Phase I on synthetic ASPN/pntOS data. [1] Exhibit P-40, OPN Line Item 2657 (March 2024) describes GPNTS as the Navy's primary PNT system — open architecture, hosting the M-code MGUE card — with FY2025 M-GUE and NoGAPSS kits installing in FY2026. [5] Phase I maps to GPNTS modularly; the interface documents arrive in Phase II.

**Operational use case and user.** The preferred Phase I use case is a destroyer transit through a GPS-degraded or spoofed strait. The intended user is the electronics technician–navigation (ETV). An ECDIS-like layout is a familiarity target, not a certification claim. [1]

**Policy drivers.** OPNAVINST 9420.1C paragraph 5a(3) requires a DoD-approved primary and a GPS-independent alternate; paragraph 5a(11) requires new PNT systems to indicate degradation from jamming, multipath, weather, terrain, or spoofing. [4] GAO-22-106010 found Navy alternative-PNT business cases incomplete and no oversight-council progress metrics. [6] A unified awareness layer that reports degradation together with its evidence addresses the presentation half of what paragraph 5a(11) requires.

**Current threat evidence.** Closed NAVCEN GPS Problem Reports for June–August 2026 include Red Sea jamming and spoofing, a multi-vessel Fujairah disruption, Baltic interference, and GPS failure southeast of Sweden, each with no constellation anomaly. [7] U.S. Maritime Advisory 2026-008 directs pre-departure planning for GPS disruption. [2]

**The increment.** The topic identifies fragmented physical displays as increasing workload and slowing decisions. [1] The increment is one workflow for triage (fault versus jamming versus spoofing) and fallback: a unified air-gapped informational console that keeps source health visible, adds a transparent composite, and names missing evidence — without new sensors, ownship-fix algorithms, or ship control. No operator-performance gain is claimed until measured.

**Dual use.** Follows the topic's Phase III list, including commercial shipping and logistics, aviation operations, and critical infrastructure monitoring (Section 3.3).

---
## 2.0 KEY PERSONNEL

### 2.1 Principal Investigator

**Name:** Kord Campbell
**Title:** Founder, DeepBlue Dynamics [PI designation to confirm]
**Employer:** DeepBlue Dynamics [confirm primary employment at award and during performance]
**Clearance:** [to confirm; none required for the Phase I base effort as proposed]
**Foreign person:** [confirm]
**Education:** University of Central Oklahoma, computer science and mathematics, 1990–1995 [degree conferral to confirm]

**Qualifications:** Mr. Campbell has more than two decades of experience founding and operating companies that build search and data systems over high-volume machine data, and recent applied machine-learning leadership. He has been responsible for product architecture, engineering leadership, developer adoption, and commercialization at each of them.

**Relevant experience:**
- 2019–present — Founder, DeepBlue Dynamics. Retrieval and interface software, including the PNT reference corpus, hybrid retrieval engine, and nemesis8 container tooling described in Section 1.3.
- 2022–2023 — Chief AI Officer, FeatureBase. Machine-learning applications for a high-throughput database.
- 2009–2012 — Founder and CEO, Loggly. SaaS time-series log search.
- 2007–2009 — Director of Developer Marketing, Splunk. Developer advocacy for time-series machine-data search.
- 2000–2003 — Founder and CEO, Grub, Inc. Open-source distributed web crawler; acquired by LookSmart (2004).

**Publications:** "Building Self-Aware Machines," presentation, Lucidworks Activate 2018. Internet-Draft, "Agentic Hypercall Protocol (AHP): Tool Invocation, Blind Settlement, and Portable Reputation over HTTP," IETF Datatracker, 2026 [authorship and draft name to confirm].

**Proposed role:** Direct the technical approach and architecture; own the evidence-retrieval, rule-synthesis, and explanation design; lead Government interaction; write the transition and commercialization plan. **Effort:** [base hours / option hours to confirm].

### 2.2 Software Lead

**Name:** Clint Robison
**Title:** [to confirm]
**Employer:** DeepBlue Dynamics [start date to confirm; August 2026 is a drafting assumption]
**Clearance:** [to confirm]
**Foreign person:** [confirm]
**Education:** University of Central Oklahoma, computer science, 1999–2003 [degree conferral to confirm]

**Qualifications:** Mr. Robison is a full-stack engineer with production delivery on Python, PostgreSQL, REST and GraphQL interfaces, Linux, Docker, and CI/CD, in product-owner-facing roles. His earlier Department of Defense programming work and Navy sea service give shipboard context for the interface work; they are not presented as GPNTS or APNT-specific expertise.

**Relevant experience:**
- 2024–2025 — Lead Software Engineer, Behold Business Intelligence.
- 2022–2024 — Senior Software Engineer, Apkudo. Pipelines, internal workflow, and customer/partner portals on AWS, Python, Postgres.
- 2020–2022 — Principal Software Engineer, Incyte Studios. Product-owner and developer role covering cloud operations, CI/CD, and UI/UX with a client creative team.
- 2018–2019 — Senior Software Engineer, Cognizant. Revenue-cycle clearinghouse workflow connecting 340,000 providers.
- 2002–2003 — Computer Scientist, Department of Defense. Ada-to-C++ conversion.
- 1993–1996 — Electrician's Mate (EM4), U.S. Navy, USS Kalamazoo (AOR-6).

**Publications:** None listed.

**Proposed role:** Implement the ingestion and normalization services, the containerized secured runtime, the operator interface, and the evaluation harness; run the latency, isolation, and security gate tests. **Effort:** [base hours / option hours to confirm].

### 2.3 Subcontractors and Consultants

[None currently proposed; confirm.] If any are added, this section will state name, employer, role, and percentage of base and option effort, and the Phase I small-business performance minimum (at least two-thirds of the research effort performed by DeepBlue Dynamics) will be verified against Volume 3 [confirm against current CSO terms]. [Suggested, to confirm: DeepBlue Dynamics anticipates engaging a navigation subject-matter consultant in Phase II for the operator-evaluation design.]

### 2.4 Intellectual Property Arrangements

[Company to confirm background intellectual property — reference corpus, retrieval engine, nemesis8 tooling — ownership, and any proposed restrictions for Volume 5.] No consultant IP-sharing agreement exists to describe; if a consultant is added, the ownership and licensing terms for award-generated IP will be documented here.

### 2.5 Prior, Current, or Pending Support of Similar Proposals or Awards

DeepBlue Dynamics has no prior, current, or pending support for a similar proposal or award. [confirm]

---

## 3.0 COMMERCIALIZATION/TRANSITION PLAN SUMMARY

### 3.1 Anticipated Phase I Results and Foundation for Phase II

Phase I will produce the requirements-to-test matrix, the frozen evaluation set, a measured feasibility prototype, an evidence package (timing, security, evidence fidelity, bounded recommendations, information access), and the initial Phase II proposal. Several products have value independent of Phase II: the cited rule library with its provenance table, the labelled training dataset and replay harness, the secured offline packaging, and the interface schema for ASPN/pntOS-compatible sources.

Phase I positions DeepBlue Dynamics to extend the prototype in Phase II along modular seams designed in from the start. Source adapters are separable from the rule library, so GPNTS message formats are added as adapters when ICDs arrive. Rules are compiled from cited guidance, so representative Navy procedures are added by extending the guidance base and re-running the training loop rather than rewriting logic. The audit trail is designed so that operator acknowledgements from a representative Phase II environment can feed offline retraining under applicable handling rules. The deterministic alert path and the drill-down explanation are separate, so Phase II can mature the explanation layer without touching the timed path. Phase III, funded from other sources, would consist of program-of-record integration work and any modifications needed for commercial product form.

### 3.2 Defense Transition

The primary DoD transition target is the GPNTS program of record, which the Q&A names as the primary integration target and transition owner. [1] GPNTS is the Navy's primary shipboard PNT system, an open-architecture development hosting the M-code MGUE card, with M-code and NoGAPSS upgrade kits from FY2025 procurements installing in FY2026. [5] The topic identifies GPNTS as the shipboard integration baseline for ingesting alternate PNT sources via ASPN and pntOS message standards. [1]

The proposed transition model has three steps:

- **Phase I — Feasibility and interface alignment.** Establish software feasibility on ASPN/pntOS synthetic streams in an air-gapped containerized runtime; deliver a Phase II transition plan and GPNTS interface mapping.
- **Phase II — Prototype maturity and GPNTS integration.** Ingest representative GPNTS message formats, validate against representative Navy data sources, and conduct Government-SME design reviews subject to the appropriate research-determination process.
- **Phase III — Program-of-record insertion.** Transition the software module into GPNTS acquisition baselines as a decision-support extension for bridge displays and navigation consoles.

This pathway is a proposed technical alignment strategy. It does not imply Government endorsement, acquisition commitment, or a pre-awarded Phase III contract.

### 3.3 Potential Commercial Applications

The reusable asset is not a navigation display; it is a software module that takes heterogeneous source feeds, applies a compiled rule library derived from that domain's guidance, and presents source health, a transparent composite, named missing evidence, and bounded recommendations. Changing domains means changing the source adapters and re-running the training loop over different guidance — the module and its evaluation harness stay the same. Application areas follow the topic's Phase III list. [1]

- **Commercial shipping and logistics.** Bridge crews face the same fault-versus-jamming-versus-spoofing triage the ETV faces, in the same straits; Maritime Advisory 2026-008 (active, expires 21 October 2026) directs them to plan for it before departure. [2] A unified awareness layer fed by a ship's existing GNSS, inertial, and timing sources is the direct commercial analogue.
- **Aviation operations.** Operations centers monitoring GNSS-dependent approaches and GNSS-derived surveillance need the same distinction between source agreement and independent corroboration.
- **Critical infrastructure and telecommunications timing.** Networks, data centers, and grid operators depend on GNSS-disciplined timing; a source-health and composite view with named missing evidence applies to timing references as well as position.
- **Autonomous transportation and industrial automation.** Vehicle and plant supervisors need to know when a localization solution is being trusted on the basis of correlated inputs.
- **Public safety and enterprise operations centers.** Dispatch and fleet operators need a bounded recommendation, not a forced diagnosis, when location feeds disagree.

All commercial opportunities are prospective. No commercial sales, private revenue, or customer commitments are claimed for Phase I.

### 3.4 Customer Evidence and Letters of Interest

DeepBlue Dynamics has no existing customers for this capability and does not claim any. [confirm] During Phase I the firm will present the prototype and evidence package, through the TPOC, to the GPNTS program office and to [commercial fleet operators, port authorities, and PNT integrators to identify], to elicit feedback on security, data, and integration requirements and to seek letters of interest supporting the Phase II proposal. Any letter obtained will be included in Volume 5 without being characterized as a commitment.

### 3.5 Proposed Milestones

All milestones are proposed engineering targets.

- **Month 6 (proposed).** Complete the Phase I feasibility report; measure the proposed <100 ms gate from input receipt at the system boundary to the first displayed frame containing both the alert and initial recommendation, with security enabled. Any event ≥100 ms fails the proposed gate; the Government's <1 s requirement is reported separately; a failed proposed gate is a reported feasibility limitation, not a waiver. Verify air-gapped operation.
- **Phase II (contingent on award and interface access).** Complete prototype integration with GPNTS message interfaces and ASPN/pntOS live streams.
- **Phase III preparation (contingent on transition agreements).** Prepare the Phase III transition package and a commercial software licensing model; resolve applicable deployment and container-hardening requirements with the Government.

### 3.6 Intellectual Property and Data Rights

[Company to confirm background intellectual property, ownership, and proposed restrictions for Volume 5.] Award-generated software and technical data will be delivered with rights and markings consistent with the applicable contract clauses.

---

## FACILITIES/EQUIPMENT

DeepBlue Dynamics proposes to perform the effort at [U.S. performance location to confirm]. [Company to identify available office space, workstations, instrumentation, local build infrastructure, and test network.] Development and synthetic-data evaluation will use local workstation compute and simulation tools. [Company to confirm equipment availability, any purchases, and consistency with Volume 3.]

The full application will operate in a secured, air-gapped environment. Applicable CUI handling and assessment requirements will be confirmed with the Government before affected performance. [Company to confirm the existing environment, required remediation, and assessment status against the Topic Q&A of 28 August 2026.] No accreditation or assessment completion is claimed. [1]

[Company to confirm that the performance facilities meet applicable federal, state, and local environmental laws and regulations concerning airborne emissions, waterborne effluents, external radiation, outdoor noise, solid and bulk waste, and toxic or hazardous materials.]

---

## REFERENCES

[1] Department of the Navy, DoW 2026 SBIR CSO Release 5, Open Topic DON26BX05-NP004, "NAVWAR Open Topic for Unified Assured Positioning, Navigation, and Timing Operational Awareness and Decision Support," topic text and Topic Q&A (answers dated 1 Jul–1 Sep 2026). https://www.navysbir.com/n26_5/DON26BX05-NP004.htm (public mirror; DSIP is controlling). Accessed 7 Sep 2026.

[2] U.S. Maritime Administration, U.S. Maritime Advisory 2026-008, "Global – U.S. Maritime Advisory Updates, Resources, and Contacts" (active; expires 21 Oct 2026). https://www.maritime.dot.gov/msci/2026-008-global-us-maritime-advisory-updates-resources-and-contacts

[3] National Institute of Standards and Technology, Special Publication 800-190, "Application Container Security Guide." https://csrc.nist.gov/pubs/sp/800/190/final

[4] Office of the Chief of Naval Operations, OPNAVINST 9420.1C, "Positioning, Navigation and Timing Policy," 30 Sep 2019, paragraphs 5a(3) and 5a(11). https://www.secnav.navy.mil/doni/Directives/09000%20General%20Ship%20Design%20and%20Support/09-400%20Command%20and%20Surveillance%20Systems%20Support/9420.1C.pdf

[5] Department of the Navy, Exhibit P-40 Budget Line Item Justification, PB 2025, Other Procurement Navy, Line Item 2657 "NAVSTAR GPS Receivers (Space)," March 2024, pp. 1–2. [Cite the official Navy FY2025 OPN justification book; an unclassified secondary copy was used for drafting.]

[6] U.S. Government Accountability Office, GAO-22-106010, "GPS Alternatives: DOD Is Developing Navigation Systems but Is Not Measuring Overall Progress," 5 Aug 2022. https://www.gao.gov/products/gao-22-106010

[7] U.S. Coast Guard Navigation Center, "GPS Problem Report Status," marine entries June–August 2026. https://www.navcen.uscg.gov/gps-problem-report-status Accessed 7 Sep 2026.

[8] International Maritime Organization, Resolution MSC.302(87), "Adoption of Performance Standards for Bridge Alert Management," 2010. [Verify citation; supports "IMO alert and integrity guidance" in Section 1.0.5.]

[9] U.S. Department of Homeland Security, "Resilient Positioning, Navigation, and Timing (PNT) Conformance Framework," Version 2.0, 2022. [Verify citation and version; supports "resilient-PNT frameworks" in Section 1.0.5.]

---

## FIGURES

- **Figure 1 — Notional console sketch** (existing: notes/hmi-mockups/remarkable/fig_console_sketch-8.png). Alert banner with acknowledge, resolution options, chart area, source roster, event log.
- **Figure 2 — High-level architecture** [to produce]. Source adapters → normalization (identity, health, confidence, age, dependencies, missingness) → compiled rule engine → deterministic alert/recommendation path → display; keyed retrieval and optional local model on the drill-down path only; tamper-evident audit trail; single Iron Bank-based container boundary.
- **Figure 3 — Combative-training loop** [to produce]. Scenario generator with evaluator-held truth → development-environment model exercising the retrieval tools → candidate rules and tests with guidance citations → human review, versioning, regression → compiled rules shipped. Frozen held-out set drawn outside the loop.
- **Figure 4 — Phase I base schedule** (table in Section 1.2; Gantt rendering to produce).
- **Figure 5 — Evidence trace / drill-down** [to produce]. A displayed INDETERMINATE alert resolving to its supporting observations (with ages and shared dependencies), the rule version and guidance clause that produced it, and the named cross-check that would resolve it.
