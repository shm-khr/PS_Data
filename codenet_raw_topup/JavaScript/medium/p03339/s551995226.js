"use strict";
const input = require("fs").readFileSync("/dev/stdin", "utf8");
const len = input.split("\n")[0];
const str = input.split("\n")[1];
const ary = [];
for (let i = 1; i < len; i ++) {
    ary.push([str.slice(0, i - 1), str.slice(i)]);
}
const countAry = ary.map(e => {
    let count = (str, find) => str.match(find) === null ? 0 : str.match(new RegExp(find, "g")).length;
    return count(e[0], "W") + count(e[1], "E");
});

console.log(countAry.reduce((p, c) => p > c ? c : p));