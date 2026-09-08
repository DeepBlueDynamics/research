# Technical approach insert (Kord's plan, 2026-09-07; drafted by Claude for Codex to integrate)

Placement: a "Technical approach" subsection at the end of 1.0, after the current paragraph 7, plus the SOW and Related Work deltas below. About 430 words for the 1.0 insert. Company-asserted facts are bracketed for confirmation. Runtime stays deterministic; the model is used at training time. All latency numbers other than the Government's one-second requirement are targets.

## Insert for 1.0 (technical approach)

**Technical approach.** The delivered capability is a trainable retrieval-augmented pipeline that drives the operator display. It ships as one container image built on an Iron Bank base, carrying the retrieval tools, the reference-document base, the retrieval index, and the compiled decision rules [company to confirm the prototype image, base, and date]. The firm has prototyped this packaging and the pipeline that drives the display; Phase I adapts and measures it, and does not start from an empty repository.

The decision rules are deterministic code derived from guidance documents: the public PNT interface standards, IMO alert and integrity guidance, resilient-PNT frameworks, and the representative procedures the Q&A permits performers to define. They are produced by a development-time training loop, which the firm calls combative training:

1. The scenario generator produces failure scenarios (fault, jamming, spoofing, shared dependency, stale or missing data, recovery) with evaluator-held truth.
2. A language model, running in the development environment, exercises the pipeline's own tools against each scenario: it queries the local retrieval service over the document base, inspects what is returned, and writes candidate rule code and test cases that handle the case. Each rule carries the citation of the guidance clause it embodies.
3. Rule code is reviewed, versioned, and regression-tested. Only compiled rules, the index, the reference data, and versioned procedures ship. No model participates in the runtime alert or recommendation path; a local model, if present, composes drill-down explanation after the alert is displayed and may be absent without loss of the initial response.
4. Training produces a labelled dataset of scenario runs, tool returns, rule versions, and outcomes that serves as regression evidence. Training scenarios are kept separate from the frozen held-out evaluation cases, so the no-win and recoverable cases score rules that never saw them.

Agents are used only on training scenarios, simulated in Phase I, never in the shipboard runtime. The pipeline is built to be retrained: audit records of alerts, evidence, recommendations, and operator acknowledgements are collected in a form that can feed later retraining offline, under whatever handling rules apply to that data, with representative Government data expected only in Phase II.

**Retrieval.** The local hybrid search (lexical, vector, graph) is keyed by anomaly state so that the procedure and evidence for a displayed alert are fetched by a precomputed key. The design target is a keyed lookup under 30 microseconds, with semantic search reserved for operator drill-down, so retrieval never threatens the proposed 100 ms gate. This is a target to be measured, not a result.

**Unresolved cases.** When the observations do not discriminate among fault, jamming, and spoofing, the rules produce an explicit unresolved state rather than a forced diagnosis. The console shows that the cause is not determined, names the accessible cross-check that would resolve it, and offers an acknowledge action that records the operator's decision in the audit trail. No-win scenarios reward this behaviour; nominal and recoverable scenarios penalize abstention when the evidence supports a response.

**Deployment.** Building on an Iron Bank base is hardening-ready packaging, not accreditation. Whether an Iron Bank image is required for the Phase I demonstration remains an open Government question; the secured-runtime gate applies regardless.

## Deltas for 1.2 SOW (Codex)

- B2: add "Generate combative-training scenarios and their evaluator-held truth as a dataset separate from the frozen held-out set."
- B3: add "Run the rule-synthesis loop: model-assisted rule and test generation from guidance documents and tool returns in the development environment; human review; versioned, cited rules compiled into the runtime. Key the retrieval index by anomaly state; measure keyed-lookup latency against the 30 microsecond target."
- B4 or B5 deliverables: add "training dataset, rule provenance (rule to guidance clause), and regression results."

## Delta for 1.3 Related Work (Grok)

Add one sentence: "The firm has prototyped a container built on an Iron Bank base image that packages the retrieval tools, reference data, and display driver [company to confirm image, base, and date]; it is hardening-ready packaging, not an accredited or fielded system."

## Notes for the user

- The under-30-microsecond figure is written as a keyed-lookup target. A hybrid semantic query cannot meet it; the text limits the target to the precomputed-key path and puts semantic search on drill-down.
- The training-time model must run where the scenario data lives. With synthetic ASPN/pntOS data that is the development environment; if any Government-furnished material is CUI, the training loop inherits that handling scope.
- Adding this insert raises the page count. It fits only with proportional 10-point typesetting and the page-8 sketch used as a figure in place of descriptive prose.
