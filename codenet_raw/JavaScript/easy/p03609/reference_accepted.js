let [a, b] = require("fs").readFileSync("/dev/stdin", "utf8").split(" ").map(Number);
console.log(Math.max(0, a - b));