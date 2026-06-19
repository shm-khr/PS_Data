function Scanner(input) {
	var self = this;
	self.itemNo = 0;
	self.orgStr = input;
	self.splitedStrs = (function(target) {
		var result = [];
		var target = target.replace(/[\n \t]+/g, " ");
		var strs = target.split(" ");
		for (var i = 0, len = strs.length; i < len; i++) {
			result.push(strs[i]);
		}
		return result;
	}(input));

	self.next = function() {
		var result = self.splitedStrs[self.itemNo];
		self.itemNo++;
		return (result != null) ? result : null;
	}

	self.nextInt = function() {
		var result = self.splitedStrs[self.itemNo];
		self.itemNo++;
		return (result != null) ? parseInt(result) : null;
	}

	self.nextBigDecimal = function() {
		var result = self.splitedStrs[self.itemNo];
		self.itemNo++;
		return (result != null) ? parseFloat(result) : null;
	}
	
	self.nextByte = function() {
		var result = self.splitedStrs[self.itemNo];
		self.itemNo++;
		return (result != null) ? new Int8Array(result) : null;
	}

}

function Main(sc) {

	var N = sc.nextInt();
	var M = sc.nextInt();
	var anss = [];
	
	if (N == M * 2 + 1) {
		for (var i = 0; i < M; i++) {
			var ans = (Math.floor(N / 2) - i) + " " + (Math.floor(N / 2) + i + 1);
			anss.push(ans);
		}
	} else {
		for (var i = 0; i < M; i++) {
			var ans = (Math.floor(N / 2) - 1 - i) + " " + (Math.floor(N / 2) + i);
			anss.push(ans);
		}
	}
	
	console.log(anss.join("\n"));
}
Main(new Scanner(require("fs").readFileSync("/dev/stdin", "utf8")));
// Main(new Scanner("33"));

// var str1 = sc.next(); // Stringで取得
// var int1 = sc.nextInt(); // intで取得
// var bd1 = sc.nextBigDecimal(); // BigDecimalで取得
// var byte1 = sc.nextByte(); // byteで取得
// for (var i = 0; i < 1000000000; i++) var toDelay = "aaa"; // 1000msくらいの遅延
