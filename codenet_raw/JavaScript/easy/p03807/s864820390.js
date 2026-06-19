function Main(s) {
  var s = s.split("\n")[1].split(" ").map(e => parseInt(e, 10));
  var cnt = 0;
  for (var i of a) if (i % 2 === 1) cnt++;
  console.log(cnt % 2 === 0 ? "YES":"NO");
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));