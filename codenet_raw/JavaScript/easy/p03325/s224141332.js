"use strict";
function Main(input) {
    let cin = new Inputer(input);
    let N = cin.getInt(), A = cin.getIntArray(N);
    let ans = 0, done = true, loop=0;
    while (done) {
        let n, imax, max = 0;
        for (n = 0; n < N; n++) 
            if (A[n] % 2 == 0 && max < A[n]) max = A[imax = n];
        if (max > 0) {
            for (let m = 0; m < N; m++) {
                if (imax == m) A[m] /= 2; //else A[m] *= 3;
            }
            ans++;
        } else done = false;
    }
    console.log(ans);
}
class Inputer{constructor(t){if(typeof t=='undefined')throw new Error('引数（stdin）を省略できません！');this.cnt=0;this.items=t.split(/\n|\s/)}getInt(){return this.items[this.cnt++]-0}getIntArray(t){if(typeof t=='undefined')throw new Error('引数（1以上）を省略できません！');if(t<1)throw new Error('引数は1以上であること！');let r=new Array(t);for(let e=0;e<t;e++)r[e]=this.getInt();return r}getStr(){return this.items[this.cnt++]}getStrArray(t){if(typeof t=='undefined')throw new Error('引数（1以上）を省略できません！');if(t<1)throw new Error('引数は1以上であること！');let r=new Array(t);for(let e=0;e<t;e++)r[e]=this.getStr();return r}}
if (typeof window == "undefined") Main(require("fs").readFileSync("/dev/stdin", "utf8"));