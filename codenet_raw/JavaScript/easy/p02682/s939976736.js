// const TEST = `1 2 3 4`
// A B C K

// inputに入力データ全体が入る
function Main(input) {
  const inputArr = input.trim().split(" ");
  let countA = parseInt(inputArr[0])
  let countB = parseInt(inputArr[1])
  let countK = parseInt(inputArr[3])
  let res = 0
  countK = countK - countA
  res = res + countA
  if (0 >= countK) {
    console.log(res)
    return;
  }
  countK = countK - countB
  if (0 >= countK) {
    console.log(res)
    return;
  }
  res = res - countK
  console.log(res)
}
// Main(TEST)

//*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));