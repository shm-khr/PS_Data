function Main(input) {
  input = input.split("\n");
  let line0 = input[0].split(" ");
  let N = parseInt(line0[0]);
  let K = parseInt(line0[1]);
  if (K % 2 === 0) {
    console.log(Math.floor(N / K) ** 3 + Math.floor((N + K / 2) / K) ** 3);
  } else {
    console.log(Math.floor(N / K) ** 3);
  }
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));