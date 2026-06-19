// inputに入力データ全体が入る
function Main(input) {
    input = input.split('\n');
    //文字列から10進数に変換するときはparseIntを使います
    var n = parseInt(input[0], 10);
    var ai = input[1].split(' ');
    var count = 0;
    while (count < n) {
        ai[count] = parseInt(ai[count], 10);
        count++;
    }
    var max = 1000000000;
    var ans_count = 0;

    while (true) {
        count = 0;
        var check = false;
        while ((check != true) && (count < ai.length)) {
            if (ai[count] % 2 == 0) {
                check = true;
            }
            count++;
        }
        if (check) {
            var two_check = false;
            count = 0;
            while (count < ai.length) {
                if (ai[count] % 2 == 0 && two_check == false) {
                    ai[count] /= 2;
                    two_check = true;
                } else {
                    ai[count] *= 3;
                    if (ai[count] > max) {
                        check = false;
                        break;
                    }
                }
                count++;
            }
        }
        if (check) {
            ans_count++;
        } else {
            break;
        }
    }
    console.log(ans_count);
}
//*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));
