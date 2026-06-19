const Main = (input) => {
  const tmp = input.trim().split(' ').map(n => parseInt(n))
  const A = tmp[0]
  const B = tmp[1]
  const N = tmp[2]

  let result = 0

  for (let x = 1; x <= N; x += (N / 10 < 1) ? 1 : N / 10) {
    const ans = Math.floor((A * x / B) - (A * Math.floor(x / B)))
    if (ans > result) {
      result = ans
    }
  }

  console.log(result)
  return result
}

Main(require('fs').readFileSync('/dev/stdin', 'utf8'))