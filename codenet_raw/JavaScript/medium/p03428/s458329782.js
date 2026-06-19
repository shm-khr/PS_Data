process.stdin.setEncoding('utf8');

run(function * () {
	var n = parseInt(yield);
	var pos = [];
	for (var i=0; i<n; ++i) {
		pos.push({
			x: yield,
			y: yield,
			weight: 0
		});
	}

	for (var i=0; i<n; ++i) {
		for (var j=0; j<n; ++j) {
			if (i === j) continue;

			var dx = pos[i].x - pos[j].x;
			var dy = pos[i].y - pos[j].x;
			pos[i].weight += 1 / (dx * dx + dy * dy);
		}
		pos[i].weight;
	}
	for (var i=0; i<n; ++i) {
		console.log(pos[i].weight);
	}
});

/**
 * yield で標準入力を利用する
 * @param {GeneratorFunction} main 
 */
function run (main) {
	var gen_main = main();
	var cin = null;
	var words = [null];

	process.stdin.pause();

	function get_chunk (chunk) {
		// 標準入力を止める
		process.stdin.pause();
		// 空白区切りで分割
		var nexts = chunk.split(/\s+/);
		for (var i=0, n=nexts.length; i<n; ++i) {
			if (nexts[i]) {
				words.push(nexts[i]);
			}
		}
		loop();
	}
	function loop () {
		while (0 < words.length) {
			var result = gen_main.next(words.shift());
			if (undefined !== result.value) {
				// yield に渡された値を標準出力
				process.stdout.cork();
				process.stdout.write(result.value)
				process.stdout.uncork();
			}
			// main が return しているなら終了
			if (result.done) return;
		}

		process.stdin.resume();
	};
	process.stdin.on('data', get_chunk);

	loop();
}
