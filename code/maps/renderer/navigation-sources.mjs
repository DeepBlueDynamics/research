// Browser-local, illustrative observations only: no real sensors, RF model or accuracy claim.
const EARTH_RADIUS_METRES = 6371008.8;
const RADIANS = Math.PI / 180;
const KNOTS_TO_METRES_PER_SECOND = 1852 / 3600;
const COMPARISON_LIMIT_METRES = 100;
const RADAR_ORIGIN = [-123.57, 48.18];
// Deliberately synthetic reference points, not charted objects or navigation aids.
const RADAR_TARGETS = [
  { id: 'SYN-1', position: [-123.65, 48.19] },
  { id: 'SYN-2', position: [-123.50, 48.19] },
  { id: 'SYN-3', position: [-123.49, 48.14] },
];
const MODE_LABELS = {
  normal: 'Normal', offline: 'Offline', 'bad-data': 'Bad data',
  jammed: 'Jammed (injected)', spoofed: 'Spoofed (injected)',
  drift: 'Drift', holdover: 'Holdover',
};
const DEFINITIONS = [
  { id: 'gps-a', label: 'GPS-A', family: 'gnss', hz: 5,
    description: 'Simulated GNSS fix, COG and SOG; bounded deterministic perturbations. Fault modes are injected, not diagnosed.',
    modes: ['normal', 'offline', 'bad-data', 'jammed', 'spoofed'] },
  { id: 'gps-b', label: 'GPS-B', family: 'gnss', hz: 2,
    description: 'Separate simulated GNSS receiver; shares the GNSS family and coherent spoof displacement with GPS-A.',
    modes: ['normal', 'offline', 'bad-data', 'jammed', 'spoofed'] },
  { id: 'ins', label: 'INS', family: 'inertial', hz: 10,
    description: 'Dead reckoning from the initial position and commanded heading/speed, not GPS. Accumulated drift persists until reset.',
    modes: ['normal', 'offline', 'bad-data', 'drift'] },
  { id: 'alt-pnt', label: 'Alternate PNT / eLoran', family: 'terrestrial', hz: 1,
    description: 'Illustrative eLoran-like fix-level channel only; no transmitters, waveform, propagation or RF diagnosis.',
    modes: ['normal', 'offline', 'bad-data', 'jammed', 'drift'] },
  { id: 'radar', label: 'Radar fix', family: 'radar', hz: 1,
    description: 'Fix reconstructed from three synthetic range/true-bearing observations. SYN-1: 123.65W, 48.19N; SYN-2: 123.50W, 48.19N; SYN-3: 123.49W, 48.14N. Not charted targets.',
    modes: ['normal', 'offline', 'bad-data'] },
  { id: 'clock', label: 'Clock', family: 'clock', hz: 10,
    description: 'Simulated UTC. Offset is a model diagnostic, not independently measured UTC error. Holdover and drift use illustrative exaggerated rates.',
    modes: ['normal', 'offline', 'bad-data', 'holdover', 'drift'] },
].map((definition) => Object.freeze({ ...definition, modes: Object.freeze(definition.modes.map((value) => Object.freeze({ value, label: MODE_LABELS[value] }))) }));

const wrapDegrees = (degrees) => ((degrees % 360) + 360) % 360;
const wrapLongitude = (degrees) => ((degrees + 180) % 360 + 360) % 360 - 180;

function destination(position, headingDegrees, metres) {
  const latitude = position[1] * RADIANS;
  const longitude = position[0] * RADIANS;
  const bearing = headingDegrees * RADIANS;
  const angle = metres / EARTH_RADIUS_METRES;
  const nextLatitude = Math.asin(Math.sin(latitude) * Math.cos(angle) + Math.cos(latitude) * Math.sin(angle) * Math.cos(bearing));
  const nextLongitude = longitude + Math.atan2(Math.sin(bearing) * Math.sin(angle) * Math.cos(latitude), Math.cos(angle) - Math.sin(latitude) * Math.sin(nextLatitude));
  return [wrapLongitude(nextLongitude / RADIANS), nextLatitude / RADIANS];
}

function displacement(position, eastMetres, northMetres) {
  return destination(position, Math.atan2(eastMetres, northMetres) / RADIANS, Math.hypot(eastMetres, northMetres));
}

