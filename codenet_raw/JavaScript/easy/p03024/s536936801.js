// inputに入力データ全体が入る
function Main(input) {
  // 1行目がinput[0], 2行目がinput[1], …に入る
  var str = input;

  str += 'oooooooooooooooooooooooooooooooooo';

  str = str.substring(0,15);

  var count = 0;

  for ( var i = 0; i < 16; i++ ){
    if ( str[i] == 'o' ) {
      count ++;
    }
  }

  if ( count >= 8 ){
    console.log('YES');
  } else {
    console.log('NO');
  }

}
//*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));