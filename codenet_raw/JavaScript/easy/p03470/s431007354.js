'use strict';

function Main(INPUT) {
    let input = INPUT.split("\n").map(n => Number(n));
    const N = input[0];
    let a = input.slice(1);
    console.log(new Set(a).size);
}

Main(require("fs").readFileSync("/dev/stdin", "utf8"));
