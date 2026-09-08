# Antigravity Research Notes — NP004 Opening Pages (Pages 1 & 2)

**Author:** Antigravity (Independent Research & Authorship)  
**Date:** September 7, 2026  
**Target Topic:** NAVWAR Open Topic DON26BX05-NP004 (Unified Assured PNT Operational Awareness & Decision Support)  
**Output Files:** `antigravity_pages_1_2.md` and `antigravity_research_notes.md`

---

## 1. Mapping to Navy Technical Volume 2 Template

The user-assigned headings for this exercise ("Page 1: 1. Identification and Significance of the Problem / Operational Need" and "Page 2: 2. Phase I Technical Objectives & KPPs") directly map to the official **Department of the Navy Phase I Open Topics Technical Volume 2 Template** (`DON_SBIR_Phase_I_OPEN_TOPICS_Technical_Volume_2_Template_2026-0304.docx`, extracted in `docs/F/F5_Navy_Volume_2_and_5_templates_2026-09-07.md`).

| Exercise Draft Section (antigravity_pages_1_2.md) | Official Navy Volume 2 Template Section | Mapping & Synthesis Strategy |
| :--- | :--- | :--- |
| **Page 1: 1. Identification and Significance of the Problem / Operational Need** | **1.0 Description of Proposed Phase I Technical Effort** & **1.4 Defense Need** | Section 1.1–1.3 map to **Section 1.0** (technical effort description, problem statement, software innovation, air-gapped local stack, security gate, and scope boundaries). Section 1.1 & 1.2 map to **Section 1.4** (defense need, customer use-case on DDG-51, operational threat of coherent spoofing, and differentiation from current fragmented alternatives). |
| **Page 2: 2. Phase I Technical Objectives & Key Performance Parameters (KPPs)** | **1.1 Technical Objectives** | Objective 1–5 and the KPP Matrix map to **Section 1.1** (Phase I Technical Objectives). Enumerates specific technical questions, feasibility targets, hard subsecond latency limits, secured runtime controls, measurable performance parameters, test methods, and failure criteria. |

---

## 2. Firm Acceptance Constraints Integration

Per user clarification, three firm acceptance constraints govern the technical architecture and proposal feasibility claims:

### Constraint A: 100% Air-Gapped & Local AI/UI Stack
*   **Requirement:** The entire application stack—ingestion pub/sub bus, analytic correlation engines, local vector search engine (`lume serve`), local LLM rationale generator, and WebGL UI—must run **100% locally on the shipboard compute environment**.
*   **Implementation:** Zero external API dependencies, zero cloud phone-homes, and complete network egress isolation. Container network namespaces are configured with network egress disabled (`network_mode: none` or internal bridge only). All RAG/retrieval models (Shivvr embedder + local LLM) are kept warm in resident memory to prevent execution blocking.

### Constraint B: Secured Runtime & Automated Pre-Execution Security Gate
*   **Requirement:** Incorporate explicit container security controls and a pre-execution security verification gate without claiming prior ATO, accreditation, or CMMC certification is already achieved.
*   **Implementation:** 
    1. *Container Hardening Controls (NIST SP 800-190):* Non-root user execution (`UID 10001`), read-only root filesystems (`read_only: true`), dropped Linux capabilities (`cap_drop: [ALL]`), no SSH daemons, and state persistence strictly on external mounted volumes.
    2. *Pre-Execution Security Verification Gate:* An automated pipeline check executing Iron Bank readiness audits, Software Bill of Materials (SBOM) validation, static container vulnerability scanning (zero high/critical CVEs), and network egress probe verification prior to runtime launch.
    3. *Accreditation Framing:* Clearly framed as **"hardening-ready / security-gated"** infrastructure. CMMC Level 2 Self-Assessment obligations (NIST SP 800-171 Rev 2) are documented for post-award execution.

