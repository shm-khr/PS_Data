// inputに入力データ全体が入る
function Main(input) {
  if(input.slice(-1) === 's') {
    input = input + 'es';
  } else {
    input = input + 's';
  }
  console.log(input);
}


// let input = `bus`;
// Main(input);


// *この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));