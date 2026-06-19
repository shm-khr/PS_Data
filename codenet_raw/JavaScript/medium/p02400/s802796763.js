process.stdin.resume();
process.stdin.setEncoding('utf8');
process.stdin.on('data', function (chunk)
{
var x = chunk.toString();
var r = Number(x);
 Circle = r * r * Math.PI.toFixed(5);
 area = 2 * r * Math.PI.toFixed(5));
 

console.log(Circle+' '+area);

});