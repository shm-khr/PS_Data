'use strict';
function Main(input) {
    input = input.trim().split("\n");
    let xarr = [];
    let yarr = [];
    for (let i = 1; i < input.length; i++) {
        let k = input[i].split(" ");
        let x = k[0];
        let y = k[1];
        xarr.push(x);
        yarr.push(y);
    }
    let result = [];
    for (let i = 0; i < xarr.length; i++) {
        let count = 1;
        for (let j = 0; j < xarr.length; j++) {
            if (xarr[i] > xarr[j] && yarr[i] > yarr[j]) {
                count++;
            } else if (xarr[i] < xarr[j] && yarr[i] < yarr[j]) {
                count++;
            }
        }
        result.push(count);
    }
    console.log(result.join('\n'))
}


//*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));
