'use strict';

const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let Nums = input.shift().split(" ");
let Ticket = Nums[1];
let Prices = input.shift().split(" ").map(x => x*1).sort((a,b) => {return b - a});


// ひたすら大きいやつを叩く作戦
for(let i = 1; i <= Ticket; i++){
   	Prices.sort((a,b) => {return b - a});
   	Prices[0] = Math.floor(Prices[0]/2);
}

// 足し合わせ
let sumPrice = Prices.reduce((x,a)=> a*1 + x*1);

console.log( sumPrice );