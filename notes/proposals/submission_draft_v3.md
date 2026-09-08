<!-- DRAFT v3 — ACME-shaped rewrite. Grok, 2026-09-07.
     After Mild Zebra / Codex heading-swap. Does not overwrite
     submission_draft.md or submission_draft_v2.md.
     Navy Open Topic headings; ACME narrative progression.
     Not for DSIP until company facts are filled and the volume is
     typeset in 10-point proportional type under ten pages. -->

DeepBlue Dynamics | DON26BX05-NP004 | Phase I Technical Proposal (draft v3)

# 1.0 Description of Proposed Phase I Technical Effort

DeepBlue Dynamics, with Kord Campbell as Principal Investigator [PI designation to confirm], proposes a unified APNT operator interface for DON26BX05-NP004, NAVWAR Open Topic for Unified Assured Positioning, Navigation, and Timing Operational Awareness and Decision Support. The intended user is the electronics technician–navigation (ETV) on a Navy combatant. The Phase I product is a single air-gapped container, built on an Iron Bank base, that packages the retrieval tools, the reference documents, the index over them, the compiled decision rules, and the display. It preserves per-source health, computes an explainable composite, and presents an informational alert and initial recommendation on a deterministic path (offeror-proposed under 100 milliseconds; Government requirement under one second). Phase I measures that stack on synthetic ASPN/pntOS streams. It does not integrate live GPNTS or claim a fielded APNT system.

During a destroyer transit through a GPS-degraded or spoofed strait, that technician must answer three questions in the time it takes to look up: what information remains credible, which assumption has failed, and what evidence would justify the next response. DON26BX05-NP004 identifies fragmented APNT displays as an obstacle to timely understanding and decisions. The operational need is a coherent assessment with an understandable basis, rather than an additional isolated indicator. [1] The need has a current maritime context: U.S. Maritime Advisory 2026-008 calls for planning responses to GPS disruption before departure. [2]

The firm’s relevant existing software is not a GPNTS-integrated product. Phase I starts from four development assets: an unclassified ASPN/pntOS interface library (standards source, not GFI); a vendored local retrieval engine for post-alert drill-down; a notional console layout (not certified ECDIS); and a nemesis8 prototype container on an Iron Bank base that already packages retrieval tools, reference data, and the display driver. Hardening-ready is not accredited and not fielded. Section 1.3 states what is reused versus new.

The central hypothesis is that making dependencies and unresolved uncertainty visible will help operators find decision-relevant evidence more effectively than aggregation alone. Phase I tests technical feasibility of that hypothesis and establishes the basis for a later, authorized operator-effectiveness evaluation. It does not claim an operator-performance gain in this period.

Decision rules are compiled, deterministic code derived from public guidance documents before the container is sealed. They are produced by a development-time loop the firm calls combative training (Task B3). A language model is used only in the training room. No model sits on the shipboard alert path. If a local model is present at sea, it may write explanations after the alert is already on screen; the alert does not wait for it.

When the observations cannot tell a fault from jamming from spoofing, a console that guesses is worse than no console. This one states that the cause is not determined (INDETERMINATE), names the accessible cross-check that would determine it, and offers one button: acknowledge. The acknowledgement goes in the audit trail. Evaluation rewards that honesty on no-win cases and punishes it on cases where the evidence supports a decision. Nominal, recoverable, and unresolved scenarios are therefore tested together, so abstention cannot dominate the score.

The work develops no new PNT sensors, timing sources, hardware, or ownship-fix / navigation-solution algorithms. It integrates, assesses, and presents existing-source information. The composite is not a replacement navigator. No ship controls are actuated. Recommendations are informational only. An ECDIS-inspired layout is a familiarity target for the ETV, not an S-57/S-52/NMEA or ECDIS-certification claim. GPNTS integration is planned modularly for Phase II when interface documents arrive. [1]

