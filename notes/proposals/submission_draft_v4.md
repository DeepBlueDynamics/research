<!-- DRAFT v4 — Claude ACME sub-structure interleaved with Grok gates.
     2026-09-07. Does not overwrite v1/v2/v3.
     Not for DSIP until company facts are filled and the volume is
     typeset in 10-point proportional type under ten pages. -->

DeepBlue Dynamics | DON26BX05-NP004 | Phase I Technical Proposal (draft v4)

# 1.0 Description of Proposed Phase I Technical Effort

## 1.0.1 Introduction

DeepBlue Dynamics [together with consultants — none currently proposed; confirm] is pleased to submit this proposal to develop SEXTANT, the offeror code name for a unified assured positioning, navigation, and timing (APNT) awareness and decision-support interface, in response to Department of the Navy Open Topic DON26BX05-NP004, “NAVWAR Open Topic for Unified Assured Positioning, Navigation, and Timing Operational Awareness and Decision Support.” [1] SEXTANT is an offeror designation, not a Navy program name or endorsement.

The team maps to what the topic asks for — data integration, analytics, and decision-support — rather than new navigation algorithms. Principal Investigator Mr. Kord Campbell [PI designation to confirm] and software lead Mr. Clint Robison [title to confirm] are described in Section 2.0. The intended Government customer is NAVWAR; the Topic Q&A names GPNTS as the primary integration target and transition owner. [1] That is the intended path, not a claim that GPNTS has selected or endorsed this firm.

## 1.0.2 Identification of the Problem

Consider a destroyer transit through a GPS-degraded strait. The electronics technician–navigation (ETV) is looking at several physical displays, each reporting on one positioning or timing source. Two feeds agree. A third disagrees, then goes stale. The technician must decide, in minutes, what information is still credible, which assumption has failed, and what evidence would justify the next response. DON26BX05-NP004 identifies exactly this condition — fragmented APNT displays — as an obstacle to timely understanding and decisions, and asks for a coherent assessment with an understandable basis rather than one more isolated indicator. [1]

The condition is current, not hypothetical. U.S. Maritime Advisory 2026-008 alerts mariners to worldwide GPS disruption and directs them to plan responses before departure. [2] Policy, program, and recent marine disruption evidence are in Section 1.4.

Three failures make the fragmented-display problem harder than aggregation. First, agreement is not corroboration: two sources can agree because they share a compromised dependency, and a display that averages them reports false confidence. Second, the available observations often cannot distinguish a receiver fault from jamming from spoofing; a display that forces a diagnosis will sometimes be confidently wrong. Third, data ages and goes missing; a display that silently drops a stale field removes the evidence the operator needs to judge the rest. Current fragmented displays leave all three burdens on the technician.

The desired tool keeps individual source health visible, adds a transparent composite whose basis can be inspected, names missing evidence, and offers informational recovery options with their prerequisites — without adding sensors, replacing the navigation solution, or actuating any ship control. [1]

## 1.0.3 The Opportunity

The intent of this Phase I SBIR is to research and develop a software interface that presents source health, a separately explained composite assessment, and prerequisite-bound informational recommendations for 3–8 simultaneous PNT sources at 1–10 Hz, running air-gapped and secured, with a proposed initial response under 100 milliseconds (Government requirement under one second). [1]

The central hypothesis is that making dependencies and unresolved uncertainty visible will help operators find decision-relevant evidence more effectively than aggregation alone. Phase I tests technical feasibility of that design and produces the evidence needed to justify an appropriately authorized operator-effectiveness evaluation later. No operator-performance gain is claimed until it is measured.

Success is redefined. A confident answer unsupported by the available evidence fails, even when it happens to match hidden truth. Permanent uncertainty fails cases where a useful response is supported. Nominal, recoverable, and unresolved scenarios are therefore tested together, with evaluator truth isolated from operational inputs. Recovery transitions test whether the interface updates its recommendation when credible evidence returns.

**Scope boundaries.** No new sensors, timing hardware, or ownship-fix / navigation-solution algorithms; not a replacement navigator; informational recommendations only. ECDIS-inspired layout is a familiarity target, not a certification claim. The simulator is feasibility infrastructure; the product is the interface. [1]

