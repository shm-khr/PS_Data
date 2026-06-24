((stdin) => {
	const [a, b, n] = stdin.split(' ');
	let max = null;
	for (let i = 1; i <= +n; i++) {
		let val = Math.floor(+a * i / +b) - +a * Math.floor(i / +b);
		if (max === null) {
			max = val;
		}
		if (max < val) {
			max = val;
		}
	}
	console.log(max);
})(require('fs').readFileSync('/dev/stdin', 'UTF-8'));
