"use strict";
function Main(input) {
    let lines = input.split("\n");
    let nk = lines[0].split(/\s/).map((v) => v - 0);
    let N = nk[0] - 0, K = nk[1] - 0;
    let H = lines[1].split(/\s/).map((v) => v - 0);
    let dp = new Array(N+K).fill(Number.MAX_SAFE_INTEGER);
    dp[0] = 0;
    for (let n = 0; n <= N; n++) {
        for (let m = 0; m < K; m++) {
            dp[n + m] = Math.min(dp[n + m], dp[n] + Math.abs(H[n] - H[n + m]));
        }
    }
    console.log(dp[N-1]);
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));