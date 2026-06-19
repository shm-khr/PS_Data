"use strict";
var input=require("fs").readFileSync("/dev/stdin","utf8");
var cin=input.split(/ |\n/),cid=0;
function next(){return +cin[cid++];}
function nextstr(){return cin[cid++];}
function nextbig(){return BigInt(cin[cid++]);}
function nexts(n,a){return a?cin.slice(cid,cid+=n):cin.slice(cid,cid+=n).map(a=>+a);}
function nextm(h,w,a){var r=[],i=0;if(a)for(;i<h;i++)r.push(cin.slice(cid,cid+=w));else for(;i<h;i++)r.push(cin.slice(cid,cid+=w).map(a=>+a));return r;}
function xArray(v){var a=arguments,l=a.length,r="Array(a["+--l+"]).fill().map(x=>{return "+v+";})";while(--l)r="Array(a["+l+"]).fill().map(x=>"+r+")";return eval(r);}

var myOut = main();
if(myOut !== undefined)console.log(String(myOut));

function main(){
  const bit = 10, mx = 1e5+1;
  var n = next();
  var vw = nextm(n,2);
  var q = next();
  var need = xArray("[]",n);
  for(var i = 0; i < q; i++){
    var v = next()-1, l = next();
    need[v].push(i,l);
  }
  var ans = xArray(0,q);
  var dp = Array(bit);
  dp[0] = Array(mx).fill(0,0,vw[0][1]).fill(vw[0][0],vw[0][1]);
  f1(0,dp[0]);
  var q1 = [];
  if(n > 2)q1 = [1,-1,2,1];else if(n === 2)q1 = [1,-1];
  while(q1.length){
    var d = q1.pop(), v = q1.pop();
    if(d < 0)d = -d, dp[d] = dp[d-1];
    else dp[d] = dp[d-1].concat();
    var vv = vw[v][0], ww = vw[v][1];
    for(var i = mx-1; i >= ww; i--){
      if(dp[d][i] < dp[d][i-ww]+vv)dp[d][i] = dp[d][i-ww]+vv;
    }
    f1(v,dp[d]);
    v=v+v+1, d++;
    if(v >= n)continue;
    if(d < bit){
      if(v+1 === n)q1.push(v,-d);else q1.push(v,-d,v+1,d);
      continue;
    }
    var q2 = [v,0];
    if(v+1 < n)q2.push(v+1,0);
    var zt = [];
    while(q2.length){
      var ln = q2.pop(), v = q2.pop();
      var vv = vw[v][0], ww = vw[v][1];
      zt.length = ln, zt.push(vv,ww);
      for(var i = 0; i < ln; i+=2){
        if(zt[i+1]+ww < mx)zt.push(zt[i]+vv,zt[i+1]+ww);
      }
      f2(v,dp[bit-1],zt);
      v=v+v+1;
      if(v >= n)continue;
      q2.push(v,zt.length)
      if(v+1 < n)q2.push(v+1,zt.length);
    }
  }
  return ans.join("\n");

  function f1(n,dp){
    var a = need[n];
    for(var i = 0; i < a.length; i+=2){
      var v = a[i], l = a[i+1];
      ans[v] = dp[l];
    }
  }
  function f2(n,dp,zt){
    var a = need[n];
    for(var i = 0; i < a.length; i+=2){
      var v = a[i], l = a[i+1];
      ans[v] = dp[l];
      for(var j = 0; j < zt.length; j+=2){
        var vv = zt[j], ww = zt[j+1];
        if(l < ww)continue;
        if(ans[v] < dp[l-ww]+vv)ans[v] = dp[l-ww]+vv;
      }
    }
  }
}