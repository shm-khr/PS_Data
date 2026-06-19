function Main(input) {
	input = input.split(" ");
	var a = parseInt(input[0], 10);
	var b = parseInt(input[1], 10);
	var c = parseInt(input[2], 10);
	var s = a + b
    if(s > c){
      console.log("Yes");
    }else{
      console.log("No")
    }
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));