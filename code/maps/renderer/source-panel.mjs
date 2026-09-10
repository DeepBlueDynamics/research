const SVG_NS = 'http://www.w3.org/2000/svg';
const POINT_COLORS = ['#8ac8dc', '#d9bc81', '#b8a5dd', '#92c7ad', '#e2a293', '#becbd3'];
const finite = Number.isFinite;
const number = (value, digits = 1) => finite(value) ? value.toFixed(digits) : '—';

function setText(node, value) {
  if (node.textContent !== value) node.textContent = value;
}

function coordinate(value, positive, negative) {
  return `${Math.abs(value).toFixed(5)}° ${value < 0 ? negative : positive}`;
}

/** Render reported observations only. The caller owns simulation and scheduling. */
export function createSourcePanel(root, { onModeChange, onReset }) {
  const doc = root.ownerDocument;
  const cards = new Map();
  const dots = new Map();
  let destroyed = false;
  const previousLabel = root.getAttribute('aria-label');
  root.setAttribute('aria-label', 'Simulated navigation source controls');
  root.classList.add('source-panel');

  function element(tag, className, text) {
    const node = doc.createElement(tag);
    if (className) node.className = className;
    if (text !== undefined) node.textContent = text;
    return node;
  }

  function svgElement(tag, attributes = {}) {
    const node = doc.createElementNS(SVG_NS, tag);
    for (const [key, value] of Object.entries(attributes)) node.setAttribute(key, String(value));
    return node;
  }

  const heading = element('div', 'source-panel-heading');
  const titleGroup = element('div');
  titleGroup.append(element('div', 'source-eyebrow', 'SIMULATED INPUTS'), element('h2', '', 'SOURCES'));
  const reset = element('button', 'source-reset', 'Reset sources');
  reset.type = 'button';
  reset.title = 'Restore normal source modes and observations';
  const resetHandler = () => onReset();
  reset.addEventListener('click', resetHandler);
  heading.append(titleGroup, reset);
  const body = element('div', 'source-panel-body');
  const simulation = element('p', 'source-simulation');
  const instruction = element('p', 'source-instruction', 'Fault selectors inject test conditions; they do not diagnose sensor faults.');
  const roster = element('div', 'source-roster');
  const comparisonSection = element('section', 'source-comparison');
  comparisonSection.setAttribute('aria-label', 'Reported position comparison');
  comparisonSection.append(element('h3', '', 'POSITION COMPARISON'));
  const comparisonStatus = element('p', 'source-comparison-status');
  comparisonStatus.setAttribute('role', 'status');
  const separation = element('p', 'source-separation');
  const reference = element('p', 'source-reference');
  const scatter = element('div', 'source-scatter');
  const svg = svgElement('svg', { viewBox: '0 0 148 148', role: 'img', 'aria-label': 'Reported position offsets in metres' });
  const plotTitle = svgElement('title');
  svg.append(plotTitle);
  svg.append(svgElement('rect', { x: 18, y: 18, width: 112, height: 112, rx: 3, class: 'source-plot-frame' }));
  svg.append(svgElement('path', { d: 'M74 18V130M18 74H130', class: 'source-plot-axis' }));
  for (const [text, x, y] of [['N', 74, 11], ['E', 141, 78]]) {
    const label = svgElement('text', { x, y, 'text-anchor': 'middle', class: 'source-plot-axis-label' });
    label.textContent = text;
    svg.append(label);
  }
  const plotPoints = svgElement('g');
  svg.append(plotPoints);
  const scale = svgElement('text', { x: 74, y: 144, 'text-anchor': 'middle', class: 'source-plot-scale' });
  svg.append(scale);
  const legend = element('ul', 'source-offsets');
  scatter.append(svg, legend);
  const limitNote = element('p', 'source-note');
  const evidence = element('details', 'source-evidence');
  evidence.append(element('summary', '', 'View reported-position evidence'), reference, scatter, element('p', 'source-note', 'GNSS pair agreement alone is not independent confirmation. Comparison uses recent available reported positions from at least two source families—not vessel truth.'));
  comparisonSection.append(comparisonStatus, separation, limitNote, evidence);
  body.append(simulation, instruction, comparisonSection, roster);
  root.append(heading, body);

  function createCard(source) {
    const node = element('article', 'source-card');
    const top = element('div', 'source-card-top');
    const name = element('h3');
    const status = element('span', 'source-reception');
    top.append(name, status);
    const modeRow = element('div', 'source-mode-row');
    const label = element('label', 'source-mode-label', 'Test condition');
    const select = element('select');
    select.id = `source-${source.id}-mode`;
    label.htmlFor = select.id;
    const changeHandler = () => onModeChange(source.id, select.value);
    select.addEventListener('change', changeHandler);
    modeRow.append(label, select);
    const sample = element('p', 'source-sample');
    const last = element('div', 'source-last', 'LAST REPORTED OBSERVATION · NOT LIVE');
    const measurements = element('dl', 'source-measurements');
    const fields = new Map();
    for (const [key, title] of [['position', 'Position'], ['motion', 'Motion'], ['time', 'Clock reading'], ['offset', 'Model offset']]) {
      const group = element('div');
      const value = element('dd');
      group.append(element('dt', '', title), value);
      measurements.append(group);
      fields.set(key, { group, value });
    }
    const radar = element('details', 'source-radar');
    const radarSummary = element('summary');
    const targets = element('dl', 'source-targets');
    radar.append(radarSummary, targets);
    const modelDetails = element('details', 'source-model');
    const description = element('p', 'source-description');
    modelDetails.append(element('summary', '', 'Model assumptions'), description);
    node.append(top, modeRow, sample, last, measurements, radar, modelDetails);
    return { node, name, status, select, sample, last, fields, radar, radarSummary, targets, targetRows: new Map(), description, modeSignature: null, changeHandler };
  }

  function updateCard(card, source) {
    setText(card.name, source.label);
    card.select.setAttribute('aria-label', `${source.label}: injected test condition`);
    const signature = JSON.stringify(source.modes);
    if (card.modeSignature !== signature) {
      const options = source.modes.map(mode => {
        const option = element('option', '', mode.label);
        option.value = mode.value;
        return option;
      });
      card.select.replaceChildren(...options);
      card.modeSignature = signature;
    }
    // Do not rebuild or reassign a live select on every observation.
    if (card.select.value !== source.mode) card.select.value = source.mode;
    const reading = source.reading;
    const sampled = source.ageSeconds !== null && reading != null;
    const stale = sampled && !source.available;
    card.node.dataset.reception = source.available && sampled ? 'receiving' : stale ? 'last' : 'none';
    setText(card.status, source.available && sampled ? 'Receiving' : stale ? 'Last reading' : 'No samples');
    card.last.hidden = !stale;
    setText(card.sample, `Age ${source.ageSeconds === null ? '—' : number(source.ageSeconds)} sim s · ${number(source.hz, source.hz < 1 ? 2 : 0)} Hz nominal · #${source.sequence}`);
    const values = {};
    if (sampled) {
      if (Array.isArray(reading.position) && reading.position.length === 2 && reading.position.every(finite)) {
        values.position = `${coordinate(reading.position[1], 'N', 'S')} / ${coordinate(reading.position[0], 'E', 'W')}`;
      }
      const motion = [];
      if (finite(reading.headingDegrees)) motion.push(`HDG ${number(reading.headingDegrees)}° T`);
      if (finite(reading.courseDegrees)) motion.push(`COG ${number(reading.courseDegrees)}° T`);
      if (finite(reading.speedKnots)) motion.push(`SOG ${number(reading.speedKnots)} kn`);
      if (motion.length) values.motion = motion.join(' · ');
      if (finite(reading.timeMilliseconds)) {
        const clock = new Date(reading.timeMilliseconds);
        if (finite(clock.getTime())) values.time = clock.toISOString().replace('T', ' ').replace('Z', ' UTC');
      }
      if (finite(reading.clockOffsetMilliseconds)) values.offset = `${reading.clockOffsetMilliseconds >= 0 ? '+' : ''}${number(reading.clockOffsetMilliseconds, 2)} ms · model diagnostic, not measured UTC error`;
    }
    for (const [key, field] of card.fields) {
      field.group.hidden = values[key] === undefined;
      if (values[key] !== undefined) setText(field.value, values[key]);
    }
    const reportedTargets = sampled && Array.isArray(reading.targets) ? reading.targets : [];
    card.radar.hidden = reportedTargets.length === 0;
    setText(card.radarSummary, `${reportedTargets.length} synthetic radar targets · range / bearing${stale ? ' · LAST' : ''}`);
    const targetIds = new Set();
    for (const target of reportedTargets) {
      targetIds.add(target.id);
      let row = card.targetRows.get(target.id);
      if (!row) {
        const node = element('div');
        const label = element('dt');
        const value = element('dd');
        node.append(label, value);
        card.targets.append(node);
        row = { node, label, value };
        card.targetRows.set(target.id, row);
      }
      setText(row.label, String(target.id));
      setText(row.value, `${number(target.rangeMetres)} m / ${number(target.bearingDegrees)}° T`);
    }
    for (const [id, row] of card.targetRows) {
      if (!targetIds.has(id)) { row.node.remove(); card.targetRows.delete(id); }
    }
    setText(card.description, source.description || '');
    card.description.hidden = !source.description;
  }

  function updateComparison(comparison, sources) {
    const labels = new Map(sources.map(source => [source.id, source.label]));
    const states = { 'within-limit': 'Within demo comparison limit', divergent: 'Reported positions diverge', insufficient: 'Insufficient independent positions' };
    comparisonSection.dataset.status = comparison.status;
    setText(comparisonStatus, states[comparison.status] || 'Comparison unavailable');
    setText(separation, `Maximum reported separation: ${finite(comparison.maxSeparationMetres) ? `${number(comparison.maxSeparationMetres)} m` : '—'}`);
    const referenceName = labels.get(comparison.referenceId) || comparison.referenceId;
    setText(reference, referenceName ? `Offsets relative to ${referenceName}` : 'No reported-position reference');
    setText(limitNote, `${number(comparison.thresholdMetres, 0)} m demo limit · not an accuracy or integrity assessment.`);
    const offsets = comparison.offsets.filter(offset => finite(offset.eastMetres) && finite(offset.northMetres));
    scatter.hidden = !referenceName || offsets.length === 0;
    // The centre is a reported source, never the simulation's true position.
    let extent = 10;
    for (const offset of offsets) extent = Math.max(extent, Math.abs(offset.eastMetres), Math.abs(offset.northMetres));
    const magnitude = 10 ** Math.floor(Math.log10(extent));
    const limit = Math.ceil(extent / magnitude) * magnitude;
    setText(scale, `±${number(limit, 0)} m per axis`);
    setText(plotTitle, `Reported offsets from ${referenceName || 'no reference'}, east to right and north up; each axis spans minus to plus ${limit} metres. Coincident dots may overlap; all values appear in the legend.`);
    const ids = new Set();
    for (const offset of offsets) {
      ids.add(offset.id);
      let dot = dots.get(offset.id);
      if (!dot) {
        const circle = svgElement('circle', { r: 3.5, class: 'source-plot-dot' });
        const title = svgElement('title');
        circle.append(title);
        plotPoints.append(circle);
        const item = element('li');
        const swatch = element('span', 'source-offset-swatch');
        const text = element('span');
        item.append(swatch, text);
        legend.append(item);
        dot = { circle, title, item, swatch, text };
        dots.set(offset.id, dot);
      }
      const color = POINT_COLORS[Math.max(0, sources.findIndex(source => source.id === offset.id)) % POINT_COLORS.length];
      dot.circle.setAttribute('fill', color);
      dot.circle.setAttribute('cx', String(74 + offset.eastMetres / limit * 51));
      dot.circle.setAttribute('cy', String(74 - offset.northMetres / limit * 51));
      dot.swatch.style.backgroundColor = color;
      const text = `${labels.get(offset.id) || offset.id}: E ${number(offset.eastMetres)} / N ${number(offset.northMetres)} m`;
      setText(dot.text, text);
      setText(dot.title, text);
    }
    for (const [id, dot] of dots) {
      if (!ids.has(id)) { dot.circle.remove(); dot.item.remove(); dots.delete(id); }
    }
  }

  function render(snapshot) {
    if (destroyed) return;
    setText(simulation, `${snapshot.running ? 'Voyage running' : 'Voyage paused'} · ${number(snapshot.elapsedSeconds)} simulated s`);
    const ids = new Set(snapshot.sources.map(source => source.id));
    for (const [id, card] of cards) {
      if (!ids.has(id)) {
        card.select.removeEventListener('change', card.changeHandler);
        card.node.remove();
        cards.delete(id);
      }
    }
    let index = 0;
    for (const source of snapshot.sources) {
      let card = cards.get(source.id);
      if (!card) { card = createCard(source); cards.set(source.id, card); }
      // Stable roster updates leave focused selectors and open details in place.
      if (roster.children[index] !== card.node) roster.insertBefore(card.node, roster.children[index] || null);
      updateCard(card, source);
      index += 1;
    }
    updateComparison(snapshot.comparison, snapshot.sources);
  }

  function destroy() {
    if (destroyed) return;
    destroyed = true;
    reset.removeEventListener('click', resetHandler);
    for (const card of cards.values()) card.select.removeEventListener('change', card.changeHandler);
    cards.clear();
    dots.clear();
    heading.remove();
    body.remove();
    root.classList.remove('source-panel');
    if (previousLabel === null) root.removeAttribute('aria-label');
    else root.setAttribute('aria-label', previousLabel);
  }

  return { render, destroy };
}
