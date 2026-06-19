function Main(input){
	var tmp = input.split(" ");
	if(tmp[0] > tmp[1]){
		console.log(tmp[0] - tmp[1]);
	}else{
		console.log(0);
	}
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));