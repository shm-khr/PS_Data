function Main(input) {
  input = input.split('\n')
  var N = input[0]
  var a = input[1].split(' ')
  var flag = true
  a = a.map(x => parseInt(x))

  if ((a[N - 2] ^ a[0]) !== a[N - 1]) {
    flag = false
  }

  if ((a[1] ^ a[N - 1]) !== a[0]) {
    flag = false
  }

  // 1 N-2
  if (flag === true) {
    for (var i = 1; i < N - 1; i++) {
      if ((a[i - 1] ^ a[i + 1]) !== a[i]) {
        flag = false
        break
      }
    }
  }

  var str = flag === true ? 'Yes' : 'No'

  console.log('%s', str)
}

Main(require('fs').readFileSync('/dev/stdin', 'utf8'))
