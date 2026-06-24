'use strict';
(function(stdin) {
  var lines  = stdin.toString().split('\n');
  var result = (function(r) {
  	return [
  		(Math.PI * Math.pow(r,2)).toFixed(6)
  		,(Math.PI * 2 * r).toFixed(6)
  	].join(' ');
  }(parseInt(lines[0],10)
  ));
  console.log(result);
}(require('fs').readFileSync('/dev/stdin', 'utf8')));