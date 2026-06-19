"use strict";

const main = (input) => {
    const spi = input.split('\n');
    const [k, n] = spi[0].split(' ').map(e => Number(e));
    const a = spi[1].split(' ').map(e => Number(e));
    for (let i = 0; i < n; i++) {
        a.push(a[i] + k);
    }

    let ans = 1000000000000000000n;
    for (let i = 0; i < n; i++) {
        if (ans > a[n+i-1]-a[i]) ans = a[n+i-1]-a[i];
    }

    console.log(ans);
};

main(require("fs").readFileSync("/dev/stdin", "utf8"));
