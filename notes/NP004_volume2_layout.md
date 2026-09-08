# NP004 Volume 2 layout plan

Working layout recommendation, 2026-09-07. This is an outline, not a completed proposal or measured-results report.

The [Forward Edge sample](https://support.forwardedge.ai/en/articles/8864982-sample-winning-phase-i-sbir-dod), published January 28, 2024, presents a historical proposal with anonymized names. The publisher describes it as winning and warns that its information is over 20 years old; award status was not independently checked. Useful structural choices are an early problem/approach explanation, architecture illustration, numbered feasibility objectives, task-based work plan, related-work evidence, and a clear continuation/commercialization story. Use these as presentation guidance. Its section numbering, consultant percentages and IP arrangement are not requirements for NP004.

Our controlling structure is the [downloaded Navy Open Topics template](../corpus/F/templates/DON_SBIR_Phase_I_OPEN_TOPICS_Technical_Volume_2_Template_2026-0304.docx), with limits in [Navy v2](../docs/F/F1_NAVY_SBIR_26BX_R5_v2_2026-09-07.md). All content, including references, figures and any title material, must fit within ten pages.

| Pages | Navy heading | Proposed content and evidence |
|---|---|---|
| 1–2 | 1.0 Description of Proposed Phase I Technical Effort | Start with the ETV's degraded-PNT decision problem, the proposed unified workflow and the specific feasibility uncertainty. Show one architecture diagram and one annotated notional console view. Explain source confidence versus composite assessment and deterministic alerting versus later evidence retrieval. |
| 3 | 1.1 Phase I Technical Objectives | Four testable objectives: normalize representative sources; derive and explain composite status; present timely alerts/recovery aids; establish operator-workflow feasibility. For each, state method, output and acceptance criterion. Distinguish requirements, proposed targets and existing measurements. |
| 4–6 | 1.2 Phase I (Base and Option) Statement of Work | Separately label six-month base and six-month option. Use task rows with purpose, method, performer, effort, schedule, deliverable and evidence. Include base milestones, option milestones, risks and Phase II handoff. Keep names/hours consistent with Volume 3. |
| 7, first half | 1.3 Related Work | Select directly relevant existing software and interface artifacts. State what exists, what was measured, and what must be adapted. Cite the repo benchmark only with its actual retrieval-test scope and verification status. |
| 7, second half | 1.4 Defense Need | Identify the GPNTS transition target and intended ETV use case; explain improvement over fragmented displays. Describe dependencies and the transition path without implying government endorsement. |
| 8 | 2.0 Key Personnel | Compact PI/team table: employer, role, relevant qualifications, responsibilities and commitment. Include consultants. All biographies/resumes count toward the page limit. |
| 9 | 3.0 Commercialization/Transition Plan Summary | Lead with an achievable first product/customer segment, evidence of demand, buyer/integrator, alternatives, revenue approach and milestones. Distinguish prospective customers from committed customers. |
| 10 | Facilities/Equipment; references | Identify actual performance location, available development/evaluation resources, planned secure environment and justified purchases. Address template facilities/environmental statement. Reserve space for concise references. |

These are page budgets, not mandatory page breaks; rebalance once the draft is typeset. Do not add a separate cover or contents page that displaces technical evidence.

Proposed opening text, subject to company review:

> [Company] proposes to adapt its data-integration and decision-support software into a unified APNT operator interface for DON26BX05-NP004. During a representative destroyer transit through degraded or spoofed GNSS conditions, the interface will bring source health, composite confidence, alerts, supporting evidence and recovery choices into one workflow. Phase I will establish feasibility using synthetic inputs and a low-to-medium-fidelity demonstration, with a defined path to GPNTS integration in Phase II.

Confirm the company's ownership and maturity of the referenced platform before using that opening. The repo demonstrates research/design assets; this wording does not assert a fielded Navy product or completed integrated APNT system.

Suggested figures: (1) an architecture diagram showing ingest → normalization/analytics → alert and initial action → evidence drill-down, audit and replay; (2) an annotated notional console showing the operator's decision sequence. Keep captions useful and text legible at final PDF size. Do not reuse the repo's superseded DO-NOT-USE images.

Before drafting: obtain the firm/PI details, team effort and rates, existing-product evidence, commercialization facts and security-environment status. Follow the [filing outline](NP004_filing_outline_2026-09-07.md) for administrative volumes and current Q&A issues. Prior/pending support and detailed rights assertions belong in Volume 5 under the Navy instructions; keep technical evidence in Volume 2.
