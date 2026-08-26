# TPOC answers ↔ DON26BX05-NP004 / ASPN·pntOS / Hyperia

**From:** Brittany Lynn, PhD — PMW/A 520 S&T APM  
**Contact:** (564) 226-7392 · brittany.e.lynn.civ@us.navy.mil  
**Date received:** 2026-08-14  
**Topic:** DON26BX05-NP004 — NAVWAR Open Topic for Unified APNT Operational Awareness and Decision Support  
**Linked source:** ION GNSS+ “ASPN and pntOS: An Open-Source Ecosystem for Building Navigation Systems” (SBIR ref. 3)

These two answers pin Phase I. They do **not** change the topic’s “no new sensors / no new filters” rule. They tell us *how* the COP must live, and *what* Phase I is actually scored on.

---

## Q1 — How the COP may be built and run

> No requirements on how the COP is developed or run, **as long as** it is
> **off-network, standalone, containerized**, and deployed on **currently
> existing, fielded compute hardware**. More capable is better. They do
> **not** know what infrastructure / compute an agent-based approach needs.

| TPOC constraint | Topic language it locks | Implication |
|---|---|---|
| Off-network | “on-prem isolated runtimes”; “minimizing cybersecurity risks from cross-application dependencies” | No cloud, no reach-back, no model API at runtime. Weights and rules ship in the image. |
| Standalone | GPNTS + alternate PNT + SA as *inputs*, not as the host | COP is a guest on fielded compute, not a new box. |
| Containerized | Topic already names containerization as the preferred deploy pattern | One image, air-gapped pull, no cross-app deps. |
| Existing fielded hardware | Phase II “representative operational environment”; Phase III Fleet / PoR | Budget CPU/RAM/GPU like a GPNTS host, not a lab cluster. |
| “More capable the better” | AAI critical area; AI-enabled operator assistance | Local-on-the-boat agents are in-scope. More capable is better. |
| Unknown agent compute | They asked *us* what the approach requires | Answer with a **fielded-hardware envelope** (CPU/RAM/GPU, model size, latency). That is not a request for a no-agent product mode. |

**Hyperia correlation:** Hyperia is the *shape* of the agentic display (multi-source COP, agent can read and act). It is **not** the deployable. The Phase I artifact is a container that behaves like this workspace on disconnected, fielded hardware.

---

## Q2 — Data, Phase I product, and who the UI is for

> No representative data for Phase I. Use public **ASPN-type sample
> repositories**. Phase I is a **study** of (1) ingesting disparate data
> types and (2) generating a single-pane-of-glass that **conforms to DoD
> Navigation Display specifications**. A trained **navigator** should
> approach it with almost no learning curve, with **Navigation Warfare**
> information added in a naturally understandable way.

| TPOC constraint | Topic / paper language it locks | Implication |
|---|---|---|
| No Navy data in Phase I | Topic lists ASPN and pntOS as example data-types; ION paper is the public substrate | Do **not** wait on GPNTS feeds. Build the ingest study on public ASPN samples. |
| Phase I = study, not a sensor demo | “This topic does not seek new PNT/APNT sensing, algorithms, timing sources, or hardware” | Score on architecture + HMI, not on a better EKF. |
| Ingest disparate types | ASPN generic measurements; pntOS transport + state-modeling plugins | Plugin ingest is the Phase I technical core. |
| Single pane of glass | Topic COP / “single pane of glass” / decision-support | One navigator-facing surface, not a wall of apps. |
| DoD Navigation Display spec | HMI / UX / human-centered design in the topic | Conformance is a deliverable, not a polish pass. Find and cite the spec in Phase I. |
| Trained navigator, low learning curve | “improve operator understanding… reduce cognitive workload… complicate training” | Speak ECDIS / CIC / nav-plot language. Do not invent a Silicon-Valley ops dashboard. |
| NAVWAR added naturally | Status, confidence, threats, degradations, operational impact, recommended COA | NAVWAR is a *layer on the nav picture* (integrity, threat, confidence), not a second product. |

