```text
DeepBlue Dynamics | DON26BX05-NP004 | Phase I Technical Proposal

----------------------------------------------------------------------
1. IDENTIFICATION AND SIGNIFICANCE OF THE PROBLEM / OPERATIONAL NEED
----------------------------------------------------------------------

During a destroyer transit through a GPS-degraded strait, the
navigation electronics technician must determine which information
remains credible and which response the evidence supports. Today,
source displays, status indicators and procedures present fragments of
that answer. DON26BX05-NP004 identifies the resulting workload,
training burden and decision delay. [1] Maritime Advisory 2026-008
reinforces the need to prepare for GPS disruption before departure.
[2]

DeepBlue Dynamics proposes a unified APNT awareness and
decision-support interface combining source health, composite
confidence, anomaly assessment and recovery guidance. Each
informational recommendation will show its prerequisites and
supporting evidence. The central hypothesis is that explaining the
basis and limits of an assessment provides more useful decision
support than aggregating indicators alone.

The representative scenario begins with apparently healthy positioning
feeds. Two feeds continue to agree because they share a compromised
dependency, while a separate reference reveals a discrepancy. That
reference then becomes stale: apparent agreement persists, but
independent corroboration is lost. The interface will expose this
change through source health, observation age, known dependencies and
the resulting composite assessment.

When evidence cannot distinguish fault, jamming or spoofing, the
interface will preserve the unresolved alternatives and identify an
available cross-check. If no accessible evidence can resolve the
condition, it will state that limit and present bounded
degraded-operation guidance. When credible evidence returns, it will
update the assessment and recovery options.

The capability combines modular integration, explainable analytics, a
navigation-style display and local supporting procedures in a secured,
air-gapped runtime. ECDIS familiarity principles will guide a concise
initial view of the condition, principal evidence and recommendation,
with rationale and history available through drill-down.

Phase I will establish feasibility through an integrated software
demonstration covering nominal, recoverable and unresolved conditions.
Unsupported confidence will fail even when a recommendation happens to
match hidden simulator truth; permanent abstention will fail when
evidence supports a useful response. The interface and integration
service are the product; simulation supplies reproducible evaluation.
The effort develops no new PNT sensors, timing sources, hardware or
navigation-solution algorithms. Recommendations remain informational,
with no ship-control actuation. [1]

----------------------------------------------------------------------
2. PHASE I TECHNICAL OBJECTIVES & KEY PERFORMANCE PARAMETERS
----------------------------------------------------------------------

The six-month Phase I base will establish whether the proposed
interface can preserve and explain multi-source evidence, present
useful recovery guidance under changing conditions, and operate within
shipboard deployment constraints.

Objective 1 - Integrate and explain APNT information. Normalize
representative ASPN/pntOS-compatible inputs while retaining source
identity, health, confidence and observation age. Present
individual-source assessments alongside a separately explained
composite assessment.

Objective 2 - Support decisions under uncertainty. Implement versioned
informational recommendations with explicit prerequisites and
traceable evidence. Identify missing corroboration, distinguish
supported conclusions from unresolved alternatives, and update the
assessment as sources degrade or recover.

Objective 3 - Demonstrate operationally relevant feasibility. Evaluate
the integrated, secured application using reproducible scenarios and
identical inputs across the proposed interface and a synthetic
fragmented-display test control. A configuration with explanations
disabled will distinguish the contribution of aggregation from that of
the proposed explanations.

----------------------------------------------------------------------
PERFORMANCE PARAMETERS AND VERIFICATION
----------------------------------------------------------------------

The source envelope is 3-8 simultaneous PNT sources updating at 1-10
Hz. [1] Air-gapped operation and a secured runtime are design
requirements. The following performance targets define the proposed
Phase I evaluation.

KPP 1: SOURCE INTEGRATION
Operate across the stated source/rate envelope. Preserve emitted
health, confidence and identity fields, or display their absence
explicitly. Verify input-to-display fidelity and report dropped
messages.

KPP 2: INITIAL RESPONSE
<100 ms from input receipt at the system boundary to the first
displayed frame containing both the alert and initial recommendation,
with security enabled. Any missing response or interval >=100 ms fails
the target. Exercise mixed rates, bursts, sustained load and
local-model failure; detailed explanation may follow asynchronously.

KPP 3: AIR-GAPPED OPERATION
Cold-start and complete ingestion, analytics, UI, retrieval, inference
and replay with external interfaces disconnected and dependencies
preloaded. Any external communication attempt or offline functional
failure fails.

KPP 4: SECURED RUNTIME
Verify least privilege, authenticated role-limited access, offline
package integrity/SBOM, protected data and keys, and persistent
tamper-evident audit. Test unauthorized access, modified packages and
audit tampering. Any mandatory-control failure or unremediated
applicable high/critical vulnerability fails. [3]

KPP 5: RECOMMENDATION QUALITY
In the proposed held-out suite, provide an acceptable response in at
least 18/20 nominal and 18/20 recoverable cases. Permit zero
unsupported definitive claims or prerequisite violations in unresolved
cases. Every predeclared critical case must pass independently of
aggregate results.

KPP 6: EVIDENCE AND INFORMATION ACCESS
Link each assessment and recommendation to its input evidence and rule
version. Reproduce analytical outputs across three replays. Across 12
predefined information-access tasks, required evidence must be
complete and reachable without critical legibility or priority
defects.

----------------------------------------------------------------------
EVALUATION APPROACH AND DELIVERABLES
----------------------------------------------------------------------

Before tuning, the team will freeze the hardware and load profile,
observation model, acceptable recommendation sets and held-out
scenarios. The proposed 60-case suite comprises 20 nominal, 20
recoverable and 20 unresolved cases, including shared dependencies,
stale or missing data, and recovery transitions. Recoverable cases
will include at least six per fault, jamming and spoofing class under
the declared observation model. Simulator truth will remain
inaccessible to the operational application.

The evaluation will report each case outcome, all timing events and
failures, per-class coverage, and the completeness of supporting
evidence. Case counts are a feasibility coverage plan, not a claim of
fleet reliability. Interaction counts will characterize information
access; they will not be presented as measured improvements in
operator workload or decision speed.

Phase I will deliver the software demonstration, interface/integration
design, reproducible evaluation results, failure analysis, final
report and initial Phase II proposal. The transition plan will address
GPNTS interface adaptation and subsequent operator-effectiveness
evaluation. Participant research is not included in this base effort.
CUI handling requirements and the applicability of specific deployment
infrastructure will be resolved with the Government before affected
performance. [1]

----------------------------------------------------------------------
REFERENCES
----------------------------------------------------------------------

[1] DON26BX05-NP004 topic and Q&A, accessed September 7, 2026.
https://www.navysbir.com/n26_5/DON26BX05-NP004.htm

[2] U.S. Maritime Advisory 2026-008.
https://www.maritime.dot.gov/msci/2026-008-global-us-maritime-advisory-updates-resources-and-contacts

[3] NIST SP 800-190, Application Container Security Guide.
https://csrc.nist.gov/pubs/sp/800/190/final
```
