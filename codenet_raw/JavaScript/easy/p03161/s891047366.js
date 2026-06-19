function Main(input){
  //パラメータ受け取り
  input = input.split("\n");
  inputStr = input[0].split(" ");
  var N = Number.parseInt(inputStr[0]);
  var K = Number.parseInt(inputStr[1]);
  inputStr = input[1].split(" ");
  var H_arr = inputStr.map( inputStr => parseInt(inputStr));
  
  //解法としてDPを用いる
  var i = 0;	//今たっている場所
  var ans = []; //回答格納用配列
  //ansの配列要素Nの確定と初期化
  for(var i=0 ; i<N ; i++){
    ans.push(0);
  }
  
  //階段の0段目のコストをメモ。値は0
  ans[0] = 0;
  //階段の1段目に進んだ時のコストをメモ
  ans[1] = Math.abs(H_arr[1]-H_arr[0]); 
  //階段の3段目以降のコストをforループで処理
  for( var i=2 ; i<N ; i++){
    var last = 1000000;
    for(var j=1 ; j<=K ; j++){
      if( i >= j){
        //自分のところ(i段目)にj段前から来た場合の値を格納
        var tmp = ans[i-j]+Math.abs(H_arr[i]-H_arr[i-j]);
        last = Math.min(tmp,last);
      }
    }
    //より小さい値(最小コスト)を回答配列の自分の段に格納
    ans[i] = last;
  }
  //結果表示
  console.log(ans[N-1]);
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));