**Hyperia correlation:** This tab already is the study object — ION (how data is shaped) beside the SBIR (what the operator must see). Phase I writes that pattern down as: ASPN ingest plugins → nav-display-conformant glass → NAVWAR layer a navigator already understands.

---

## Glass delta — their *language*, not their *monitor*

Brittany’s sentence is easy to misread as “put NAVWAR on the ECDIS they already have.” It does not say that.

> generate the single-pane-of-glass display that **conforms to** the DoD
> Navigation Display specifications … a trained navigator … little learning
> curve … NAVWAR added in as naturally understandable a way as possible.

**Conforms to** = we draw a glass that a navigator already knows how to read.  
**Not** = we have monitor-level / framebuffer / VMS plugin access.

| Phrase | Sounds like | Actually means |
|---|---|---|
| “nav picture already in the topic” / NAVWAR added naturally | Overlay on their live ECDIS | NAVWAR is a **layer in the same visual grammar** (plot, integrity, threat, COA) — on a picture **we generate** |
| “DoD Navigation Display specifications” | Their existing monitor | The **spec** our COP must satisfy. We do not get the PoR display as a surface. |
| “trained navigator, near-zero curve” | Don’t change their screen | Don’t invent a new ops-wall. Speak ECDIS/VMS/CIC. Still our app. |
| “generate the single-pane-of-glass” | — | We **render**. Phase I product is a display study, not a tap. |
| “standalone, containerized, off-network” | — | Guest COP on fielded compute. Not a hook inside Navy ECDIS / VMS / IBS. |
| “multiple interfaces… fragmented” (topic problem) | — | They **do not** have one monitor we can hijack. That is why the topic exists. |
| “present information through GPNTS” | GPNTS is the screen | GPNTS is a **data path**. Presentation is our COP. |
| Hyperia pane → desk monitor | Proof we can route any screen | Demo of **source addressing**. Not a fielded ship interface. |

**Implication (yes, with the correction):**  
They want a navigator to walk up and already know the plot, with NAVWAR sitting on that plot instead of in a second app.  
They are **not** offering the fielded nav monitor as an API. We ingest data (ASPN samples in Phase I; GPNTS/NMEA/ICDs later) and **draw** the conformant glass ourselves.

## Agentic display = one glass, many sources, agents that read and act (including dynamic viz)

This is the product claim. Hyperia is the shape, not the shippable.

- **One operator surface.** Not a wall of apps. Nav-display grammar so a trained navigator has near-zero curve.
- **Many sources.** ASPN/pntOS-style connectors, GPNTS, alt-PNT, SA, a running 3D destroyer, whatever is actually up. Bind what exists.
- **An agent that can read and act.** Local-on-the-boat (Sigil-class: typed programs, tools, container, no reach-back). Reads the situation, recommends COA, **composes the picture**.
- **Dynamic viz is in.** Agents drive what is shown, emphasized, layered, spawned (3D ownship, threat geometry, integrity chrome) from the live situation. That is “build UIs from the situation” and “NAVWAR added naturally.”
- **Not in:** a new invented UI every watch, framebuffer tap of ECDIS, or viz that abandons DoD Navigation Display grammar.

`situation → connectors → agent reads/acts → dynamic viz on a stable nav chassis`

---

## What Phase I should therefore claim

1. **Ingest study** — map public ASPN (and pntOS-shaped) samples onto a small set of measurement classes; show a new source is a plugin, not a rewrite.
2. **Display study** — a single-pane COP that a Navy navigator recognizes, aligned to DoD Navigation Display specifications (identify the controlling spec(s) and show compliance).
3. **NAVWAR as native chrome** — confidence, spoof/jam/degrade, and recommended action sit on the same plot a navigator already uses. No extra “warfare app.”
4. **Deploy envelope** — off-net, standalone, one container, local models on fielded compute. Size the agent to the boat. Do **not** propose a no-agent product; do keep the nav glass live while the agent thinks.
5. **Not claimed** — new PNT sensors, new fusion math as the product, Navy-proprietary data, cloud inference.

## Hardware failure is not a no-agent requirement

If the host or the containers die, the ship is already in a casualty. GPNTS / VMS / ECDIS have their own backups. We do **not** owe a “no-model COP” for that. Local models on fielded iron are the offering.

