'use strict'
 
function Main(input) {
    var params = input.split('\n');
    const n = parseInt(params[0].split(' ')[0], 10);
    const k = parseInt(params[0].split(' ')[1], 10);

    const a = [];
    const b = [];
    const nums = [];
    for (let i = 1; i < params.length; i++) {
        const arg = params[i].split(' ');
        nums.push([parseInt(arg[0], 10), parseInt(arg[1], 10)]);
    }
    nums.sort((a, b) => {
        return a[1] < b[1];
    });
    
    let sum = 0;
    let bitSum = 0;
    nums.map(numPair => {
        if (parseInt((bitSum | numPair[0]), 10) <= k) {
            bitSum |= numPair[0];
            sum += numPair[1];
        }
    });
    console.log(sum);
}
 
Main(require("fs").readFileSync("/dev/stdin", "utf8"));