## 1.0.4 Contractor Experience

Phase I starts from four development assets, not a fielded APNT product: an unclassified ASPN/pntOS interface library; a vendored local retrieval engine; a nemesis8 prototype container on an Iron Bank base; and the notional SEXTANT layout in Figure 1. Section 1.3 states what is reused versus new. Personnel are in Section 2.0.

## 1.0.5 Innovative Approach Overview

SEXTANT is a trainable, retrieval-augmented pipeline that drives an operator display. It ships as one Iron Bank-based container carrying retrieval tools, reference documents, the index, compiled decision rules, and the display. Figure 2 is the architecture: sources → bus → rules → screen. The air-gap surrounds everything except the sources and the evaluation scaffolding. The hot path has no language model. The simulator and held-out labels sit outside the product and unplug in Phase II. Five design choices distinguish the console from an aggregating dashboard.

**Evidence-preserving composite.** Each source is normalized while retaining identity, health, confidence, age, known dependencies, and explicit missingness. Sources speak ASPN internally; other Navy messages enter through thin adapters. Integrity-unavailable feeds never drive a decision. The composite is derived and explained separately; unknown dependencies stay marked unknown. An ordinal confidence label is never a calibrated probability. Roster and composite stay on screen together.

**Deterministic alert path.** A bounded code path presents the alert and initial informational recommendation. The latency gate is defined once, in Section 1.1. No language model participates. A local model, if present, writes drill-down explanation after the alert; if absent, the initial response is unchanged.

**Rules from guidance, via combative training.** Decision rules are deterministic code derived from public PNT interface standards, IMO bridge-alert management guidance, the DHS resilient-PNT conformance framework, and representative procedures the Q&A permits performers to define. [1][8][9] Figure 3 is the development-time loop, run in Task B3: (1) a scenario generator produces fault, jamming, spoofing, shared-dependency, stale/missing, and recovery cases and keeps the truth; (2) in the development environment only, a language model uses the pipeline’s own tools to write cited rule code and tests; (3) people review, version, and regression-test — only compiled rules, the index, reference data, and versioned procedures ship; (4) labelled runs become the regression suite, kept apart from frozen held-out cases. Agents touch training scenarios only, simulated in Phase I. Audit records are shaped for later offline retraining; representative Government data is expected only in Phase II.

**Explicit unresolved state.** When observations cannot discriminate among fault, jamming, and spoofing, the rules produce INDETERMINATE. The console names the accessible cross-check and offers acknowledge. If no discriminating evidence is accessible, it states that limit. No-win cases reward this; nominal and recoverable cases penalize abstention when the evidence supports a response.

**Keyed retrieval.** Before seal, every reachable anomaly state is mapped to its recommendation, procedure, and evidence layout. At runtime the screen looks up that key (design target under 30 microseconds, unmeasured). Semantic search is drill-down only, so retrieval never threatens the latency gate (Section 1.1). Every assessment resolves to its evidence and rule version (Figure 5). A local bus is the only path between components. The image is built from pinned, hash-verified packages with an SBOM; a failed security control fails the build. Whether the Phase I demonstration must run on an Iron Bank image is a Government question; an isolated containerized demonstration is highly encouraged. [1] [3]

**Figure 1.** Notional SEXTANT display (embed a still; counts toward the ten-page limit). Banner and acknowledge; source roster; composite tiles that never replace the roster; informational COA cards with prerequisites; evidence on drill-down. Schematic chart, not an ENC; not certified ECDIS.

**Figure 2.** Sources → bus → rules → screen. Air-gap around everything except sources and scaffolding. No model on the hot path. Retrieval keyed off the initial render.

# 1.1 Phase I Technical Objectives

The six-month base will answer three questions: can the interface preserve and explain multi-source evidence; can it distinguish supported recommendations from unresolved alternatives; and can it do so within a secured, air-gapped envelope that meets the latency gate below? The prototype will, at a minimum:

