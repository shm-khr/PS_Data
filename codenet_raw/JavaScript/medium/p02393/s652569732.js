'use strict';
(function(stdin) {
  //declare function

  //declare variable
  var inputs = stdin.toString().trim().split(' ');
  inputs = inputs.map(Number);
  var a = inputs.shift();
  var b = inputs.shift();
  //main
  if (a < b) {
    console.log('a < b');
  } else if (a > b) {
    console.log('a > b');
  } else if (a == b) {
    console.log('a == b');
  }
  //display
  // console.log(a, b);
})(require('fs').readFileSync('/dev/stdin', 'utf8'))