// inputに入力データ全体が入る
function Main(input) {
	// 1行目がinput[0], 2行目がinput[1], …に入る
	input = input.split("\n");
	tmp = input[0].split(" ");
	//文字列から10進数に変換するときはparseIntを使います
       console.log(tmp)
   tmp.sort(function(a,b){
    if( a < b ) return -1;
    if( a > b ) return 1;
    return 0;
	})
   
console.log(tmp.toString() == ['1','4','7','9'])

}
//*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));