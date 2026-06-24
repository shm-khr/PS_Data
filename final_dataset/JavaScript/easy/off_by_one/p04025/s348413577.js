function Main (input) {
  input = input.split("\n");
  var N = parseInt(input[0], 10);
  var a = input[1].split(" ").map(Number);
  var ave = 0;
  var ans = 0;
  for (var i of a) {
    ave += i;
  }
  ave = Math.ceil(ave/N);
  for (var i of a) {
    ans += Math.pow(i-ave, 2);
  }
  console.log(ans);
}

Main(require("fs").readFileSync("/dev/stdin", "utf8"));