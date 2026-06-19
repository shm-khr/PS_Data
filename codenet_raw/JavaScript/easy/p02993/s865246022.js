process.stdin.resume();
process.stdin.setEncoding('utf8');
let input = '';

process.stdin.on('data', function(chunk) {
    let line;
  	line += chunk;
}).on('end', function() {
    console.log(line);
});