1. **Model the source data** — normalize synthetic ASPN/pntOS inputs (3–8 sources at 1–10 Hz), retaining identity, health, confidence, age, dependencies, and explicit missingness. [1]
2. **Build the rule library from guidance** — cited, versioned, human-reviewed deterministic rules via combative training, including INDETERMINATE when evidence cannot support a conclusion.
3. **Derive a separately explained composite** — confidence and triage (fault versus jamming versus spoofing) that resolves to evidence and rule version and that distinguishes agreement from independent corroboration.
4. **Support decisions** — versioned informational recommendations with prerequisites; name the accessible cross-check; update on recovery.
5. **Run secured and air-gapped** — full stack, offline cold start, container image built from an Iron Bank base (hardening-ready, not accredited), least privilege, role-limited access, verified offline packages/SBOM, protected data and keys, tamper-evident audit. [3]
6. **Establish measured feasibility** — frozen held-out scenarios against an identical-input synthetic fragmented-display surrogate and an explanation-disabled unified view. The surrogate is a test control, not a validated fleet baseline.

Objectives 1–2 by B2; 2–4 by B3; 5–6 by B4–B5. Option tasks O1–O3 do not reopen the frozen base set except as versioned regression.

The source envelope (3–8 sources at 1–10 Hz), the Government’s sub-second response, air-gapped operation, and secured runtime are fixed constraints. [1] Other numerical thresholds are offeror-proposed. Freeze threat model, hardware, loads, oracle, and held-out cases before tuning.

**Latency gate (stated once; later sections refer to it by name).** Government requirement: under one second from ingestion to presentation of the alert and initial recommended course of action; reported separately. [1] Offeror gate: under 100 milliseconds from input receipt at the system boundary to the first displayed frame containing both the alert and the initial recommendation, hardened configuration, monotonic clock, queueing and actual frame included. Rationale: headroom for Phase II GPNTS integration. Test: 3/8-source × 1/10-Hz corners, mixed rates, and local-model failure; report every event, maximum, distribution, and drops. Any missing response or event at or above 100 milliseconds fails the offeror gate. Uncertainty overlapping 100 milliseconds is not a pass. A failed offeror gate is a reported feasibility limitation, not a waiver of the Government requirement.

| Gate | Measurement | Fails if |
|---|---|---|
| Air-gapped operation | Cold-start ingestion, UI, analytics, retrieval, inference, and replay with external interfaces disconnected; only declared internal communications. | Any attempted external communication or offline functional failure. |
| Secured runtime | Inspect effective controls; exercise denied access, modified packages, and audit tampering. [3] | Any mandatory-control failure or unremediated applicable high/critical vulnerability. |
| Evidence fidelity and replay | Across held-outs and three repeats, every assessment and recommendation resolves to input evidence and rule version; required fields preserved or marked missing. | Any silent loss, unsupported citation, or unexplained analytical replay mismatch. |
| Useful, bounded recommendations | 60 frozen cases: 20 nominal, 20 recoverable, 20 unresolved, spanning fault/jam/spoof, shared dependencies, missing/stale data, and recovery; at least six recoverable cases per fault, jamming, and spoofing class. | Any unsupported definitive claim or prerequisite violation in an unresolved case; fewer than 18/20 acceptable in nominal or recoverable; any predeclared critical-case oracle failure; any claim contradicted by observable evidence. |
| Information access | On 12 frozen tasks, required evidence reachable and complete; no critical legibility or priority defect under a predefined checklist. Compared to the fragmented surrogate and the explanation-disabled view. | Any unreachable or incomplete required evidence, or any critical checklist defect. Counts are workflow proxies; no promised percentage improvement. |

These case counts support feasibility testing, not fleet reliability claims. No research on human participants is proposed. Topic Q&A dated 1 September 2026 is not treated as a human-research exemption. CUI handling scope must be resolved with the Government; synthetic data do not establish public releasability. Whether an Iron Bank image is required for the Phase I demonstration remains an open Government question; the secured-runtime gate applies regardless. [1]

# 1.2 Phase I (Base and Option) Statement of Work

