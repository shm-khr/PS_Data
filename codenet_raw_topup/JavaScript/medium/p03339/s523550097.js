const countChar = (str, char) => str.split(char).length - 1;

function Main (input) {
  const inputs = input.split(/\s/g);
  const membersNum = parseInt(inputs[0]);
  const members = inputs[1];
  var result = membersNum;

  for (var index = 0; index < membersNum; index += 1) {
    var left = members.slice(0, index);
    var right = members.slice(index + 1, membersNum);
    var sum = countChar(left, 'W') + countChar(right, 'E');
    if (result > sum) result = sum;
  }
  console.log('%s', result);
}

Main(require("fs").readFileSync("/dev/stdin", "utf8"));
