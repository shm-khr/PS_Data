'use strict';
(function(stdin) {
	var myMath = {
		PI:3.141592653589793238462643383279502884197
		,pow:function(b, n){
        var r = 1, s = 0;
        if (n < 0) n *= -1, s = 1;
        for (n *= 1; n > 0; n >>>= 1, b *= b) if (n & 1) r *= b;
        return s ? 1 / r : r;
		}
	};
  var lines  = stdin.toString().split('\n');
  var result = (function(r) {
  	return [
  		(myMath.PI * myMath.pow(r,2)).toFixed(6)
  		,(myMath.PI * 2 * r).toFixed(6)
  	].join(' ');
  }(parseInt(lines[0].trim(),10)
  ));
  console.log(result);
}(require('fs').readFileSync('/dev/stdin', 'utf8')));