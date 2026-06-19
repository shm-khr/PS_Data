function Main(input) {
	input = input.split(" ");
  
  
  	var b = input[0] + input[1] + input[2];
  
  	if(b = 17){
        	for(var i=0; i<3; i++){
      	if(input[i] == 5 || input[i] == 7){
      		console.log('YES');
    	}else{
      		console.log('NO');
          	return;
    	}
    }
    }else{
      console.log('NO');
    }
}
//*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));