# Architecture Review: Deterministic Tool Registry, Playbook Dispatch, and Latency/Security Integration (v4 → vInfinity) — Corrected Synthesis

**Author:** Antigravity  
**Date:** September 7, 2026  
**Context:** Working from `notes/proposals/submission_draft_v4.md` pursuant to `notes/proposals/v4_forward_architecture_brief.md` and peer synthesis feedback.  
**Focus:** Architectural specification of the signed allowlisted tool registry, compiled playbook dispatch, dual-path resolution (exact lookup vs. analogue matching), typed prerequisite validation, explicit abstention, protected audit with restart continuity, and empirical latency/security integration under the strict <100 ms offeror gate and air-gapped container controls.

---

## 1. Executive Assessment & Synthesis Corrections

Following synthesis review, this document refines the forward architecture to eliminate unsupported timing assertions, remove over-scoped tool definitions, and ground all security and evaluation claims in verifiable engineering discipline.

### Explicit Architectural Corrections:
1. **Purely Informational Tool Registry (No Navigation Actuation):** All tools in the registry are strictly limited to **presentation, alerting, evidence visualization, and procedural runbook display**. Tools do not switch navigation modes, alter autopilot setpoints, or actuate ship systems. Previous references to "transitioning to INS-only" or "radar fixes" are recast strictly as informational display cards presenting guidance and prerequisites to the human watchstander.
2. **Removal of Unsupported Microsecond and Millisecond Latency Claims:** All speculative numbers (e.g., claiming "<50 µs SIMD search" or "800–2500 ms LLM bounds") are removed. Latency cannot be proven by summing an idealized budget on paper. End-to-end latency must be empirically measured across the physical boundary—from network socket byte ingress to the first hardware-latched display frame—under the strict <100 ms offeror gate (0% percentile miss allowance) and the Government's under-one-second requirement.
3. **Removal of Arbitrary Dimension and Library Constants:** Fixed parameters (e.g., "32 dimensions", "500 scenarios") are removed. Telemetry feature dimensionality and baseline scenario library sizing are design parameters to be frozen during Task B1/B2 development, not hardcoded a priori.
4. **Technology Neutrality (No Mandatory Language or Cryptographic Lock-in):** The architecture mandates compiled native binary dispatch and standard public-key signature verification; it does not lock the implementation exclusively to Rust/C++ or Ed25519 where equivalent approved languages and cryptographic algorithms satisfy requirements.
5. **Heuristic Nature of Distance Thresholding:** We explicitly state that distance thresholding in situation space is a **bounded classification heuristic, not a mathematical guarantee of out-of-distribution (OOD) detection**. Manifold density variations or unmodeled sensor dynamics can cause anomalous inputs to appear near known clusters. Failure reporting and explicit abstention are mandated when inputs violate observable evidence bounds.
6. **Prerequisite Enforcement for All Guidance (Including Manual DR):** Recommendations to fall back on manual dead reckoning cannot be assumed unconditionally safe; manual DR guidance itself requires verified prerequisites (e.g., valid last known good fix, valid gyro heading, and operational speed log).
7. **Privileged Tamper Resistance & Restart Continuity:** A bare hash chain and monotonic clock do not defeat an attacker with privileged access. The audit architecture incorporates an **external protected storage anchor** (e.g., a write-once mounted volume or external daemon) and **restart continuity verification** to detect log truncation, rollback, or deletion across container restarts.
8. **No Accreditation Claims:** The container configuration is defined as **hardening-ready**, implementing NIST SP 800-190 controls without asserting formal ATO, CMMC, or cryptographic module certification.

---

## 2. Technical Specification: Signed Tool Registry & Compiled Playbook Dispatch

### 2.1 The Signed Enumerated Informational-Tool Registry

In strict adherence to the topic description [DON26BX05-NP004 Description; Q&A 7/1/26; Q&A 8/26/26], the tool registry provides decision support exclusively through informational display elements. The system never executes autonomous command or control loops.

