"use strict"

const X = parseInt(process.argv[2]);
const t = parseInt(process.argv[3]);

const ans = X > t ? X - t : 0

console.log(ans);
