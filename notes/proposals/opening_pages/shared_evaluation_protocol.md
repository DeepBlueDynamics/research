# Shared evaluation protocol — agreed draft v3

Planning detail supporting the two opening sections, not technical overflow for Volume 5. Relevant commitments must fit Volume 2/SOW. Nothing here has been implemented or tested by this drafting exercise.

## Fixed requirements and proposed choices

User mandates secured, air-gapped, subsecond. Topic/Q&A Aug20/25/26 sets 3–8 sources1–10Hz and ingress-to-alert/initialCOA latency. These are binding design constraints. New ownship-fix / navigation-solution algorithms, new sensors, control actuation, and shore-system dependencies are outside the proposed work. Explainable composite confidence and triage over existing sources remain in scope. Distinct-error-family cross-checks (when those sources are present in the inputs) remain in scope. All test numbers and the specific hardening checklist are offeror-proposed.

## Latency and load

Proposed four 30-minute corner runs (3 and8 sources, each1 and10Hz), plus a30-minute sweep through4–7 sources with mixed rates in range. Predeclare message sizes, timestamp rules, burst/concurrent-event patterns and representative baseline hardware/OS/container/UI versions. Add a 60-minute soak at 8 sources × 10 Hz with event bursts. At least1,000 scored event transitions across the suite; declare the distribution, avoid treating repeating one event as diverse coverage.

Event ID links input receipt to the first frame visibly containing both relevant alert and initial recommendation. Validate presentation instrumentation; a queued callback alone is not proof of a displayed frame. Use a common trusted monotonic measurement clock or document cross-process clock alignment and uncertainty. Retain all event latencies, failures, missing renders, maximum and quantiles. If measurement uncertainty overlaps1second, pass is not established. No percentile exceptions; ≥1second fails.

Anomaly onset to observation arrival, and cold-start time, are reported separately. They must not be passed off as ingestion-to-render latency. Start accepting source input only when the authenticated UI and mandatory services are ready. Exercise source reconnects, malformed/stale input handling and local model unavailable/busy cases. Missing-source detection uses predeclared stale timeouts; report timeout contribution separately. The deterministic path must never wait for model generation. Apply the same security controls in every timing run.

## Scenario oracle

60 proposed held-out cases divided20nominal/20recoverable/20unresolved are a coverage budget, not a powered reliability sample. Include at least 6 recoverable cases each for fault, jam and spoof indicators under the observable-evidence oracle, and report class-specific counts/outcomes without treating these small groups as precise reliability estimates. Specify family/seed/parameter coverage, including shareddependency, partial/missingmetadata,staleness and recovery. Include observation-equivalent pairs with distinct hidden truths. Count pairs as related cases, not independent samples.

Freeze development/holdout partition and oracle before tuning. For each case define the system-accessible observation window, available verification actions and prerequisites, acceptable recommendation sets, prohibited claims, and any critical-case designation. Mark critical cases before observing outcomes; include observable contradictions/common-dependency transitions and loss/restoration of corroboration. When diagnosis is not identifiable, accept alternatives consistent with observations; never require knowing inaccessible truth.

Distinguish a well-supported conservative instruction from abstention. No unsupported definitive assertion or prerequisite violation is allowed in unresolved cases. Require at least18/20 acceptable responses separately in nominal and recoverable strata. Any critical-case failure fails independently of aggregate scores. Report success counts, all failures, case clusters and uncertainty; make no universal zero-failure claim from a finite suite.

The evaluator owns hidden truth separately from inputs. Verify operational code and retrieval content cannot read labels, case names encoding diagnoses, seeds revealing classes, or truth stores. Repeat3times for deterministic analytical outputs; timestamps and generative prose need not match, but any displayed factual explanation must remain evidence-bound.

## Information-access comparison

12 tasks spanning source freshness, source dependency, composite driver, anomaly alternatives, fallback prerequisite and cited guidance. Freeze required evidence and design checklist before comparing. Use same inputs, evidence availability and factual content for fragmented surrogate, unified interface, and unified interface with added explanations disabled. The last is a feature configuration, not a third separately built product.

Record views, interactions and evidence completeness. Do not assign a weak automated policy to the fragmented view and label the result a human benefit. A one-screen dump cannot pass if it violates the predefined critical legibility/priority checks. Record checklist criteria and reviewer role; no participant performance study or blanket no-IRB exemption. Subsequent human evaluation needs an appropriate determination. No surrogate is claimed to be a validated fleet baseline.

## Secured airgap

Declare boundary including hostOS, containers, stores, local UI/client, model, retrieval, update media and admin interfaces. A private internal network is allowed; external interfaces must be disconnected/disabled for functional tests. Avoid network_mode:none if the design needs inter-service links; isolation must preserve the declared internal architecture.

Threat model covers unauthorized operator/admin access, malformed inputs, tampered dependencies/configuration/evidence, exposed stored records/keys and removable-media updates. Verify:
- Non-root services, dropped unnecessary privileges/capabilities, read-only executable/configuration areas, allowlisted internal access.
- Authenticated roles with denied unauthorized read/write/admin tests, including protected logs/data and key storage.
- Pinned offline packages, verified trust anchors and signatures/hashes, SBOM, dated vulnerability data, remediation of applicable high/critical findings. Keep a documented applicability rationale; do not erase a real finding by relabeling it.
- Controlled offline update verification rejecting a modified package; restore a known-good version.
- Persistent access/configuration and recommendation audit; attempt edit/deletion and verify detection against a protected integrity anchor. A bare recomputable hash chain is insufficient against a privileged attacker.
- Protected data at rest and in internal transit as determined by the threat model and applicable handling requirements; inspect effective settings, not just configuration intent.
- Boot, execute all functions and replay without licensing,DNS,telemetry,package,model or external API fetches. Capture at boundary and inspect application/service logs. Negative connectivity probes alone do not establish functional independence.

Any mandatory-control failure, external-communication attempt, offline failure or unremediated applicable high/critical finding fails. Report scope limitations: no penetration-test completeness,ATO,CMMC or cryptographic validation claim from this finite demonstration. CMMC/award readiness remains separate corporate compliance work. CUI scope must be resolved before affected performance; do not treat existing public material as automatically newly designated CUI.

## Source and template mapping

Official topic and current public Q&A: https://www.navysbir.com/n26_5/DON26BX05-NP004.htm (public mirror, authenticated DSIP confirmation remains). Navyv2 and preface/template extracts retained under docs/F with September7 filenames. Page1 maps to Navy1.0/1.4;Page2 to1.1. NIST SP800-190 https://csrc.nist.gov/pubs/sp/800/190/final informs container threat/control choices; proposed control gates are not quotations of a Navy acceptance checklist.
