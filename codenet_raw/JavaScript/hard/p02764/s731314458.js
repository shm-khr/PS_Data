"use strict";
var input=require("fs").readFileSync("/dev/stdin","utf8");
var cin=input.split(/ |\n/),cid=0;
function next(a){return a?cin[cid++]:+cin[cid++];}
function nexts(n,a){return a?cin.slice(cid,cid+=n):cin.slice(cid,cid+=n).map(a=>+a);}
function nextm(h,w,a){var r=[],i=0;if(a)for(;i<h;i++)r.push(cin.slice(cid,cid+=w));else for(;i<h;i++)r.push(cin.slice(cid,cid+=w).map(a=>+a));return r;}
function xArray(v){var a=arguments,l=a.length,r="Array(a["+--l+"]).fill().map(x=>{return "+v+";})";while(--l)r="Array(a["+l+"]).fill().map(x=>"+r+")";return eval(r);}

var myOut = main();
if(myOut !== undefined)console.log(myOut);

function main(){
  var n = next(), k = next();
  if(k === 1)return 0;
  var c = nextm(n,3);
  var ans = 1e9;
  for(var i = 0; i < n; i++){
    var q = [[0,i]], x = c[i][0], y = c[i][1];
    for(var j = 0; j < n; j++){
      if(i === j)continue;
      q.push([solve(x,y,c[j]),j]);
    }
    q.sort((a,b)=>a[0]-b[0]);
    var cost = q[k-1][0];
    var l = 500;
    while(l > 1e-7){
      var d = solve2(x,y,c[q[k-1][1]]), q2 = [], f = 1;
      var xd = x - d[0]*l, yd = y - d[1]*l;
      for(var j = 0; j < k && f; j++){
        var t = solve(xd,yd,c[q[j][1]]);
        if(cost < t)f = 0;
        else q2.push([t,q[j][1]]);
      }
      if(f){
        q2.sort((a,b)=>a[0]-b[0]);
        cost = q2[k-1][0];
        q = q2;
        x = xd, y = yd;
      }else{
        l /= 2;
      }
    }
    if(cost < ans)ans = cost
  }
  return ans;
}

function solve(x,y,a){
  var x1 = a[0], y1 = a[1], c1 = a[2];
  var dx = x-x1, dy = y-y1;
  return c1 * Math.sqrt(dx*dx + dy*dy);
}

function solve2(x,y,a){
  var x1 = a[0], y1 = a[1];
  var dx = x-x1, dy = y-y1;
  var l = Math.sqrt(dx*dx + dy*dy);
  return [dx/l , dy/l];
}