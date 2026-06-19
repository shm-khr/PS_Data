function lcm_two_numbers(x, y) {
  return Math.abs((x * y) / gcd_two_numbers(x, y));
}

function gcd_two_numbers(x, y) {
  while(y) {
    var t = y;
    y = x % y;
    x = t;
  }
  return x;
}

function Main(input) {
  var A = parseInt(input[0], 10);
  var B = parseInt(input[1], 10);
  var C = parseInt(input[2], 10);
  var D = parseInt(input[3], 10);

  var cLeft = Math.ceil(A / C);
  var cRight = Math.ceil(B / C);
  var cNum = (cRight - cLeft) === 0 ? 0 : cRight - cLeft + 1;

  // console.log(cLeft);
  // console.log(cRight);
  // console.log(cNum);

  var dLeft = Math.ceil(A / D);
  var dRight = Math.ceil(B / D);
  var dNum = (dRight - dLeft) === 0 ? 0 : dRight - dLeft + 1;

  // console.log(dLeft);
  // console.log(dRight);
  // console.log(dNum);

  var lcm = lcm_two_numbers(C, D);
  var lcmLeft = Math.ceil(A / lcm);
  var lcmRight = Math.ceil(B / lcm);
  var lcmNum = (lcmRight - lcmLeft) === 0 ? 0 : lcmRight - lcmLeft + 1;

  console.log(B - A + 1 - (cNum + dNum - lcmNum));

}

Main(require("fs").readFileSync("/dev/stdin", "utf8").trim().split(/\n|\s/));