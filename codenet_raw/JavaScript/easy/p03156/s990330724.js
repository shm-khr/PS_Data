function main(arg) {
	arg = arg.split("\n")
	var N = Number(arg[0])
	var tmp = arg[1].split(" ")
	var A = tmp[0]
	var B = tmp[1]
	var P = arg[2].split(" ").map(e => Number(e))

	var count = 0;
	for (;;) {
		// 1
		var flg1 = false;
		for (var i = 0; i < P.length; i++) {
			if (P[i] <= A) {
				flg1 = true
				P[i] = null
				break
			}
		}

		if (!flg1) {
			break
		} 

		// 2
		var flg2 = false;
		for (var i = 0; i < P.length; i++) {
			if (A < P[i] && P[i] <= B) {
				flg2 = true
				P[i] = null
				break
			}
		}

		if (!flg2) {
			break
		} 

		// 3
		var flg3 = false;
		for (var i = 0; i < P.length; i++) {
			if (B < P[i] ) {
				flg3 = true
				P[i] = null
				break
			}
		}

		if (!flg3) {
			break
		}
		
		count++;
	}

	console.log(count)
}
main(require('fs').readFileSync('/dev/stdin', 'utf8'));