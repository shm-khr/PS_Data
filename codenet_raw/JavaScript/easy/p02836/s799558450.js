"use strict";
// import bigInt from 'big-integer'

const Main = input => {
  input = input.trim();
  const length = input.length;

  const frontHalf = Math.floor(length / 2);
  const backHalf = length % 2 === 0 ? frontHalf : frontHalf + 1;
  const frontWords = input.slice(0, frontHalf).split("");
  const backWords = input
    .slice(backHalf)
    .split("")
    .reverse();
  console.log(frontWords);
  console.log(backWords);

  let count = 0;
  for (let i = 0; i < frontHalf; i++) {
    if (frontWords[i] !== backWords[i]) count++;
  }
  console.log(count);
};

Main(require("fs").readFileSync("/dev/stdin", "utf8"));
