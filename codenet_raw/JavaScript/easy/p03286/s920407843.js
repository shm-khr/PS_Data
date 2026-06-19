'use strict'
function Main(input) {
  input = input.split("\n")
  let N = parseInt(input[0])
  let res = ''
  while (N !== 0) {
    res = String(N % -2) + res
    N = parseInt(N / -2)
  }
  console.log(res)
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"))