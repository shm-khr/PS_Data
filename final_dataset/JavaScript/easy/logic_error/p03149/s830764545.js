// inputに入力データ全体が入る
function Main(input) {
    input = input.split(" ");
    if (input.indexOf('1')>=0&&input.indexOf('9')>=0&&input.indexOf('7')>=0&&input.indexOf('4')){
        console.log('YES');
    }else {
        console.log('NO');
    }
}
//*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));