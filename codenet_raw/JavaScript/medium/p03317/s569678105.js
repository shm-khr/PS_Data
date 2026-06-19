function Main(input) {
	input = input.trim();
	var n = Number(input[0]);
	var k = Number(input[2]);
	if(n == k){
		console.log(1);
	} else {
		console.log(Math.floor(n/(k-1)));
	}
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));
