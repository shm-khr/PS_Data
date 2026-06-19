"use strict";
function I(s,f){this._s=s.split("\n");this._c=0;this._l=0;this._f=f||Number}I.prototype.a=function(){var l=this._s[this._l];if(!l)return;var t=l.trim().split(" ");var a=t[this._c];this._c++;if(t.length===this._c){this._c=0;this._l++}return this._f(a)};I.prototype.l=function(){var l=this._s[this._l];if(!l)return;this._c=0;this._l++;return l.split(" ").map(this._f)};module.exports=I;

function main(input) {
  const o = new I(input);

  const N = o.a();


  for (let i = 1; i<= N; i++) {
    for (let j = i + 1; j <= N; j++ ) {
      if (N % 2 === 0) {
        if (j !== N + 1 - i) {
          console.log(`${i} ${j}`)
        }
      } else {
        if (j !== N - i) {
          console.log(`${i} ${j}`)
        }
      }
    }
  }
}


main(require("fs").readFileSync("/dev/stdin", "utf8"));
