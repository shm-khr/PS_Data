"use strict";
    
const main = arg => {
    arg = arg.trim().split("\n");
    const N = parseInt(arg[0].split(" ")[0]);
    let A = arg[1].split(" ").map(n=>parseInt(n)).sort((a,b)=>a-b);
    
    // console.log(A);
    
    for(let i=0; i<N; i++) {
        let Alen = A.length;
        let flg = false;
        let trigger = false;
        
        for(let j=i+1; j<Alen; j++) {
            // console.log("A[j]:" + A[j]);
            
            if(A[j] === A[i]) {
                flg = true;
            }
            
            if(A[j] % A[i] === 0) {
                A[j] = -1;
                // A.splice(j, 1);
                trigger = true;
            }
        }
        
        if(flg) {
            A[i] = -1; 
            trigger = true;
        }
        
        if(trigger) {
            A = A.filter(n=> n !== -1);
        }
    }
    
    // console.log(A);

    console.log(A.length);
}
main(require('fs').readFileSync('/dev/stdin', 'utf8'));
