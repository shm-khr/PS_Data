const main = (input) => {
  input = input.trim().split('\n')

  const n = input[1].split(' ').map(Number).sort((a, b) => a - b)
  const biggest = n[n.length-1]
  const arr = new Array(biggest+1).fill(0)

  for (let i=0; i<n.length; i++) {
    for (let v=n[i]; v<=biggest; v+=n[i]) {
      arr[v]++
    }
  }

  let ans = 0
  for (let i=0; i<n.length; i++) {
    if (arr[n[i]] === 1) ans++
  }

  return console.log(ans)
}

process.env.MYTEST
  ? (process.env.MYTEST === 'test' ? test() : main(require('fs').readFileSync('dev/stdin', 'utf8')))
  : main(require('fs').readFileSync('/dev/stdin', 'utf8'))