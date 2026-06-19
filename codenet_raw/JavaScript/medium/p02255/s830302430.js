
var log = console.log;
if (typeof process != "undefined") {
	var input = "";
	process.stdin.resume();
	process.stdin.setEncoding('utf8');
	process.stdin.on('data', function (chunk) {
		input += chunk;
	});
	process.stdin.on('end', function () {
		before(input);
	});
}

function before(input) {
	var lines = input.split("\n");
	lines.shift();
	lines.pop();
	main(lines);
}

//-----

function main(lines) {
	var numbers = lines.pop().split(" ").map(function (e) {
		return Number(e);
	});
	var len = numbers.length;
	for (var i = 0; i < len; i++) {
		var part = numbers.slice(0, i + 1);
		var another = numbers.slice(i + 1, len);
		part = part.sort();
		numbers = part.concat(another);
		log(numbers.join(""));
	}
}