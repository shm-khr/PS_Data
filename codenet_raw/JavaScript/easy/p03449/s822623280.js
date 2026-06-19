// inputに入力データ全体が入る
function Main(input) {
	var line = input.split("\n");
	var N = Number(line[0]);
	var A1 = line[1].split(" ");
	var A2 = line[2].split(" ");
	var S1 = [];
	var S2 = [];
	var sum1 = 0;
	var sum2 = 0;
	for(var i = 0; i < N; i++){
		sum1 += A1[i];
		sum2 += A2[N-1-i];
		S1[i] = sum1;
		S2[N-1-i] = sum2;
	}
	var ans = 0;
	for(var j = 0; j < N; j++){
		if(S1[j]+S2[j] >= ans) ans = S1[j]+S2[j];
	}
	console.log(ans);
}

//*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));