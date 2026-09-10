import { createNavigationSources } from './navigation-sources.mjs';
import { createSourcePanel } from './source-panel.mjs';

const SOURCE = 'navigation-reports';
const emptyGeometry = () => ({ type: 'FeatureCollection', features: [] });

// The simulator feeds observers; comparison and map reports consume observations only.
export function createNavigationControls(map, vessel, root) {
  const model = createNavigationSources(vessel.state());
  let geometry = emptyGeometry();
  let lastRender = -Infinity;
  let removed = false;

  function render() {
    if (removed) return;
    const snapshot = model.snapshot();
    panel.render(snapshot);
    const fresh = snapshot.sources.filter(source => source.available && source.reading?.position && source.ageSeconds <= 2 / source.hz);
    const reference = fresh.find(source => source.id === snapshot.comparison.referenceId);
    const features = [];
    for (const source of fresh) {
      features.push({ type: 'Feature', properties: { kind: 'fix', id: source.id, label: source.label, age: source.ageSeconds }, geometry: { type: 'Point', coordinates: source.reading.position } });
      if (reference && reference.id !== source.id) features.push({ type: 'Feature', properties: { kind: 'separation' }, geometry: { type: 'LineString', coordinates: [reference.reading.position, source.reading.position] } });
    }
    geometry = { type: 'FeatureCollection', features };
    map.getSource(SOURCE)?.setData(geometry);
    lastRender = performance.now();
  }

  function setMode(id, mode) {
    model.setMode(id, mode);
    render();
  }

  function reset() {
    model.reset(vessel.state());
    render();
  }

  const panel = createSourcePanel(root, { onModeChange: setMode, onReset: reset });
  const unsubscribe = vessel.subscribe((truth, reason) => {
    if (reason === 'reset') model.reset(truth);
    else model.advance(truth);
    if (reason !== 'tick' || performance.now() - lastRender >= 250) render();
  });

  function attach() {
    map.addSource(SOURCE, { type: 'geojson', data: geometry });
    map.addLayer({ id: 'navigation-separation', type: 'line', source: SOURCE, filter: ['==', ['get', 'kind'], 'separation'], paint: { 'line-color': '#8ac8dc', 'line-width': 1, 'line-opacity': 0.55, 'line-dasharray': [2, 3] } });
    map.addLayer({ id: 'navigation-fixes', type: 'circle', source: SOURCE, filter: ['==', ['get', 'kind'], 'fix'], paint: { 'circle-radius': 4, 'circle-color': '#102b3b', 'circle-stroke-width': 1.5, 'circle-stroke-color': '#8ac8dc' } });
    map.addLayer({ id: 'navigation-fix-labels', type: 'symbol', source: SOURCE, filter: ['==', ['get', 'kind'], 'fix'], layout: { 'text-field': ['get', 'label'], 'text-font': ['Noto Sans Regular'], 'text-size': 10, 'text-anchor': 'left', 'text-offset': [0.8, 0] }, paint: { 'text-color': '#d3e7ed', 'text-halo-color': '#0c1922', 'text-halo-width': 1.5 } });
  }

  if (map.isStyleLoaded()) attach(); else map.once('load', attach);
  map.once('remove', () => {
    removed = true;
    unsubscribe();
    panel.destroy();
    map.off('load', attach);
  });
  return { state: () => model.snapshot(), setMode, reset };
}