DeepBlue Dynamics will perform all tasks at [U.S. performance location to confirm] on synthetic ASPN/pntOS-conformant data. The evaluation plan is frozen before tuning. Existing firm software (Section 1.3) is reused where it fits. The base effort requires no human-subject research, shipboard access, or Government-furnished equipment. Hours will match Volume 3 and Section 2.0 before submission.

**Figure 4. Phase I base schedule** (bars are planned spans, not demonstrated progress).

| Task | M1 | M2 | M3 | M4 | M5 | M6 |
|---|:-:|:-:|:-:|:-:|:-:|:-:|
| B1 Requirements, architecture, evaluation plan | ■ | ■ | | | | |
| B2 Source ingestion and scenario simulation | ■ | ■ | ■ | | | |
| B3 Rule library, interface, local decision support | | ■ | ■ | ■ | | |
| B4 Secured runtime and measured evaluation | | | ■ | ■ | ■ | ■ |
| B5 Findings and Phase II preparation | | | | | ■ | ■ |
| Reviews | Kickoff | TPOC review | Progress | | | Final demo |

Option from exercise: O1 months 1–2; O2 months 2–4; O3 months 4–6; reviews at option months 1, 3, and 6.

## Base period: six months from award

**B1. Requirements, architecture, and evaluation plan. Months 1–2. Performer: DeepBlue Dynamics.** Translate the topic, the Q&A, and Section 1.1 into a requirements-to-test matrix: each requirement paired with its test and pass/fail rule. Define source interfaces, evidence dependencies, threat model, failure states, and the secured offline runtime. Separate development scenarios from a frozen held-out set. Document hardware, workloads, timestamp boundaries, and measurement uncertainty. Provide the architecture and evaluation plan to the Government Technical Point of Contact for review at the end of Month 2; comments received will be addressed before the held-out set is frozen. This is a review, not a CSO-required hold point.
Deliver: kickoff briefing (Month 1); architecture; evaluation plan and requirements-to-test matrix.

**B2. Source ingestion and scenario simulation. Months 1–3. Performer: DeepBlue Dynamics.** Adapters and a repeatable simulator for 3–8 sources at 1–10 Hz. Identity, health, confidence, and age preserved; missing fields shown as missing, never invented. Nominal, recoverable, and unresolved cases spanning faults, jamming, spoofing, stale data, and shared dependencies. Combative-training scenarios generated with evaluator-held truth, separate from the frozen held-out set. Simulator truth never enters the inference path.
Deliver: interface schema; versioned fixtures; replay harness; training scenario set.

**B3. Rule library, explainable interface, and local decision support. Months 2–4. Performer: DeepBlue Dynamics.** Unified display, evidence-based confidence and triage, prerequisite-bound recommendations, and INDETERMINATE with acknowledge. Initial alert and recommendation on a deterministic path independent of language-model generation. Retrieval, optional inference, and detailed explanations run locally; initial functionality is retained if the local model fails. Run the combative-training loop in Section 1.0.5. Key the retrieval index by anomaly state; measure keyed-lookup latency against the 30-microsecond target (unmeasured until B4).
Deliver: integrated feasibility prototype; evidence-linked traces; rule provenance (rule → guidance clause).

**B4. Secured runtime and measured evaluation. Months 3–6. Performer: DeepBlue Dynamics.** Package the full stack for offline cold start. Verify the Section 1.1 air-gap and secured-runtime controls. Attack unauthorized access, a tampered package, and an edited audit record. Run the latency gate (Section 1.1) with security on: four 30-minute corners (3 and 8 sources × 1 and 10 Hz), a 30-minute mixed-rate sweep, a 60-minute soak at 8 sources and 10 Hz with bursts, at least 1,000 scored events, every one reported. Run the frozen 60-case evaluation, critical-case checks, three repeats, and the twelve information-access tasks against the fragmented-display surrogate and the explanation-disabled configuration. Report every miss. Infer nothing about fleet reliability or operator performance.
Deliver: test evidence; security findings; feasibility assessment; training dataset; rule provenance; regression results.

