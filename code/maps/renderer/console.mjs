import { createENCStyle } from './enc-map.mjs';
const status=document.querySelector('#map-status');
const body=document.querySelector('#matrix-body');
const names=['A','B','INS','ALT','RAD','CLK'];
const offsets=[[240,8],[248,8],[0,0],[4,-3],[-5,3],null];
for(let i=0;i<6;i++){
 const tr=document.createElement('tr');tr.innerHTML='<th>'+names[i]+'</th>';
 for(let j=0;j<6;j++){
  const td=document.createElement('td');
  if(i===j){td.textContent='—';}
  else if(!offsets[i]||!offsets[j]){td.textContent='N/C';td.className='nc';td.title='No comparable position supplied by clock';}
  else{const d=Math.hypot(offsets[i][0]-offsets[j][0],offsets[i][1]-offsets[j][1]);td.textContent=d<=100?'✓':'×';td.className=d<=100?'good':'bad';td.title=d.toFixed(1)+' m · simulated';}
  tr.append(td);
 }
 body.append(tr);
}
function resize(){document.documentElement.style.setProperty('--scale',Math.min(innerWidth/1600,(innerHeight-(document.body.classList.contains('presentation')?0:44))/750));}
function presentation(){document.body.classList.toggle('presentation');resize();}
document.querySelector('#present').onclick=presentation;
document.addEventListener('keydown',e=>{if(e.key.toLowerCase()==='p'&&!e.ctrlKey&&!e.metaKey)presentation();if(e.key==='Escape'){document.body.classList.remove('presentation');resize();}});
addEventListener('resize',resize);resize();
const cfg=await(await fetch('./config.json')).json();
let map,error=null;
try{
 map=new maplibregl.Map({container:'map',style:await createENCStyle(cfg),center:[-123.584,48.171],zoom:12.65,interactive:false,attributionControl:false,preserveDrawingBuffer:true});
 map.on('error',e=>{error=e.error?.message||String(e);status.textContent='Chart error: '+error;});
 const canvas=document.querySelector('#chart-overlay');canvas.width=1924;canvas.height=1212;
 const ctx=canvas.getContext('2d');ctx.scale(2,2);
 const own=[-123.57,48.18];
 function point(ll){return map.project(ll);}
 function text(s,x,y,size=14,color='#153c4d'){ctx.font='bold '+size+'px Arial';ctx.lineWidth=5;ctx.strokeStyle='#ffffffec';ctx.strokeText(s,x,y);ctx.fillStyle=color;ctx.fillText(s,x,y);}
 function line(coords,color,width=2,dash=[]){ctx.strokeStyle=color;ctx.lineWidth=width;ctx.setLineDash(dash);ctx.beginPath();coords.map(point).forEach((p,i)=>i?ctx.lineTo(p.x,p.y):ctx.moveTo(p.x,p.y));ctx.stroke();ctx.setLineDash([]);}
 function draw(){
  ctx.clearRect(0,0,962,606);
  // All operational geometry below is a frozen illustrative fixture.
  const polygon=[[-123.566,48.186],[-123.539,48.184],[-123.535,48.173],[-123.55,48.168],[-123.566,48.186]];
  ctx.beginPath();polygon.map(point).forEach((p,i)=>i?ctx.lineTo(p.x,p.y):ctx.moveTo(p.x,p.y));ctx.fillStyle='#df9c2533';ctx.fill();ctx.strokeStyle='#a4670a';ctx.lineWidth=2;ctx.setLineDash([8,5]);ctx.stroke();ctx.setLineDash([]);
  const rp=point([-123.557,48.175]);text('RF INTERFERENCE — REPORTED',rp.x-15,rp.y,13,'#805000');text('Exercise inject RF-07 · 22:41Z',rp.x-15,rp.y+19,12,'#805000');
  const route=[[-123.538,48.176],[-123.567,48.179],[-123.59,48.183],[-123.608,48.185]];
  line(route,'#576d98',2,[7,5]);
  route.forEach((ll,i)=>{const p=point(ll);ctx.beginPath();ctx.arc(p.x,p.y,10,0,Math.PI*2);ctx.fillStyle='#fff';ctx.fill();ctx.lineWidth=2;ctx.strokeStyle='#485e87';ctx.stroke();text(String(i+1),p.x-4,p.y+5,13);});
  line([[-123.532,48.175],[-123.545,48.1765],[-123.556,48.178],own],'#146a78',3);
  // 18 kn x six minutes = 1.8 NM, at 281 degrees true.
  const rad=Math.PI/180,R=6371008.8,b=281*rad,a=3333.6/R,lat=own[1]*rad,lon=own[0]*rad;
  const lat2=Math.asin(Math.sin(lat)*Math.cos(a)+Math.cos(lat)*Math.sin(a)*Math.cos(b));
  const lon2=lon+Math.atan2(Math.sin(b)*Math.sin(a)*Math.cos(lat),Math.cos(a)-Math.sin(lat)*Math.sin(lat2));
  const end=[lon2/rad,lat2/rad];line([own,end],'#142d42',2,[8,4]);const ep=point(end);text('6 MIN · 18 kn',ep.x-15,ep.y-17,13);
  const p=point(own);const east=point([own[0]+76/(111195*Math.cos(lat)),own[1]]);const r=Math.abs(east.x-p.x);
  ctx.beginPath();ctx.ellipse(p.x,p.y,r,r*.63,-.19,0,2*Math.PI);ctx.fillStyle='#e3a12355';ctx.fill();ctx.lineWidth=3;ctx.strokeStyle='#a96700';ctx.stroke();
  ctx.beginPath();ctx.arc(p.x,p.y,r*12/76,0,2*Math.PI);ctx.strokeStyle='#18765b';ctx.lineWidth=1.5;ctx.stroke();
  ctx.save();ctx.translate(p.x,p.y);ctx.rotate(b);ctx.beginPath();ctx.moveTo(0,-10);ctx.lineTo(6,9);ctx.lineTo(0,5);ctx.lineTo(-6,9);ctx.closePath();ctx.fillStyle='#173b4d';ctx.fill();ctx.strokeStyle='white';ctx.lineWidth=1.5;ctx.stroke();ctx.restore();
  text('OWN SHIP · R95 76 m',p.x-22,p.y+34,14,'#7b4b00');
  // Magnified inset makes the nominal/degraded size change visible at print size.
  ctx.fillStyle='#fffffff2';ctx.fillRect(330,350,208,132);ctx.strokeStyle='#a7bac4';ctx.lineWidth=1;ctx.strokeRect(330,350,208,132);
  text('R95 ENVELOPE · 5× DETAIL',342,368,12);
  ctx.beginPath();ctx.ellipse(434,421,r*5,r*.63*5,-.19,0,2*Math.PI);ctx.fillStyle='#e3a12344';ctx.fill();ctx.strokeStyle='#a96700';ctx.lineWidth=2;ctx.stroke();
  ctx.beginPath();ctx.arc(434,421,r*5*12/76,0,2*Math.PI);ctx.strokeStyle='#18765b';ctx.lineWidth=2;ctx.stroke();
  text('76 m / nominal 12 m',355,467,13,'#744700');
  const mpp=40075016.686*Math.cos(map.getCenter().lat*rad)/(512*Math.pow(2,map.getZoom()));
  document.querySelector('#chart-scale').textContent='Compilation scales 1:90,000 / 1:45,000';
  const sx=350,sy=530,w=1852/mpp;ctx.strokeStyle='#122f40';ctx.lineWidth=3;ctx.beginPath();ctx.moveTo(sx,sy-5);ctx.lineTo(sx,sy);ctx.lineTo(sx+w,sy);ctx.lineTo(sx+w,sy-5);ctx.stroke();text('1 NM',sx+w/2-15,sy-8,12);
 }
 map.on('render',draw);
 map.on('load',()=>{status.textContent='';draw();});
 window.m={map,state:()=>({ready:map.loaded(),error,center:map.getCenter(),zoom:map.getZoom(),mode:'frozen notional scenario',source:'NOAA ENC display snapshot',cells:['US4WA1IF','US4WA1IG']}),scenario:{time:'22:50Z',operator:'NAV_ET',r95Metres:76,nominalR95Metres:12,scores:{position:62,navigation:92,timing:94,overall:61},clockNanoseconds:72,offsets,marginMinutes:18,marginComputed:false}};
}catch(e){error=e.message;status.textContent='Chart error: '+error;window.m={state:()=>({ready:false,error})};}
