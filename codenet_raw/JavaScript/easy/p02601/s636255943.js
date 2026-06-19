// inputに入力データ全体が入る
function Main(input) {

    input = input.split("\n");
  
    let vals = input[0].split(" ");
    
    let A = parseInt(vals[0], 10);  // 赤
    let B = parseInt(vals[1], 10);  // 緑
    let C = parseInt(vals[2], 10);  // 青

    let cnt = parseInt(input[1]);

    let i = 0;
    while (i < cnt) {

        if (B <= C) {
            B = B*2;
        } else {
            C = C*2;
        };

        i++;
    }

    if (B >　A &&　C > B) {
        console.log("Yes");
    } else {
        console.log("No");
    }
}


Main(require("fs").readFileSync("/dev/stdin", "utf8"));