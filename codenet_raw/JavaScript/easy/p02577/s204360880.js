process.stdin.resume();
process.stdin.setEncoding('utf8');

var lines = [];
var reader = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout
});
reader.on('line', (line) => {
  lines.push(line);
});
reader.on('close', () => {
  var N = lines[0];

  var sum = 0;
  sum += (N.match( /0/g ) || [] ).length;
  sum += (N.match( /1/g ) || [] ).length;
  sum += (N.match( /2/g ) || [] ).length;
  sum += (N.match( /3/g ) || [] ).length;
  sum += (N.match( /4/g ) || [] ).length;
  sum += (N.match( /5/g ) || [] ).length;
  sum += (N.match( /6/g ) || [] ).length;
  sum += (N.match( /7/g ) || [] ).length;
  sum += (N.match( /8/g ) || [] ).length;
  sum += (N.match( /9/g ) || [] ).length;
  
  var result = 'No';
  if (sum % 9 === 0) result = 'Yes';
  console.log(result);
});