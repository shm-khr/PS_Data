function Main(input) {
	input += "ooooooooooooooo"
	input = input.split("");
	var sum = 0;
	for(var i=0;i<15;i++){
		if(input[i]=="o") sum++;
	}
	console.log(sum>=8?"YES":"NO")
}Main(require("fs").readFileSync("/dev/stdin", "utf8").trim());
