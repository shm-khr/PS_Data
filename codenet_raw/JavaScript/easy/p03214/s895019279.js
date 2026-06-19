process.stdin.resume();
process.stdin.setEncoding('utf8');
// 自分の得意な言語で
// Let's チャレンジ！！

let lines = [];

const reader = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout
});
reader.on('line', (line) => {
   lines.push(line);
});
reader.on('close', () => {
  let n = parseInt(lines.shift());
  let arr = lines.shift().split(/\s/).map(x => parseInt(x));
  let sum = arr.reduce((s, i) => s + i);
  let average = sum / arr.length;

  let min = 101;
  let ans = 0;
  for (let i = arr.length - 1; i >= 0; i--) {
    if (min >= Math.abs(arr[i] - average)) {
      min = Math.abs(arr[i] - average);
      ans = i;
    }
  }
  console.log(ans);
});