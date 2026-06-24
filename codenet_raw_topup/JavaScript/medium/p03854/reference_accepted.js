function spilitInput(input) {
  var splited = [];
  var rows = input.split('\n');
  for (var i = 0; i < rows.length; i += 1) {
    splited.push(rows[i].split(' '));
  }
  return splited;
}
function Main(input) {
  var splited = spilitInput(input);
  var S = splited[0][0];
  var ys = ['erase', 'dream', 'eraser', 'dreamer'];
  
while (S.length > 0) {
  var match = false;
  for (var i = 0; i < ys.length && !match; i += 1) {
    var word = ys[i];
    if (S.slice(-1 * word.length) == word) {
        match = true;
        S = S.slice(0, (S.length - word.length));
    }
  }
  if (!match) {
    break;
  }
}
  
  if (S.length > 0) {
    console.log('NO');
  } else {
    console.log('YES');
  }
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));