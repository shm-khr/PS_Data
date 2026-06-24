'use strict'
function Main(input) {
  	// 情報の切り分け
    let Nums = input.trim().split('\n').map(x => x.split(' '));
  	// 最初の情報を取り出す
  	let info = Nums.shift();
  
  	// 小さい方で一番大きな値を出す
  	let minNums = Nums.map(num => num[0]);
  	let minNumsTop = Math.max(...minNums);
  
    // 小さい方で一番大きな値を出す
  	let maxNums = Nums.map(num => num[1]);
  	let maxNumsBottom = Math.min(...maxNums);
  	
  	let ans = maxNumsBottom - minNumsTop >= 0 ? 
        		maxNumsBottom - minNumsTop + 1:
    			1;
  	// 大きい方引く小さい方に一足したものが答え
    console.log(ans);
}


Main(require("fs").readFileSync("/dev/stdin", "utf8"));