**Figure 1.** Notional ETV console (embed a still of the working mockup; it counts toward the ten-page limit). Degradation banner and acknowledge at the top; source roster with health, age, and integrity; composite tiles that never replace the roster; informational course-of-action cards with prerequisites; evidence on drill-down. Schematic chart, not an ENC. Not a certified ECDIS. The operator sequence is: see that something broke, see which sources still speak independently, see what would settle the rest, acknowledge if nothing will.

**Figure 2.** Software architecture: sources → bus → rules → screen. The air-gap is a box around everything except the sources and the evaluation scaffolding. Hot path has no language model. Retrieval is keyed by anomaly state and is off the initial render. Simulator and held-out labels sit outside the product and unplug in Phase II.

The air gap is the shape of the system: one container, one host, no network beyond it. The image is built from pinned, hash-verified packages with an SBOM, on an Iron Bank base; a failed security control fails the build. Whether Phase I must run on an Iron Bank image is a Government question; an isolated containerized demonstration is highly encouraged. [1] [3] Sources speak ASPN internally; other Navy messages enter through thin adapters; integrity-unavailable feeds never drive a decision; identity, health, confidence, and age are never collapsed. The compiled core checks each source and whether sources with different failure modes agree, then emits composite, triage (nominal, fault, jamming, spoofing, or INDETERMINATE), evidence, and an anomaly-state key that the screen looks up (design target under 30 microseconds, unmeasured). Retrieval and any model explanation start after the frame. The latency gate is defined once, in Section 1.1. The simulator sits outside the product and unplugs in Phase II; the evaluator holds the truth.

The representative simulation begins with apparently healthy positioning feeds. Two feeds then agree because they share a compromised dependency; a separate reference contradicts them before becoming stale. The operator must distinguish agreement from independent corroboration. The interface shows supporting observations, their age, known dependencies, and the conditions required for each proposed response; unknown dependencies stay marked unknown. A confident answer unsupported by available evidence fails, even when it matches hidden truth. Permanent uncertainty fails cases where a useful response is supported. Recovery transitions test whether the recommendation updates when credible evidence returns. The simulator is feasibility infrastructure; the delivered capability is the interface.

# 1.1 Phase I Technical Objectives

The six-month base will answer three questions: can the interface preserve and explain multi-source evidence; can it distinguish supported recommendations from unresolved alternatives; and can it do so within a secured, air-gapped execution envelope that meets the latency gate below?

**O1—Integrate.** Normalize synthetic ASPN/pntOS-compatible inputs, retain source identity, health, confidence and age, and derive a separately explained composite assessment.

**O2—Support decisions.** Present versioned informational recommendations, prerequisites and traceable evidence; recognize missing corroboration and update on recovery; report INDETERMINATE when the evidence cannot support a definitive conclusion.

**O3—Establish feasibility.** Exercise the secured stack on frozen scenarios against an identical-input synthetic fragmented-display surrogate—a test control, not a validated fleet baseline.

O1 is demonstrated by B2; O2 by B3; O3 by B4–B5. Option tasks OP1–OP3 do not reopen the frozen base evaluation set except as versioned regression.

The source-stated envelope is 3–8 simultaneous sources at 1–10 Hz. [1] The source envelope, the Government’s sub-second response, air-gapped operation, and secured runtime are fixed constraints. The offeror latency gate and the remaining numerical gates are proposed engineering targets. Before tuning, freeze the threat model, hardware profile, payload and load assumptions, test oracle, and held-out cases. Proposed starting coverage is 60 cases: 20 nominal, 20 recoverable, and 20 unresolved, with fault, jam, and spoof indicators, shared dependencies, missing or stale data, and recovery transitions; report counts and outcomes by anomaly class. These counts support feasibility testing, not fleet reliability claims.

**Latency gate (stated once; later sections refer to it by name).** Government requirement: under one second from ingestion to presentation of the alert and initial recommended course of action; reported separately. [1] Offeror gate: under 100 milliseconds from input receipt at the system boundary to the first displayed frame containing both the alert and the initial recommendation, hardened configuration, monotonic clock, queueing and actual frame included. Rationale: headroom for Phase II GPNTS integration. Test: 3/8-source × 1/10-Hz corners, mixed rates, and local-model failure; report every event, maximum, distribution, and drops. Any missing response or event at or above 100 milliseconds fails the offeror gate. Uncertainty overlapping 100 milliseconds is not a pass. A failed offeror gate is a reported feasibility limitation, not a waiver of the Government requirement.

