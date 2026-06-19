function Main(input) {
  input = input.split(' ').map(value => parseInt(value));

  const [A, B, N] = input

  let x = 0;
  let max = 0;
  while(x <= N){
    const temp = Math.floor(A * x / B) - A * Math.floor(x / B);
    if (max < temp) max = temp;
    x++
  }

  console.log(max)
}

// Main("10000 123 90000");

// Don't edit this line!
Main(require("fs").readFileSync("/dev/stdin", "utf8"));