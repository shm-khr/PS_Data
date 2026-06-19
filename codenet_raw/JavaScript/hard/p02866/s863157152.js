"use strict";
    
function factorial(num) {
  if (num == 1) {
    return num;
  } else {
    return num * factorial(num - 1);
  }
}

const main = arg => {
    arg = arg.trim().split("\n");
    const N = parseInt(arg[0]);
    const D = arg[1].split(" ").map(n=>parseInt(n));
    
    const max = Math.max(...D);
    
    if(D[0] !== 0) {
        console.log(0);
        return;
    }
    
    let answer = 1;
    let list = {0: 1};
    
    for(let i=1; i<N; i++) {
        if(list[D[i]]) {
           list[D[i]]++; 
        } else {
           list[D[i]] = 1;
        }
    }
    
    // console.log(JSON.stringify(list))
    
    for(let i=1; i<=max; i++) {
        // 親としてありえる個数
        const parents = list[i-1];
        // console.log("親の候補個数:" + parents);
        
        const temp = Math.pow(parents, list[i])
        // console.log(i + ":" + temp)
        
        answer *= temp;
    }
    
    console.log(answer % 998244353);
}
main(require('fs').readFileSync('/dev/stdin', 'utf8'));