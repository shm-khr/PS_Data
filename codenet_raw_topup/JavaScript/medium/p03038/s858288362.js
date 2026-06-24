"use strict";
    
const main = arg => {
    arg = arg.split("\n");
    const N = parseInt(arg[0].split(" ")[0]);
    const M = parseInt(arg[0].split(" ")[1]);
    
    const A  = arg[1].split(" ").map(n=>parseInt(n)).sort((a,b)=>a-b);
    const BC = arg.slice(2, M + 2);
    
    for(let i in BC) {
        let B = parseInt(BC[i].split(" ")[0]);
        let C = parseInt(BC[i].split(" ")[1]);
        
        let deleteCnt = 0;
        for(let j=0; j<B; j++) {
            
            if(A[j] < C) {
                deleteCnt++;
            }
        }
        
        for(let j=0; j<deleteCnt; j++) {
            A.shift();
        }
        
        let cnt = 0;
        let insertPoint;
        
        for(let j in A) {
            if(A[j] > C) {
                insertPoint = j;
                break;
            }
        }
        
        if(insertPoint === undefined) {
            insertPoint = N;
        }
        
        for(let j=0; j<deleteCnt; j++) {
            A.splice(insertPoint, 0, C);
        }
    }
    
    console.log(A.reduce((m,n)=>m+n));
}
main(require('fs').readFileSync('/dev/stdin', 'utf8'));