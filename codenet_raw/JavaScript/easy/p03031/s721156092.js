function main(input) {
  const inputs = input.split('\n');
  var n = inputs[0].split(' ')[0] - 0;
  var m = inputs[0].split(' ')[1] - 0;

  var ds = [];
  for (var i = 0; i < n; i++) {
    ds.push(inputs[i + 1].split(' ').filter((n, i) => i > 0).map((n) => n - 1));
  }
  var p = inputs[1 + m].split(' ').map((n) => parseInt(n, 10));

  var counter = 0;
  // bit all search
  for (var bit = 0; bit < (1 << n); bit++) {
    var allOn = true;
    // all search for switches
    for (var swi = 0; swi < n; swi++) {
      var sum = 0;
      // a bit pattern
      for (var biti = 0; biti < n; biti++) {
        if ((bit & (1 << biti)) != 0) continue;
        if (ds[swi].find((v) => v == biti) >= 0) sum++;
      }
      allOn = allOn && (sum % 2 == p[swi]);
    }
    if (allOn) counter += 1;
  }
  console.log(counter);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
