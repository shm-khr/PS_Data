function Main(input){
  input = input.split("\n");
  inputStr = input[0].split(" ");
  var A = Number.parseInt(inputStr[0]);
  var B = Number.parseInt(inputStr[1]);
  var C = Number.parseInt(inputStr[2]);
  var D = Number.parseInt(inputStr[3]);
  //変数を定義
  var ARR = [];	//C/Dの倍数を溜めるカウンタ
  var cnt = 0;	//回答に使うカウンタ
  //CとDの倍数を配列ARRに溜め込む
  var i = 1;
  while ( C * i <= B || D * i <= B ){
    ARR.push(C*i);
    ARR.push(D*i);
    i++;
  }
  //AからBまでループして、配列ARRに含まれない場合はcntを足し込む
  //console.log(ARR);
  for( var j = A; j < B+1; j++){
    if(ARR.indexOf(j) === -1){
      cnt += 1;
    }
  }
  console.log(cnt);
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));