'use strict'
function main(input) {
    const tmp = input.split('\n');
    const N = parseInt(tmp.shift(), 10);
    const a = tmp.map((elem) => parseInt(elem, 10));
    console.log(lcm2(a, 1, 0));
}

function gcd(a, b) {
    if (b === 0) {
        return a;
    }

    return gcd(b, a % b);
}

function lcm(a, b) {
    return (a * b) / gcd(a, b);
}

function lcm2(arr, a, i) {
    if (i === arr.length) {
        return a;
    } else {
        return lcm2(arr, lcm(a, arr[i]), i + 1);
    }
}
main(require('fs').readFileSync('/dev/stdin', 'utf8'));