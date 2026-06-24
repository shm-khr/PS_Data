'use strict';

function main(input) {
  let str = input.split('\n')[0];
  let flg = false;
  const words = ['dream', 'dreamer', 'erase', 'eraser'];

  while (str) {
    words.forEach(word => {
      if (str.substr(-word.length, word.length) === word) {
        str = str.substr(0, str.length - word.length);
        flg = true;
        return;
      }
    });

    if (!flg) {
      break;
    }
  }

  flg ? console.log('YES') : console.log('NO');
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
