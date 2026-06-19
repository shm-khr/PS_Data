const main = stdin => {
  const input = stdin.trim().split('\n')

  const S = input[0]

  if (S[0] === S[1] || S[1] === S[2] || S[2] === S[3]) {
    console.log('Bad')
  } else {
    console.log('Good');
  }

}
// 標準入力
main(require("fs").readFileSync("/dev/stdin", "utf8"))
