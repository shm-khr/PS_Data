function gets(str){
  this._s = str.split("\n");
  this._y = 0;
};
gets.prototype = {
  a: function(f){
    var s = this._s, y = this._y, r;
    if(typeof s[y] === "string")s[y] = s[y].split(" ").reverse();
    r = s[y].pop();
    if(!s[y].length)this._y++;
    return f?r:+r;
  },
  l: function(f){
    var s = this._s[this._y++].split(" ");
    return f?s:s.map(a=>+a);
  },
  m: function(n,f){
    var s = this._s, y = this._y, r = [], i = 0;
    if(f)for(;i < n; i++)r[i] = s[y+i].split(" ");
    else for(;i < n; i++)r[i] = s[y+i].split(" ").map(a=>+a);
    this._y += n;
    return r;
  },
};
var o=new gets(require("fs").readFileSync("/dev/stdin","utf8"));

console.log(main());
function main(){
  var n = o.a() * 2;
  var c = o.m(n,1);
  var b = 1, w = 1, ans = 0;
  for(i = 0; i < n; i++){
    var j = 0, k = 0;
    while((c[j][0] === "B" && c[j][1] != b) || (c[j][0] === "W" && c[j][1] != w)){
      if((c[j][0] === "B" && c[j][1] > b) || (c[j][0] === "W" && c[j][1] > w))k++;
      j++;
    }
    if(c[j][0] === "B")b++; else w++;
    ans += k;
  }
  return ans;
}