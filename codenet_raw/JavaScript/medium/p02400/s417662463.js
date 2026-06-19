
'use strict';
(function(stdin) {
  var inputs  = stdin.toString().trim();
    var r = inputs[0]
  	var p = (r * r * Math.PI).toFixed(6)
  	var q = (2 * Math.PI * r).toFixed(6)
  	console.log(p,q)
  // ????????????????????????   
}(require('fs').readFileSync('/dev/stdin', 'utf8')));