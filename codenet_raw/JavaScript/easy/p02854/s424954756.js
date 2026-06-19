"use strict";
    
const main = arg => {
    arg = arg.trim().split("\n");
    const N = parseInt(arg[0]);
    const A = arg[1].split(" ").map( str => parseInt(str, 10) );;
    let num = 0;
    for(var i=0;i<N;i++){
        num+=A[i];
    }
    let ans = Infinity;
    let mem = A[0];
    for(var i=1;i<N-1;i++){
        mem+=A[i];
        ans=Math.min(ans,Math.abs(num-mem*2));
    }
    console.log(ans);
}
main(require('fs').readFileSync('/dev/stdin', 'utf8'));
