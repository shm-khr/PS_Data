"use strict";
    
const main = arg => {
    arg = arg.trim().split("\n");
    const N     = ~~arg[0];
    const table = arg.slice(1, 3).map(n=>n.split(" ").map(l=>~~l));
    
    const topLowSum    = table[0].reduce((m,n)=>m+n);
    const bottomLowSum = table[1].reduce((m,n)=>m+n);
    
    let answer = 0;
    let pivot;

    for(let i=0; i<N; i++) {
        let top  = topLowSum - table[0].slice(0, i + ~~1).reduce((m,n)=>m+n) + table[1][N-1];
        let down = i === 0 ? bottomLowSum : bottomLowSum - table[1].slice(0, i).reduce((m,n)=>m+n);
    
        if(down > top) {
            pivot = i;
            break;
        }
    }
    
    if(pivot !== undefined) {
        const beforePivot = table[0].slice(0, pivot + 1).reduce((m,n)=>m+n);
        const afterPivot  = table[1].slice(pivot, N).reduce((m,n)=>m+n);

        console.log(beforePivot + afterPivot);
    } else {
        console.log(topLowSum + table[1][N-1]);
    }
}
main(require('fs').readFileSync('/dev/stdin', 'utf8'));