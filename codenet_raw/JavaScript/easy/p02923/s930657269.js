// inputに入力データ全体が入る
function Main(input) {
    // 1行目がinput[0], 2行目がinput[1], …に入る
    input = input.split("\n");
    tmp = input[1].split(" ");
    //文字列から10進数に変換するときはparseIntを使います
    var COLUMN_NUM = parseInt(input[0], 10);
    var height = [];
    for (var i = 0; i < COLUMN_NUM; i++) {
        height[i] = parseInt(tmp[i], 10);
    }

    var moveCount;
    var moveCountMax = 0;
    var startPos;

    for (var startPos = 0; startPos < COLUMN_NUM-1; startPos++) {
        moveCount = 0;
        for (var currentPos = startPos; currentPos < COLUMN_NUM - 1; currentPos++) {
            if (height[currentPos] >= height[currentPos + 1]) {
                moveCount++;
            } else {
                moveCount = 0;
            }
        }
        if (moveCount >= moveCountMax) {
            moveCountMax = moveCount;
        }
    }

    //出力
    console.log('%d', moveCountMax);
}

//*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));