**B5. Findings and Phase II preparation. Months 5–6. Performer: DeepBlue Dynamics.** Demonstrate the prototype against recorded evidence, objective by objective. Name remaining risks, interface dependencies, and corrective work. Write the final report and the initial Phase II proposal with integration milestones and a transition plan.
Deliver: demonstration; final technical report; initial Phase II proposal.

**Feasibility analysis (B4/B5).** Combine: Section 1.1 gates with every failure reported; security findings; development risk (reused versus new, GPNTS ICD dependency); extensibility of adapters and rules; user acceptability deferred (information-access counts only); cost in Volume 3. Where alternatives score equivalently, solicit TPOC input before recommending one.

**Reporting.** Kickoff Month 1, progress Month 3, final demo and report Month 6; draft final report three weeks before period end. Products: prototype package, interface documentation, scenario/replay package, training dataset, rule provenance, evaluation evidence, data-rights markings.

## Option period: six months from exercise

The option advances Phase II preparation and bridges the funding gap. Exercise is contingent on Government action following Phase II selection. Option work does not depend on access to a ship or an operational system.

**O1. Resolve feasibility findings. Option months 1–2. Performer: DeepBlue Dynamics.** Address prioritized base-period deficiencies and extend scenario coverage. Preserve original evaluation results; measure change with separately versioned regression and challenge sets.
Deliver: updated prototype; issue disposition; regression evidence.

**O2. Prepare integration and deployment. Option months 2–4. Performer: DeepBlue Dynamics.** Refine the GPNTS-facing interface plan from available authorized specifications; say plainly where assumptions stand in for specifications that are not. Exercise interface emulators, offline installation and update, and resource budgets on the declared test platform.
Deliver: interface-control draft; deployment package; dependency register.

**O3. Establish Phase II readiness. Option months 4–6. Performer: DeepBlue Dynamics.** Repeat performance and security gates after option changes. Refine the Phase II schedule, verification criteria, and transition risks. If operator research is proposed for Phase II, prepare the determination and approval plan that must precede it.
Deliver: option demonstration; updated evidence package; final option report; Phase II execution plan.

Option reviews: kickoff in option month 1, progress in month 3, final review and report in month 6. Accreditation, ECDIS certification, and operational deployment are outside this statement of work.

# 1.3 Related Work

What exists is a public unclassified corpus, reusable software, and design tooling — not a GPNTS-integrated product, not a certified navigation display, and not a measured operator result. Phase I reuses the container, the local hybrid retrieval service, and the notional display driver as the starting runtime; adapters, compiled decision rules, the frozen evaluation harness, and measured latency, isolation, and security evidence are the new work.

**1.3.1 PNT interface reference corpus (internally funded).** Provenance-tracked public ASPN/pntOS material, topic, Q&A, and CSO. Phase I standards source and combative-training document base. Not GFI; does not include Phase II ICDs. Period: [to confirm].

**1.3.2 Hybrid retrieval engine (internally funded).** Vendored lexical/vector/graph search. Phase I adapts it to keyed anomaly-state lookup (30 µs target, unmeasured) and to semantic drill-down. Not yet measured under the Section 1.1 latency gate. Period: [to confirm].

**1.3.3 nemesis8 container prototype (internally funded).** Iron Bank base image packaging retrieval tools, reference data, and display driver. Hardening-ready, not accredited or fielded. Phase I adapts and measures it under the secured-runtime gate. Period: [to confirm].

**1.3.4 Notional SEXTANT layout (Figure 1).** ECDIS-inspired familiarity target for the ETV. Not certified ECDIS, not real chart data, not an S-57/S-52/NMEA claim.

**1.3.5 Principal Investigator — prior commercial work.** Mr. Campbell’s prior systems (Grub, Splunk, Loggly, FeatureBase) ingest high-rate heterogeneous machine data and present it for operator decision. None is a PNT or Navy program. Publications and roles: Section 2.1.

**1.3.6 Software lead — prior work.** Mr. Robison’s production pipelines and operator-facing interfaces, plus DoD programming work and Navy EM4 service, are shipboard context for the interface. Not presented as GPNTS or APNT-specific expertise. Roles: Section 2.2.

