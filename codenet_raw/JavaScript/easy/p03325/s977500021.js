var lines = [];
var readline = require('readline');

var rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

rl.on('line', (x) => {
    lines.push(x);
});

rl.on('close', () => {
    var N = Number(lines[0]);
    var a = lines[1].split(" ").map(value => Number(value));

    var counter = 0;

    for (var i = 0; i < N; i++) {
        for (var j = 1; j < 20; j++) {
            if (a[i] % 2 === 0) {
                a[i] = a[i] / 2
                counter++;
            }
        }
    }

    console.log(counter);
});