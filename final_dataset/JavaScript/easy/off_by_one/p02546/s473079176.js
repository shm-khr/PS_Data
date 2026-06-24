function Main(input){
  let answer;
  if(input.substr(-1)==="s"){
    answer = input + "es";
  }else{
    answer = input + "s";
  }
  console.log('%s',answer);
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));