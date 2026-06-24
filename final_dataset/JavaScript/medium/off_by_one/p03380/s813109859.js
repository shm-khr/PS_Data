"use strict";
function Main(input) {
    let cin = new Inputer(input);
    let N = cin.getInt(), A = cin.getIntArray(N);
    const P = function(n, r) {
        let ans = 1;
        for (let m = n; r > 0; m--, r--) ans *= m;
        return ans;
    }
    const C = function(n, r) {
        let ans = P(n, r);
        for (; r > 0; r--) ans /= r;
        return ans;
    }
    A.sort((a, b) => b - a);
    let a = A[0];
    let max = 0, b;
    for (let n = 1; n < N; n++) {
        let c = C(a, A[n]);
        if (max < c) max = c, b = A[n];
    }
    console.log(`${a} ${b}`);
}
class Inputer{constructor(t){if(typeof t=='undefined')throw new Error('引数（stdin）を省略できません！');this.cnt=0,this.items=t.split(/\n|\s/)}getInt(){return this.items[this.cnt++]-0}getIntArray(t){if(typeof t=='undefined')throw new Error('引数（1以上）を省略できません！');let r=new Array(t);for(let e=0;e<t;e++)r[e]=this.getInt();return r}getStr(){return this.items[this.cnt++]}getStrArray(t){if(typeof t=='undefined')throw new Error('引数（1以上）を省略できません！');let r=new Array(t);for(let e=0;e<t;e++)r[e]=this.getStr();return r}}
if (typeof window == "undefined") Main(require("fs").readFileSync("/dev/stdin", "utf8"));