// Meridian-derived MapLibre renderer; NOAA performs the S-57/S-52 portrayal.
// The local georeferenced image is an official NOAA ENC display-service export,
// not raw S-57 ingestion or a certified ECDIS.
export async function createENCStyle(cfg) {
  const response = await fetch(cfg.basemap.image);
  if (!response.ok) throw new Error('Local NOAA ENC image HTTP ' + response.status);
  const { image } = await response.json();
  const [west, south, east, north] = cfg.view.bounds;
  return {
    version: 8,
    glyphs: decodeURI(new URL(cfg.labels.glyphs, location.href).href),
    sources: { 'noaa-enc': {
      type: 'image', url: image,
      coordinates: [[west,north],[east,north],[east,south],[west,south]]
    }},
    layers: [
      {id:'outside-coverage',type:'background',paint:{'background-color':'#c6cdd0'}},
      {id:'noaa-enc-chart',type:'raster',source:'noaa-enc',paint:{'raster-fade-duration':0}}
    ]
  };
}
export function createENCInfo(root, cfg, vessel) {
  root.className = 'marine-controls';
  root.innerHTML = '<h3>OFFICIAL NOAA ENC DATA</h3><p>Juan de Fuca · Freshwater Bay / Port Angeles approaches</p><p>Local snapshot of NOAA’s S-52 display service. Chart depths and aids are part of the ENC image.</p><p id="enc-coverage"></p><p>Snapshot detail is fixed; zooming adds no chart detail. No live updates or computed safe-water margin.</p><a href="../enc/provenance.json" target="_blank" rel="noopener">Chart provenance and extent</a>';
  let inside = true;
  const unsubscribe = vessel.subscribe(({position:[x,y]}) => {
    const [w,s,e,n] = cfg.view.bounds; inside=x>=w&&x<=e&&y>=s&&y<=n;
    root.querySelector('#enc-coverage').textContent = inside ? 'Ownship within packaged chart extent.' : 'OWN SHIP OUTSIDE PACKAGED CHART EXTENT';
  });
  return {state:()=>({type:'NOAA ENC display snapshot',insideCoverage:inside,depthLookupAvailable:false}),depthAt:()=>null,dispose:unsubscribe};
}