| KPP | Verification and failure |
|---|---|
| Air-gapped operation | Cold-start ingestion, UI, analytics, retrieval, inference, and replay with external interfaces disconnected. Any attempted external communication or offline functional failure fails. |
| Secured runtime | Least privilege, authenticated role-limited access, verified offline packages/SBOM, protected data and keys, tamper-evident audit. Test denied access, modified packages, audit tampering. Any mandatory-control failure or unremediated applicable high/critical vulnerability fails. [3] |
| Evidence fidelity and replay | Required fields or explicit missingness; every assessment/recommendation resolves to input evidence and rule version. Across held-outs and three repeats, any silent loss, unsupported citation, or unexplained analytical replay mismatch fails. |
| Useful, bounded recommendations | Zero unsupported definitive claims or prerequisite violations in unresolved cases. At least 18/20 nominal and 18/20 recoverable acceptable. Every predeclared critical case passes its evidence-based oracle. Report each stratum and failure. |
| Information access | On 12 frozen tasks, required evidence reachable and complete; no critical legibility/priority defect. Compare to fragmented surrogate and explanation-disabled unified view. Workflow proxies only; no promised percentage; no research on human participants. |

The final report will include results, unresolved integration risks, and the Phase II plan. No research on human participants is proposed; Topic Q&A dated 1 September 2026 is not treated as a human-research exemption. CUI handling scope must be resolved with the Government; synthetic data do not establish public releasability. Iron Bank timing remains an open implementation question and does not relax the secured-runtime requirement. [1]

# 1.2 Phase I (Base and Option) Statement of Work

All work is performed by DeepBlue Dynamics at [U.S. performance location to confirm] on synthetic ASPN/pntOS-conformant data. No human-subject research, no shipboard access, and no Government-furnished equipment are required in the base or the option. Assigned personnel and hours will match Volume 3 and Section 2.0 before submission.

**Figure 3.** Phase I schedule (six-month base from award; six-month option from exercise). Bars are planned spans, not demonstrated progress.

| Task | M1 | M2 | M3 | M4 | M5 | M6 |
|---|---|---|---|---|---|---|
| B1 Requirements, architecture, evaluation plan | X | X | | | | |
| B2 Adapters, simulator, training scenarios | X | X | X | | | |
| B3 Display, rules, keyed retrieval | | X | X | X | | |
| B4 Seal, attack, measure | | | X | X | X | X |
| B5 Demonstrate, report, Phase II plan | | | | | X | X |
| Reviews (kickoff / mid / final) | K | | P | | | F |

Option (from exercise): OP1 months 1–2; OP2 months 2–4; OP3 months 4–6; reviews at option months 1, 3, and 6.

## Base period: six months from award

**B1. Decide what “right” means. Months 1–2. Performer: DeepBlue Dynamics.**
Turn the topic and the three questions in Section 1.1 into a requirements-to-test matrix. Fix the source interfaces, the evidence dependencies the console will display, the threat model, the failure states, and the secured offline runtime. Freeze the held-out evaluation set, the acceptable-response sets, the critical cases, and the pass/fail rules before anyone tunes anything. Declare the hardware, the loads, where the clock starts and stops, and the measurement uncertainty.
Deliver: kickoff briefing; architecture; evaluation plan.

**B2. Build the world to break it in. Months 1–3. Performer: DeepBlue Dynamics.**
Adapters and a repeatable simulator for 3 to 8 sources at 1 to 10 Hz. Source identity, health, confidence, and age preserved; missing fields shown as missing, never invented. Nominal, recoverable, and unresolved cases covering faults, jamming, spoofing, stale data, and shared dependencies. Combative-training scenarios generated with their truth held by the evaluator, separate from the frozen held-out set. Simulator truth never enters the inference path.
Deliver: interface schema; versioned fixtures; replay harness; training scenario set.