```
+---------------------------------------------------------------------------------------------------------+
|                                SIGNED INFORMATIONAL TOOL REGISTRY MANIFEST                              |
+---------------------------------------------------------------------------------------------------------+
|  Tool Identifier                  | Type Signature                        | Display Function            |
|-----------------------------------+---------------------------------------+-----------------------------|
|  TOOL_DISPLAY_BAM_BANNER          | (Priority, AlertId, CauseCode)        | Renders MSC.302(87) Alert   |
|  TOOL_DISPLAY_EVIDENCE_PANEL      | (SourceMask, ResidualVector, Finding) | Renders Scatter & Matrix    |
|  TOOL_DISPLAY_COA_CARD            | (CoaId, PrereqList, ActionSummary)    | Renders Informational COA   |
|  TOOL_DISPLAY_PROCEDURAL_RUNBOOK  | (DocId, SectionRef, ClauseCitation)   | Surfacing Backing SOP/TTP   |
|  TOOL_DISPLAY_ABSTENTION_NOTICE   | (AmbiguitySet, MissingEvidenceList)   | Renders INDETERMINATE State |
|  TOOL_UPDATE_SOURCE_ROSTER        | (SourceId, HealthState, Age, Mode)    | Updates Raw Source Tile     |
+---------------------------------------------------------------------------------------------------------+
| Security Envelope: Signed Manifest Digest, Verified Against Immutable Trust Anchor at Cold-Start      |
+---------------------------------------------------------------------------------------------------------+
```

* **Cryptographic Allowlist & Signing:** Every informational display tool is statically registered in a signed manifest. The manifest digest is verified at startup against an immutable, read-only trust anchor. Invocation of any unlisted or modified tool halts the dispatch engine.
* **Pre-Reviewed Compiled Bindings:** The mapping between evaluated operational states and tool invocations is established during development via the combative-training loop and verified through 100% human SME review. Playbook bindings are compiled into native executable tables. There is no dynamic code generation, runtime scripting, or LLM-driven tool composition on the operational execution path.

### 2.2 Typed Arguments & Prerequisite Validation Engine

Every informational tool invocation requires strictly typed arguments and must satisfy explicit prerequisite predicates evaluated against live sensor telemetry before the display card is rendered:

1. **Typed Argument Boundaries:** Tool arguments are strictly typed primitives, bounded numeric ranges, or enumerated constants. Malformed payloads are rejected at the deserialization boundary.
2. **Prerequisite Verification on Informational Guidance:**
   * *Advisory to Cross-Check Radar:* Before presenting an informational card recommending a radar fix, the prerequisite engine checks whether the radar telemetry interface is reporting valid target returns and whether the platform is within range of mapped navigational landmarks.
   * *Advisory to Rely on INS Dead Reckoning:* Before presenting an informational card recommending reliance on INS dead reckoning, the prerequisite engine validates that the INS status reports valid operational health, solution age is within acceptable bounds, and drift variance has not exceeded safe navigational tolerances.
   * *Advisory for Manual Dead Reckoning:* Recommending manual plotting requires verifying that a credible last known good fix exists, heading sensors are operational, and speed log feeds are active. If heading or speed data is absent, manual DR cannot be presented as a viable recovery option.
3. **Action on Prerequisite Failure:** If the prerequisites for a specific recovery recommendation are not met, that recommendation is suppressed. If no supported alternative exists, the engine invokes `TOOL_DISPLAY_ABSTENTION_NOTICE` (`INDETERMINATE`), explicitly identifying which prerequisites failed and what independent evidence is missing.

---

## 3. Dual-Path Dispatch: Exact Lookup vs. Telemetry Analogue Matching

To combine deterministic predictability for known threat signatures with resilience against noisy, non-canonical inputs, SEXTANT employs a dual-path dispatch architecture:

```
                          +-----------------------------------+
                          | Normalized ASPN Sensor Telemetry  | (3-8 sources, 1-10 Hz)
                          +-----------------+-----------------+
                                            |
                                            v
                          +-----------------------------------+
                          | Mathematical Anomaly Key & Vector |
                          +-----------------+-----------------+
                                            |
                  +-------------------------+-------------------------+
                  |                                                   |
      (Canonical Discrete State)                             (Non-Canonical / Noisy)
                  |                                                   |
                  v                                                   v
    +---------------------------+                       +---------------------------+
    |   PATH A: EXACT LOOKUP    |                       | PATH B: ANALOGUE MATCHING |
    | - O(1) Precompiled Table  |                       | - Engineered Vector Space |
    | - Deterministic Binding   |                       | - Baseline Scenario k-NN  |
    +-------------+-------------+                       +-------------+-------------+
                  |                                                   |
                  |                                         +---------+---------+
                  |                                         |                   |
                  |                                  d <= tau_abstain    d > tau_abstain
                  |                                         |                   |
                  |                                         v                   v
                  |                                  +--------------+    +--------------+
                  |                                  | Display Best |    | Enforce Full |
                  |                                  | Analogue Case|    | Abstention:  |
                  |                                  | Card         |    | INDETERMINATE|
                  |                                  +-------+------+    +-------+------+
                  |                                          |                   |
                  +--------------------+---------------------+-------------------+
                                       |
                                       v
                          +---------------------------+
                          | Prerequisite Verification | (Validates telemetry predicates)
                          +-------------+-------------+
                                        |
                                        v
                          +---------------------------+
                          | Display Frame Render      | (Strict <100 ms offeror gate)
                          +-------------+-------------+
                                        |
                                        v
                          +---------------------------+
                          | Protected Audit Store     | (Write-once anchor + continuity)
                          +---------------------------+
```

### 3.1 Path A: Exact Anomaly-State Lookup (Canonical Hot Path)
When telemetry resolves cleanly into known failure categories (e.g., clear $C/N_0$ collapse indicating jamming, or single-receiver variance jump indicating hardware fault), the core extracts a canonical discrete state key and performs an $O(1)$ table lookup. This immediately retrieves the precompiled, pre-reviewed informational action card.

### 3.2 Path B: Telemetry Analogue Matching (Engineered Feature Space)
When telemetry exhibits partial degradation, conflicting indicators, or non-discrete sensor noise, Path B is engaged:
* **Engineered Situation Vector:** Telemetry is mapped into an engineered feature vector capturing normalized residuals, pairwise sensor agreement deltas, SNR drops, solution age, and missingness bit-masks.
* **Nearest-Scenario Search:** The vector is compared against a frozen baseline of labeled synthetic training scenarios.
* **Limitations of Distance Thresholding ($\tau_{\text{abstain}}$):**
  * While distance matching identifies close historical analogues, **distance thresholding cannot guarantee out-of-distribution (OOD) detection**. In high-dimensional spaces, non-uniform data density, anisotropic noise, or unmodeled sensor cross-correlations can cause an OOD or maliciously crafted input to fall within the Euclidean distance threshold of a known benign cluster.
  * Consequently, distance matching is treated strictly as a **heuristic diagnostic aid**. If the distance $d > \tau_{\text{abstain}}$, the engine enforces full abstention (`INDETERMINATE`). Even if $d \le \tau_{\text{abstain}}$, the system subjects the proposed analogue action to prerequisite validation and observable-evidence consistency checks. If any observable evidence contradicts the candidate match, the system rejects the analogue and abstains.

---

## 4. Latency Integration Under the Strict <100 ms Gate

### 4.1 Boundary Measurement vs. Budget Sums
A paper latency budget is a design target, not proof of compliance. To establish technical feasibility under the user's firm acceptance constraints:
* **Government Requirement:** Under one second (< 1,000 ms) from data ingestion to the presentation of alerts and initial recommended courses of action [Q&A 8/25/26]. Reported separately.
* **Offeror Gate:** **Under 100 milliseconds** from input receipt at the system boundary to the first displayed frame containing both the BAM alert banner and initial recommendation card, with security controls active and **0% percentile miss allowance**. Any single measured event $\ge 100\text{ ms}$ fails the offeror gate. If clock uncertainty overlaps 100 ms, pass is not established.
* **Empirical Measurement Boundary:** Timing is instrumented using a hardware-based monotonic clock (`CLOCK_MONOTONIC_RAW`). The interval begins when the first raw byte string hits the container's input socket and ends when the display rendering engine completes frame rasterization and latches the frame to the display buffer.

