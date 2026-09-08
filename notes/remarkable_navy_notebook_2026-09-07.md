# reMarkable "Navy" notebook, transcribed 2026-09-07

Source: reMarkable 2 notebook "Navy" (device ID 553d06fd…, last modified 2026-09-04), pulled over the USB web interface as PDF and rasterized. Files: `hmi-mockups/remarkable/navy_notebook_2026-09-07.pdf`, page renders `navy_p-1.png` … `navy_p-9.png` (200 dpi), crops `fig_console_sketch-8.png` and `fig_storyline_steps-8.png`. Transcription is my reading of Kord's handwriting; question marks in brackets are words I could not read with confidence.

## Page 1: four-panel storyboard (candidate figure)

Four framed panels with captions, like a pitch storyboard:

1. **Scenario**: a ship (destroyer silhouette) in a strait with coastline on both sides and weather.
2. **Display Solution, LOCAL FIRST**: a console screen showing a chart with the ship, its track, a dashed uncertainty circle, and a side panel labelled "GPS".
3. **Tech**: "Roaring Graphs, Vector Store, Containers (Iron Bank), Stored Procedures, Agent loop?"
4. **Team**: "Devs, Ex-CO [?] / Clint".

## Page 2: architecture and stack notes

Panels: **Data**; **SignalK**; **Sim** with "Docs" and "Code" beneath it, an arrow labelled "live data" to **pntOS?**; **N8** with an arrow down to **deploy**; **deploy** with an arrow to **BMP_25 sub-millisecond responses**; captions **Iron Bank** and **Hybrid Agentic Search**.

Reading: simulator emits live data in pntOS form; docs and code feed the sim; n8 drives deployment; the deployed stack targets sub-millisecond internal responses; retrieval is hybrid agentic search; Iron Bank is the container base.

## Page 3: hex-grid alert concept

"Hex grid alerts? speed, distance, direction." Sketches of a speed vector from an origin, a "directions" star of six arrows from a hex cell, a coastline, and a hex distance field numbered 1 to 5 outward from a marked cell with a second marked cell at distance 5. Checks and crosses beside a column labelled "distance". Idea: express alert severity or proximity on a hex grid by speed, distance, and direction to a hazard or to a spoofed position.

## Page 4: text generation notes

"Combative speech fragments assembly, training. Procedural prompt template generation, training." Then the three-step storyline: "① Heading 281° anomaly detected. ② Navigation status updated. ③ Navigation nominal."

## Page 5: procedural prompt notes

"prompt: 'the cat ran'. procedural prompt f(x): 'the $1 $2'. prompt combat: 'the $1 $2' versus '$1 is [graph?] against $2'." Template-based prompt construction with slots and an adversarial pairing.

## Page 6 (rotated): generation methods for text

"gen methods of text: data → LLM; LLM → data(); → code(); → graph(); training (builds index); embed. What sections relate to this scenario, to other sections? graph? embeddings?" A sketch of a document with sections a, b, c linked by arrows. Reading: relate scenario text to document sections via graph and embeddings; training builds the index.

## Page 7 (rotated): retrieval flow

"inputs → search → expand (graph) → augment. How do they chunk? graph chunks [tools?]. 1. GPS A lost, 2. Shoal, 3. Speed, 4. Depth, 5. ??? Tools: search, graph, vectors. docs → augments → tools → chunks." Reading: query expansion over a graph, augmentation from docs, an ordered list of anomaly cues (GPS A lost, shoal, speed, depth).

## Page 8: console sketch (primary candidate figure)

Top: the three-step storyline again, "① Heading 281° anomaly detected. ② Navigation status updated. ③ Navigation nominal."

Sketch of the operator console:
- Top banner: **"GPS A Degraded"** with an **[Ack]** button, banner highlighted yellow.
- Left column **"Resolution"**: numbered items 1, 2, 3, each with a short text line and a button.
- Centre: chart with ownship, a dotted alternate track, and waypoint diamonds along the planned track.
- Right column, source roster: **GPS A** (yellow, degraded), **GPS B** (plain), **INS** (green, good), "…" for further sources.
- Bottom strip: a timeline or log with three rows of entries.

This matches the shared draft's design: source-level state never collapsed (roster), a bridge-alert-style banner with acknowledge, informational resolution options, chart context, and a replayable event log.

## Page 9: submission outline and schedule

"Submission: 1. state problem, 2. team, 3. solution (simple), 4. tech (complex), 5. plan for execution → ??. 4th–26th, 20 days. Monday 7th: SAMPLES (me), Go or Navigator?? (Clint), Docs, SBIR stuff, tech stack inventory."

Reading: Kord's five-part narrative order for the proposal, a 20-day working window from the 4th to the 26th, and a Monday task split: samples for Kord; a go/no-go or "Navigator" question for Clint; docs, SBIR paperwork, and a tech-stack inventory.

## How these could be used

- Page 8 crop as Figure 2 (annotated notional console) in section 1.0, replacing several sentences of description; page 1 storyboard or page 2 as Figure 1 (architecture) if redrawn cleanly.
- The three-step storyline is a ready-made demo script: anomaly detected, status updated, nominal restored, which maps to detect, respond, recover.
- Page 9's order (problem, team, simple solution, complex tech, execution plan) is a narrative order, not the Navy template order; the template headings must stay, but the prose inside 1.0 can follow it.