function separation(from, to) {
  const latitudeA = from[1] * RADIANS;
  const latitudeB = to[1] * RADIANS;
  const longitudeDelta = wrapLongitude(to[0] - from[0]) * RADIANS;
  const halfChord = Math.sin((latitudeB - latitudeA) / 2) ** 2 + Math.cos(latitudeA) * Math.cos(latitudeB) * Math.sin(longitudeDelta / 2) ** 2;
  const distanceMetres = 2 * EARTH_RADIUS_METRES * Math.asin(Math.sqrt(Math.max(0, Math.min(1, halfChord))));
  const bearing = Math.atan2(Math.sin(longitudeDelta) * Math.cos(latitudeB), Math.cos(latitudeA) * Math.sin(latitudeB) - Math.sin(latitudeA) * Math.cos(latitudeB) * Math.cos(longitudeDelta));
  return { distanceMetres, eastMetres: distanceMetres * Math.sin(bearing), northMetres: distanceMetres * Math.cos(bearing), bearingDegrees: wrapDegrees(bearing / RADIANS) };
}

function finitePosition(position) {
  return Array.isArray(position) && position.length === 2 && position.every(Number.isFinite) && Math.abs(position[0]) <= 180 && Math.abs(position[1]) <= 90;
}

function copyTruth(truth) {
  if (!finitePosition(truth.position) || !Number.isFinite(truth.headingDegrees) || !Number.isFinite(truth.speedKnots) || truth.speedKnots < 0 || !Number.isFinite(truth.elapsedSeconds) || truth.elapsedSeconds < 0) {
    throw new RangeError('Navigation sources require finite vessel position, heading, nonnegative speed and elapsed time.');
  }
  return { position: truth.position.slice(), headingDegrees: wrapDegrees(truth.headingDegrees), speedKnots: truth.speedKnots, elapsedSeconds: truth.elapsedSeconds, running: Boolean(truth.running) };
}

// The radar generator and inverse use the same fixed local tangent-plane approximation.
function radarCoordinates(position) {
  return [wrapLongitude(position[0] - RADAR_ORIGIN[0]) * RADIANS * EARTH_RADIUS_METRES * Math.cos(RADAR_ORIGIN[1] * RADIANS), (position[1] - RADAR_ORIGIN[1]) * RADIANS * EARTH_RADIUS_METRES];
}
const RADAR_POINTS = RADAR_TARGETS.map((target) => ({ id: target.id, coordinates: radarCoordinates(target.position) }));

function radarReading(position, seconds, mode) {
  const observer = radarCoordinates(position);
  if (mode === 'bad-data') { observer[0] += 650; observer[1] -= 420; }
  let east = 0;
  let north = 0;
  const targets = RADAR_POINTS.map((target, index) => {
    const dx = target.coordinates[0] - observer[0];
    const dy = target.coordinates[1] - observer[1];
    const rangeMetres = Math.max(0, Math.hypot(dx, dy) + 3 * Math.sin(seconds * 0.21 + index * 2));
    const bearingDegrees = wrapDegrees(Math.atan2(dx, dy) / RADIANS + 0.012 * Math.sin(seconds * 0.17 + index));
    east += target.coordinates[0] - rangeMetres * Math.sin(bearingDegrees * RADIANS);
    north += target.coordinates[1] - rangeMetres * Math.cos(bearingDegrees * RADIANS);
    return { id: target.id, rangeMetres, bearingDegrees };
  });
  return {
    position: [wrapLongitude(RADAR_ORIGIN[0] + east / 3 / (EARTH_RADIUS_METRES * RADIANS * Math.cos(RADAR_ORIGIN[1] * RADIANS))), RADAR_ORIGIN[1] + north / 3 / (EARTH_RADIUS_METRES * RADIANS)],
    targets,
  };
}

