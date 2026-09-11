# Juan de Fuca NOAA ENC app
Run from the repository root (no install or frontend build required):

    node code/maps/server/serve.mjs --host 0.0.0.0 --port 8095

Open http://127.0.0.1:8095/renderer/basemap.html on the server host.
If 8095 already serves this checkout, use that process instead of starting another.

The existing host service in Costly Chimpanzee serves the updated main page at
http://127.0.0.1:8095/renderer/basemap.html .

Main page: frozen, explicitly notional proposal scenario.
P toggles presentation chrome; Escape restores it. No injection controls appear
in the figure. The toolbar opens the retained interactive simulator at
renderer/simulator.html and the drawn architecture figure at renderer/architecture.svg.

The chart is a georeferenced PNG returned by NOAA's official ECDIS Display Service.
NOAA performs the S-57/S-52 portrayal; the existing Meridian-derived MapLibre stack
displays that result. This is not a local S-57 reader or certified ECDIS.
The PNG is stored without changing its bytes as a data URL in
juan-de-fuca-image.json. provenance.json records the request, extent and SHA-256.
NOAA identifyDatasets confirmed US4WA1IF and US4WA1IG as visible at the export
extent and size; cell-metadata.json records the intersecting cell metadata.
No ETOPO1 or OSM layer is loaded by the new main page or simulator.

The source models, ownship and synthetic radar references were relocated to Juan
de Fuca. All chart detail is fixed to the packaged snapshot. No additional detail
or updates are acquired while zooming. Grey outside the image means no packaged
chart coverage. The illustrative simulator can travel outside the image and reports
that condition. It does not constrain ship movement to safe water.

Scenario: 22:50Z, NAV_ET; position 62%, R95 76 m (nominal reference 12 m);
navigation 92%, timing 94% / 72 ns, overall 61%, margin approximately 18 min.
These are authored fixtures, not outputs of an assessment or margin engine.
GPS-A/B offsets from DR: (240,8) / (248,8) m.
INS/ALT/radar: (0,0), (4,-3), (-5,3) m; maximum mutual separation 10.82 m.
Matrix criterion 100 m; clock's positional comparisons are N/C.
R95 is drawn to map scale; the nominal 12 m reference is shown alongside it.
RF polygon, waypoints, track, procedure and assessment are simulated.
§4.2 is a representative procedure identifier, not an authoritative operational citation.

Figure 1 layout (1600×750 CSS pixels; target capture 3200×1500):
+-----------------------------------------------------------------------+
| SEXTANT / Juan de Fuca             NOTIONAL / SIMULATED / 22:50Z       |
| SUSPECTED GNSS DEGRADATION — ACKNOWLEDGE                 [ACKNOWLEDGE] |
+----------------+----------------------------------+-------------------+
| Six-row roster | Official NOAA ENC + ownship      | Four status tiles |
| GPS-A / GPS-B  | track + six-minute vector        | Time to margin    |
| INS / ALT PNT  | waypoints 1,2,3,4 + R95 ellipse   | Scatter + 6×6     |
| RADAR / CLOCK  | Reported interference polygon    | agreement matrix  |
| Shared GNSS    | NOAA cell / datum / scale stamp  | Finding + verdict |
| dependency     | North arrow                      | Procedure / steps |
+----------------+----------------------------------+-------------------+
| onset 22:41Z — NAV_ET ack 22:47Z — GNSS excluded 22:49Z — LIVE 22:50Z  |
| DEMONSTRATOR · NOT FOR NAVIGATION             authored fixture notice |
+-----------------------------------------------------------------------+

Figure 2: renderer/architecture.svg is editable vector artwork.
Only compiled artifacts move from the ashore panel to the aboard panel.
The return path is struck out; runtime does not train or update aboard.

Verification is being recorded in verification-juan-de-fuca.json. Historical
verification.json describes the older Hormuz demo and is not evidence for this UI.
