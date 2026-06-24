"use strict";
var input=require("fs").readFileSync("/dev/stdin","utf8");
var cin=input.split(/ |\n/),cid=0;
function next(a){return a?cin[cid++]:+cin[cid++];}
function nexts(n,a){return a?cin.slice(cid,cid+=n):cin.slice(cid,cid+=n).map(a=>+a);}
function nextm(h,w,a){var r=[],i=0;if(a)for(;i<h;i++)r.push(cin.slice(cid,cid+=w));else for(;i<h;i++)r.push(cin.slice(cid,cid+=w).map(a=>+a));return r;}
function xArray(v){var a=arguments,l=a.length,r="Array(a["+--l+"]).fill().map(x=>{return "+v+";})";while(--l)r="Array(a["+l+"]).fill().map(x=>"+r+")";return eval(r);}

class priorityQueue{
  constructor(){
    this.a=[];
  }
  push(num,inc){
    const a = this.a;
    for(var i = a.length, j; i; i = j){
      j = i - 1 >> 1;
      if(a[j][0] <= num)break;
      a[i] = a[j];
    }
    a[i] = [num,inc];
  }
  pop(){
    const a = this.a, r = a[0], x = a.pop(), k = a.length >> 1;
    for(var i = 0, j; i < k; i = j){
      j = (i << 1) + 1;
      if(a[j+1] && a[j+1][0] < a[j][0])j++;
      if(x[0] <= a[j][0])break;
      a[i] = a[j];
    }
    if(a.length)a[i] = x;
    return r;
  }
  get size(){
    return this.a.length;
  }
  get top(){
    return this.a[0];
  }
}

var myOut = main();
if(myOut !== undefined)console.log(myOut);

function main(){
  var NN = "No", YY = "Yes";
  var n = next();
  var up = [], sum = 0, rest = 0;
  for(var i = 0; i < n; i++){
    var mn = 0, last = 0;
    var s = next(1);
    for(var j = 0; j < s.length; j++){
      if(s[j] === "(")last++;
      else{
        last--;
        if(last < mn)mn = last;
      }
    }
    sum += last;
    if(last > 0 || last === mn)rest += last;
    else up.push([-mn,last]);
  }
  if(sum)return NN;
  up.sort((a,b)=>b[0]-a[0]);
  for(var i = 0; i < up.length; i++){
    var [mn,last] = up[i];
    if(mn > rest)return NN;
    rest -= last;
  }
  return YY;
}