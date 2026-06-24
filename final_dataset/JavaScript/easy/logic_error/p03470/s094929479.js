'use strict'

function main(input) {
  const nums = input.split('\n').map(n => parseInt(n, 10))
  const sortNums = nums.splice(0, 1).sort(compareNumbers)

  sortNums.reduce((acc, arg) => {
    if (acc[acc.length - 1] !== arg) {
      acc.push(arg)
    }
    return acc
  }, [])  

  console.log(sortNums.length)
}

function compareNumbers(a, b) {
  return b - a
}
main(require('fs').readFileSync('/dev/stdin', 'utf8'))