### Constraint C: Hard Subsecond Ingress-to-Alert Latency (< 1,000 ms, 0% Percentile Miss Allowance)
*   **Requirement:** End-to-end processing from message ingress on the pub/sub bus to rendered BAM alert banner + initial informational COA card on screen MUST be strictly `< 1,000 ms` with **zero percentile miss allowance (100.0% compliance, 0 misses out of N samples)**.
*   **Implementation:** 
    *   *Hot Path (Subsecond, Deterministic):* Ingest $\rightarrow$ ASPN normalizer $\rightarrow$ two-tier analytic core $\rightarrow$ composite confidence $\rightarrow$ compiled static anomaly-state lookup $\rightarrow$ WebGL alert banner & initial COA card render. Operates strictly in C++/Rust memory without network I/O, disk I/O, or LLM generation on the hot path.
    *   *Relaxed Path (Asynchronous Progressive Disclosure per Q&A 8/25/26):* Deep RAG vector retrieval, synthesized narrative rationale, and procedure runbook compilation execute asynchronously in the background. The operator receives the subsecond alert and initial COA card immediately, with detailed rationale surfacing via progressive-disclosure drill-down.
    *   *Verification Boundary:* High-resolution audit clock timing verification over $N=10,000$ consecutive test epochs. Failure criterion: any single epoch exceeding $1,000\text{ ms}$ ($>0$ misses out of $N=10,000$).

---

## 3. Authoritative Sources & Citation Register

All citations referenced in `antigravity_pages_1_2.md` and `antigravity_research_notes.md` are verified public documents and official topic captures located in the repository corpus.

1. **NAVWAR Topic DON26BX05-NP004 & Official Q&A Capture**
   *   **URL:** `https://www.navysbir.com/n26_5/DON26BX05-NP004.htm`
   *   **Local Provenance:** `docs/F/F2_DON26BX05-NP004_topic_2026-09-07.md` (retrieved 2026-09-07).
   *   **Key Clauses & Dates:**
       *   *Description:* Outlines requirement for unified operational experience, single pane of glass, decision support, and explicit exclusion of new PNT sensing/navigation algorithms/hardware.
       *   *Q&A 8/25/26:* Establishes subsecond latency requirement (< 1 s) for ingestion-to-initial-COA; confirms progressive disclosure for detailed evidence. Encourages explainable composite confidence.
       *   *Q&A 8/26/26:* Mandates API-first containerized architecture handling **3 to 8 simultaneous PNT sources updating at 1 Hz to 10 Hz**. Confirms primary integration target is GPNTS and shipboard ECDIS UX conventions.
       *   *Q&A 8/28/26:* Clarifies all Phase I data and activity is Controlled Unclassified Information (CUI); permits synthetic data conforming to open ASPN/pntOS. Confirms ECDIS is a **UX familiarity target** (not full formal ECDIS software certification). Allows commercial container runtime in Phase I.
       *   *Q&A 8/31/26:* Confirms adapted commercial data-integration/decision-support platforms are responsive.
       *   *Q&A 9/1/26:* Confirms **no human research is expected** under this SBIR. Confirms no facility security clearance expected for Phase II.

2. **GAO-21-320SP: Defense Navigation Capabilities**
   *   **Source:** U.S. Government Accountability Office, May 2021.
   *   **Local Provenance:** `docs/F/F3_GAO-21-320SP_Defense_Navigation.md`
   *   **Key Citations:** Highlight DOD dependence on GPS, vulnerabilities to electronic jamming/spoofing, and the critical operational need for resilient, multi-source APNT integration across military platforms.

3. **OPNAVINST 9420.1C: Positioning, Navigation, and Timing (PNT)**
   *   **Source:** Office of the Chief of Naval Operations, Department of the Navy, 2019.
   *   **Local Provenance:** `docs/F/F3_OPNAVINST_9420.1C_PNT.md`
   *   **Key Citations:** Establishes Navy policy for PNT governance, primary/alternate PNT source selection, and requirement for robust integrity monitoring across surface fleet combatants.

