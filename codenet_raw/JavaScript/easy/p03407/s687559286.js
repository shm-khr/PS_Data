'use strict';

function Main(INPUT) {
    const N = INPUT.split(" ").map(n => Number(n));
    console.log(N[2] - (N[0] + N[1]) >= 0 ? "Yes" : "No");
}

Main(require("fs").readFileSync("/dev/stdin", "utf8"));
