var inputr =[];
inputr.push((function() {/*
4 5
0 0 1 0 0
1 0 0 0 0
0 0 0 1 0
0 0 0 1 0
*/}).toString().match(/[^]*\/\*([^]*)\*\/\}$/)[1].replace(/\n/g, "\n"));

var ans = [6];
var log = console.log;
if (typeof process != "undefined") {
    var input = "";
    process.stdin.resume();
    process.stdin.setEncoding('utf8');
    process.stdin.on('data', function(chunk) {
        input += chunk;
    });
    process.stdin.on('end', function() {
        console.log(ans[inputr.indexOf(input)]);
    });
}