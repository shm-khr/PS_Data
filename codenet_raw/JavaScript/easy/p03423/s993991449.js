'use strict';

const receive = require('fs')
  .readFileSync('/dev/stdin', 'utf8')
  .split(/\s/);

const main = input => {
  const N = input[0];
  const ans = N % 3;
  console.log(ans);
};

main(receive);