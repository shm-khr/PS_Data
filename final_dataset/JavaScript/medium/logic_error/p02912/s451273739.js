function Main(input){
  input = input.split("\n");
  inputStr = input[0].split(" ");
  const N = Number.parseInt(inputStr[0]);
  const M = Number.parseInt(inputStr[1]);
  //品目情報を配列Aに格納する
  inputStr = input[1].split(" ");
  var A = inputStr.map( inputStr => Number.parseInt(inputStr));
  //チケット枚数分ループ(一番大きな値を値切る方針)
  for(var i=0 ; i<M ; i++){
    //品物の中から最大値とその場所を特定
    var posi = A.indexOf(Math.max.apply(null, A));
    //半額にしていく
    A[posi] = Math.floor(A[posi]/2);
  }
  //合計金額を標準出力
  console.log(A.reduce(function(total, data){return total + data}));
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));
