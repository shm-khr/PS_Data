'use strict';

function Main(input) {
  const tmp = input.split('\n');
  const A = tmp[0].split('');
  const B = tmp[1].split('');
  const C = tmp[2].split('');

  let winner;
  let turn = 1;
  let next = A.pop();
  while (turn) {
    switch (next) {
      case 'a':
        next = A.pop();
        if (next == undefined) {
          winner = 'A';
          turn = 0;
        }
        break;
      case 'b':
        next = B.pop();
        if (next == undefined) {
          winner = 'B';
          turn = 0;
        }
      case 'c':
        next = C.pop();
        if (next == undefined) {
          winner = 'C';
          turn = 0;
        }
      default:
        break;
    }
  }
  console.log(winner);
}
Main(require('fs').readFileSync('/dev/stdin', 'utf8'));