### 4.2 Decoupling of Hot Path from Asynchronous Progressive Disclosure
To prevent latency spikes and ensure deterministic sub-100 ms execution:
* **Hot Path (<100 ms):** Ingestion, schema parsing, residual computation, dispatch (Path A or Path B), prerequisite validation, and initial HTML5/WebGL frame render execute strictly in native compiled code. No language models, dynamic compilers, or heavy neural network embedders participate in this path.
* **Asynchronous Drill-Down Path (Relaxed):** The local language model and lexical/vector hybrid search (`lume`) execute in the background. They generate deep rationale, historical post-mortems, and expanded runbook documentation, which populate the UI upon operator drill-down without delaying the initial alert frame [Q&A 8/25/26].

---

## 5. Security Architecture & Tamper-Resistant Audit

### 5.1 Hardened Container Controls (NIST SP 800-190)
The deployment stack runs in an isolated container environment implementing defense-in-depth:
* **Air-Gap Enforcement:** Network namespace configured with zero external routes (`network_mode: none` or isolated bridge). The application must boot, ingest, analyze, render, and replay without external DNS, package mirrors, or license validation.
* **Least Privilege:** Non-root execution (`UID 10001`), read-only root filesystem (`read_only: true`), all Linux capabilities dropped (`cap_drop: [ALL]`), and no remote administrative services (no SSH/telnet daemons).
* **Hardening-Ready Posture:** The environment is structured to meet Iron Bank criteria; no formal ATO, DIACAP, or CMMC certification is claimed for Phase I.

### 5.2 Tamper-Resistant Audit Store with Restart Continuity
A simple in-container hash chain can be recomputed or truncated by an attacker with root privileges. To provide defensible audit integrity:
* **Append-Only Protected Anchor:** Audit records are written to a dedicated, write-once volume mount or piped across an isolated local socket to a distinct logging service running with separate access boundaries.
* **Cryptographic Chaining:** Each record incorporates the SHA-256 digest of the preceding record, a monotonic hardware timestamp, the input telemetry digest, the active rule/tool identifier, prerequisite evaluation flags, and operator interaction states.
* **Restart and Rollback Continuity:** At container initialization, the audit engine reads the latest record from the protected anchor, verifies signature continuity, and logs a signed restart event. If log records have been deleted, reordered, or rolled back, the verification sequence detects the broken continuity, raises an audit alert, and halts execution.

---

## 6. Test Matrix, Denominators, and Explicit Failure Criteria

Evaluation is conducted on representative synthetic data without human subjects research [Q&A 9/1/26]. Tests specify clear denominators and failure criteria:

| Test ID | Evaluation Focus | Instrumentation & Test Method | Sample Plan & Denominator | Failure Criteria |
| :--- | :--- | :--- | :--- | :--- |
| **TEST-LAT-01** | Hot-Path Latency (Exact Lookup) | Monotonic clock delta: boundary input receipt to displayed frame render callback. Corner loads: 3 & 8 sources at 1 & 10 Hz. | $N \ge 1,000$ scored anomaly events across four 30-minute corner runs. | Any event $\ge 100\text{ ms}$; clock uncertainty overlapping 100 ms; frame drop; unhandled queueing. |
| **TEST-LAT-02** | Hot-Path Latency (Analogue Matching) | Monotonic clock delta: non-canonical telemetry input to displayed frame render callback under full load. | $N \ge 250$ injected non-canonical events during mixed-rate sweep. | Any event $\ge 100\text{ ms}$; clock uncertainty overlapping 100 ms. |
| **TEST-TOOL-01** | Signed Registry Integrity | Pre-execution gate signature check; injection of unauthorized or modified tool manifests. | 100% of startup runs + 50 negative injection tests. | Any unauthorized tool loads; any tampered manifest fails to halt execution. |
| **TEST-TOOL-02** | Prerequisite Enforcement | Evaluation of recommendations under invalid telemetry (e.g., degraded INS, absent landmarks, missing heading). | 60 frozen cases $\times$ corrupt telemetry permutations ($N \ge 240$ runs). | Any recommendation displayed when its required prerequisites are not fully met. |
| **TEST-ABST-01** | Distance-Bounded Abstention | Injection of synthetic out-of-distribution (OOD) scenarios with distance $d > \tau_{\text{abstain}}$. | $N \ge 20$ held-out unresolvable/OOD scenario runs. | Emitting a definitive diagnosis or active recommendation instead of `INDETERMINATE`. |
| **TEST-SEC-01** | Air-Gap Isolation & Hardening | Automated egress packet probes, privilege escalation checks, and rootfs write attempts. | 100% of container test executions. | Any outbound network communication; root execution; successful write to rootfs. |
| **TEST-AUD-01** | Audit Tamper & Restart Continuity | Intentional bit-level modification, record deletion, truncation, and container restart simulation. | 100 test runs with randomized disk modifications and restarts. | Failure to detect modified, deleted, or truncated log records against the protected anchor. |