The only in-container distinction: keep the nav-glass process off the LLM process so a model OOM does not blank the plot. That is process isolation, not a second product.

## pntOS is not “what the boat runs”

Topic language: *“Examples of these data-types include … ASPN and pntOS.”* Examples. Not exclusive.

Public GitHub (Aug 2026): `Open-PNT/pntOS-C` = **3 stars / 4 forks / 6 commits** (created Jan 2026). `Open-PNT/ASPN-ICD` = **8 stars**. Stars are a bad DoD signal — the real stack is GOTS/FOUO.

What is actually fielded on Navy ships is older and wider:

| Layer | What it is |
|---|---|
| **GPNTS** | Current PNT PoR; replacing **NAVSSI** as the shipboard PNT distribution service |
| **NAVSSI** | Legacy integrator still on many combatants |
| **WSN-7 / WSN-12** | Ring-laser inertial |
| **AN/WRN-6 (etc.)** | GPS user equipment |
| **Navy ECDIS / VMS / IBS** | The navigator’s actual glass (Northrop; ECDIS-N → Navy ECDIS PoR) |
| **NMEA + box ICDs** | How most of the above still talk |

pntOS / ASPN sit in the *future ingest* column: Army C5ISR + IS4S MOSA, community data model, cited so Phase I can study disparate ingest on public samples. The glass Brittany named is **DoD Navigation Display**, which maps to the ECDIS/VMS world, not to a 3-star GitHub API.

---

## Display-spec landscape (public record — BAA does not pick one)

The topic’s reference list is **not** a display standard. It is OPNAVINST **9420.1** (PNT policy), a GAO PNT report, the ASPN/pntOS paper, and the JADC2 summary. “DoD Navigation Display specifications” is Brittany’s phrase. The government has not numbered it in the BAA.

Three candidate tiers (cite in the proposal; ask TPOC which, if any, is controlling at Phase I):

**Tier 1 — Navy ECDIS look-and-feel (chart-based nav glass)**  
- **OPNAVINST 9420.2B** (4 Apr 2024): current Navy ECDIS instruction. Transitions ECDIS-N → Navy ECDIS PoR. ENC + AML (military layers: boundaries, Q-routes).  
- Nuance: a system that is **not** ECDIS-certified may only **enhance SA in support of safe navigation**. That is exactly an APNT decision-support overlay. Align look-and-feel without claiming certified-nav status. Companion cert path: **NAVSEAINST 9420.4** (NAVCERT).  
- Commercial stack under that look: IMO MSC.232(82) / A.817(19), IHO S-52 / S-57, IEC 61174, IEC 62288, IEC 60945.  
- Chart ground truth: DNC/MATT/TOD retired toward ENC (S-57), Submarine ENC, AML. Do not cite old MIL-PRF DNC as controlling.

**Tier 2 — shipborne nav display, not full ECDIS**  
IMO MSC.191(79) as amended by MSC.466(101) → IEC 62288; MSC.1/Circ.1609 (UI standardization); SN.1/Circ.243 (symbols/terms).

**Tier 3 — tactical / C2 COP (often the better fit for a GPNTS “single pane”)**  
- **MIL-STD-2525E** (31 Dec 2022): current joint military symbology (NATO APP-6(D) interoperable).  
- **MIL-STD-1472H** (15 Sep 2020): DoD human-engineering. Rev H adds information presentation and **ship bridge** design. Default HMI/HFE bar.

**GPNTS** (ACAT II, PMW/A 170) is a **data-fusion/distribution hub** replacing NAVSSI — not an ECDIS. Reading: COP/decision-support layer under 1472H/2525E; ECDIS-consistency (9420.2B / S-52 / 62288) only where we actually draw chart-based nav.

---

## Open items to close in the study

- Ask TPOC (by 25 Aug): *Should Phase I treat any display spec as controlling (9420.2B / IEC 62288 / 2525E / 1472H), or is the government agnostic at the feasibility stage?* Do not assume there is one numbered spec.
- Point at the **public ASPN sample repos** we will actually use.
- Write the **fielded-hardware envelope** so the agent question is answered in their language, not ours.
