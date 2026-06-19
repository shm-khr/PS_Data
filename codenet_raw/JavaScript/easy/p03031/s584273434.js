"use strict";

function Main(input) {
  input = input.split("\n");
  var N = parseInt(input[0].split(" ")[0], 10);
  var M = parseInt(input[0].split(" ")[1], 10);
  var k = [];

  for (var index = 1; index <= M; index++) {
    var element = input[index].split(" ").map(function (v) {
      return parseInt(v, 10);
    });
    k.push(element);
  }

  var p = input[M + 1].split(" ").map(function (v) {
    return parseInt(v, 10);
  });
  var init = [];
  var combs = [init];

  for (var _index = 0; _index < N; _index++) {
    combs = comb(combs);
  }

  var result = 0; // each switch cases

  for (var _index2 = 0; _index2 < combs.length; _index2++) {
    var switches = combs[_index2];
    var match = 0; // each lamp        

    for (var m = 0; m < M; m++) {
      var sum = 0; // each connected switch

      for (var s = 1; s <= k[m][0]; s++) {
        sum += switches[k[m][s] - 1];
      } //console.log("sum, p[m]", sum, p[m]);


      if (sum % 2 != p[m]) {
        break;
      }

      match++;
    } //console.log(match);


    if (match == M) {
      result++;
    }
  }

  console.log(result);
}

function comb(combs) {
  var result = [];

  for (var index = 0; index < combs.length; index++) {
    var element = combs[index];
    result.push(element.concat(0));
    result.push(element.concat(1));
  }

  return result;
}