---

## 7. Exact Proposed Prose Changes for `submission_draft_v4.md`

To integrate this corrected specification into the formal proposal, the following text changes are proposed:

### 7.1 Proposed Amendment to Section 1.0.5 (Innovative Approach Overview)

**Location:** `submission_draft_v4.md`, Lines 46–52.  
**Action:** Replace paragraphs *"Deterministic alert path"*, *"Rules from guidance..."*, and *"Keyed retrieval"* with the following text:

```markdown
**Deterministic alert path and signed tool registry.** A bounded, type-safe code path presents the alert banner and initial informational recommendation without runtime language-model composition. All presented actions are drawn from an enumerated, cryptographically signed tool registry (informational alert banners, evidence panels, prerequisite-bound action cards, procedural runbook excerpts, and explicit abstention notices) verified against an immutable trust anchor at startup. Recommendations carry strictly typed arguments and explicit prerequisite predicates evaluated against live telemetry (e.g., presenting an informational card to consult INS dead reckoning requires valid INS stream health, solution age within bounds, and variance within safe limits; recommending manual dead reckoning requires a valid last known fix, heading data, and speed log). Unmet prerequisites automatically suppress invalid guidance.

**Dual-path dispatch: exact lookup and analogue matching.** Canonical anomaly states are mapped to pre-reviewed, compiled rule bindings. At runtime, the core executes an O(1) hash lookup on canonical anomaly keys. When telemetry is noisy, corrupted, or non-canonical, an engineered situation vector (residuals, C/N0 trends, clock stability, and missingness flags) searches a frozen baseline of labeled scenarios. A frozen distance threshold (tau_abstain) bounds analogue matching: if the nearest scenario distance exceeds tau_abstain, the system refuses to guess and emits INDETERMINATE. Because distance thresholding is a heuristic classifier rather than a guarantee of out-of-distribution detection, analogue matches are further verified against observable-evidence consistency checks. Both exact and analogue paths execute under the strict <100 ms offeror latency gate (Section 1.1).

**Combative training, protected audit, and local airgap.** Decision rules are derived offline in Task B3 via a combative-training loop: a scenario generator produces failure cases with evaluator-held truth; in the development environment only, a local model queries the document base to synthesize candidate rule code citing guidance clauses [1][8][9]; human engineers review, approve, and compile bindings into native binaries. The operational runtime contains no language model on the hot path; an optional local model composes narrative rationale and runbook drill-down asynchronously after the initial alert renders. A tamper-resistant audit store records telemetry digests, match keys, tool IDs, and operator interactions; audit integrity is enforced via cryptographic chaining, an external protected storage anchor, and restart continuity checks that detect log truncation or tampering without cloud dependencies.
```

### 7.2 Proposed Amendment to Section 1.1 (Phase I Technical Objectives & Gate Table)

**Location:** `submission_draft_v4.md`, Line 63 (Objective 2) and Lines 78–81 (Gate Table).  
**Action:** Update Objective 2 and add dedicated rows for Signed Registry, Both-Path Latency, and Prerequisite Enforcement:

*Update Objective 2 (Line 63):*
```markdown
2. **Build the rule library and signed tool registry** — cited, versioned, human-reviewed deterministic rules and typed informational tool bindings via combative training, enforcing prerequisite checks and explicit INDETERMINATE abstention when evidence cannot support a conclusion.
```

