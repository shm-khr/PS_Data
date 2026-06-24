"use strict";

// read lines from stdin
const input = require("fs")
  .readFileSync("/dev/stdin", "utf8")
  .split("\n");

const firstLine = input[0].split(" ").map((val) => parseInt(val, 10));

const N = firstLine[0];
const Q = firstLine[1];

const S = input[1];

const indexes = [];

for (let i = 0; i < N; i++) {
  if (S[i] !== "A") {
    continue;
  }

  if (S[i + 1] === "C") {
    indexes.push(i);
  }
}

for (let i = 2; i < Q + 2; i++) {
  const line = input[i].split(" ").map((val) => parseInt(val, 10));
  const l = line[0] - 1;
  const r = line[1] - 1;

  console.log(indexes.filter((index) => index >= l && index < r).length);
}
