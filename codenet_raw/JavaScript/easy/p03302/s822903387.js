function Main(input) {
	input = input.split(" ").map(Number);
  if(input[0]*input[1]==15||input[0]+input[1]==15){
  console.log("*")
  }else{
  console.log("x")
  }
}Main(require("fs").readFileSync("/dev/stdin", "utf8").trim());