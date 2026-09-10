// Browser-local motion demonstrator, not a sensor or navigation solution.
const METRES_PER_NM = 1852;
const EARTH_RADIUS_METRES = 6371008.8;
const RADIANS = Math.PI / 180;
const INITIAL = { position: [56.45, 26.55], headingDegrees: 281, speedKnots: 18, timeScale: 10 };
const SOURCE = 'vessel-motion';

function destination(position, headingDegrees, metres) {
  const latitude = position[1] * RADIANS;
  const longitude = position[0] * RADIANS;
  const bearing = headingDegrees * RADIANS;
  const angle = metres / EARTH_RADIUS_METRES;
  const nextLatitude = Math.asin(Math.sin(latitude) * Math.cos(angle) + Math.cos(latitude) * Math.sin(angle) * Math.cos(bearing));
  const nextLongitude = longitude + Math.atan2(Math.sin(bearing) * Math.sin(angle) * Math.cos(latitude), Math.cos(angle) - Math.sin(latitude) * Math.sin(nextLatitude));
  return [((nextLongitude / RADIANS + 540) % 360) - 180, nextLatitude / RADIANS];
}

function clock(seconds) {
  const whole = Math.floor(seconds);
  const hours = Math.floor(whole / 3600);
  return (hours ? String(hours).padStart(2, '0') + ':' : '') + String(Math.floor(whole / 60) % 60).padStart(2, '0') + ':' + String(whole % 60).padStart(2, '0');
}

