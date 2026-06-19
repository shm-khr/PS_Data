function Main(s) {
  var s = s.split("\n");
  var n = parseInt(s[0], 10);
  var a = s[1].split(" ").map(e => parseInt(e, 10));
  var acc = 0, cnt = 0, arr = [];
  for (var i = 0; i < n; i++) {
    acc += a[i];
    if (i === 0) {
      if (acc === 0) {
        acc++;
        cnt++;
      }
    } else {
      if (arr[i - 1] > 0) {
        if (acc >= 0) {
          cnt += (acc + 1);
          acc -= (acc + 1);
        }
      } else {
        if (acc <= 0) {
          cnt += (Math.abs(acc) + 1);
          acc += (Math.abs(acc) + 1);
        }
      }
    }
    arr.push(acc);
  }
  console.log(cnt);
}

Main(require("fs").readFileSync("/dev/stdin", "utf8"));