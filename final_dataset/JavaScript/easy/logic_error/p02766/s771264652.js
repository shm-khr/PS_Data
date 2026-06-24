function Main(input) {
  var line = input.split(' ');
  var N = Number(line[0]);
  var K = Number(line[1]);
  var log2 = Math.ceil(Math.log2(N));
  // console.log(log2);
  var log10 = Math.ceil(Math.log10(N));
  // console.log(log10);
  if (K == 2) {
    console.log(log2);
  } else if (K == 10) {
    console.log(log10);
  } else {
    for (var i = log10 + 1; i < log2; i ++) {
      var n = Math.pow(K, i);
      // console.log(n);
      if (N <= n) {
        console.log(i);
        break;
      }
    }
  }
}

Main(require("fs").readFileSync("/dev/stdin", "utf8"));
