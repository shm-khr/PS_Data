function main(arg) {
  let input = arg.trim().split('\n').map(item => parseInt(item));
  let yen500 = input[0];
  let yen100 = input[1];
  let yen50 = input[2];
  let total = input[3];
  let count = 0;
  for (var n = 0; n <= yen500; n++) {
    for (var m = 0; m <= yen100; m++) {
      for (var v = 0; v <= yen50; v++) {
        if (500 * n + 100 * m + 50 * v === total) {
          count++;
        }
      }
    }
  }
  console.log(count);
}
main(require('fs').readFileSync('/dev/stdin', 'utf8'));
