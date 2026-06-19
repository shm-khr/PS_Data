const main = (arg) => {
  const lines = arg.trim().split('\n');
  const N = Number.parseInt(lines[0]);
  const btcToJpy = (n) => n * 380000;
  let ans = 0;
  [...Array(N).keys()].forEach((i) => {
    let [x, u] = lines[i + 1].split(' ');
    x = Number.parseFloat(x);
    if (u === 'JPY') {
      ans += x;
    } else {
      ans += btcToJpy(x);
    }
  });
  console.log(ans);
};
main(require('fs').readFileSync('/dev/stdin', 'utf8'));
