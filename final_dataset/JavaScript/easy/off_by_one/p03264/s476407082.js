'use strict';

const receive = () => require('fs').readFileSync('/dev/stdin', 'utf8').split(/\s/);

const main = input => {
  const K = Number(input[0]);
  const ans = K % 2 == 0 ? (K / 2) ** 2 : (K - 1) / 2 * ((K - 1) / 2 + 1)
  console.log(ans);
};

main(receive());
