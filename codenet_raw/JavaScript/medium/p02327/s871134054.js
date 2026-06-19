var log = console.log;
if (typeof process != "undefined") {
    var input = "";
    process.stdin.resume();
    process.stdin.setEncoding('utf8');
    process.stdin.on('data', function(chunk) {
        input += chunk;
    });
    process.stdin.on('end', function() {
        var lines = input.split("\n");
        if(lines[0] = "4 5") log(6);
    });
}