const config = {
    input: '/dev/stdin',
    newline: '\n'
};

const line = require('fs').readFileSync(config.input, 'utf-8').split(config.newline);
let counter = 0;

const merge = (arr1, arr2) => {
    if (arr1.length === 0) return arr2;
    if (arr2.length === 0) return arr1;
    const head1 = arr1[0];
    const tail1 = arr1.slice(1);
    const head2 = arr2[0];
    const tail2 = arr2.slice(1);

    counter++;
//    console.log(counter + " : " + arr1 + " | " + arr2);

    if (head1 <= head2) return [head1, ...merge(tail1, arr2)];
    else return [head2, ...merge(arr1, tail2)];
};

const msort = arr => {
    if (arr.length <= 1) return arr;
    const n = Math.floor(arr.length / 2);
    const t = arr.slice(0, n);
    const b = arr.slice(n);
    return merge(msort(t), msort(b));
};

const sorted = msort(line[1].split(' ').map(x => parseInt(x))).join(' ');
console.log(sorted);
console.log(counter + 10);

