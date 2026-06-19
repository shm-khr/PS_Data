const input = require("fs").readFileSync("/dev/stdin", "utf8")

;(input => {

    const lines = input.split('\n')
    const N = lines[0] - 0
    const a = lines[1].split(' ').map(Number)

    a.sort((a, b) => a - b)

    const dp = Array(a[N - 1] + 2).fill(0)
    for (let i = 0; i < N; i++) {
        dp[a[i]]++
    }

    const sum = []
    sum[0] = dp[0] + dp[1]
    for (let i = 1; i < dp.length - 1; i++) {
        sum[i] = dp[i - 1] + dp[i] + dp[i + 1]
    }

    console.log(Math.max(...sum))

})(input)
