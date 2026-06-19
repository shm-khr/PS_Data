"use strict";
function Main(input) {
    let lines = input.split("\n");
    const nums = lines.shift().split(/\s/).map((v) => v - 0);
    const N = nums[0], Q = nums[1];
    const A = 'A'.charCodeAt(0);
    let S = lines.shift().split(/\s/)[0].split('').map((v) => v.charCodeAt(0) - A);
    let lr = new Array(Q);
    let ans = new Array(Q).fill(0);
    for (let n = 0; n < Q; n++) {
        lr[n] = lines.shift().split(/\s/).map((v) => v - 0 - 1);
    }
    let Z = [];
    for (let m = 0; m < S.length-1; m++) {
        if (S[m] == 0 && S[m + 1] == 2) {
            Z.push(m++);
        }
    }
    lr.forEach(function(v, i, a) {
        ans[i] = Z.reduce((ac, m) => (v[0] <= m && m < v[1]) ? 1 : 0, 0);
    });
    console.log(ans.join('\n'));
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));
