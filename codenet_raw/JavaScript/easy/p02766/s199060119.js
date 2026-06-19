// inputに入力データ全体が入る
function Main(input) {
  input = input.split("\n");
  // 1行目がinput[0], 2行目がinput[1], …に入る
  var inputs = input[0].split(" ");
  var n = Number(inputs[0]);
  var k = Number(inputs[1]);
  console.log(n.toString(k));
  console.log(String(n.toString(k)).length);
}
//*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));
// Main('11 2');
// Main('1010101 10');
// Main('314159265 3');
