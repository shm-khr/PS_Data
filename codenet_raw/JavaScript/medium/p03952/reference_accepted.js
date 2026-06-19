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
  var x = next();
  var m = n*2-1;
  if(x === 1 || x === m)return "No";
  console.log("Yes");
  if(n === 2)return "1\n2\n3";
  var ans = Array(m);
  if(x === 2){
    for(var i = 1; i <= m; i++){
      var t = i+n-3;
      ans[t%m] = i;
    }
  }else{
    ans[n-2] = x-1;
    ans[n-1] = x;
    ans[n] = x+1;
    ans[n+1] = x-2;
    for(var i = 5; i <= m; i++){
      var t = i+n-3;
      ans[t%m] = (x+i-4)%m+1;
    }
  }
  return ans.join("\n");
}