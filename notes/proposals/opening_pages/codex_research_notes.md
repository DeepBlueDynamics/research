# Codex independent research notes — 2026-09-07

## Provenance and scope

Authored before reading other agents' proposal files. Read README.md, PHASE1_BUILD_PLAN.md, filing outline and relevant current instruction extracts. Live-read public topic/Q&A September 7 with web tool. The mirror labels itself unofficial; authenticated DSIP amendment/Q&A verification remains a filing task.

Primary source: https://www.navysbir.com/n26_5/DON26BX05-NP004.htm ; full locally retained capture: ../../../docs/F/F2_DON26BX05-NP004_topic_2026-09-07.md.
- Topic Objective/Description/Phase I: operator awareness and integration rather than new navigation hardware/algorithms; feasibility demonstration and Phase II plan.
- Aug 20/25: local air-gapped stack, source + composite confidence, processing through initial rendered recommendation subsecond; evidence drill-down can follow; fragmented physical displays as baseline.
- Aug 26: 3–8 sources at 1–10 Hz, primary GPNTS integration and APNT scope; representative rules permissible with later authoritative alignment.
- Aug 28: ECDIS familiarity UX target, synthetic public-standard data allowed, all Phase I data/activity described as CUI. Iron Bank question not directly answered.
- Sep 1: no human research expected. Does not declare an exemption for whatever study we design.
- Earlier informational-aids answer: do not execute ship-control or source-switch commands.

Controlling Navy v2: ../../../docs/F/F1_NAVY_SBIR_26BX_R5_v2_2026-09-07.md ; DSIP source URL https://www.dodsbirsttr.mil/submissions/api/public/download/solicitationDocuments?component=NAVY&documentType=INSTRUCTIONS&release=5&solicitation=DOD_SBIR_2026_P1_CBX .
Current preface: ../../../docs/F/F4_DOW_CSO_R5_PREFACE_2026-09-07.md .
Official template extraction: ../../../docs/F/F5_Navy_Volume_2_and_5_templates_2026-09-07.md .
Map requested Page 1 to Navy 1.0 Description of Proposed Phase I Technical Effort and 1.4 Defense Need; Page 2 to 1.1 Technical Objectives. Two draft sections are not a compliant completed Volume 2. Actual ten-page limit includes every section; no PDF pagination checked.

## Independent argument

The key experiment is observational indistinguishability. If two worlds emit identical observable inputs but differ in hidden truth, reliable inference cannot distinguish them without further evidence. This is a logical inference under the declared observation model, not a claim that all real spoofing is undetectable. The simulator must never pass hidden truth into the operational component. It should evaluate claims against available evidence as well as physical truth.

Dependency metadata is a design assumption, not guaranteed GPNTS data. Where unknown, display uncertainty and avoid counting sources as independent by default. A proposed cross-check is useful only when it references an accessible input or a plainly conditional request for operator verification. No guarantee of sensor availability or new navigation algorithm.

A third comparison arm (unified view without added explanations) tests whether apparent benefits arise from aggregation alone. Scripted views/interactions characterize the interface, not operators. Human cognition cannot be inferred from these counts; actual human-effectiveness evidence remains future work subject to scope determination.

## KPP rationale and limits

All sample sizes and gates are proposed planning choices, not powered human trials or statistically validated operational limits. 60 cases / 20 per stratum make a six-month engineering demonstration inspectable while retaining both usefulness and uncertainty checks. Cases should span distinct scenario configurations; 60 adjacent timestamps are not 60 independent cases. Variants of the same seed remain clustered in reporting.

18/20 useful recommendations is a proposed 90% demonstrator gate, not a demonstrated accuracy or Navy threshold. Zero violations in 20 unresolved cases is a finite-suite criterion, not proof of a zero real-world failure probability. Count unsupported assertions individually as well as cases; do not dilute failures with nominal timestamps. Freeze evaluators before final testing; changes to the rubric require a new version and rerun, not retrospective relabeling.

Four load corners exercise 3/8 sources × 1/10 Hz. Thirty minutes is an initial endurance assumption. Hardware, payload sizes, event rates, burst patterns and initial startup treatment must be frozen in the evaluation protocol; report warm/cold behavior separately. Ingress-to-render differs from physical anomaly-onset-to-render: report the latter where simulation truth permits but never claim subsecond ingestion latency proves subsecond physical detection.

12 workflow tasks / 9 improved is a proposed engineering screen. Tasks should include source age, dependency, confidence driver, fallback prerequisite and cited rationale, balanced across conditions. A simplified fragmented surrogate can bias the comparison; label it synthetic and secure post-award alignment. Do not claim actual current-watchstation measurements.

Three repeats test deterministic output; they do not increase independent scenario sample size. Local runtime is not cybersecurity authorization or CMMC certification. CUI handling and image-base timing require clarification before award/performance.

## Corrections to older build-plan assumptions

Do not reuse its all-public performance assertion, blanket ECDIS conformance, guaranteed independent source, single correct COA ground truth, operator-study promises, or CMMC=Rev3 claim. Those statements exceed present evidence or conflict with newer instructions. Repository retrieval benchmarks were not rerun and establish no APNT/operator benefit.

## Unresolved before commitment

Company approval of targets, base staffing/cost feasibility, dependencies/source schema realism, actual fragmented baseline fidelity, permissible evaluation activities, CUI scope and Iron Bank timing. No builds, benchmarks, prototype performance tests or PDF layout verification run for this draft.
