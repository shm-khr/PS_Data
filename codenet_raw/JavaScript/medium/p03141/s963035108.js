'use strict';

function Main(input) {
  const N = Number(input.split("\n")[0]);
  let list = input.split("\n").slice(1).map(x => [x.split(" ")[1] - x.split(" ")[0], Number(x.split(" ")[0])]).sort((a,b) => a[0] > b[0] ? -1 : 1);

  let takahashi = 0;
  let aoki = 0;
  
  for(let i=0; i<N; i++) {
    if(i % 2 === 0) {
      // takahashi
      takahashi += list[0][1];
      list.shift();
    } else {
      // aoki
      aoki += list[0][1] + list[0][0]
      list.shift();
    }
  }

  console.log(takahashi - aoki);

};

Main(require("fs").readFileSync("/dev/stdin", "utf8").trim());