"use strict";

const main = arg => {
    const input = arg.trim().split("\n");

    const N = parseInt(input[0].split(" ")[0]);
    const A = input[1].split(" ").map(n => parseInt(n));
    A.sort((a,b) => a-b)
    let cnt = 0
    for(let i = 1; i<A.length; i++){
        if(A[i-1] == A[i] || (i !== A.lengh -1 && A[i+1] == A[i]) ) continue
        let canDivide = false
        let j = 0
        const half = A[i]/2
        while(j<i && A[j] < half){
            if(A[i] == A[j] || A[i] % A[j] == 0){
                canDivide = true
                break
            }
            j++
        }
        if(canDivide === false) cnt++
    }
    console.log(cnt)
}
main(require('fs').readFileSync('/dev/stdin', 'utf8'));  