**1.3.7 Consultants.** [None currently proposed. If a consultant is added, list prior work here and effort share in Section 2.3.]

No prior, current, or pending Government support for similar work is claimed; if any exists, client, point of contact, and dates belong in Volume 5.

# 1.4 Defense Need

The Topic Q&A names the GPNTS program of record as transition owner, Phase II ICDs as Government-furnished information, no shore interface, and Phase I on synthetic ASPN/pntOS data. [1] Exhibit P-40, OPN Line Item 2657 (March 2024) describes GPNTS as the Navy’s primary PNT system — open architecture, hosting the M-code MGUE card — with FY2025 M-GUE and NoGAPSS kits installing in FY2026 (secondary copy of the unclassified exhibit). [5] Phase I maps to GPNTS modularly; interface documents arrive in Phase II. This is not a claim that GPNTS selected or endorsed this firm.

The preferred Phase I use case is a destroyer transit through a GPS-degraded or spoofed strait. The intended user is the ETV. An ECDIS-like layout is a familiarity target, not a certification claim. [1]

OPNAVINST 9420.1C paragraph 5a(3) requires a DoD-approved primary and a GPS-independent alternate; paragraph 5a(11) requires new PNT systems to indicate degradation from jamming, multipath, weather, terrain, or spoofing. [4] GAO-22-106010 (5 August 2022) reported incomplete Navy alternative-PNT business cases and no Oversight Council progress metrics. [6] A unified awareness layer that reports degradation together with its evidence addresses the presentation half of what paragraph 5a(11) requires.

Closed NAVCEN GPS Problem Reports, June–August 2026, include Red Sea jamming and spoofing, Fujairah multi-vessel disruption, Baltic interference, and GPS failure southeast of Sweden; each closed with no constellation anomaly. [7] U.S. Maritime Advisory 2026-008 directs pre-departure planning for GPS disruption. [2]

The topic identifies fragmented physical displays as increasing workload and slowing decisions. [1] The increment is one workflow for triage (fault versus jamming versus spoofing) and fallback: a unified air-gapped informational console that keeps source health visible, adds a transparent composite, and names missing evidence — without new sensors, ownship-fix algorithms, or ship control. No operator-performance gain is claimed until measured. Dual-use follows the topic’s Phase III list (Section 3.3).

# 2.0 Key Personnel

Resumes are not attached separately; this section counts toward the ten-page limit. Nothing below has been checked against employer, academic, or military records.

## 2.1 Principal Investigator

**Name:** Kord Campbell. **Title:** Founder, DeepBlue Dynamics [PI designation to confirm]. **Employer:** DeepBlue Dynamics [confirm primary employment at award and during performance]. **Clearance:** [to confirm; none required for the Phase I base as proposed]. **Foreign person:** [confirm]. **Education:** University of Central Oklahoma, computer science and mathematics, 1990–1995 [degree conferral to confirm].

**Qualifications / experience.** Two decades founding and operating search and data systems over high-volume machine data: DeepBlue Dynamics (2019–present; software in Section 1.3); CAIO, FeatureBase (2022–2023); founder/CEO, Loggly (2009–2012); Director of Developer Marketing, Splunk (2007–2009); founder/CEO, Grub, Inc. (2000–2003, acquired 2004).

**Publications.** “Building Self-Aware Machines,” Lucidworks Activate 2018. Internet-Draft, “Agentic Hypercall Protocol (AHP): Tool Invocation, Blind Settlement, and Portable Reputation over HTTP,” IETF Datatracker, 2026 [authorship and draft name to confirm].

**Proposed role.** Direct the technical approach and architecture; own evidence-retrieval, rule-synthesis, and explanation design; lead Government interaction; write the transition and commercialization plan (objectives 2–4, B3, B5). **Effort:** [base hours / option hours to confirm].

## 2.2 Software Lead

