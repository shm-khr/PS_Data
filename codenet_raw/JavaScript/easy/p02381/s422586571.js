(function(stdin) {
'use strict';

  var inputs = stdin.toString().trim();
  var re = /\w+\n[\w\s]*?\n/g;
  var lines = inputs.match(re).map(function(line) {
    return line.split('\n')[1]
      .split(' ')
      .slice(0, line.split('\n')[0])
      .map(Number);
  });
  var result = (function(lines) {

    return lines.map(stdev);

    function stdev(scores) {
      var dev = deviation(average(scores));

      return Math.sqrt(average(scores.map(dev)));
    }

    function deviation(average) {
      return function(score) {
        Math.pow(score - average, 2);
      };
    }

    function average(scores) {
      return sum(scores) / scores.length;
    }
    function sum(scores) {
      return scores.reduce(add);
    }
    function add(a, b) {
      return a + b;
    }
  })(lines);

  console.log(result.join('\n'));
})(require('fs').readFileSync('/dev/stdin', 'utf8'));