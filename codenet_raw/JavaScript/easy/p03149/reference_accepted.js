function Main(input) {
	input = input.split(" ").sort().join("");
	console.log(input=="1479" ? "YES" : "NO");
}Main(require("fs").readFileSync("/dev/stdin", "utf8").trim());