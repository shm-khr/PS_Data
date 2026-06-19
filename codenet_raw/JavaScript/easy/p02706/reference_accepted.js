
const main = (input) => {
  input = input.trim().split('\n')

  const [n, m] = input[0].split(' ').map(Number)
  const arr = input[1].split(' ').map(Number)

  const homework = arr.reduce((a, b) => a + b, 0)

  return console.log(n - homework >= 0 ? n - homework : -1)
}

process.env.MYTEST
  ? (process.env.MYTEST === 'test' ? test() : main(require('fs').readFileSync('dev/stdin', 'utf8')))
  : main(require('fs').readFileSync('/dev/stdin', 'utf8'))