"use strict";
function Main(input) {
    let lines = input.split("\n");
    let nk = lines.shift().split(/\s/).map((v) => v - 0);
    let N = nk[0], K = nk[1];
    const even = K % 2 == 0;
    const k2 = Math.ceil(K / 2);
    let set = [];
    for (let n = 1; n <= N; n++) {
        if (n % K == 0) set.push(n);
        else if (even && n % K == k2) set.push(n);
    }
    let ans = 0;
    const sLength = set.length;
    for (let a = 0; a < sLength; a++) {
        let A = set[a];
        for (let b = 0; b < sLength; b++) {
            let B = set[b];
            if ((A + B) % K != 0) continue; 
            for (let c = 0; c < sLength; c++) {
                let C = set[c];
                if ((A + C) % K != 0) continue; 
                if ((B + C) % K != 0) continue; 
                ans++;
            }
        }
    }
    console.log(ans);
}
if (typeof window == "undefined") Main(require("fs").readFileSync("/dev/stdin", "utf8"));
