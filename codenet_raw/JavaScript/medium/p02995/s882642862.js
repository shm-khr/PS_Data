function lcm(a,b) {
    var g = (n, m) => m ? g(m, n % m) : n
    return a * b / g(a, b)
}
function Main(input){
  input = input.split("\n");
  inputStr = input[0].split(" ");
  var A = Number.parseInt(inputStr[0]);
  var B = Number.parseInt(inputStr[1]);
  var C = Number.parseInt(inputStr[2]);
  var D = Number.parseInt(inputStr[3]);
  var lcm_val = lcm(D,C);
  //変数を定義
  var cnt = 0;
  //計算を実施
  cnt = Math.floor(B/C) - Math.floor((A-1)/C);
  cnt += Math.floor(B/D) - Math.floor((A-1)/D);
  cnt -= Math.floor(B/lcm_val) - Math.floor((A-1)/lcm_val);
  console.log(B-(A-1)-cnt);
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));