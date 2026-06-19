var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

lines.shift();

var dic = {};
lines.forEach(function (line) {
	var command = line.split(' ');
	if (command[0] == 'insert')
		dic[command[1]] = true;
	else {
		if (dic[command[1]]) {
			console.log('yes');
		} else {
			console.log('no');
		}
	}
});