**B3. Build the screen and the rules behind it. Months 2–4. Performer: DeepBlue Dynamics.**
The unified display. Prerequisite-bound informational recommendations. The INDETERMINATE state with its acknowledge action. The alert path independent of any model. Local retrieval, optional local inference, and drill-down explanations that the alert never waits for. The retrieval index keyed by anomaly state, its lookup latency measured against the 30-microsecond target (a target, not a result).

Rule synthesis (combative training), in this task only: (1) a scenario generator produces faults, jamming, spoofing, shared-dependency agreement, stale or missing data, and recovery, and keeps the truth; (2) in the development environment a language model uses the pipeline’s own tools to write cited rule code and tests; (3) people review, version, and regression-test; only compiled rules, the index, reference data, and versioned procedures ship—the model stays in the training room; (4) labelled runs become the regression suite, kept apart from frozen held-out cases. Agents touch training scenarios only, simulated in Phase I.

Deliver: integrated feasibility prototype; evidence-linked traces; rule provenance from each rule to its guidance clause.

**B4. Seal it, then try to break it. Months 3–6. Performer: DeepBlue Dynamics.**
Package the full stack for offline cold start. Verify the Section 1.1 air-gap and secured-runtime controls. Attack unauthorized access, a tampered package, and an edited audit record. Run the latency gate (Section 1.1) with security on: four 30-minute corners (3 and 8 sources × 1 and 10 Hz), a 30-minute mixed-rate sweep, a 60-minute soak at 8 sources and 10 Hz with bursts, at least 1,000 scored events, every one reported. Run the frozen 60-case evaluation (at least six recoverable cases per fault, jamming, and spoofing class), critical-case checks, three repeats, and the twelve information-access tasks against a synthetic fragmented-display control and an explanation-disabled configuration. Report every miss. Infer nothing about fleet reliability or operator performance.
Deliver: test evidence; security findings; feasibility assessment; training dataset and regression results.

**B5. Say what we learned. Months 5–6. Performer: DeepBlue Dynamics.**
Demonstrate the prototype against the recorded evidence, objective by objective. Name the remaining risks, the interface dependencies, and the corrective work. Write the final report and the initial Phase II proposal with integration milestones and the transition plan.
Deliver: demonstration; final technical report; initial Phase II proposal.

Base reviews: kickoff in month 1, progress report in month 3, final demonstration and report in month 6. Final products: the prototype package, interface documentation, the scenario and replay package, and the evaluation evidence, with data-rights markings.

## Option period: six months from exercise

The option carries the work to the start of Phase II and is exercised on selection for Phase II. It does not depend on access to a ship or an operational system.

**OP1. Fix what the base exposed. Option months 1–2. Performer: DeepBlue Dynamics.**
Work the prioritized deficiencies and extend scenario coverage. Keep the original evaluation results untouched; measure change with separately versioned regression and challenge sets.
Deliver: updated prototype; issue disposition; regression evidence.

**OP2. Get ready to plug in. Option months 2–4. Performer: DeepBlue Dynamics.**
Refine the GPNTS-facing interface plan from whatever authorized specifications are available, and say plainly where assumptions stand in for specifications that are not. Exercise interface emulators, offline installation and update, and resource budgets on the declared test platform.
Deliver: interface-control draft; deployment package; dependency register.

**OP3. Prove it still holds. Option months 4–6. Performer: DeepBlue Dynamics.**
Repeat the performance and security gates after the option changes. Refine the Phase II schedule, verification criteria, and transition risks. If operator research is proposed for Phase II, prepare the determination and approval plan that must precede it.
Deliver: option demonstration; updated evidence package; final option report; Phase II execution plan.

Option reviews: kickoff in month 1, progress report in month 3, final review and report in month 6. Accreditation, ECDIS certification, and operational deployment are outside this statement of work.

# 1.3 Related Work

