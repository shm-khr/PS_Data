process.stdin.resume();
process.stdin.setEncoding('utf8');
process.stdin.on('data', function (chunk) {
  var lines = chunk.toString().split('\n');
  var N = lines[0];
  var A = lines[1].replace(/ +/g, ' ').split(' ');
  console.log(A.join(" "));
  for (var i = 1; i < N; i++) {
    var key = A[i] - 0;
    var j = i - 1;
    while (j >= 0 && A[j] - 0 > key) {
    　　A[j + 1] = A[j] - 0;
    　　j--;
    }
    A[j + 1] = key;
    console.log(A.join(" "));
  }
});