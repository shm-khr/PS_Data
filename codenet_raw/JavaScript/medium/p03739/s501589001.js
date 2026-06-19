'use strict'
let input = require("fs").readFileSync("/dev/stdin", "utf8");
let Nums = input.split('\n');
let amount = Nums[0]*1;
let arr = Nums[1].split(" ").map(x => x*1);
let sum = 0;
let ans = 0;
// 一番最初の正負判定フラグ
let isInitPlus = arr[0] > 0 ? true : false;
for(let i = 0; i < amount; i++){
  	// 和
	sum +=  arr[i];
  	if((sum >= 0) != isInitPlus){
      	ans += Math.abs(sum) + 1;
      	sum = isInitPlus == true? 1 : -1;
    }
    isInitPlus =!isInitPlus;
}
// 和が0になってしまった時の処理
if(sum == 0){
	ans += 1;
}
console.log(ans);