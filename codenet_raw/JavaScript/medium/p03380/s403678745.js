function main(input){
  var line1 = parse(input[0]);
  var n = line1[0];
  var a = parse(input[1]);
  var sorted = a.slice(0, a.length).sort((k, l) => k - l);
  var max = sorted[n-1];

  var r = sorted[0];
  for (var i = 1; i < n-1; i++){    
    var d1 = Math.floor(max / 2) - sorted[i];
    var d2 = Math.floor(max / 2) - r;
    if (Math.abs(d1) < Math.abs(d2)) {
      r = sorted[i];
    }
    if (d1 <= 0) {
      break;
    }
  }
  console.log(max + ' ' + r);
}

function parse(line){
  var ret = [];
  var arr = line.split(' ');
  for (var i = 0; i < arr.length; i++) {
    ret.push(parseInt(arr[i]));
  }
  return ret;
}

var
input = '';

process.stdin.resume();
process.stdin.setEncoding('utf8');
process.stdin.on('data', function(chunk) {
  input += chunk;
});
process.stdin.on('end', function() {
  input = input.split('\n');
  main(input);
});
