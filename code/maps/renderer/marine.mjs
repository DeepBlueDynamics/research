// Geographic reference overlays. No depth sounder, chart datum or live aid status.
const DEPTH_SOURCE = 'marine-depths';
const AID_SOURCE = 'marine-aids';
const DEPTH_LAYERS = ['marine-depth-lines', 'marine-depth-labels'];
const AID_LAYERS = ['marine-aid-symbols', 'marine-aid-labels'];

export function createMarineLayers(map, vessel, root) {
  const events = new AbortController();
  const node = (tag, text) => { const value = document.createElement(tag); if (text !== undefined) value.textContent = text; return value; };
  const heading = node('h3', 'DEPTHS & AIDS');
  const controls = node('div');
  controls.className = 'marine-options';
  function toggle(id, label) {
    const wrapper = node('label');
    const input = node('input');
    input.type = 'checkbox'; input.id = id; input.checked = true; input.disabled = true;
    wrapper.append(input, document.createTextNode(label)); controls.append(wrapper);
    return input;
  }
  const depthToggle = toggle('marine-depth-toggle', 'Depth contours');
  const aidToggle = toggle('marine-aids-toggle', 'Buoys / lights');
  const depthValue = node('p', 'Loading regional marine data…');
  depthValue.id = 'marine-grid-depth';
  const note = node('p', 'ETOPO1 (2009) · 1′ grid · metres below MSL. Regional contours, not surveyed soundings or safe clearance.');
  const aidNote = node('p', 'OSM aid records; coverage and current operational status are not verified.');
  const provenance = node('a', 'Data provenance and limitations');
  provenance.href = '../marine/provenance.json'; provenance.target = '_blank'; provenance.rel = 'noopener';
  root.className = 'marine-controls';
  root.append(heading, controls, depthValue, note, aidNote, provenance);
  let grid = null;
  let ready = false;
  let error = null;
  let aidCount = 0;
  let buoyCount = 0;
  let lastGridKey = null;
  let latestSample = null;
  let popup = null;
  let alive = true;
  const data = {};

  function depthAt(position) {
    if (!grid || position[0] < grid.bounds[0] || position[0] > grid.bounds[2] || position[1] < grid.bounds[1] || position[1] > grid.bounds[3]) return null;
    const column = Math.round((position[0] - grid.longitudeStart) / grid.stepDegrees);
    const row = Math.round((position[1] - grid.latitudeStart) / grid.stepDegrees);
    const elevationMetres = grid.elevations[row]?.[column];
    if (!Number.isFinite(elevationMetres)) return null;
    return { column, row, position: [grid.longitudeStart + column * grid.stepDegrees, grid.latitudeStart + row * grid.stepDegrees], elevationMetres, depthMetres: elevationMetres < 0 ? -elevationMetres : null };
  }

  function updateDepth(position) {
    if (!grid) return;
    const sample = depthAt(position);
    const key = sample ? sample.row + ':' + sample.column : 'outside';
    if (key === lastGridKey) return;
    lastGridKey = key;
    latestSample = sample;
    depthValue.textContent = !sample ? 'Ownship is outside the regional depth grid.' : sample.depthMetres === null ? 'Nearest grid elevation: ' + sample.elevationMetres + ' m MSL · not a water-depth value' : 'Nearest grid depth to ownship: ~' + sample.depthMetres + ' m MSL';
  }

  function visibility(layers, visible) {
    for (const id of layers) if (map.getLayer(id)) map.setLayoutProperty(id, 'visibility', visible ? 'visible' : 'none');
  }
  depthToggle.addEventListener('change', () => visibility(DEPTH_LAYERS, depthToggle.checked), { signal: events.signal });
  aidToggle.addEventListener('change', () => visibility(AID_LAYERS, aidToggle.checked), { signal: events.signal });
  const unsubscribe = vessel.subscribe(truth => updateDepth(truth.position));

  function icon(kind) {
    const canvas = document.createElement('canvas');
    canvas.width = canvas.height = 40;
    const ctx = canvas.getContext('2d');
    ctx.scale(2, 2);
    ctx.lineWidth = 1.5; ctx.lineJoin = 'round'; ctx.strokeStyle = '#e2ebef'; ctx.fillStyle = '#102b3b';
    ctx.beginPath();
    if (kind === 'buoy') {
      ctx.moveTo(5, 12); ctx.lineTo(15, 12); ctx.lineTo(13, 16); ctx.lineTo(7, 16); ctx.closePath(); ctx.fill(); ctx.stroke();
      ctx.beginPath(); ctx.moveTo(10, 12); ctx.lineTo(10, 5); ctx.stroke();
      ctx.beginPath(); ctx.arc(10, 4, 1.5, 0, Math.PI * 2); ctx.fillStyle = '#8ac8dc'; ctx.fill();
      ctx.beginPath(); ctx.moveTo(3, 18); ctx.lineTo(17, 18); ctx.stroke();
    } else {
      ctx.moveTo(6, 17); ctx.lineTo(8, 6); ctx.lineTo(12, 6); ctx.lineTo(14, 17); ctx.closePath(); ctx.fill(); ctx.stroke();
      ctx.beginPath(); ctx.moveTo(10, 2); ctx.lineTo(10, 4); ctx.moveTo(3, 5); ctx.lineTo(6, 6); ctx.moveTo(14, 6); ctx.lineTo(17, 5); ctx.stroke();
    }
    return ctx.getImageData(0, 0, 40, 40);
  }

  function showAid(event) {
    const feature = event.features?.[0];
    if (!feature) return;
    const properties = feature.properties;
    const content = node('div'); content.className = 'marine-popup-content';
    content.append(node('h3', properties.name || properties.seamarkType));
    content.append(node('p', 'OSM map record · ' + properties.seamarkType));
    let tags = properties.tags;
    if (typeof tags === 'string') { try { tags = JSON.parse(tags); } catch { tags = {}; } }
    const details = node('dl');
    const labels = { 'seamark:buoy_lateral:category': 'Lateral category', 'seamark:buoy_cardinal:category': 'Cardinal category', 'seamark:light:character': 'Light character', 'seamark:light:colour': 'Light colour', 'seamark:light:period': 'Light period (s)', 'seamark:light:range': 'Light range (NM)' };
    if (properties.colour) { details.append(node('dt', 'Recorded colour'), node('dd', properties.colour)); }
    for (const [key, label] of Object.entries(labels)) if (tags?.[key]) details.append(node('dt', label), node('dd', String(tags[key])));
    content.append(details, node('p', 'Position: ' + feature.geometry.coordinates[1].toFixed(5) + '° N / ' + feature.geometry.coordinates[0].toFixed(5) + '° E'));
    if (properties.osmTimestamp) content.append(node('p', 'OSM edit: ' + properties.osmTimestamp + ' · not a field-verification date'));
    const link = node('a', 'Open source record');
    link.href = 'https://www.openstreetmap.org/node/' + encodeURIComponent(properties.osmId); link.target = '_blank'; link.rel = 'noopener';
    content.append(link, node('p', 'Not a current operational-status report or navigation chart symbol.'));
    popup?.remove();
    popup = new maplibregl.Popup({ maxWidth: '310px', className: 'marine-popup' }).setLngLat(feature.geometry.coordinates).setDOMContent(content).addTo(map);
  }
  const enterAid = () => { map.getCanvas().style.cursor = 'pointer'; };
  const leaveAid = () => { map.getCanvas().style.cursor = ''; };

  function attach() {
    if (!alive) return;
    map.addSource(DEPTH_SOURCE, { type: 'geojson', data: data.contours, attribution: '<a href="https://www.ncei.noaa.gov/products/etopo-global-relief-model" target="_blank" rel="noopener">NOAA NGDC ETOPO1 (2009)</a>' });
    map.addLayer({ id: DEPTH_LAYERS[0], type: 'line', source: DEPTH_SOURCE, paint: { 'line-color': '#5a93a8', 'line-width': ['case', ['>=', ['get', 'depthMetres'], 100], 1, 0.7], 'line-opacity': 0.65 } }, 'earth');
    map.addLayer({ id: DEPTH_LAYERS[1], type: 'symbol', source: DEPTH_SOURCE, layout: { 'symbol-placement': 'line', 'symbol-spacing': 280, 'text-field': ['concat', ['to-string', ['get', 'depthMetres']], ' m MSL'], 'text-font': ['Noto Sans Regular'], 'text-size': 10 }, paint: { 'text-color': '#a5c4d0', 'text-halo-color': '#102b3b', 'text-halo-width': 2 } }, 'earth');
    map.addSource(AID_SOURCE, { type: 'geojson', data: data.seamarks, attribution: '© <a href="https://www.openstreetmap.org/copyright" target="_blank" rel="noopener">OpenStreetMap contributors</a>' });
    map.addImage('marine-buoy', icon('buoy'), { pixelRatio: 2 });
    map.addImage('marine-light', icon('light'), { pixelRatio: 2 });
    map.addLayer({ id: AID_LAYERS[0], type: 'symbol', source: AID_SOURCE, layout: { 'icon-image': ['case', ['==', ['get', 'aidClass'], 'buoy'], 'marine-buoy', 'marine-light'], 'icon-size': ['interpolate', ['linear'], ['zoom'], 7, 0.7, 11, 1], 'icon-allow-overlap': true } });
    map.addLayer({ id: AID_LAYERS[1], type: 'symbol', source: AID_SOURCE, minzoom: 11, layout: { 'text-field': ['coalesce', ['get', 'name'], ['get', 'seamarkType']], 'text-font': ['Noto Sans Regular'], 'text-size': 10, 'text-anchor': 'top', 'text-offset': [0, 1.1] }, paint: { 'text-color': '#d3e0e5', 'text-halo-color': '#0c1922', 'text-halo-width': 1.5 } });
    map.on('click', AID_LAYERS[0], showAid);
    map.on('mouseenter', AID_LAYERS[0], enterAid);
    map.on('mouseleave', AID_LAYERS[0], leaveAid);
    ready = true;
    depthToggle.disabled = aidToggle.disabled = false;
    aidNote.textContent = buoyCount + ' buoys · ' + aidCount + ' total OSM aid records. Coverage is incomplete; current operational status is unverified.';
    updateDepth(vessel.state().position);
  }

  const loading = Promise.all(['bathymetry-grid.json', 'bathymetry-contours.geojson', 'seamarks.geojson'].map(async name => {
    const response = await fetch(new URL('../marine/' + name, import.meta.url), { signal: events.signal });
    if (!response.ok) throw new Error(name + ' HTTP ' + response.status);
    return response.json();
  })).then(([elevations, contours, seamarks]) => {
    if (!alive) return;
    grid = elevations; data.contours = contours; data.seamarks = seamarks;
    aidCount = seamarks.features.length;
    buoyCount = seamarks.features.filter(feature => feature.properties.aidClass === 'buoy').length;
    if (map.isStyleLoaded()) attach(); else map.once('load', attach);
  }).catch(cause => {
    if (!alive) return;
    error = cause.message;
    depthValue.textContent = 'Marine data unavailable: ' + error;
    root.classList.add('error');
  });

  map.once('remove', () => {
    alive = false;
    events.abort(); unsubscribe(); popup?.remove();
    map.off('load', attach);
    map.off('click', AID_LAYERS[0], showAid);
    map.off('mouseenter', AID_LAYERS[0], enterAid);
    map.off('mouseleave', AID_LAYERS[0], leaveAid);
  });
  return { loading, depthAt, state: () => ({ ready, error, aidCount, buoyCount, depthVisible: depthToggle.checked, aidsVisible: aidToggle.checked, gridSample: latestSample ? { ...latestSample, position: latestSample.position.slice() } : null }) };
}