4. **ASPN and pntOS Open-Source Ecosystem Paper**
   *   **Source:** Integrated Solutions for Systems (IS4S) Team, *Proceedings of ION GNSS+ 2023*, pp. 1121-1132.
   *   **Local Provenance:** `docs/F/F3_..._ASPN_pntOS_2023.md` / `docs/A/`
   *   **Key Citations:** Defines open data structures and interface standards for All-Source Positioning and Navigation (ASPN YAML data model) and PNT Operating System (pntOS API).

5. **IMO MSC.302(87) & MIL-STD-1472H Standards**
   *   **Local Provenance:** `docs/B/`
   *   **Key Citations:** IMO Resolution MSC.302(87) adoption of Performance Standards for Bridge Alert Management (BAM §5–7). MIL-STD-1472H Human Engineering criteria for Human-Systems Integration (HSI §5.2).

6. **DHS Resilient PNT Conformance Framework v2.0, NIST IR 8323r1, NIST SP 800-190**
   *   **Local Provenance:** `docs/C/C2_NIST_IR_8323r1.md`, `docs/C/C3_DHS_Resilient_PNT_Conformance_Framework_v2.0.md`, `docs/E/`
   *   **Key Citations:** DHS PNT Conformance Levels 1–4; NIST IR 8323r1 Cybersecurity Framework Profile for PNT; NIST SP 800-190 Application Container Security Guide.

---

## 4. Scrutiny of KPPs, Assumptions, and Operational Boundaries

To ensure proposal credibility, technical parameters are strictly categorized into **Topic Source-Stated Requirements**, **Firm Acceptance Constraints**, **Proposed Measurable Targets**, and **Unverified Assumptions**.

```
+-----------------------------------------------------------------------------------+
|                            KPP CATEGORIZATION FRAMEWORK                           |
+-----------------------------------------------------------------------------------+
| 1. Topic Source-Stated Requirements & Firm Acceptance Constraints:                |
|    - 3 to 8 disaggregated PNT streams at 1 to 10 Hz (Q&A 8/26/26)                 |
|    - End-to-end ingestion-to-initial-COA latency < 1,000 ms (0% miss allowance)    |
|    - 100% air-gapped local AI/UI stack with zero external egress (User Mandate)   |
|    - Hardened runtime & pre-execution security verification gate (NIST SP 800-190)  |
|    - Open ASPN and pntOS message compatibility (Topic & Q&A 8/28/26)              |
|    - ECDIS-like UX familiarity alignment (Q&A 8/28/26)                            |
|                                                                                   |
| 2. Proposed Measurable Technical Targets (Offeror Design):                        |
|    - Anomaly triage accuracy ≥ 90% overall; 100% coherent spoofing detection       |
|    - 100% INDETERMINATE emission on held-out ambiguous Kobayashi Maru runs        |
|    - < 5% false abstention on nominal/recoverable runs                            |
|    - ≥ 50% task completion time reduction; System Usability Scale (SUS) ≥ 80       |
|                                                                                   |
| 3. Unverified Operational Assumptions:                                            |
|    - Containerized PoC satisfies Iron Bank readiness for Phase II transition      |
|    - CUI handling environment established prior to award performance              |
|    - Synthetic ASPN/pntOS data accurately mirrors GPNTS sensor dynamics           |
+-----------------------------------------------------------------------------------+
```

### Measurement Boundaries & Denominator / Sample Size Plan
*   **Hard Ingestion Latency Boundary (KPP-2):** Measured from the exact instant an ASPN message byte string hits the local pub/sub transport socket (`t_ingest`) to the instant the HTML5/WebGL canvas receives the callback rendering the BAM alert banner and COA card (`t_render`). Sample size: $N = 10,000$ consecutive epochs across 10 simulation runs. Failure criterion: $100\%$ must render in $<1,000\text{ ms}$ (0 misses allowed).
*   **Air-Gapped Egress Boundary (KPP-6):** Evaluated by auditing container network namespace routing tables and running automated outbound socket probes (`ping`, `curl` outbound attempts) during execution. Failure criterion: any unapproved outbound network connection.
*   **Pre-Execution Security Gate (KPP-7):** Evaluated during container build/launch. Scans container image for root execution, writable rootfs, undropped Linux capabilities, and known CVEs. Failure criterion: any unverified high/critical vulnerability or non-compliant runtime configuration.

