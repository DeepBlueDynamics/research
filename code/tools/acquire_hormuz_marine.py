#!/usr/bin/env python3
"""Acquire compact NOAA ETOPO1 and OSM marine context. Python standard library only.
Run from any directory: python3 code/tools/acquire_hormuz_marine.py
Network is needed only for acquisition; the generated map data is runtime-local.
"""
import csv
import datetime
import hashlib
import io
import json
from collections import Counter, defaultdict
from pathlib import Path
import urllib.parse
import urllib.request

BOUNDS = [55, 25, 57.5, 27.5]
DEPTHS = [10, 20, 50, 100, 200, 500, 1000]
BATH_URL = 'https://coastwatch.pfeg.noaa.gov/erddap/griddap/etopo180.csv?' + urllib.parse.quote('altitude[(25):1:(27.5)][(55):1:(57.5)]', safe='():,')
OSM_QUERY = '[out:json][timeout:90];nwr["seamark:type"](25,55,27.5,57.5);out meta center;'
OSM_URL = 'https://overpass-api.de/api/interpreter?data=' + urllib.parse.quote(OSM_QUERY)


def download(url):
    request = urllib.request.Request(url, headers={'User-Agent': 'SEXTANT-offline-regional-data/1.0'})
    with urllib.request.urlopen(request, timeout=120) as response:
        return response.read()


def grid_from_csv(raw):
    rows = list(csv.reader(io.StringIO(raw.decode('utf-8'))))
    if rows[:2] != [['latitude', 'longitude', 'altitude'], ['degrees_north', 'degrees_east', 'm']]:
        raise ValueError('Unexpected ETOPO CSV schema or units')
    samples = {(round(float(lon), 10), round(float(lat), 10)): int(z) for lat, lon, z in rows[2:]}
    lons = sorted({p[0] for p in samples})
    lats = sorted({p[1] for p in samples})
    if len(samples) != 151 * 151 or [lons[0], lats[0], lons[-1], lats[-1]] != BOUNDS:
        raise ValueError('ETOPO subset is incomplete or has changed resolution')
    elevations = [[samples[(lon, lat)] for lon in lons] for lat in lats]
    if any(value == 32767 for row in elevations for value in row):
        raise ValueError('Unexpected ETOPO missing value in region')
    return {'schemaVersion': 1, 'dataset': 'NOAA NGDC ETOPO1 ice-surface grid-registered (2009)',
            'bounds': BOUNDS, 'crs': 'EPSG:4326', 'horizontalDatum': 'WGS 84',
            'verticalDatum': 'mean sea level', 'units': 'metres', 'positive': 'up',
            'registration': 'grid/node', 'width': len(lons), 'height': len(lats),
            'longitudeStart': lons[0], 'latitudeStart': lats[0], 'stepDegrees': 1 / 60,
            'rowOrder': 'south-to-north', 'columnOrder': 'west-to-east',
            'noData': None, 'elevations': elevations,
            'warning': 'Regional gridded relief, not surveyed soundings or chart-datum depths. Negative elevations are below mean sea level; do not infer navigable water or a coastline from this grid.'}


def join_segments(segments):
    adjacency = defaultdict(list)
    for index, (a, b) in enumerate(segments):
        adjacency[a].append(index)
        adjacency[b].append(index)
    used = set()
    lines = []

    def trace(start, edge):
        line = [start]
        point = start
        while edge not in used:
            used.add(edge)
            a, b = segments[edge]
            point = b if point == a else a
            line.append(point)
            remaining = [item for item in adjacency[point] if item not in used]
            if len(adjacency[point]) != 2 or not remaining:
                break
            edge = remaining[0]
        lines.append(line)

    for point, edges in adjacency.items():
        if len(edges) != 2:
            for edge in edges:
                if edge not in used:
                    trace(point, edge)
    for edge, (a, _) in enumerate(segments):
        if edge not in used:
            trace(a, edge)
    return lines


