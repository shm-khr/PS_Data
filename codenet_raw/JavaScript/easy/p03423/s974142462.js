"use strict";

function main(arg) {
    const N = arg.split("\n");
    console.log(N % 3 < 3 ? Math.floor(N / 3) : (N / 3) - 1);
}
main(require('fs').readFileSync('/dev/stdin', 'utf8'));