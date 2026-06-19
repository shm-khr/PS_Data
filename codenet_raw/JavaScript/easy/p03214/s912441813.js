// inputに入力データ全体が入る
function Main(input) {
  var input = input.split('\n');
  var N = parseInt(input[0]);
  // debug
  // console.log(inpu);
  var an = input[1].split(' ');
  an.map(e => Number(e));
  
  var total = 0;

  an.forEach(element => {
    total += parseInt(element);
  });
  
  var av = total / an.length;

  var dt = 0;
  var wk = 0;
  var ans = 0;
  for (var i = 0; i < an.length; i++){
    dt = Math.abs(an[i] - av);
    if (dt === 0){
      console.log('%d', i);
      return;
    }
    if(wk > dt){
      wk = dt;
      ans = i; // 最小の添え字を保持
    } 
  }

   console.log('%d', ans);
}
//*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));


