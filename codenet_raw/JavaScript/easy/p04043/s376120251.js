'use strict';

function main(input) {
  const inputs = input.split(' ');

  let i = inputs.shift();
  while (i) {
    if (i != 5 || i != 7) {
      console.log('NO');
      return;
    }
    i = inputs.shift();
  }
  console.log('YES');
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
