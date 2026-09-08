# V4 forward: architecture review and implementation planning

User direction: work from notes/proposals/submission_draft_v4.md toward subsequent versions. Preserve v4 and earlier drafts. This is proposal/research iteration; do not claim implementation or measurements not performed.

Separate three representations:
1. Text corpus: small local text embedder plus lume lexical retrieval. Visual documents: a separate page-image/document embedder. User candidates include Qwen3-Embedding-0.6B, Jina Embeddings v4, and Qwen3-VL-Embedding. Verify primary model cards, licenses, dimensions, resource requirements and benchmark claims before adopting. Pin model revision, preprocessing, dimensions and index manifest; model changes require compatible rebuilds.
2. Telemetry: engineered situation vector, not stringified text. Include normalized source residuals, pairwise agreement, C/N0 and AGC trends, ages, rates, environment, and explicit missingness/dependencies. Optional contrastive encoder trained on labeled Skiff scenarios. Evaluate generalization on frozen heldouts with no training leakage. Distances indicate diagnostic analogues, not assurance or calibrated probability. Verify what attribution can actually establish.
3. Tool selection: signed enumerated informational-tool registry. Development-time LLM synthesizes playbook bindings, human review, compiled rules. Runtime exact anomaly-state lookup; nearest-scenario fallback returns labeled analogues, with frozen similarity/abstention threshold. No generated code or model-composed tool calls on the hot path. Bindings remain prerequisite-checked, argument-constrained and allowlisted. Audit match ID, distance, rule/registry versions and evidence. Unknown or unsupported cases return INDETERMINATE.

Derived documentation: separate authoritative and generated collections. Generated postmortems/rationales/query-answer pairs carry provenance and review state; guide retrieval but citation panel cites authoritative passages. Fetch documents only in development under licensing/manifest controls. Full runtime airgap.

Training environment: post-award loop must support local-only operation under applicable data controls. Verify exact Q&A CUI scope; don't assume public pre-award material is designated CUI or authorize cloud disclosure of controlled material.

Metrics: retrieval recall@k per trigger against golden set; situation encoder class separation and retrieval quality on heldouts including ambiguous/OOD cases; tool selection accuracy against observable-evidence oracle, with coverage/abstention and unsafe selection failures. Define denominators, baselines, failure criteria and uncertainty. All targets unmeasured unless verified.

Retain strict <100 ms input receipt at system boundary through first displayed frame with alert AND initial recommendation, security enabled; any >=100 ms fails proposed gate. Report Government <1 s separately. Measure fallback as well as exact lookup if it participates in that path. Keep current ACME-shaped narrative, explicit problem, contractor credibility, complete work plan and commercial story.
