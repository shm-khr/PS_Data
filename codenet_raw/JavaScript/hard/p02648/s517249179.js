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
  var n = next();
  const aa = 9;
  var mn = Math.min(n,1<<aa);
  const mx = 1e5+1;
  var dp = Array(mn);
  var V = nextm(n,2);
  var v = V[0][0], w = V[0][1];
  dp[0] = Array(mx).fill(0,0,w).fill(v,w);
  for(var i = 1; i < mn; i++){
    var p = i-1>>1;
    v = V[i][0], w = V[i][1];
    dp[i] = dp[p].concat();
    for(var j = mx-1; w <= j; j--)if(dp[i][j] < dp[i][j-w]+v)dp[i][j] = dp[i][j-w]+v;
  }
  var q = next();
  var ans = Array(q);
  for(var i = 0; i < q; i++){
    var [u,l] = nexts(2);
    var d = 31-Math.clz32(u--);
    var s = [];
    while(aa < d){
      v = V[u][0], w = V[u][1];
      if(l < w)continue;
      var k = s.length;
      s.push(v, w);
      for(var j = 0; j < k; j+=2){
        var t = s[j+1]+w;
        if(t <= l){
          s.push(s[j]+v, t);
        }
      }
      u = u-1>>1, d--;
    }
    ans[i] = d < 9 ? dp[u][l] : dp[u-1>>1][l];
    if(aa === d && l >= V[u][1]){
      v = V[u][0], w = V[u][1];
      u = u-1>>1
      if(ans[i] < dp[u][l-w]+v)ans[i] = dp[u][l-w]+v;
      for(var j = 0; j < s.length; j+=2){
        if(ans[i] < dp[u][l-s[j+1]]+s[j])ans[i] = dp[u][l-s[j+1]]+s[j];
        var t = s[j+1]+w;
        if(t <= l){
          if(ans[i] < dp[u][l-t]+s[j]+v)ans[i] = dp[u][l-t]+s[j]+v;
        }
      }
    }
  }
  return ans.join("\n");
}