def contours_from_grid(grid):
    features = []
    heights = grid['elevations']
    for depth in DEPTHS:
        segments = set()
        for row in range(grid['height'] - 1):
            for col in range(grid['width'] - 1):
                vertices = [(col, row), (col + 1, row), (col + 1, row + 1), (col, row + 1)]
                values = [heights[y][x] + depth for x, y in vertices]
                intersections = {}
                for edge in range(4):
                    following = (edge + 1) % 4
                    a, b = values[edge], values[following]
                    if (a >= 0) == (b >= 0):
                        continue
                    t = -a / (b - a)
                    x0, y0 = vertices[edge]
                    x1, y1 = vertices[following]
                    intersections[edge] = (round(55 + (x0 + t * (x1 - x0)) / 60, 7),
                                           round(25 + (y0 + t * (y1 - y0)) / 60, 7))
                if len(intersections) == 2:
                    pairs = [tuple(intersections)]
                elif len(intersections) == 4:
                    # Bilinear-center rule disambiguates saddle cells without added samples.
                    pairs = [(0, 1), (2, 3)] if (sum(values) >= 0) == (values[0] >= 0) else [(0, 3), (1, 2)]
                else:
                    continue
                for a, b in pairs:
                    p, q = intersections[a], intersections[b]
                    if p != q:
                        segments.add(tuple(sorted((p, q))))
        lines = join_segments(sorted(segments))
        if lines:
            features.append({'type': 'Feature', 'id': 'etopo1-depth-' + str(depth),
                             'properties': {'depthMetres': depth, 'source': 'NOAA ETOPO1',
                                            'kind': 'regional-depth-contour', 'verticalDatum': 'mean sea level'},
                             'geometry': {'type': 'MultiLineString', 'coordinates': lines}})
    return {'type': 'FeatureCollection', 'bbox': BOUNDS, 'features': features}


def seamarks_from_osm(data):
    if data.get('remark'):
        raise ValueError('Overpass reported an incomplete or failed query: ' + data['remark'])
    features = []
    for element in data['elements']:
        tags = element.get('tags', {})
        kind = tags.get('seamark:type', '')
        selected = kind.startswith(('buoy_', 'beacon_', 'light_')) or (kind == 'landmark' and 'seamark:light:reference' in tags)
        if element['type'] != 'node' or not selected:
            continue
        lon, lat = element['lon'], element['lat']
        if not (55 <= lon <= 57.5 and 25 <= lat <= 27.5):
            raise ValueError('Out-of-bounds OSM aid node')
        properties = {'osmId': str(element['id']), 'osmType': 'node',
                      'osmUrl': 'https://www.openstreetmap.org/node/' + str(element['id']),
                      'osmVersion': element['version'], 'osmTimestamp': element['timestamp'],
                      'seamarkType': kind, 'aidClass': kind.split('_', 1)[0],
                      'category': 'buoy' if kind.startswith('buoy_') else 'navigation-aid',
                      'tags': tags}
        if 'seamark:name' in tags or 'name' in tags:
            properties['name'] = tags.get('seamark:name', tags.get('name'))
        if 'seamark:' + kind + ':colour' in tags:
            properties['colour'] = tags['seamark:' + kind + ':colour']
        features.append({'type': 'Feature', 'id': 'node/' + str(element['id']),
                         'geometry': {'type': 'Point', 'coordinates': [lon, lat]}, 'properties': properties})
    return {'type': 'FeatureCollection', 'bbox': BOUNDS, 'features': features}


