# Technical approach and work plan, rewrite (Steve Jobs voice, 2026-09-07)

Drop-in replacements for the "Technical approach" subsection of 1.0 and for all of 1.2. Same commitments as the assembled draft: nothing added, nothing measured, nothing promised that the SOW does not deliver. Bracketed items are company facts.

---

## 1.0, Technical approach

**One screen.** A navigation technician in a strait where GPS is lying needs three answers in the time it takes to look up: what do we actually know, what just broke, and what would settle it. We are building the screen that gives those three answers. Everything else in this proposal exists to make that screen trustworthy.

**What ships.** One container, built on an Iron Bank base. Inside it: the retrieval tools, the reference documents, the index over them, the compiled decision rules, and the display. Nothing reaches out. Nothing waits on a model. The firm has already prototyped this packaging and the display it drives in its nemesis8 tooling; Phase I adapts and measures it rather than starting from zero.

**Where the rules come from.** Not from a model at runtime. From the guidance documents, turned into code before the container is sealed. We do it with a training loop we call combative training:

1. A scenario generator produces failures: a faulted receiver, jamming, spoofing, two feeds that agree because they share a dependency, stale data, missing fields, and recovery. The generator keeps the truth to itself.
2. In the development environment, a language model attacks each scenario using the pipeline's own tools. It queries the reference documents, reads what comes back, and writes the rule code and the tests that handle the case. Every rule carries the citation of the clause it came from.
3. People review the code. It is versioned and regression-tested. Only compiled rules, the index, the reference data, and versioned procedures go into the container. The model stays in the training room. If a local model is present on the ship it writes explanations after the alert is already on screen, and the alert does not wait for it.
4. Every run leaves a labelled record: the scenario, what the tools returned, which rule version answered, and how it turned out. That record is the regression suite, and it is kept apart from the frozen held-out cases so the evaluation scores rules that never saw them. Agents touch training scenarios only, simulated in Phase I. The audit records the console writes at sea are shaped so they can feed retraining later, offline, under whatever handling rules apply.

**How fast.** The Government asks for under one second from ingestion to alert and initial recommendation. We think that is slow. Our gate is under 100 milliseconds from the moment a message arrives to the first displayed frame that shows both the alert and the recommendation, with security controls on. Any event at or above 100 milliseconds fails our gate. Retrieval cannot be allowed to threaten that number, so the procedure and evidence for an alert are fetched by a key precomputed from the anomaly state, with a design target under 30 microseconds; free-text search is for the operator's drill-down, never the alert path. These are targets we will measure and report, including every miss.

**When we don't know.** Sometimes the observations cannot tell a fault from jamming from spoofing. A console that guesses in that moment is worse than no console. Ours says the cause is not determined, names the cross-check that would determine it, and offers one button: acknowledge. The acknowledgement goes in the audit trail. The evaluation is built to reward that honesty on the no-win cases and to punish it on the cases where the evidence supports a decision.

**What we are not doing.** No new sensors, no navigation or fusion algorithms, no timing hardware, no ship control. The console presents; the operator decides. Iron Bank packaging is hardening-ready, not accreditation, and whether the Phase I demonstration must run on an Iron Bank image is a question we have put to the Government.

---

## 1.2 Phase I (Base and Option) Statement of Work

All work is performed by DeepBlue Dynamics at [performance location] on synthetic ASPN/pntOS-conformant data. No human-subject research, no shipboard access, and no Government-furnished equipment are required in the base or the option.

### Base period: six months from award

**B1. Decide what "right" means. Months 1–2.**
Turn the topic and the three questions above into a requirements-to-test matrix. Fix the source interfaces, the evidence dependencies the console will display, the threat model, the failure states, and the secured offline runtime. Freeze the held-out evaluation set, the acceptable-response sets, the critical cases, and the pass/fail rules before anyone tunes anything. Declare the hardware, the loads, where the clock starts and stops, and the measurement uncertainty.
Deliver: kickoff briefing; architecture; evaluation plan.

**B2. Build the world to break it in. Months 1–3.**
Adapters and a repeatable simulator for 3 to 8 sources at 1 to 10 Hz. Source identity, health, confidence, and age preserved; missing fields shown as missing, never invented. Nominal, recoverable, and unresolved cases covering faults, jamming, spoofing, stale data, and shared dependencies. Combative-training scenarios generated with their truth held by the evaluator, separate from the frozen held-out set. Simulator truth never enters the inference path.
Deliver: interface schema; versioned fixtures; replay harness; training scenario set.

**B3. Build the screen and the rules behind it. Months 2–4.**
The unified display. The rule-synthesis loop: model-assisted rule and test generation from the guidance documents and tool returns, human review, versioned rules with their citations, compiled into the runtime. Prerequisite-bound informational recommendations. The unresolved state with its acknowledge action. The alert path independent of any model. The retrieval index keyed by anomaly state, its lookup latency measured against the 30 microsecond target. Local retrieval, optional local inference, and drill-down explanations that the alert never waits for.
Deliver: integrated feasibility prototype; evidence-linked traces; rule provenance from each rule to its guidance clause.

**B4. Seal it, then try to break it. Months 3–6.**
Package the full stack for offline cold start. Verify least privilege, authenticated role-limited access, protected configuration and data, verified offline updates with a software bill of materials, and tamper-evident audit. Attack it: unauthorized access, a tampered package, an edited audit record. Run the latency gate with security on: four 30-minute corners at 3 and 8 sources and 1 and 10 Hz, a 30-minute sweep through 4 to 7 sources at mixed rates, a 60-minute soak at 8 sources and 10 Hz with bursts, at least 1,000 scored events, every one reported. Any event at or above 100 milliseconds fails our gate; the Government's one-second requirement is reported separately. Run the frozen 60-case evaluation with at least six recoverable cases per fault, jamming, and spoofing class, the critical-case checks, three repeats for determinism, and the twelve information-access tasks, against a synthetic fragmented-display control and an explanation-disabled configuration. Report every miss and every unsupported conclusion. Infer nothing about fleet reliability or operator performance from these numbers.
Deliver: test evidence; security findings; feasibility assessment; training dataset and regression results.

