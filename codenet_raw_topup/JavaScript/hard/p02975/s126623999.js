// inputに入力データ全体が入る
function Main(input) {
  var noList = input.split("\n")[1].split(" ");
  for(var i = 0; i < noList.length; i++){
    var mae = i - 1;
    if(mae == -1)mae = noList.length - 1;
    var ato = i + 1;
    if(ato == noList.length)ato = 0;
    
    if(0 != (noList[mae] ^ noList[i] ^ noList[ato]).toString()){
       console.log("No");
       return;
    }
  }
  console.log("Yes");
}
//*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));
