// inputに入力データ全体が入る
function Main(input) {
	// 1行目がinput[0], 2行目がinput[1], …に入る
  input = input.split("\n");
  var boushiNum = Number(input[0]);
  var boushiArray = input[1].split(" ");
  function myXOR(a,b) {
    return a ^ b;
  }
  var flag = true;
  var result = 'Yes';
  for(var i=0; i < boushiNum; i++){
    if(i===0){
      if(Number(boushiArray[0]) != myXOR(Number(boushiArray[1]),Number(boushiArray[boushiNum-1]))){
        flag = false;
      }
    }
    else if(i ===  boushiNum-1){
      if(Number(boushiArray[boushiNum-1]) != myXOR(Number(boushiArray[0]),Number(boushiArray[boushiNum-2]))){
        flag = false;
      }
    }
    else{
      if(Number(boushiArray[i]) != myXOR(Number(boushiArray[i-1]),Number(boushiArray[i+1]))){
        flag = false;
      }
    }
    if(!flag){
      result = 'No';
    }
  }
  for(var i=boushiNum; i > 0; i--){
    if(i===0){
      if(Number(boushiArray[0]) != myXOR(Number(boushiArray[1]),Number(boushiArray[boushiNum-1]))){
        flag = false;
      }
    }
    else if(i ===  boushiNum-1){
      if(Number(boushiArray[boushiNum-1]) != myXOR(Number(boushiArray[0]),Number(boushiArray[boushiNum-2]))){
        flag = false;
      }
    }
    else{
      if(Number(boushiArray[i]) != myXOR(Number(boushiArray[i-1]),Number(boushiArray[i+1]))){
        flag = false;
      }
    }

    if(!flag){
      result = 'No';
    }
  }
  
 	console.log(result);
 }
 //*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
 Main(require("fs").readFileSync("/dev/stdin", "utf8"));