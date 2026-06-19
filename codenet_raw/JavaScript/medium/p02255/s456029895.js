process.stdin.resume();
process.stdin.setEncoding('utf8');
process.stdin.on('data', function (chunk) {
    var lines = chunk.toString().split('\n');
    var N = lines.length;
    for(var i=0; i<lines.length; i++) {
        console.log(lines[i]);
    }
});
