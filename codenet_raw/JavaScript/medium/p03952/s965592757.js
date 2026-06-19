// inputに入力データ全体が入る
function Main(input) {
	input = input.split(" ");
	var N = parseInt(input[0], 10);//max
	var x = parseInt(input[1], 10);//index 0
	//リスト作成
	var list = new Array(2*N-1);
	var i2 = 0;
	for(var i = 0;i < list.length;i++){
		list[i] = i+1;
	}
//	return;
	//検査
	var chk = chkList(N,list);
	if(chk == x){
		console.log("Yes");
		for(var k = 0;k < list.length;k++){
			console.log(list[k]);
		}
		return;
	}
	console.log("No");

}
function chkList(N,list){
//	console.log(N);
//	console.log(list);
	if(N != 2){
		N--;
	} else {
//		console.log("ret " + list[1]);
		return list[1];
	}
	var nextList= new Array(2*N -1);
	for(var j = 0;j < nextList.length;j++){
		var sort = [list[j],list[j+1],list[j+2]]
			sort.sort(function(a,b){
				if( a < b ) return -1;
				if( a > b ) return 1;
				return 0;
			});
		nextList[j] = sort[1];
	}
	return chkList(N,nextList)
}

//*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));