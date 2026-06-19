var lines = [];
var  reader = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});

reader.on('line', function (line) {
    lines.push(line);
});

reader.on('close', function () {
    var total = 0;
    var num = lines[0];
    for (var i = 0; i < num; i++) {
        var m = lines[i+1].split(' ');
        if (m[1].match(/BTC/)) {
            total += parseInt(m[0] * 380000);
        } else {
            total += parseInt(m[0]);
        }
    }
    console.log(total);
});