'use strict'

const main = (INPUT) => {
  const input = INPUT.split('\n')[0].split(' ').map(n => Number(n))

  if (input[1] < input[0]) {
    console.log(0)
  } else if (input[1] / input[0] <= input[2]) {
    console.log(input[1] / input[0])
  } else {
    console.log(input[2])
  }
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'))
