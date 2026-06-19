function main(input) {
  let inputs = input.split('\n')
  let n = Number(inputs[0])
  let values = inputs[1].split(' ')

  values = values.map(v => Number(v))

  let flag = false
  for (let i = 0; i < n; i++) {
    if (!(values[i] % 2) && values[i] % 3 && values[i] % 5) {
      console.log(values[i])
      flag = true
      break
    }
  }

  console.log(!flag ? 'APPROVED' : 'DENIED')
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'))
