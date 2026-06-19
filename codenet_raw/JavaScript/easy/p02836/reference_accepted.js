'use strict'

const main = (INPUT) => {
  const S = INPUT.split('\n')[0]
  let ans = 0
  for (let i = 0; i < S.length / 2; i++) {
    if (S[i] != S[S.length - 1 - i]) {
      ans++
    }
  }
  console.log(ans)
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'))
