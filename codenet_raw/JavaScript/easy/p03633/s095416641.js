// const input = require('fs').readFileSync('/dev/stdin', 'utf8');
// input: 'A　B'
// const inputList = input.split(' '); // 空白文字に注意
// const inputNumberList = inputList.map(Number);

const input = require('fs').readFileSync('/dev/stdin', 'utf8');
const inputList = input.split('\n');
const inputNumberList = inputList.map(Number);

const n = inputNumberList[0];
const list = inputNumberList.slice(1, inputNumberList.length - 1);

function gcd(a, b) {
  if (a === b) {
    return a;
  }

  if (a > b) {
    let m = a % b;
    if (m === 0) {
      return a;
    }
    let n = b;
    while (!(m === 0) && !(n === 0)) {
      n = n % m;
      if (n === 0) {
        return a * b / m;
        break;
      }
      m = m % n;
      if (m === 0) {
        return a * b / n;
        break;
      }
    }

    return a * b;
  }

  let m = b % a;
  if (m === 0) {
    return b;
  }
  let n = a;
  while (!(m === 0) && !(n === 0)) {
    n = n % m;
    if (n === 0) {
      return a * b / m;
      break;
    }
    m = m % n;
    if (m === 0) {
      return a * b / n;
      break;
    }

    return a * b;
  }
};

let ans = 1;

list.forEach((i) => {
  ans = gcd(ans, i);
})

console.log(ans);
