"use strict";
    
const main = arg => {
    const N = parseInt(arg.split("\n")[1]);
    const d = arg.split("\n").slice(1, N+1).sort((a,b)=>b-a);
    
    const set = new Set(d);
    
    console.log(parseInt(set.size));
}
main(require('fs').readFileSync('/dev/stdin', 'utf8'));
