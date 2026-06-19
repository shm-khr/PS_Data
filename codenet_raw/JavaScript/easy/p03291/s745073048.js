function Main(s){
  var a = [0];
  var c = [0];
  var q = [0];
  var l = s.length;
  for(var i = 1; i <= l; i++){
    if(s[i-1] === "?"){a[i] = a[i-1]; c[i] = c[i-1]; q[i] = q[i-1] + 1;}
    else if(s[i-1] === "A"){a[i] = a[i-1] + 1; c[i] = c[i-1]; q[i] = q[i-1];}
    else if(s[i-1] === "C"){a[i] = a[i-1]; c[i] = c[i-1] + 1; q[i] = q[i-1];}
    else {a[i] = a[i-1]; c[i] = c[i-1]; q[i] = q[i-1];}
  }
  var ans = 0;
  for(var i = 2; i < l; i++){
    if(s[i-1] !== "B" && s[i-1] !== "?")continue;
    ans += abmod(a[i-1], c[l]-c[i], Math.pow(3,q[i-1]), Math.pow(3,q[l]-q[i]));
    ans += abmod(q[i-1], c[l]-c[i], Math.pow(3,q[i-1]-1), Math.pow(3,q[l]-q[i]));
    ans += abmod(a[i-1], q[l]-q[i], Math.pow(3,q[i-1]), Math.pow(3,q[l]-q[i]-1));
    ans += abmod(q[i-1], q[l]-q[i], Math.pow(3,q[i-1]-1), Math.pow(3,q[l]-q[i]-1));
    ans %= mod
  }
  console.log(ans);
}
var mod = 1e9 + 7;
function abmod(){var a=arguments,r=a[0],i=1;for(;i<a.length;)r=((r>>16)*a[i]%mod*65536+(r&65535)*a[i++])%mod;return r;}

Main(require("fs").readFileSync("/dev/stdin","utf8").trim());