export function createVesselControls(map) {
  const node = (name) => document.getElementById('vessel-' + name);
  const fields = node('fields');
  const heading = node('heading');
  const headingRange = node('heading-range');
  const speed = node('speed');
  const speedRange = node('speed-range');
  const rate = node('rate');
  const toggle = node('toggle');
  const mode = node('mode');
  const positionOutput = node('position');
  const elapsedOutput = node('elapsed');
  const distanceOutput = node('distance');
  const events = new AbortController();
  const on = (element, event, handler) => element.addEventListener(event, handler, { signal: events.signal });
  const state = { ...INITIAL, position: INITIAL.position.slice(), running: false, ready: false, elapsedSeconds: 0, distanceNm: 0 };
  const listeners = new Set();
  const snapshot = () => ({ ...state, position: state.position.slice() });
  const publish = (reason) => {
    if (!listeners.size) return;
    const value = snapshot();
    for (const listener of listeners) listener(value, reason);
  };
  const trail = [state.position.slice(), state.position.slice()];
  const geometry = { type: 'FeatureCollection', features: [
    { type: 'Feature', properties: { kind: 'trail' }, geometry: { type: 'LineString', coordinates: trail } },
    { type: 'Feature', properties: { kind: 'vector' }, geometry: { type: 'LineString', coordinates: [] } },
  ] };
  let animation = 0;
  let lastFrame = 0;
  let lastReadout = 0;
  let sampledDistance = 0;
  let geometryDirty = true;

  const symbol = document.createElement('div');
  symbol.id = 'vessel-marker';
  symbol.className = 'vessel-marker';
  symbol.setAttribute('role', 'img');
  // Ownship chevron from the current apnt-console.html design reference.
  symbol.innerHTML = '<svg viewBox="-20 -20 40 40" width="40" height="40" aria-hidden="true"><path d="M0,-16 L9,14 L0,7 L-9,14 Z" fill="#163947" stroke="#eaf1f5" stroke-width="2" stroke-linejoin="round"/><path d="M0,-7 L0,4" stroke="#8ac8dc" stroke-width="1.5"/></svg>';
  const marker = new maplibregl.Marker({ element: symbol, anchor: 'center', rotationAlignment: 'map', pitchAlignment: 'map' })
    .setLngLat(state.position).setRotation(state.headingDegrees).addTo(map);

  const renderControls = (reason = 'controls') => {
    heading.value = headingRange.value = String(state.headingDegrees);
    speed.value = state.speedKnots.toFixed(1);
    speedRange.value = String(state.speedKnots);
    rate.value = String(state.timeScale);
    toggle.textContent = state.running ? 'Pause' : 'Run';
    toggle.setAttribute('aria-pressed', String(state.running));
    mode.textContent = state.ready ? (state.running ? 'RUNNING' : 'PAUSED') : 'LOADING';
    mode.dataset.running = String(state.running);
    symbol.setAttribute('aria-label', 'Simulated ownship, heading ' + state.headingDegrees + ' degrees true');
    marker.setRotation(state.headingDegrees);
    publish(reason);
  };

  const renderReadouts = () => {
    const [longitude, latitude] = state.position;
    positionOutput.textContent = Math.abs(latitude).toFixed(5) + '°' + (latitude >= 0 ? 'N' : 'S') + ' / ' + Math.abs(longitude).toFixed(5) + '°' + (longitude >= 0 ? 'E' : 'W');
    elapsedOutput.textContent = clock(state.elapsedSeconds);
    distanceOutput.textContent = state.distanceNm.toFixed(2) + ' NM';
    if (!state.ready || !geometryDirty) return;
    if (state.distanceNm > sampledDistance) {
      trail.push(state.position.slice());
      if (trail.length > 600) trail.splice(0, trail.length - 600);
      sampledDistance = state.distanceNm;
    }
    geometry.features[1].geometry.coordinates = [state.position.slice(), destination(state.position, state.headingDegrees, state.speedKnots * METRES_PER_NM / 10)];
    map.getSource(SOURCE).setData(geometry);
    geometryDirty = false;
  };

  const advance = (now) => {
    if (!state.running) return;
    const seconds = (now - lastFrame) / 1000 * state.timeScale;
    lastFrame = now;
    state.elapsedSeconds += seconds;
    const metres = state.speedKnots * METRES_PER_NM / 3600 * seconds;
    if (metres !== 0) {
      state.position = destination(state.position, state.headingDegrees, metres);
      state.distanceNm += metres / METRES_PER_NM;
      marker.setLngLat(state.position);
      geometryDirty = true;
    }
    publish('tick');
  };

  const frame = () => {
    // A queued RAF timestamp can predate a command event in the same frame.
    // Use the same monotonic clock as Run, Pause and heading/speed changes.
    const now = performance.now();
    advance(now);
    if (now - lastReadout >= 250) { renderReadouts(); lastReadout = now; }
    animation = requestAnimationFrame(frame);
  };

  const pause = () => {
    advance(performance.now());
    state.running = false;
    cancelAnimationFrame(animation);
    animation = 0;
    renderControls();
    renderReadouts();
  };

  on(toggle, 'click', () => {
    if (state.running) { pause(); return; }
    if (!state.ready || document.hidden) return;
    state.running = true;
    lastFrame = lastReadout = performance.now();
    renderControls();
    animation = requestAnimationFrame(frame);
  });

  const setHeading = (value) => {
    advance(performance.now());
    if (Number.isFinite(value)) state.headingDegrees = ((Math.round(value) % 360) + 360) % 360;
    geometryDirty = true;
    renderControls();
    renderReadouts();
  };
  const setSpeed = (value) => {
    advance(performance.now());
    if (Number.isFinite(value)) state.speedKnots = Math.max(0, Math.min(40, Math.round(value * 2) / 2));
    geometryDirty = true;
    renderControls();
    renderReadouts();
  };
  on(heading, 'change', () => setHeading(heading.valueAsNumber));
  on(headingRange, 'input', () => setHeading(headingRange.valueAsNumber));
  on(speed, 'change', () => setSpeed(speed.valueAsNumber));
  on(speedRange, 'input', () => setSpeed(speedRange.valueAsNumber));
  on(rate, 'change', () => {
    advance(performance.now());
    const value = Number(rate.value);
    if ([1, 10, 30].includes(value)) state.timeScale = value;
    renderControls();
    renderReadouts();
  });
  on(node('center'), 'click', () => map.easeTo({ center: state.position, zoom: Math.max(map.getZoom(), 10), duration: 450 }));
  on(node('reset'), 'click', () => {
    pause();
    Object.assign(state, INITIAL, { position: INITIAL.position.slice(), elapsedSeconds: 0, distanceNm: 0 });
    sampledDistance = 0;
    trail.splice(0, trail.length, state.position.slice(), state.position.slice());
    marker.setLngLat(state.position);
    geometryDirty = true;
    renderControls('reset');
    renderReadouts();
  });
  on(document, 'visibilitychange', () => { if (document.hidden && state.running) pause(); });

  const attach = () => {
    geometry.features[1].geometry.coordinates = [state.position.slice(), destination(state.position, state.headingDegrees, state.speedKnots * METRES_PER_NM / 10)];
    map.addSource(SOURCE, { type: 'geojson', data: geometry });
    map.addLayer({ id: 'vessel-trail', type: 'line', source: SOURCE, filter: ['==', ['get', 'kind'], 'trail'], layout: { 'line-join': 'round', 'line-cap': 'round' }, paint: { 'line-color': '#8ac8dc', 'line-width': 2, 'line-opacity': 0.65 } });
    map.addLayer({ id: 'vessel-vector', type: 'line', source: SOURCE, filter: ['==', ['get', 'kind'], 'vector'], paint: { 'line-color': '#eaf1f5', 'line-width': 1.4, 'line-dasharray': [3, 3], 'line-opacity': 0.8 } });
    state.ready = true;
    fields.disabled = false;
    renderControls();
    renderReadouts();
  };
  if (map.isStyleLoaded()) attach(); else map.once('load', attach);
  map.once('remove', () => {
    cancelAnimationFrame(animation);
    state.running = false;
    state.ready = false;
    events.abort();
    listeners.clear();
    marker.remove();
    map.off('load', attach);
  });
  renderControls();
  renderReadouts();
  return {
    state: snapshot,
    subscribe: (listener) => {
      listeners.add(listener);
      listener(snapshot(), 'initial');
      return () => listeners.delete(listener);
    },
  };
}
