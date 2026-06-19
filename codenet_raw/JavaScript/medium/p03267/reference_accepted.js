"use strict";
function Main(input) {
    let cin = new Inputer(input);
    let L = cin.getInt();
    let l = L, dl = 0;
    let ce = 0;
    let te = new Array(20).fill(false);
    while (l) {
        if (l & 1) {
            te[dl] = true;
            ce++;
        }
        l >>= 1;
        dl++;
    }
    console.log(`${dl} ${(dl - 1) * 2 + ce - 1}`);
    l = L;
    let t = 1;
    for (let i = 1; i < dl; i++) {
        console.log(`${i} ${i + 1} ${0}`);
        console.log(`${i} ${i + 1} ${t}`);
        if (te[i - 1]) {
            console.log(`${i} ${dl} ${l - t}`);
            l -= t;
        }
        t <<= 1;
    }
}
class Inputer{constructor(t){this.cnt=0,this.items=t.split(/\n|\s/)}getInt(){return this.items[this.cnt++]-0}getIntArray(t){let r=new Array(t);for(let e=0;e<t;e++)r[e]=this.getInt();return r}getStr(){return this.items[this.cnt++]}getStrArray(t){let r=new Array(t);for(let e=0;e<t;e++)r[e]=this.getStr();return r}}
if (typeof window == "undefined") Main(require("fs").readFileSync("/dev/stdin", "utf8"));