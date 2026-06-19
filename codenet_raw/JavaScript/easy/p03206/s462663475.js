function Main(input) {
  input = input.split("\n").map(x => parseInt(x, 10));
 
  const n = input[0];
  input.shift();
 
  const top = input.reduce((x, y) => math.Max(x, y));
  const sum = input.reduce((x, y) => x + y);
 
  console.log(sum - (top / 2))
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));