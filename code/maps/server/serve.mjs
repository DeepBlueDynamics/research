#!/usr/bin/env node
// Derived from Meridian electron/main.js /charts/ Range route via the
// navy-hormuz-map extraction. Static demonstrator assets only; no Electron.
// Run: node code/maps/server/serve.mjs --port 8090
import http from 'node:http';
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

const args = process.argv.slice(2);
const option = (name, fallback) => {
  const index = args.indexOf(name);
  return index >= 0 ? args[index + 1] : fallback;
};
const root = fs.realpathSync(option('--root', path.join(path.dirname(fileURLToPath(import.meta.url)), '..')));
const port = Number(option('--port', 8090));
const host = option('--host', '0.0.0.0');
const mime = {
  '.html': 'text/html; charset=utf-8', '.js': 'text/javascript; charset=utf-8',
  '.mjs': 'text/javascript; charset=utf-8', '.css': 'text/css; charset=utf-8',
  '.json': 'application/json; charset=utf-8', '.txt': 'text/plain; charset=utf-8',
  '.png': 'image/png', '.svg': 'image/svg+xml', '.pbf': 'application/x-protobuf',
  '.pmtiles': 'application/octet-stream',
};

const server = http.createServer((request, response) => {
  if (request.method !== 'GET' && request.method !== 'HEAD') {
    response.writeHead(405, { Allow: 'GET, HEAD' }).end('GET/HEAD only');
    return;
  }
  let urlPath;
  try { urlPath = decodeURIComponent(new URL(request.url, 'http://local').pathname); }
  catch { response.writeHead(400).end('Invalid path'); return; }
  if (urlPath === '/') {
    response.writeHead(302, { Location: '/renderer/basemap.html' }).end();
    return;
  }
  const requested = path.resolve(root, '.' + urlPath);
  const inside = (file) => file.startsWith(root + path.sep);
  if (!inside(requested)) { response.writeHead(403).end('Forbidden'); return; }
  let file, stat;
  try {
    file = fs.realpathSync(requested);
    if (!inside(file)) { response.writeHead(403).end('Forbidden'); return; }
    stat = fs.statSync(file);
  } catch { response.writeHead(404).end('Not found'); return; }
  if (!stat.isFile()) { response.writeHead(404).end('Not found'); return; }

  const size = stat.size;
  response.setHeader('Accept-Ranges', 'bytes');
  response.setHeader('Content-Type', mime[path.extname(file).toLowerCase()] || 'application/octet-stream');
  response.setHeader('X-Content-Type-Options', 'nosniff');
  response.setHeader('Cache-Control', 'no-cache');
  let start = 0, end = size - 1;
  if (request.method === 'GET' && request.headers.range) {
    const match = /^bytes=(\d*)-(\d*)$/.exec(request.headers.range);
    const failRange = () => response.writeHead(416, { 'Content-Range': `bytes */${size}` }).end();
    if (!match || (!match[1] && !match[2])) { failRange(); return; }
    const first = match[1] ? Number(match[1]) : null;
    const last = match[2] ? Number(match[2]) : null;
    if ((first !== null && !Number.isSafeInteger(first)) ||
        (last !== null && !Number.isSafeInteger(last))) { failRange(); return; }
    if (first === null) start = Math.max(0, size - last);
    else { start = first; end = last === null ? end : Math.min(last, end); }
    if (start > end || start >= size) { failRange(); return; }
    response.statusCode = 206;
    response.setHeader('Content-Range', `bytes ${start}-${end}/${size}`);
  }
  response.setHeader('Content-Length', end - start + 1);
  if (request.method === 'HEAD' || size === 0) { response.end(); return; }
  const stream = fs.createReadStream(file, { start, end });
  stream.on('error', (error) => response.destroy(error));
  response.on('close', () => stream.destroy());
  stream.pipe(response);
});
server.on('error', (error) => { console.error(error.message); process.exitCode = 1; });
server.listen(port, host, () => console.log(`Hormuz map ready at http://${host}:${port}/ (HTTP Range enabled)`));