**B5. Say what we learned. Months 5–6.**
Demonstrate the prototype against the recorded evidence, objective by objective. Name the remaining risks, the interface dependencies, and the corrective work. Write the final report and the initial Phase II proposal with integration milestones and the transition plan.
Deliver: demonstration; final technical report; initial Phase II proposal.

Base reviews: kickoff in month 1, progress report in month 3, final demonstration and report in month 6. Final products: the prototype package, interface documentation, the scenario and replay package, and the evaluation evidence, with data-rights markings.

### Option period: six months from exercise

The option carries the work to the start of Phase II and is exercised on selection for Phase II. It does not depend on access to a ship or an operational system.

**O1. Fix what the base exposed. Option months 1–2.**
Work the prioritized deficiencies and extend scenario coverage. Keep the original evaluation results untouched; measure change with separately versioned regression and challenge sets.
Deliver: updated prototype; issue disposition; regression evidence.

**O2. Get ready to plug in. Option months 2–4.**
Refine the GPNTS-facing interface plan from whatever authorized specifications are available, and say plainly where assumptions stand in for specifications that are not. Exercise interface emulators, offline installation and update, and resource budgets on the declared test platform.
Deliver: interface-control draft; deployment package; dependency register.

**O3. Prove it still holds. Option months 4–6.**
Repeat the performance and security gates after the option changes. Refine the Phase II schedule, verification criteria, and transition risks. If operator research is proposed for Phase II, prepare the determination and approval plan that must precede it.
Deliver: option demonstration; updated evidence package; final option report; Phase II execution plan.

Option reviews: kickoff in month 1, progress report in month 3, final review and report in month 6. Accreditation, ECDIS certification, and operational deployment are outside this statement of work.

---

## 1.0, Software architecture

**Figure 2 (proposed): one line, left to right.** Sources → bus → rules → screen. Everything else hangs off that line and none of it is allowed to slow it down.

**The boundary.** One container image, one host, no network beyond it. The air gap is not a deployment option; it is the shape of the system. The display, the analytics, the retrieval, the audit store, and any local model all live inside the boundary and are started, tested, and replayed with the outside disconnected. The image is built in a disconnected stage from pinned, hash-verified packages with a software bill of materials, on an Iron Bank base. The build is the security gate: non-root services, read-only executable and configuration areas, dropped capabilities, no remote shells, authenticated role-limited access, protected data and keys, and an audit log anchored so a privileged edit is detectable. A failed control fails the build.

**The data.** Every source speaks one internal language: the open ASPN data model, code-generated from the published schema so a version change is a regeneration, not a rewrite. pntOS and other Navy message standards enter through thin adapters at the edge. A source that cannot carry integrity information, such as a consumer marine feed, is marked integrity-unavailable and is never allowed to drive a decision. Source identity, health, confidence, and age travel with every message and are never collapsed; the roster on the screen shows each source exactly as it reported itself.

**The bus.** A local publish-subscribe backbone carries every message and every decision. It is the only path between components, which is what makes the system replayable: record the bus, replay the bus, get the same screen.

**The rules.** The analytic core is compiled, deterministic code produced by the training loop described above. It runs two checks on every epoch: is each source plausible on its own, and do sources with different failure modes agree with each other. From those it derives one composite assessment, a triage class of nominal, fault, jamming, spoofing, or unresolved, and the evidence that drove it. The composite never replaces the source-level view; both are on screen at once. The output of the core is an anomaly-state key.

**The key.** That key is the trick that makes 100 milliseconds possible. Before the container is sealed, every reachable anomaly state is mapped to its informational recommendation, its procedure, and its evidence layout. At runtime the core emits the key and the screen looks it up. No search, no generation, no waiting. Free-text retrieval over the reference documents and any model-written explanation run on a second, relaxed path that starts after the frame is on screen and can fail without taking the alert with it.

**The screen.** An ECDIS-familiar layout, because that is what the technician already knows: chart in the centre, alert banner across the top with one acknowledge control, source roster on one side, resolution options on the other, an event timeline below. Nothing on it is decorative. Every element is bound to a named field on the bus through a deterministic connector, so what the operator sees is what the core computed, and the conformance annex says which elements follow a convention and which are ours.

**The record.** Every alert, its evidence, the recommendation, and the operator's acknowledgement are written to an append-only audit store with an integrity anchor and a non-GPS monotonic clock. The same record feeds three things: short-term replay for the operator, the evaluation harness for us, and, later and offline, retraining of the rules.

**The scaffolding.** The simulator and the scenario generator sit outside the product boundary. They emit the same ASPN messages a real source would, which is why they can be unplugged in Phase II and Government sources plugged in without touching the product. The evaluator holds the truth; the product never sees it.

---

*Drafting note: about 560 words for the technical approach, 640 for the architecture, and 760 for 1.2. The architecture text describes proposed structure; the console and the container packaging are the pieces already prototyped. Every gate, count, boundary, and exclusion matches the four-agent-accepted protocol and the user's 100 ms decision. Figure 2 should be drawn from this section as a single left-to-right line with the air-gap boundary as a box around everything but the sources and the scaffolding.*
