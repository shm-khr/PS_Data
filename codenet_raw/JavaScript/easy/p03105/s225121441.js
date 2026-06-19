function main(args) {
  const A, B, C = args.split(' ').map(Number);
  let ans;
  if (B >= A * C) {
    ans = C;
  } else {
    ans = Math.floor(B / A);
  }
  console.log(ans);
}

main(require("fs").readFileSync("/dev/stdin", "utf8"));