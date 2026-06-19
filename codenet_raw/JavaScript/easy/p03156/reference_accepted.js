function Main(input) {
	input = input.trim().split("\n").map(function(x) { return x.split(" ")});
	var N = parseInt(input[0][0], 10);
	var A = parseInt(input[1][0], 10);
	var B = parseInt(input[1][1], 10);
	var vec_P = input[2].map(e => parseInt(e, 10));
	var vec_ans = [0, 0, 0];
	for (var i = 0; i < N; i++){
		if (vec_P[i] <= A) vec_ans[0]++;
		else if (vec_P[i] <= B) vec_ans[1]++;
		else vec_ans[2]++;
	}
	console.log(Math.min(vec_ans[0], vec_ans[1], vec_ans[2]));
}

Main(require("fs").readFileSync("/dev/stdin", "utf8")); 