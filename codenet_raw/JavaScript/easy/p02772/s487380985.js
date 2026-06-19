'use strict';

function main(input) {
  const arr = input.trim().split('\n');
  const a = Number(arr[0]);
  const b = arr[1].split(' ').map(x => Number(x));
  let isPass = true;

  for (let i = 0; i < a; i++) {
    if (b[i] % 2 === 0 && (b[i] % 3 === 0 || b[i] % 5 === 0)) {
      continue;
    } else {
      isPass = false;
    }
  }
  console.log(isPass ? 'APPROVED' : 'DENIED');
}


main(require("fs").readFileSync("/dev/stdin", "utf8"));