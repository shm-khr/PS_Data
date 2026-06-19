const input = require("fs").readFileSync("/dev/stdin", "utf8")
const lines = input.split('\n')
let N = lines[0].trim() - 0

let min = Infinity
let max = -Infinity

for (let i = 1; i <= N; i++) {
    const p = lines[i].split(' ').map(Number)
    min = Math.min(min, p[0] + p[1])
    max = Math.max(max, p[0] + p[1])
}

console.log(max - min)
