'use strict'

const Main = (input) => {
  const tmp = input.trim().split('\n')
  const N = parseInt(tmp[0])
  const aArr = tmp[1].split(' ').map(Number)

  let result = 0

  for (let i = 0; i < N; i++) {
    let tmpNum = aArr[i]
    let loop = true
    while (loop) {
      if ((tmpNum % 2) === 0) {
        tmpNum = tmpNum / 2
        result += 1
      } else {
        loop = false
      }
    }
  }

  console.log(result)
  return result
}

Main(require('fs').readFileSync('/dev/stdin', 'utf8'))