var GET=(function(){function f(s){return new g(s);}function g(s){this._s=s.trim().split("\n");this._y=0;}g.prototype.a=function(f){var s=this._s, y=this._y, r;if(typeof s[y]==="string")s[y]=s[y].split(" ").reverse();r=s[y].pop();if(!s[y].length)this._y++;return f?r:+r;};g.prototype.l=function(f){var s=this._s[this._y++].split(" ");return f?s:s.map(a=>+a);};g.prototype.m=function(n,f){var r=this._s.slice(this._y,this._y+=n).map(a=>a.split(" "));return f?r:r.map(a=>a.map(a=>+a));};g.prototype.r=function(n,f){var r=this._s.slice(this._y,this._y+=n);return f?r:r.map(a=>+a);};return f;})();
var o=GET(require("fs").readFileSync("/dev/stdin","utf8"));
function xArray(v){var a=arguments,l=a.length,r="Array(a["+--l+"]).fill(0).map(x=>{return "+v+";})";while(--l)r="Array(a["+l+"]).fill(0).map(x=>"+r+")";return eval(r);}
var n,s,e,a;

console.log(main());
function main(){
  n = o.a();
  s = o.a(1);
  e = xArray("[]",n);
  for(var i = 1; i < n; i++){
    var t = o.l(); t[0]--, t[1]--;
    e[t[0]].push(t[1]);
    e[t[1]].push(t[0]);
  }
  var ans = 1e9;
  for(var i = 0; i < n; i++){
    var t = tree(i);
    if(t < ans)ans = t;
  }
  return ans===1e9?-1:ans;
}

function tree(r){
  a = Array(n);
  dfs(r,-1);
  if(a[r][1]&1 || a[r][0])return 1e9;
  return a[r][1] >> 1;
}

function dfs(v,p){
  var u = [0,0,0], mx = 0, sum = 0;
  for(var i of e[v]){
    if(i === p)continue;
    dfs(i,v);
    var m = a[i][0]+a[i][2];
    u[1] += a[i][1];
    u[2] += a[i][2];
    sum += m;
    if(mx < m)mx = m;
  }
  u[1] += u[2];
  if(s[v] === "1")u[2]++;
  u[0] = Math.max(0,mx*2-sum);
  a[v] = u;
}