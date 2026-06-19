function Main(input){
	var tmp = input.split("");
	var count = 0;
	while(count<tmp.length){
		console.log(tmp[count]);
		count += 2;
	}
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));