The Open Topic template requires related work by the PI, firm, consultants, or others. What exists is a public unclassified corpus and design tooling—not a GPNTS-integrated product, not a certified navigation display, and not a measured operator result.

The firm has a provenance-tracked public library of PNT interface material (including ASPN and pntOS) and the current topic, Q&A, and CSO. It is the intended Phase I standards source, not Government-furnished information. A vendored retrieval engine is available for optional drill-down after the initial alert and recommendation (offeror-proposed under 100 ms; Government requirement under one second). A notional console layout (source health, composite, alert, informational recovery options) is design reference only—not certified ECDIS and not real chart data. The firm has prototyped, in its nemesis8 tooling, a container built on an Iron Bank base image that packages the retrieval tools, reference data, and display driver; this is existing firm work and hardening-ready packaging, not an accredited or fielded system.

Phase I reuses that container, the local hybrid retrieval service, and the notional display driver as the starting runtime; adapters, compiled decision rules, the frozen evaluation harness, and measured latency, isolation, and security evidence are the new work.

Phase I will adapt these assets to three-to-eight synthetic ASPN/pntOS streams, keep source health separate from a transparent composite, and run air-gapped with informational recommendations only.

[PI publications, firm product/IP, and consultant prior work to be confirmed.] No prior, current, or pending Government support is claimed; if any exists, client, point of contact, and dates belong in Volume 5.

# 1.4 Defense Need

Q&A names the GPNTS program of record as transition owner, Phase II ICDs as Government-furnished information, no shore interface, and Phase I on synthetic ASPN/pntOS data. That is the intended path, not a claim that GPNTS selected or endorsed this firm.

The preferred Phase I use case is a destroyer transit through a GPS-degraded or spoofed strait. The intended user is the electronics technician–navigation (ETV). An ECDIS-like layout is a familiarity target, not a certification claim.

The topic identifies fragmented physical displays as increasing workload and slowing decisions. The increment is one workflow for triage (fault versus jamming versus spoofing) and fallback: a unified air-gapped informational console that keeps source health visible, adds a transparent composite, and names missing evidence, without new sensors, ownship-fix algorithms, or ship control. No operator-performance gain is claimed until measured.

OPNAVINST 9420.1C paragraph 5a(3) requires a DoD-approved primary and a GPS-independent alternate; paragraph 5a(11) requires new PNT systems to indicate degradation from jamming, multipath, weather, terrain, or spoofing. [4] Exhibit P-40, OPN LI 2657 (March 2024) describes GPNTS as the Navy primary PNT system (open architecture, MGUE M-code); FY2025 M-GUE and NoGAPSS kits install in FY2026 (secondary copy of the unclassified exhibit). [7] GAO-22-106010 (5 August 2022) reported incomplete Navy alternative-PNT business cases and no Oversight Council progress metrics. [6]

Closed NAVCEN GPS Problem Reports, June–August 2026, include Red Sea jamming and spoofing, Fujairah multi-vessel disruption, Baltic interference, and GPS failure southeast of Sweden; each closed with no constellation anomaly. [5]

Phase I establishes synthetic feasibility against a fragmented-display surrogate (a test control, not a validated fleet baseline). Phase II maps modularly to GPNTS when interface documents arrive. Dual-use follows the topic’s Phase III list (for example commercial shipping and logistics, aviation operations, and critical infrastructure monitoring).

# 2.0 Key Personnel

Resumes are not attached separately; this compact section is the personnel content that counts toward the ten-page limit. Nothing below has been checked against employer, academic, or military records. Bracketed items must be filled or confirmed by the company before certification.

## Key personnel summary