function compare(sources) {
  // No truth, fault modes or modeled error enters this measurement-only comparison.
  const usable = sources.filter((source) => source.available && source.ageSeconds !== null && Number.isFinite(source.ageSeconds) && source.ageSeconds >= 0 && source.ageSeconds <= 2 / source.hz && finitePosition(source.reading?.position));
  const pairs = [];
  let maxSeparationMetres = null;
  for (let a = 0; a < usable.length; a++) {
    for (let b = a + 1; b < usable.length; b++) {
      const distanceMetres = separation(usable[a].reading.position, usable[b].reading.position).distanceMetres;
      pairs.push({ a: usable[a].id, b: usable[b].id, distanceMetres });
      maxSeparationMetres = Math.max(maxSeparationMetres ?? 0, distanceMetres);
    }
  }
  // The first eligible report is only a display origin, never a selected truth source.
  const reference = usable[0];
  const offsets = usable.map((source) => {
    const { eastMetres, northMetres } = separation(reference.reading.position, source.reading.position);
    return { id: source.id, eastMetres, northMetres };
  });
  const enoughFamilies = new Set(usable.map((source) => source.family)).size >= 2;
  return { status: !enoughFamilies ? 'insufficient' : maxSeparationMetres > COMPARISON_LIMIT_METRES ? 'divergent' : 'within-limit', thresholdMetres: COMPARISON_LIMIT_METRES, maxSeparationMetres, referenceId: reference?.id ?? null, offsets, pairs };
}

function copyReading(reading) {
  if (!reading) return null;
  const copy = { ...reading };
  if (reading.position) copy.position = reading.position.slice();
  if (reading.targets) copy.targets = reading.targets.map((target) => ({ ...target }));
  return copy;
}

