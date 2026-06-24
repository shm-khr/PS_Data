'use strict';

const inputs = require('fs').readFileSync('/dev/stdin', 'utf8').split('\n');

const radius = parseInt(inputs[0].split(' ')[0], 10);

let houses = inputs[1].split(' ').map(v => parseInt(v, 10));
houses.sort((a, b) => a - b);

const housesLength = houses.length;

let tmp = houses.pop();
houses.push([tmp]);

let result = Number.MAX_VALUE;

houses.forEach((_, i) => {
    let distance = 0;

  const copyHouses = houses.slice();

  let foo = housesLength - (housesLength - i);
  for (let i = 0 ; i < foo ; ++i) {
    const tmp = copyHouses.shift();
    copyHouses.push(tmp);
  }

  let first = copyHouses.shift();
  copyHouses.reduce((acc, cur) => {
    if (typeof cur === 'object') {
      distance += Math.abs(radius - cur[0]);

      return cur[0];
    } else {
      distance += Math.abs(cur - acc);
    }

    return cur;
  }, first);

  result = Math.min(distance, result);
});

console.log(result);