*Update Gate Table (Lines 78–81):*
```markdown
| Gate | Measurement | Fails if |
|---|---|---|
| Air-gapped operation | Cold-start ingestion, UI, analytics, retrieval, inference, and replay with external interfaces disconnected; only declared internal communications. | Any attempted external communication, outbound packet, or offline functional failure. |
| Secured runtime & signed registry | Inspect effective controls; verify signature of tool registry manifest and rule binaries against trust anchor; exercise denied access, modified packages, and audit tampering. [3] | Any mandatory-control failure, unauthorized tool invocation, signature mismatch, audit tampering miss, or unremediated high/critical vulnerability. |
| Sub-100 ms latency (both paths) | Hardened configuration, monotonic clock, input receipt at system boundary to displayed frame holding alert AND recommendation. Test Path A (exact lookup) and Path B (analogue matching). | Any event >=100 ms (0% miss allowance); clock uncertainty overlapping 100 ms; frame drop; or unhandled queueing latency. (Government <1 s reported separately). |
| Evidence fidelity and replay | Across held-outs and three repeats, every assessment and recommendation resolves to input evidence, tool ID, and rule version; required fields preserved or marked missing. | Any silent loss, unsupported citation, prerequisite violation, or unexplained analytical replay mismatch. |
| Useful, bounded recommendations & abstention | 60 frozen cases: 20 nominal, 20 recoverable, 20 unresolved, spanning fault/jam/spoof, shared dependencies, missing/stale data, and recovery; plus held-out out-of-distribution distance runs. | Any unsupported definitive claim or prerequisite violation; fewer than 18/20 acceptable in nominal or recoverable; failure to emit INDETERMINATE when distance > tau_abstain or evidence is ambiguous. |
| Information access | On 12 frozen tasks, required evidence reachable and complete; no critical legibility or priority defect under a predefined checklist. Compared to surrogate and explanation-disabled view. | Any unreachable or incomplete required evidence, or any critical checklist defect. Counts are workflow proxies; no promised percentage improvement. |
```

### 7.3 Proposed Amendment to Section 1.2 Statement of Work (Tasks B3 & B4)

**Location:** `submission_draft_v4.md`, Line 110 (Task B3) and Line 113 (Task B4).  
**Action:** Update Task B3 and Task B4 descriptions:

*Update Task B3 (Line 110):*
```markdown
**B3. Rule library, signed tool registry, and local decision support. Months 2–4. Performer: DeepBlue Dynamics.** Implement the unified display, evidence-based composite engine, and signed informational tool registry. Establish type-safe prerequisite validation for all informational guidance cards. Compile pre-reviewed playbook bindings for exact state lookup and implement situation-vector analogue matching with a frozen abstention threshold (tau_abstain). Run the development-time combative-training loop in Section 1.0.5. Key the local retrieval index by anomaly state; measure keyed-lookup latency against empirical test instrumentation. Deliver: integrated feasibility prototype; signed tool manifest; evidence-linked traces; rule provenance (rule → guidance clause).
```

*Update Task B4 (Line 113):*
```markdown
**B4. Secured runtime and measured evaluation. Months 3–6. Performer: DeepBlue Dynamics.** Package the full stack for offline cold start on an Iron Bank base. Verify the Section 1.1 air-gap, container hardening, and signed registry verification gates. Attack unauthorized access, tampered tool manifests, unsigned binaries, and truncated audit records. Run the latency gate (Section 1.1) with security enabled across both Path A (exact lookup) and Path B (analogue matching): four 30-minute corners (3 and 8 sources × 1 and 10 Hz), a 30-minute mixed-rate sweep, a 60-minute soak at 8 sources and 10 Hz with bursts, at least 1,000 scored events, every event reported. Run the frozen 60-case evaluation, critical-case checks, out-of-distribution abstention checks, three repeats, and the twelve information-access tasks against the fragmented-display surrogate and the explanation-disabled configuration. Report every miss. Infer nothing about fleet reliability or operator performance. Deliver: test evidence; security findings; feasibility assessment; training dataset; rule provenance; regression results.
```

---

## 8. Synthesis Sign-Off & Blockers

* **Blockers:** **NONE.**
* **Synthesis Readiness:** This corrected specification incorporates all synthesis critique items, maintains full evidentiary integrity, and provides ready-to-merge prose for Codex's v5 / vInfinity synthesis.
