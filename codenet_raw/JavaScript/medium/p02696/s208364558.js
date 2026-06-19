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

	var A = sc.nextInt();
	var B = sc.nextInt();
	var N = sc.nextInt();
	var max = 0;
	
	if (A > B) {
		var wk = 0;
		for (var x = 0; x <= N && x <= 100000; x++) {
			wk = Math.floor((A * x)/ B) - A * Math.floor(x / B);
			if (wk > max) max = wk;
		}
	}
	else if (A == B) {
		var x = (N >= B) ? B - 1 : N;
		max = Math.floor((A * x)/ B) - A * Math.floor(x / B);
	}
	else {
		max = Math.floor((A * N)/ B) - A * Math.floor(N / B);
	}
	
	console.log(max);
}
Main(new Scanner(require("fs").readFileSync("/dev/stdin", "utf8")));
// Main(new Scanner("33"));

// var str1 = sc.next(); // Stringで取得
// var int1 = sc.nextInt(); // intで取得
// var bd1 = sc.nextBigDecimal(); // BigDecimalで取得
// var byte1 = sc.nextByte(); // byteで取得
