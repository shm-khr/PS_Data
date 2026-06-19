"use strict";
function Main(input) {
    let cin = new Inputer(input);
    let N = cin.getInt();
    let A = new Array(N*2);
    for (let n = 0; n < N*2; n++) {
        A[n] = cin.getInt();
    }
    let dp = new Array(N + 1).fill(0).map(() => new Array(1).fill(0));
    dp[0] = [A[0], 0];
    let s = 0, a = 0;
    while (s < N) {
        dp[s+1][0] = dp[s][0]
        if (s+1 != N) dp[s+1][0] += A[a+1];
        dp[s+1][1] = dp[s][0];
        if (s < N) dp[s+1][1] += A[a+N];
        if ((dp[s+1][0] < dp[s+1][1])) {
            dp[s+1][0] = dp[s+1][1];
            a += N;
        } else a++;
        s++;
    }
    console.log(dp[N][0]);
}
class Inputer{constructor(t){if(typeof t=='undefined')throw new Error('引数（stdin）を省略できません！');this.cnt=0;this.items=t.split(/\n|\s/)}getInt(){return this.items[this.cnt++]-0}getIntArray(t){if(typeof t=='undefined')throw new Error('引数（1以上）を省略できません！');if(t<1)throw new Error('引数は1以上であること！');let r=new Array(t);for(let e=0;e<t;e++)r[e]=this.getInt();return r}getStr(){return this.items[this.cnt++]}getStrArray(t){if(typeof t=='undefined')throw new Error('引数（1以上）を省略できません！');if(t<1)throw new Error('引数は1以上であること！');let r=new Array(t);for(let e=0;e<t;e++)r[e]=this.getStr();return r}}
if (typeof window == "undefined") Main(require("fs").readFileSync("/dev/stdin", "utf8"));