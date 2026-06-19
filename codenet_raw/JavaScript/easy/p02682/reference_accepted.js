function Main(input) {
  input = input.split(" ");
  const A = Number.parseInt(input[0]);  //1
  const B = Number.parseInt(input[1]);  //0
  const C = Number.parseInt(input[2]);  //-1
  const K = Number.parseInt(input[3]);

  if (A >= K) {
    console.log(K);
  } else if (A + B >= K) {
    console.log(A);
  } else {
    console.log(A - (K - A - B));
  }

}

// デバッグ用
function debug() {
  var input = document.getElementById("input").value;
  Main(input);
}

//* この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));