| Name and Title | Employer | Qualifications | Foreign Person (Y/N) | Publications |
|---|---|---|---|---|
| Kord Campbell, Founder [PI designation to confirm] | DeepBlue Dynamics | Founder, DeepBlue Dynamics, since September 2019. Prior: CAIO, FeatureBase (2022–2023); founder/CEO, Loggly (2009–2012, time-series search); Director of Developer Marketing, Splunk (2007–2009); founder/CEO, Grub, Inc. (2000–2003, distributed crawler, acquired 2004). University of Central Oklahoma, computer science and mathematics, 1990–1995 [degree conferral to confirm]. | [confirm] | Lucidworks Activate 2018 presentation, “Building Self-Aware Machines.” IETF Internet-Draft on Agentic Hypercall Protocol (AHP), 2026 [authorship and draft name to confirm]. |
| Clint Robison, [title to confirm] | DeepBlue Dynamics [start date to confirm] | Full-stack engineer (Python, PostgreSQL, Linux, Docker, CI/CD): Behold BI (2024–2025); Apkudo (2022–2024); Incyte Studios (2020–2022); Cognizant (2018–2019). DoD computer scientist (2002–2003). U.S. Navy EM4, USS *Kalamazoo* (AOR-6), 1993–1996. University of Central Oklahoma, computer science, 1999–2003 [degree conferral to confirm]. | [confirm] | None listed. |

**Kord Campbell** directs architecture, evidence retrieval, Government interaction, and the transition plan (O2, B3, B5). That maps to the topic’s call for data integration and decision-support, not new navigation algorithms. [base hours / option hours to confirm]

**Clint Robison** implements ingestion, the containerized runtime, the operator interface, the evaluation harness, and the latency, isolation, and security tests (O1, O3, B2, B4). DoD programming work and Navy sea service are shipboard context, not GPNTS or APNT expertise. [base hours / option hours to confirm]

A proposed description of Mr. Robison as a former bridge watchstander with underway-replenishment and tactical-navigation experience is **not used here**. The captured profile supports Navy EM4 service aboard USS *Kalamazoo* only. That sentence may be inserted only after he confirms the watchstations, qualifications, dates, and the source of any ECDIS training.

**Consultants and subcontractors.** [None proposed / list with employer, role, and share of effort. Any consultant affects the two-thirds SBC work calculation in both base and option.]

# 3.0 Commercialization/Transition Plan Summary

## 3.1 Defense transition pathway

The primary Department of Defense transition target is the GPNTS program of record, which the Q&A names as the primary integration target and transition owner. [1] GPNTS is the Navy’s primary shipboard PNT system, is an open-architecture development, hosts the M-code Military GPS User Equipment (MGUE) card, and is fielding M-code and non-GPS-aided positioning (NoGAPSS) upgrade kits with FY2025 procurements installing in FY2026. [7] The topic identifies GPNTS as the primary shipboard integration baseline for ingesting alternate PNT data sources via ASPN and pntOS. [1]

- **Phase I.** Establish software feasibility on ASPN/pntOS synthetic data streams in an air-gapped containerized runtime, delivering a Phase II transition plan and GPNTS interface mapping.
- **Phase II (contingent on award and authorized interface access).** Mature the software into a working prototype ingesting representative GPNTS message formats. Government-SME design reviews, if any, proceed only after the appropriate research-determination process; they are not Phase I work.
- **Phase III (contingent on transition agreements).** Transition the software module into GPNTS acquisition baselines as an enterprise decision-support extension for shipboard navigation consoles.

This pathway is a proposed technical alignment. It does not imply Government endorsement, formal acquisition commitment, or a pre-awarded Phase III contract.

## 3.2 Dual-use commercial markets

The first dual-use segment is commercial shipping and logistics operations centers that already fuse multiple navigation feeds and must plan for GPS disruption. U.S. Maritime Advisory 2026-008 (active, expires 21 October 2026) alerts commercial mariners to worldwide GPS disruption and urges pre-voyage contingency planning. [2] Aviation operations and critical-infrastructure monitoring are the next segments on the topic Phase III list. The remaining topic Phase III segments are prospective follow-on markets. [1]

All commercial opportunities are prospective. No commercial customer, revenue, or commitment is claimed.

## 3.3 Proposed commercialization milestones

All dates are proposed engineering targets, not demonstrated results.

