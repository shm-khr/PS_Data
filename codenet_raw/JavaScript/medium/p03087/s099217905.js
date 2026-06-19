var lines = [];
var readline = require('readline');

var rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

rl.on('line', function (x) {
    lines.push(x);
})

rl.on('close', function () {

    var tmp = lines.shift().split(" ");
    var N = Number(tmp[0]); var Q = Number(tmp[1]);

    var S = lines.shift();

    var l = Array(Q); var r = Array(Q);
    for (var i = 0; i < Q; i++) {
        tmp = lines[i].split(" ");
        l[i] = Number(tmp[0]);
        r[i] = Number(tmp[1]);
    }

    var sum = Array(N + 1).fill(0);
    for (var i = 1; i < N; i++) {
        sum[i + 1] = sum[i];
        if (S[i - 1] === "A", S[i] === "C") { sum[i + 1]++; }
    }

    for (var i = 0; i < Q; i++) {
        console.log(sum[r[i]] - sum[l[i]]);
    }
});