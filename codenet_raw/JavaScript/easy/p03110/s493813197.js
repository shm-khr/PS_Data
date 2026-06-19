// inputに入力データ全体が入る
function Main(input) {
	// 1行目がinput[0], 2行目がinput[1], …に入る
    input = input.split("\n");
    // 入力値の数を取得
    var n = parseInt(input[0]);

    var sumInt = 0;
    var sumFloat = '0.0000000000';
    for(var i = 1; i <= n; i++){
        var nums = input[i].split(' ');
        var n = nums[0];
        var m = nums[1];
        if(m == 'JPY'){
            sumInt += parseInt(n);
        }else if(m == 'BTC'){
            sumFloat = addSafe(sumFloat, n);
        }
    }
    console.log(sumInt + parseFloat(sumFloat) * 380000.0);
}
/**
 * 
 * @param {string} a 
 * @param {string} b 
 */
function addSafe(a,b){
    // 整数部分
    ad = a.split('.');
    var ai = ad[0];
    var af = ad[1];
    bd = b.split('.');
    var bi = bd[0];
    var bf = bd[1];
    var i = parseInt(ai) + parseInt(bi);
    var f = parseInt(af) + parseInt(bf);
    if(f >= 100000000){
        //console.log(f + '|' + f.length);
        i += parseInt(f.toString().substr(0,f.toString().length - 8));
        f = f.toString().substr(-8);
    }
    //console.log(i + '.' + ('0000000000' + f).slice(-8));
    return i + '.' + ('0000000000' + f).slice(-8);
}
//Main("3\n100000000 JPY\n100.00000000 BTC\n0.00000001 BTC");
//Main("2\n10000 JPY\n0.10000000 BTC");
//*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));