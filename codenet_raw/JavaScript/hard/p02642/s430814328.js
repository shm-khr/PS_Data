const main = (input) => {
  const [, n] = input.trim().split('\n')
  const nums = n.split(' ').map(v => Number(v))

  const max = Math.max(...nums)
  const arr = new Array(max+1).fill(0)

  for (let v of nums) {
    for (let i=v; i<=max+1; i+=v) {
      arr[i]++
    }
  }

  let ans = 0
  for (let v of nums) {
    if (arr[v] === 1) ans++
  }
  console.log(ans)
}

process.env.MYTEST ? test() : main(require('fs').readFileSync('/dev/stdin', 'utf8'))