def make_assets(bath_raw, osm_raw):
    grid = grid_from_csv(bath_raw)
    osm = json.loads(osm_raw)
    seamarks = seamarks_from_osm(osm)
    contours = contours_from_grid(grid)
    cells = []
    for row in range(5):
        for col in range(5):
            west, south = 55 + col * .5, 25 + row * .5
            count = sum(west <= f['geometry']['coordinates'][0] < west + .5 and
                        south <= f['geometry']['coordinates'][1] < south + .5 for f in seamarks['features'])
            cells.append({'bounds': [west, south, west + .5, south + .5], 'aidCount': count})
    provenance = {
        'schemaVersion': 1, 'name': 'Strait of Hormuz regional marine context',
        'acquiredAt': datetime.datetime.now(datetime.timezone.utc).isoformat(), 'bounds': BOUNDS,
        'purpose': 'Offline geographic context demonstrator only; not an ENC, navigation chart, ECDIS, soundings database, or operational aid inventory.',
        'bathymetry': {
            'dataset': grid['dataset'], 'versionNote': 'ETOPO1 is deprecated by NOAA in favor of ETOPO2022. This package intentionally identifies its older 2009 source; acquisition date is not a survey date.',
            'sourceUrl': BATH_URL, 'sourceSha256': hashlib.sha256(bath_raw).hexdigest(),
            'newerVersionCheck': {'date': '2026-09-10', 'url': 'https://coastwatch.pfeg.noaa.gov/erddap/search/index.json?page=1&itemsPerPage=100&searchFor=ETOPO2022', 'result': 'HTTP 404: query produced no matching results; ETOPO1 retained.'},
            'metadataUrl': 'https://coastwatch.pfeg.noaa.gov/erddap/info/etopo180/index.html',
            'documentationUrl': 'https://www.ncei.noaa.gov/products/etopo-global-relief-model',
            'citation': 'Amante, C. and B. W. Eakins (2009), ETOPO1 1 Arc-Minute Global Relief Model. NOAA Technical Memorandum NESDIS NGDC-24. doi:10.7289/V5C8276M',
            'attribution': 'NOAA NGDC ETOPO1 (Amante and Eakins, 2009)',
            'license': 'NOAA ERDDAP dataset terms: data may be used and redistributed for free but are not intended for legal use; no warranty of accuracy, completeness, or fitness.',
            'horizontalDatum': 'WGS 84', 'verticalDatum': 'Mean Sea Level (provider metadata); not local chart datum or lowest astronomical tide. No tidal correction is applied.',
            'resolutionArcMinutes': 1, 'resolutionDegrees': 1 / 60,
            'nominalSpacingMetres': {'northSouth': 1853, 'eastWestAt26Point25North': 1662},
            'resolutionWarning': 'Grid spacing is not sounding density, survey accuracy, or safe under-keel clearance. Coastal geometry may disagree with the separate OSM basemap.',
            'coverage': {'bounds': BOUNDS, 'width': 151, 'height': 151, 'sampleCount': 22801, 'missingSamples': 0},
            'elevationRangeMetres': [min(min(row) for row in grid['elevations']), max(max(row) for row in grid['elevations'])],
            'contours': {'levelsMetres': DEPTHS, 'positive': 'down', 'algorithm': 'Marching squares with linear edge interpolation and bilinear-center saddle rule; joined segments; coordinates rounded to 7 decimal degrees. No smoothing or external coastline mask.',
                         'warning': 'Derived regional MSL depth contours, not surveyed chart contours. Do not use contours as shoreline polygons, land masks, or surveyed soundings.'}},
        'seamarks': {
            'source': 'OpenStreetMap contributors, seamark-tagged objects via Overpass API', 'sourceUrl': OSM_URL,
            'query': OSM_QUERY, 'sourceSha256': hashlib.sha256(osm_raw).hexdigest(), 'osmBaseTimestamp': osm['osm3s']['timestamp_osm_base'],
            'attribution': '© OpenStreetMap contributors', 'license': 'ODbL 1.0',
            'licenseUrl': 'https://opendatacommons.org/licenses/odbl/1-0/', 'copyrightUrl': 'https://www.openstreetmap.org/copyright',
            'distributionNote': 'This OSM-derived GeoJSON database is distributed under ODbL 1.0. Retain attribution and license notice when distributing it or displaying derived maps.',
            'queriedObjectCount': len(osm['elements']), 'includedAidCount': len(seamarks['features']),
            'includedBuoyCount': sum(f['properties']['category'] == 'buoy' for f in seamarks['features']),
            'countsByType': dict(sorted(Counter(f['properties']['seamarkType'] for f in seamarks['features']).items())),
            'selection': 'Only actual OSM nodes with buoy_*, beacon_*, light_* seamark types, or landmark type with seamark:light:reference. Way/relation centers, platforms, harbours, areas, and non-light landmarks are excluded. No synthetic positions.',
            'tagPolicy': 'All original tags are retained unchanged in properties.tags. Flattened name/colour exist only when source tags exist. No fabricated names, colors, light characters, ranges, periods, live status, or radar targets.',
            'coverage': 'The full bounding box was queried; OSM mapping is incomplete and uneven. Empty cells mean no selected OSM aid nodes returned, not absence of real aids. No missing areas are filled.',
            'halfDegreeCoverageCells': cells,
            'currencyWarning': 'OSM timestamps are edit timestamps, not field verification. Some original source tags cite historical light lists. Present existence, position accuracy and operational state are not established.'},
        'schemas': {
            'bathymetry-grid.json': 'elevations[row][column] numeric metres positive up. Rows south-to-north, columns west-to-east. lon=longitudeStart+column*stepDegrees; lat=latitudeStart+row*stepDegrees. Negative values indicate below MSL, not verified navigable water.',
            'bathymetry-contours.geojson': 'GeoJSON EPSG:4326 MultiLineString features; properties.depthMetres is positive-down MSL contour level.',
            'seamarks.geojson': 'GeoJSON EPSG:4326 Point features; id=node/<OSM ID>; properties: osmId, osmType, osmUrl, osmVersion, osmTimestamp, seamarkType, aidClass (buoy/beacon/light/landmark), category (buoy/navigation-aid), tags; optional name and colour.'},
        'integration': {
            'runtime': 'Serve these files locally under /marine/. No provider access is required by the browser.',
            'contours': 'MapLibre geojson source data=/marine/bathymetry-contours.geojson. Add a line layer and optional symbol-placement=line label using depthMetres plus m MSL. Place both contour lines and labels above base water but beneath every land fill, then below vessel/track. The OSM land fills mask these regional contours; never infer a land mask from bathymetric values.',
            'aids': 'MapLibre geojson source data=/marine/seamarks.geojson. Distinguish category=buoy from other navigation-aid nodes with simple context markers, not claimed IHO chart symbols. Use only available names; show source IDs and original tags in textContent-based details.',
            'requiredLabels': ['NOAA ETOPO1 · 1′ regional depth contours · m MSL · not soundings', 'OSM aids · partial, unverified inventory', 'Not for navigation'],
            'attribution': 'NOAA NGDC ETOPO1; © OpenStreetMap contributors (ODbL 1.0)'}}
    assets = {'bathymetry-grid.json': grid, 'bathymetry-contours.geojson': contours, 'seamarks.geojson': seamarks}
    encoded = {name: json.dumps(data, ensure_ascii=False, separators=(',', ':')) + '\n' for name, data in assets.items()}
    provenance['files'] = {name: {'bytes': len(text.encode()), 'sha256': hashlib.sha256(text.encode()).hexdigest()} for name, text in encoded.items()}
    encoded['provenance.json'] = json.dumps(provenance, ensure_ascii=False, indent=2) + '\n'
    return encoded


def main():
    destination = Path(__file__).resolve().parents[1] / 'maps' / 'marine'
    names = ['bathymetry-grid.json', 'bathymetry-contours.geojson', 'seamarks.geojson', 'provenance.json']
    if any((destination / name).exists() for name in names):
        raise SystemExit('Refusing to overwrite existing marine assets; preserve or explicitly remove the previous extraction first.')
    assets = make_assets(download(BATH_URL), download(OSM_URL))
    destination.mkdir(parents=True, exist_ok=True)
    for name, text in assets.items():
        (destination / name).write_text(text, encoding='utf-8')
    print(json.dumps({name: len(text.encode()) for name, text in assets.items()}))


if __name__ == '__main__':
    main()
