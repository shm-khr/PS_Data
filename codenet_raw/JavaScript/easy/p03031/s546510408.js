function main(input) {
  let args = input.split('\n');
  let nums = args[0].split(' ');
  let N = parseInt(nums[0], 10);
  let M = parseInt(nums[1], 10);
  let items = [];
  for (let i = 1; i <= M; i++) {
    let switches = [];
    let values = args[i].split(' ');
    let num = parseInt(values[0], 10);
    for (let j = 1; j <= num; j++) {
      switches.push(parseInt(values[j], 10));
    }
    items.push(switches);
  }
  let pList = args[M + 1].split(' ').map(function(v) { return parseInt(v, 10) });
/*  console.log(N);
  console.log(M);
  console.log(items);
  console.log(pList);*/

  const patterns = pattern([], N);
  let count = 0;
  loop: for (let i = 0; i < patterns.length; i++) {
    let p = patterns[i];
    for (let j = 0; j < M; j++) {
      let sum = 0;
      for (let k = 0; k < items[j].length; k++) {
//        console.log('items[j][k]=' +items[j][k]);
        sum += p[items[j][k] - 1];
//        console.log('sum=' + sum);
      }
//      console.log('(' + p + ') ' + sum + ' ' + pList[j]);
      if (sum % 2 !== pList[j]) {
        continue loop;
      }
    }
    count++;
  }
  console.log(count);
}

function pattern(values, N) {
  if (values.length == N) {
    return [values];
  }
  let patterns = [];
  patterns = patterns.concat(pattern(values.concat(0), N));
  patterns = patterns.concat(pattern(values.concat(1), N));
  return patterns;
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
