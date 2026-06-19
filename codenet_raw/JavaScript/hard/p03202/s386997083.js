"use strict";
function I(s,f){this._s=s.split("\n");this._c=0;this._l=0;this._f=f||Number}I.prototype.a=function(){var l=this._s[this._l];if(!l)return;var t=l.trim().split(" ");var a=t[this._c];this._c++;if(t.length===this._c){this._c=0;this._l++}return this._f(a)};I.prototype.l=function(){var l=this._s[this._l];if(!l)return;this._c=0;this._l++;return l.split(" ").map(this._f)};

const max = 10e9 + 1;
function main(input) {
  var o = new I(input);

  const n = o.a();
  const a = o.l().map(x => x.toString());

  let low = 1, high = 20001;
  while (low < high - 1) {
    let mid = Math.floor((low + high) / 2);
    if (test(mid, a)) {
      high = mid;
    } else {
      low = mid;
    }
    // console.log(mid, low, high);
  }
  console.log(high);
}

function test(n, a) {
  var map = new Map();
  map.set(max, 0);
  for (var i = 1; i < a.length; i++) {
    if (a[i] > a[i - 1]) {
      continue;
    }

    var cur = max - a[i];

    for (var key of map.keys()) {
      if (key < cur) map.set(key, 0);
    }

    map.set(cur, map.get(cur) ? map.get(cur) + 1 : 1);
    // carry
    while (map.get(cur) >= n && cur < max) {
      map.set(cur, map.get(cur) - n);
      cur += 1;
      map.set(cur, map.get(cur) ? map.get(cur) + 1 : 1);
    }
  }

  if (map.get(max) >= n) {
    return false;
  } else {
    return true;
  }
}

main(require("fs").readFileSync("/dev/stdin", "utf8"));
