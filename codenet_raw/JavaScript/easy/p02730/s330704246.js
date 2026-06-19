function main(input) {
  const S = input;

  for (var i = 0; i < Math.floor(S.length / 2); i++) {
    if (S[i] !== S[S.length - (i + 1)]) {
      console.log("No");
      return;
    }
  }
  const firstS = S.slice(0, (S.length - 1) / 2);
  const lastS = S.slice((S.length + 3) / 2 - 1);

  for (var i = 0; i < Math.floor(firstS.length / 2); i++) {
    if (firstS[i] !== firstS[firstS.length - (i + 1)]) {
      console.log("No");
      return;
    }
  }

  for (var i = 0; i < Math.floor(lastS.length / 2); i++) {
    if (lastS[i] !== lastS[lastS.length - (i + 1)]) {
      console.log("No");
      return;
    }
  }

  console.log("Yes");
}

main(require("fs").readFileSync("/dev/stdin", "utf8"));
