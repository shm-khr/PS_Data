const input = require("fs").readFileSync("/dev/stdin", "utf8")

;(input => {

    const lines = input.split('\n')
    const N = lines[0] - 0
    const A = lines[1].split(' ').map(Number)

    let odd = 0
    for (let i = 0; i < N; i++) {
      odd += A[i] % 2
    }

    console.log(odd % 2 ? 'NO' : 'YES')

})(input)
