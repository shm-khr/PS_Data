function Main(input){
  console.log(input.toUpperCase());
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));