export function createNavigationSources(initialTruth, { epochMilliseconds = Date.now() } = {}) {
  if (!Number.isFinite(epochMilliseconds)) throw new RangeError('A finite simulated UTC epoch is required.');
  let truth;
  let originSeconds;
  let insPosition;
  const channels = DEFINITIONS.map((definition) => ({ definition }));

  function insStep(position, seconds, command) {
    const drifting = channels[2].mode === 'drift';
    return destination(position, command.headingDegrees + (drifting ? 2 : 0), (command.speedKnots + (drifting ? 0.6 : 0)) * KNOTS_TO_METRES_PER_SECOND * seconds);
  }

  function readingFor(channel, sampleTruth, sampleIns, seconds) {
    const { id } = channel.definition;
    const mode = channel.mode;
    const time = seconds - originSeconds;
    const modeTime = Math.max(0, seconds - channel.modeSince);
    if (id === 'clock') {
      let offset = 0.4 * Math.sin(time * 0.09);
      if (mode === 'bad-data') offset = 120000 + 1000 * Math.sin(time * 0.3);
      if (mode === 'holdover') offset = channel.clockEntryOffset + modeTime * 2;
      if (mode === 'drift') offset = channel.clockEntryOffset + 500 + modeTime * 40;
      // Resetting source faults must not rewind the voyage's simulated UTC.
      return { timeMilliseconds: epochMilliseconds + seconds * 1000 + offset, clockOffsetMilliseconds: offset };
    }
    if (id === 'radar') return radarReading(sampleTruth.position, time, mode);
    if (id === 'ins') {
      return {
        position: mode === 'bad-data' ? displacement(sampleIns, -900, 650) : sampleIns.slice(),
        headingDegrees: wrapDegrees(sampleTruth.headingDegrees + (mode === 'drift' ? 2 : mode === 'bad-data' ? 18 : 0)),
        speedKnots: sampleTruth.speedKnots + (mode === 'drift' ? 0.6 : mode === 'bad-data' ? 6 : 0),
      };
    }
    if (id === 'alt-pnt') {
      let east = 12 * Math.sin(time * 0.08 + 0.5);
      let north = 10 * Math.cos(time * 0.07 + 1);
      if (mode === 'bad-data') { east -= 1300; north -= 850; }
      if (mode === 'drift') { east += 15 + modeTime * 1.2; north -= 10 + modeTime * 0.7; }
      return { position: displacement(sampleTruth.position, east, north) };
    }
    const phase = id === 'gps-a' ? 0 : 2.1;
    let east = 4 * Math.sin(time * 0.31 + phase) + 2 * Math.cos(time * 0.13 + phase);
    let north = 5 * Math.cos(time * 0.23 + phase);
    let velocityEast = sampleTruth.speedKnots * KNOTS_TO_METRES_PER_SECOND * Math.sin(sampleTruth.headingDegrees * RADIANS);
    let velocityNorth = sampleTruth.speedKnots * KNOTS_TO_METRES_PER_SECOND * Math.cos(sampleTruth.headingDegrees * RADIANS);
    if (mode === 'bad-data') { east += 1800; north -= 850; velocityEast += 7; velocityNorth -= 3; }
    // Common displacement and velocity field for both GNSS receivers, regardless of activation order.
    if (mode === 'spoofed') { east += 250 + time * 0.8; north += 180 + time * 0.45; velocityEast += 0.8; velocityNorth += 0.45; }
    return {
      position: displacement(sampleTruth.position, east, north),
      courseDegrees: wrapDegrees((Math.hypot(velocityEast, velocityNorth) > 1e-9 ? Math.atan2(velocityEast, velocityNorth) / RADIANS : sampleTruth.headingDegrees) + 0.12 * Math.sin(time * 0.19 + phase)),
      speedKnots: Math.max(0, Math.hypot(velocityEast, velocityNorth) / KNOTS_TO_METRES_PER_SECOND + 0.025 * Math.sin(time * 0.29 + phase)),
    };
  }

  function emit(channel, sampleTruth, sampleIns, seconds) {
    channel.reading = readingFor(channel, sampleTruth, sampleIns, seconds);
    channel.sampleSeconds = seconds;
    channel.sequence += 1;
  }

  function reset(nextTruth) {
    truth = copyTruth(nextTruth);
    originSeconds = truth.elapsedSeconds;
    insPosition = truth.position.slice();
    for (const channel of channels) {
      Object.assign(channel, { mode: 'normal', modeSince: originSeconds, clockEntryOffset: 0, sampleSeconds: null, sequence: 0, reading: null });
      emit(channel, truth, insPosition, originSeconds);
    }
  }

  function setMode(id, mode) {
    const channel = channels.find((candidate) => candidate.definition.id === id);
    if (!channel || !channel.definition.modes.some((option) => option.value === mode)) throw new RangeError('Unknown navigation source or mode: ' + id + '/' + mode);
    if (channel.mode === mode) return;
    channel.clockEntryOffset = channel.reading?.clockOffsetMilliseconds ?? 0;
    channel.mode = mode;
    channel.modeSince = truth.elapsedSeconds;
    // Controls apply immediately, including while paused. Outages retain the last observation.
    if (mode !== 'offline' && mode !== 'jammed') emit(channel, truth, insPosition, truth.elapsedSeconds);
  }

  function advance(nextTruth) {
    const next = copyTruth(nextTruth);
    const seconds = next.elapsedSeconds - truth.elapsedSeconds;
    if (seconds < 0) throw new RangeError('Elapsed time moved backwards; call reset with the new voyage state.');
    if (seconds > 0) {
      const path = separation(truth.position, next.position);
      for (const channel of channels) {
        if (channel.mode === 'offline' || channel.mode === 'jammed') continue;
        const hz = channel.definition.hz;
        const tick = Math.floor((next.elapsedSeconds - originSeconds) * hz + 1e-9);
        const sampleSeconds = Math.min(next.elapsedSeconds, originSeconds + tick / hz);
        if (sampleSeconds <= channel.sampleSeconds + 1e-9) continue;
        const partialSeconds = sampleSeconds - truth.elapsedSeconds;
        const fraction = Math.max(0, Math.min(1, partialSeconds / seconds));
        const sampleTruth = {
          position: destination(truth.position, path.bearingDegrees, path.distanceMetres * fraction),
          headingDegrees: truth.headingDegrees, speedKnots: truth.speedKnots,
        };
        // Only the latest scheduled observation is materialized. Skipped ticks do not
        // inflate sequence: it counts actual emissions, not imagined frame history.
        emit(channel, sampleTruth, insStep(insPosition, Math.max(0, partialSeconds), truth), sampleSeconds);
      }
      // INS keeps integrating commands during output outages; it never consumes a fix.
      insPosition = insStep(insPosition, seconds, truth);
    }
    truth = next;
  }

  function snapshot() {
    const sources = channels.map((channel) => ({
      ...channel.definition, mode: channel.mode,
      available: channel.mode !== 'offline' && channel.mode !== 'jammed',
      ageSeconds: channel.sampleSeconds === null ? null : Math.max(0, truth.elapsedSeconds - channel.sampleSeconds),
      sequence: channel.sequence, reading: copyReading(channel.reading),
    }));
    return { elapsedSeconds: truth.elapsedSeconds, running: truth.running, sources, comparison: compare(sources) };
  }

  reset(initialTruth);
  return { advance, setMode, reset, snapshot };
}
