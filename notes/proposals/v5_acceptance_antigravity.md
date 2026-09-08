# Antigravity acceptance of v5: Tool registry, compiled bindings, full-path latency, and protected audit

Date: 2026-09-07. Reviewed `submission_draft_v5.md` (5,647 words excluding HTML comments) and `v5_synthesis_notes.md` against the assigned areas: signed allowlisted informational-tool registry, pre-reviewed compiled playbook bindings, typed arguments and prerequisite checks, both-path latency under the strict offeror gate (<100 ms, 0% miss allowance, Gov <1 s reported separately), bounded analogue fallback with explicit abstention, and protected audit track with external trust anchor and restart continuity. The draft was not modified.

## Decision: ACCEPT. No blocking fixes.

Every item required by the forward architecture brief and the synthesis constraints is accurately reflected without overclaims:

1. **Signed allowlisted informational-tool registry** (Section 1.0.5, line 43; SOW Task B3, line 114):
   - Enumerates purely informational tools: evidence cross-checks, procedure retrieval, display layouts, and replay windows.
   - Excludes all navigation-actuation, autopilot, or steering commands.
   - Offline cryptographic signature required for the registry manifest; verified at startup.

2. **Compiled, pre-reviewed playbook bindings** (Section 1.0.5, line 43; SOW Task B3, line 114):
   - Candidate bindings are generated in development, reviewed by human experts, versioned, and compiled into lookup tables.
   - Direct lookup target (<30 µs) is explicitly framed as an unmeasured design target rather than a demonstrated benchmark.
   - Runtime rules generate an anomaly-state key; vectors select only from the pre-approved compiled set. No language model or generator composes tool calls on the hot execution path.

3. **Typed arguments and prerequisite checks** (Section 1.0.5, lines 43, 45; Table 1.1, line 85; SOW Task B4, line 117):
   - Every registry entry declares strict argument schemas, numerical bounds, evidence prerequisites, and output types.
   - Arguments and prerequisites are validated against current observable evidence prior to dispatch.
   - Gate Table 1.1 explicitly fails tool selection on any unlisted invocation, invalid argument, unmet prerequisite, unsupported dispatch, or oracle mismatch.
   - Task B4 exercises argument bound validation, deliberate signature corruption, and prerequisite denial under attack testing.

4. **Both-path latency under strict <100 ms offeror gate** (Section 1.0.5, lines 43, 45; Section 1.1, lines 74, 85; Figure 2, line 55; SOW Task B4, line 117):
   - Full-path latency encompasses input ingestion at the system boundary through monotonic clocking, queueing, processing, and actual frame presentation latching on screen.
   - Both Path A (exact deterministic lookup) and Path B (bounded analogue fallback or abstention) are included in the latency denominator. Timeouts and dropped events are counted as failures, not discarded.
   - Offeror gate (<100 ms, zero-miss threshold, uncertainty overlapping 100 ms fails) is clearly separated from the Government requirement (<1 s ingestion-to-alert, reported separately).
   - Test envelope in Task B4 spans four 30-minute corner cases (3/8 sources × 1/10 Hz), a 30-minute mixed-rate sweep, and a 60-minute soak at 8 sources / 10 Hz with bursts (>=1,000 scored events).

5. **Bounded analogue fallback and explicit abstention** (Section 1.0.5, line 45; Table 1.1, line 84; SOW Task B3, line 114):
   - Fallback returns labelled historical development scenarios as analogues, not causal diagnoses or definitive fault classifications.
   - Explicitly acknowledges that a vector distance threshold alone does not prove out-of-distribution (OOD) novelty detection.
   - Enforces an explicit `INDETERMINATE` fallback when similarity falls below the floor or when evidence is contradictory/insufficient.
   - Observation-equivalent scenarios are barred from receiving distinct definitive labels based on hidden truth.

6. **Protected audit track and secured runtime** (Section 1.0.5, line 51; Section 1.1, lines 78–79; SOW Task B4, line 117):
   - Audit trail requires an external/protected trust anchor and verifiable continuity across restart/rollback, explicitly recognizing that a recomputable hash chain alone does not protect against privileged tampering.
   - Iron Bank base image is described as hardening-ready packaging, avoiding any unsubstantiated claim of operational accreditation or fleet authorization.
   - SOW Task B4 mandates explicit tamper injection tests against audit records, package modifications, unauthorized privilege escalation, and external egress attempts.

---

## Non-blocking Observations

1. **Page Budget Pressure:** At 5,647 words before figures, tables, and front matter, fitting the Phase I technical proposal into the strict 10-page ceiling remains a critical layout and typography challenge. Dense two-column proportional typesetting, compact figures, and tightly budgeted tabular rows will be necessary during PDF generation.
2. **Distinction of Targets vs. Facts:** The draft consistently and correctly maintains the distinction between proposed design gates/targets (e.g., <30 µs lookup target, <100 ms offeror latency gate, 0.90 recall@5 target, 60 frozen evaluation cases) and demonstrated prior work. No unverified empirical fleet benchmarks are claimed.