---

## 5. The Kobayashi Maru Concept: Decision Uncertainty & Non-Binary Logic

### Why Binary Decision Logic Fails in Contested Navigation
Traditional automation forces binary decisions (e.g., `SELECT_PRIMARY` vs `SELECT_SECONDARY`). Under progressive EW degradation or sophisticated RF spoofing, binary decision logic introduces two dangerous failure modes:
1. **False Coercion / Catastrophic Reliance:** In a coherent spoofing attack, both GNSS receivers report valid signals and low estimated error. A binary selector will continue routing corrupt GPS positions into the navigation system, steering the vessel off-course.
2. **Alert Flicker / System Churn:** Under intermittent jamming near threshold boundaries, binary logic toggles rapidly between sources, inducing severe operator fatigue and eroding trust in the system.

### Technical Architecture of Non-Binary Decision Support
To address decision uncertainty, our software implements a three-part framework:
1. **Explicit `INDETERMINATE` Operational State:** When cross-family residual monitoring detects significant divergence between GNSS and independent dead-reckoning sources, but intra-family metrics are ambiguous, the core assigns an `INDETERMINATE` triage state.
2. **Verification COA Generation:** Instead of ordering an immediate source switch, the system emits non-destructive verification actions (e.g., "Request Radar Fix," "Execute Visual Bearing Cross-Check," "Confirm INS-Only Holdover").
3. **Balanced Evaluation Suite:** To prevent the decision engine from defaulting to permanent safety-abstention, the evaluation suite includes:
   *   *Nominal Scenarios:* Verifies < 5% false abstention and 0% false alerts.
   *   *Recoverable Scenarios:* Single-source hardware fault or localized barrage jamming where clear alternate sources exist (verifies rapid fallback execution).
   *   *Coherent Spoofing Scenarios:* Multi-receiver capture caught via cross-family residual checking.
   *   *Held-Out Ambiguous Scenarios (No-Win):* Contradictory feeds where ground-truth verification is impossible without external operator intervention (verifies 100% `INDETERMINATE` state emission).

---

## 6. Critical Q&A Scrutiny & Unresolved Filing Issues

1. **Phase I CUI Handling vs. Synthetic Performance:**
   *   *Q&A 8/28/26 State:* "All NP004 Phase I data and activity is controlled unclassified information."
   *   *Implication:* Even though Phase I relies on public ASPN/pntOS synthetic data, the proposal and project deliverables must be handled under CUI controls (NIST SP 800-171 Rev 2 / CMMC Level 2 Self-Assessment). Proposing firms must not claim that using synthetic data exempts the project from CUI handling or permits unrestricted public dissemination of performance metrics.

2. **Human Research Exemption & Usability Evaluation Scope:**
   *   *Q&A 9/1/26 State:* "No, the Government does not expect any human research to be performed under this SBIR."
   *   *Implication:* The planned Phase I usability walkthroughs and NASA-TLX/SUS evaluations must be framed strictly as routine engineering design reviews, SME feedback sessions, and human-systems integration (HSI) evaluations—**not** IRB-regulated human subject experiments.

3. **ECDIS UX Familiarity vs. Certification Scope:**
   *   *Q&A 8/28/26 State:* ECDIS similarity is a "UX familiarity target" to decrease training requirements for Electronics Technicians.
   *   *Implication:* Reduces proposal risk by clarifying that Phase I does not require formal type-approval or full certification against IMO S-52/S-57/S-63 standards, but rather compliance with ECDIS presentation conventions, color palettes, and BAM alert prioritization.

---

## 7. Final Submission Checklist & File Locations

*   `notes/proposals/opening_pages/antigravity_pages_1_2.md`
*   `notes/proposals/opening_pages/antigravity_research_notes.md`

Both files have been fully updated to incorporate the user's firm acceptance constraints (100% air-gapped local AI/UI stack, automated pre-execution security verification gate, and strict < 1,000 ms latency with 0% percentile miss allowance). Ready for shared draft convergence.
