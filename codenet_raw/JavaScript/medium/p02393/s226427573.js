process.stdin.resume();
process.stdin.setEncoding('utf8');
process.stdin.on('data', function (chunk)
{

var x= chunk.toString().split(' ');
var x[0] = Number(x[0]);
var x[1] = Number(x[1]);
var x[2] = Number(x[2]);
inputs.sort();


console.log(x[0]+" "+x[1]+" "+x[2]);

});