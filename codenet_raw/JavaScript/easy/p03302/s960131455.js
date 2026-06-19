function Main(input) {
	input = input.split(" ").map((input)=>Number(input));
  if(input[0] + input[1] == 15){
     conosle.log("+");
     }else if(input[0] * input[1] == 15){
    conosle.log("*");
  }else{
    conosle.log("x");
  }
}

Main(require("fs").readFileSync("/dev/stdin", "utf8"));
