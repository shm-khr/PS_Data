function main(input) {
  const inputs = input.split('\n');
  var n = parseInt(inputs[0].split(' ')[0], 10);
  var m = parseInt(inputs[0].split(' ')[1], 10);

  var s = [];
  for (var i = 0; i < m; i++) {
    var temp = inputs[i + 1].split(' ').map((n, i) => (parseInt(n, 10)));
    temp.shift()
    s.push(temp);
  }
  var p = inputs[1 + m].split(' ').map((n) => parseInt(n, 10));

  var initSwitches = [];
  for (var i = 0; i < m; i++) {
    initSwitches.push(0);
  }
  var counter = 0;
  for (var bit = 0; bit < (1 << n); bit++) {
    var temp = initSwitches.concat();
    for (var i = 0; i < n; i++) {
      if (bit & (1 << i)) {
        for (var j = 0; j < m; j++) {
          if (s[j].find((v) => v == i + 1) >= 0) temp[j] += 1;
        }
      }
    }
    temp = temp.map((n, i) => n % 2);
    if (temp.every((n) => n == true)) counter += 1;
  }
  console.log(counter);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
