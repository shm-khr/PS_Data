'use strict'
// inputに入力データ全体が入る
function Main(input) {
  let inAry = input.split(" ");
  inAry = inAry.map( (value) => {
    return parseInt(value);
  })

  let a = inAry[0];
  let b = inAry[1];
  let c = inAry[2];

  let kai = b / a;
  if(kai >= c){
      console.log(c)
    }else{
      Math.floor(kai);
      if(kai < 1){
        kai = 0;
      }
      console.log(kai);
    }
}
//*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));