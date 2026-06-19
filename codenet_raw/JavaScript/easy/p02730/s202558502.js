'use strict';
function main(input) {
  const arr = input.trim().split('\n')[0];
  const howLong = arr.length;
  let isStrong = false;
  let isKaibun = false;

  if (kaibun(howLong)) {
    if (kaibun((howLong - 1) / 2)) {
      if (kaibun(howLong+ 3) / 2) {
        isStrong = true;
      }
    }
  }
  
  function kaibun (howLong) {
    for (let i = 0; i < (howLong / 2); i ++) {
      if (arr[i] !== arr[howLong - 1]) {
        return;
      }
      return isKaibun = true;
    }
  }

  console.log(isStrong ? 'Yes' : 'No');
}


main(require("fs").readFileSync("/dev/stdin", "utf8"));