**Name:** Clint Robison. **Title:** [to confirm]. **Employer:** DeepBlue Dynamics [start date to confirm]. **Clearance:** [to confirm]. **Foreign person:** [confirm]. **Education:** University of Central Oklahoma, computer science, 1999–2003 [degree conferral to confirm].

**Qualifications / experience.** Full-stack production delivery (Python, PostgreSQL, Linux, Docker, CI/CD): Behold BI (2024–2025); Apkudo (2022–2024); Incyte Studios (2020–2022); Cognizant (2018–2019, clearinghouse workflow connecting 340,000 providers). DoD computer scientist (2002–2003). Navy EM4, USS *Kalamazoo* (AOR-6), 1993–1996 — shipboard context, not GPNTS or APNT expertise. A proposed bridge-watchstander description is **not used** until he confirms watchstations, qualifications, dates, and any ECDIS training.

**Publications.** None listed.

**Proposed role.** Implement ingestion and normalization, the containerized secured runtime, the operator interface, and the evaluation harness; run the latency, isolation, and security tests (objectives 1, 5–6, B2, B4). **Effort:** [base hours / option hours to confirm].

## 2.3 Subcontractors and Consultants

[None currently proposed; confirm.] If any are added, this section will state name, employer, role, and percentage of base and option effort, and the small-business performance minimum will be verified against Volume 3. [Suggested, to confirm: a navigation subject-matter consultant in Phase II for operator-evaluation design — not Phase I.]

## 2.4 Intellectual Property Arrangements

[Company to confirm background intellectual property — reference corpus, retrieval engine, nemesis8 tooling — ownership, and any proposed restrictions for Volume 5.] No consultant IP-sharing agreement exists to describe.

## 2.5 Prior, Current, or Pending Support of Similar Proposals or Awards

DeepBlue Dynamics has no prior, current, or pending support for a similar proposal or award. [confirm]

# 3.0 Commercialization/Transition Plan Summary

## 3.1 Anticipated Phase I results

Phase I produces the requirements-to-test matrix, frozen evaluation set, measured prototype, evidence package, and initial Phase II proposal. Independent of Phase II: the cited rule library, labelled training dataset and replay harness, secured offline packaging, and ASPN/pntOS interface schema. Phase II extends along designed seams — adapters separable from rules, rules recompiled from extended guidance, audit shaped for offline retraining, alert path separate from explanation. Phase III, funded from other sources, would be program-of-record integration.

## 3.2 Defense transition

The primary DoD transition target is GPNTS (Q&A: integration target and transition owner). [1] [5] Phase I: synthetic ASPN/pntOS feasibility and an interface mapping. Phase II (if awarded, and if authorized interfaces are available): representative GPNTS formats; any Government-SME reviews only after the appropriate research-determination process — not Phase I work. Phase III (if transition agreements exist): insertion as a decision-support extension. No endorsement, acquisition commitment, or pre-awarded Phase III contract is implied.

## 3.3 Potential commercial applications

The reusable asset is not a navigation display. It is a software module that takes heterogeneous source feeds, applies a compiled rule library derived from that domain’s guidance, and presents source health, a transparent composite, named missing evidence, and bounded recommendations. Changing domains means changing adapters and re-running the training loop. Application areas follow the topic’s Phase III list. [1]

The first dual-use segment is commercial shipping and logistics operations centers that already fuse multiple navigation feeds and must plan for GPS disruption. Maritime Advisory 2026-008 (active, expires 21 October 2026) directs pre-voyage contingency planning. [2] Aviation operations and critical-infrastructure / telecommunications timing are the next segments. Remaining topic segments (autonomous transportation, industrial automation, public safety, enterprise operations centers) are prospective follow-on markets.

All commercial opportunities are prospective. No commercial sales, private revenue, or customer commitments are claimed.

## 3.4 Customer evidence and letters of interest

DeepBlue Dynamics has no existing customers for this capability and does not claim any. [confirm] During Phase I the firm will present the prototype, through the TPOC, to the GPNTS program office and to [operators and integrators to identify] and will seek letters of interest for Volume 5, not characterized as commitments.

## 3.5 Proposed milestones

All dates are proposed engineering targets.

