// inputに入力データ全体が入る
function Main(input) {
	input = input.split("");
  	let result = 0;	
  	for(let i of input){
    	result += parseInt(i);  
    }
  	if(result % 9 === 0 ){
      console.log('Yes')
    }else{
      console.log('No')
    }
}
//*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));