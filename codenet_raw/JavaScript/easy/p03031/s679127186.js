"use strict";
    
function permutateWithRepetitions(
  permutationOptions,
  permutationLength = permutationOptions.length
) {
  if (permutationLength === 1) {
    return permutationOptions.map(permutationOption => [permutationOption]);
  }

  // Init permutations array.
  const permutations = [];

  // Get smaller permutations.
  const smallerPermutations = permutateWithRepetitions(
    permutationOptions,
    permutationLength - 1
  );

  // Go through all options and join it to the smaller permutations.
  permutationOptions.forEach((currentOption) => {
    smallerPermutations.forEach((smallerPermutation) => {
      permutations.push([currentOption].concat(smallerPermutation));
    });
  });

  return permutations;
}

const main = arg => {
    arg = arg.trim().split("\n");
    const N = parseInt(arg[0].split(" ")[0]);
    const M = parseInt(arg[0].split(" ")[1]);
    
    const info = arg.slice(1, M + 1);
    const p = arg.slice(-1)[0].split(" ").map(n=>parseInt(n));
    
    const combos = permutateWithRepetitions([0, 1], N);
    let answer = 0;

    for(let i in combos) {
        let lightOn = 0;

        for(let j=0; j<M; j++) {
            let temp = info[j].split(" ").map(n=>parseInt(n));
            let k = temp[0];
            let s = temp.slice(1, k + 1);
            
            let cnt = 0;
            
            for(let k=0; k<s.length; k++) {
                if(combos[i][s[k] - 1] === 1) cnt++;
            }

            if(cnt % 2 === p[j]) {
                lightOn++;
            }
        }
        
        if(lightOn === M) {
            answer++;
        }
    }
    
    console.log(answer);
}
main(require('fs').readFileSync('/dev/stdin', 'utf8'));