- **Month 6 (Phase I).** Complete the feasibility report; measure the latency gate (Section 1.1) and the air-gapped secured-runtime gate.
- **Phase II (if awarded, and if authorized GPNTS interfaces are available).** Complete prototype integration with GPNTS message interfaces and ASPN/pntOS streams.
- **Phase III preparation (if transition agreements exist).** Prepare the transition package and a commercial licensing model; resolve applicable deployment and container-hardening requirements with the Government.

## 3.6 Intellectual property and data rights

[Company to confirm background intellectual property, ownership, and proposed restrictions for Volume 5.] Award-generated software and technical data will be delivered with rights and markings consistent with the applicable contract clauses, including DFARS 252.227-7018 (Deviation 2020-O0007) for the period the clause specifies.

# Facilities/Equipment

DeepBlue Dynamics proposes to perform the effort at [U.S. performance location to confirm]. [Company to identify available office space, workstations, local build infrastructure, and test network.] Development and synthetic-data evaluation will use existing commercial workstation compute and open-source tools. **No capital equipment purchases** are requested in Volume 3 [confirm].

The full application will operate in a secured, air-gapped environment. Applicable CUI handling and assessment requirements will be confirmed with the Government before affected performance. Topic Q&A of 28 August 2026 describes CMMC Level 2 (Self-Assessment) against NIST SP 800-171 Rev 2 for this effort; that is a planned control baseline, not a completed accreditation or a CMMC certification claim. [1]

[Company to confirm that the performance facilities meet applicable federal, state, and local environmental laws and regulations concerning airborne emissions, waterborne effluents, external radiation, outdoor noise, solid and bulk waste, and toxic or hazardous materials.]

# References

1. Department of the Navy, DoW 2026 SBIR CSO Release 5, Open Topic DON26BX05-NP004, “NAVWAR Open Topic for Unified Assured Positioning, Navigation, and Timing Operational Awareness and Decision Support,” topic text and Topic Q&A (answers dated 1 Jul–1 Sep 2026). https://www.navysbir.com/n26_5/DON26BX05-NP004.htm (public mirror; DSIP is controlling). Accessed 7 Sep 2026.
2. U.S. Maritime Administration, U.S. Maritime Advisory 2026-008, “Global – U.S. Maritime Advisory Updates, Resources, and Contacts” (active; expires 21 Oct 2026). https://www.maritime.dot.gov/msci/2026-008-global-us-maritime-advisory-updates-resources-and-contacts
3. National Institute of Standards and Technology, Special Publication 800-190, “Application Container Security Guide.” https://csrc.nist.gov/pubs/sp/800/190/final
4. Office of the Chief of Naval Operations, OPNAVINST 9420.1C, “Positioning, Navigation and Timing Policy,” 30 Sep 2019, ¶5a(3) and ¶5a(11). https://www.secnav.navy.mil/doni/Directives/09000%20General%20Ship%20Design%20and%20Support/09-400%20Command%20and%20Surveillance%20Systems%20Support/9420.1C.pdf
5. Department of the Navy, Exhibit P-40 Budget Line Item Justification, PB 2025, Other Procurement Navy, Line Item 2657 “NAVSTAR GPS Receivers (Space),” March 2024, pp. 1–2. [Cite the official Navy FY2025 OPN justification book; an unclassified secondary copy was used for drafting.]
6. U.S. Government Accountability Office, GAO-22-106010, “GPS Alternatives: DOD Is Developing Navigation Systems but Is Not Measuring Overall Progress,” 5 Aug 2022. https://www.gao.gov/products/gao-22-106010
7. U.S. Coast Guard Navigation Center, “GPS Problem Report Status,” marine entries June–August 2026. https://www.navcen.uscg.gov/gps-problem-report-status Accessed 7 Sep 2026.
8. International Maritime Organization, Resolution MSC.302(87), “Adoption of Performance Standards for Bridge Alert Management,” 17 May 2010.
9. U.S. Department of Homeland Security, “Resilient Positioning, Navigation, and Timing (PNT) Conformance Framework,” Version 2.0, 2022.