- **Month 6 (Phase I).** Complete the feasibility report; measure the latency gate (Section 1.1) and the air-gapped secured-runtime gate.
- **Month 18 (Phase II, if awarded, and if authorized GPNTS interfaces are available).** Complete prototype integration with GPNTS message interfaces and ASPN/pntOS streams.
- **Month 24 (Phase III, if transition agreements exist).** Finalize the transition package, Iron Bank container hardening as then required, and a commercial dual-use licensing model.

## 3.4 Intellectual property and data rights

DeepBlue Dynamics retains ownership of software and technical data developed under the award; the Government receives the SBIR data-rights license under DFARS 252.227-7018 (Deviation 2020-O0007) for the period the clause specifies. Any assertions of restrictions will be listed in Volume 5. [Fill with a real assertion or “none.”]

# Facilities/Equipment

The proposed Phase I technical effort will be performed at the facilities of DeepBlue Dynamics located at [performance location to confirm]. The firm [confirm] maintains office space, software development workstations, local containerized build infrastructure, and a local network. All Phase I software development, synthetic ASPN/pntOS data generation, deterministic analytic-core testing, and operator-interface prototyping will use existing commercial off-the-shelf workstation compute and open-source tools. **No capital equipment purchases** are requested in the Phase I Cost Volume (Volume 3) [confirm].

All Phase I technical activity and data handling will occur within a planned environment conforming to NIST SP 800-171 Rev 2 and CMMC Level 2 (Self-Assessment), as the Topic Q&A describes for this effort. [1] This is a planned control baseline, not a completed accreditation or a CMMC certification claim. Final environment configuration and handling protocols will be confirmed with the Contracting Officer and Program Manager prior to performance. CUI scope remains a Government question.

[Confirm:] The facilities where the proposed work will be performed meet applicable environmental laws and regulations of Federal, state, and local Governments for, but not limited to, the following groupings: airborne emissions, waterborne effluents, external radiation levels, outdoor noise, solid and bulk waste disposal practices, and handling and storage of toxic and hazardous materials.

# References

1. Department of the Navy, DoW 2026 SBIR CSO Release 5, Open Topic DON26BX05-NP004, “NAVWAR Open Topic for Unified Assured Positioning, Navigation, and Timing Operational Awareness and Decision Support,” topic text and Topic Q&A (answers dated 1 Jul–1 Sep 2026). https://www.navysbir.com/n26_5/DON26BX05-NP004.htm (public mirror; DSIP is controlling). Accessed 7 Sep 2026.
2. U.S. Maritime Administration, U.S. Maritime Advisory 2026-008, “Global – U.S. Maritime Advisory Updates, Resources, and Contacts” (active; expires 21 Oct 2026). https://www.maritime.dot.gov/msci/2026-008-global-us-maritime-advisory-updates-resources-and-contacts
3. National Institute of Standards and Technology, Special Publication 800-190, “Application Container Security Guide.” https://csrc.nist.gov/pubs/sp/800/190/final
4. Office of the Chief of Naval Operations, OPNAVINST 9420.1C, “Positioning, Navigation and Timing Policy,” 30 Sep 2019, ¶5a(3) and ¶5a(11). https://www.secnav.navy.mil/doni/Directives/09000%20General%20Ship%20Design%20and%20Support/09-400%20Command%20and%20Surveillance%20Systems%20Support/9420.1C.pdf
5. U.S. Coast Guard Navigation Center, “GPS Problem Report Status,” marine entries June–August 2026. https://www.navcen.uscg.gov/gps-problem-report-status Accessed 7 Sep 2026.
6. U.S. Government Accountability Office, GAO-22-106010, “GPS Alternatives: DOD Is Developing Navigation Systems but Is Not Measuring Overall Progress,” 5 Aug 2022. https://www.gao.gov/products/gao-22-106010
7. Department of the Navy, Exhibit P-40 Budget Line Item Justification, PB 2025, Other Procurement Navy, Line Item 2657 “NAVSTAR GPS Receivers (Space),” March 2024, pp. 1–2. [Cite the official Navy FY2025 OPN justification book; an unclassified secondary copy was used for drafting.]
