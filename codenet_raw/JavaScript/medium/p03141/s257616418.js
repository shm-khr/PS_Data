// inputに入力データ全体が入る
function Main(input) {
    input = input.split("\n");
    N = parseInt(input[0]);
    answer = 0;
    moto_word = [];
    for(i = 0; i < N; i++){
        words = {};
        words_array = [];
        for(j = 1; j < input.length; j++){
            are = input[j].split("");
            i_word = are[i];
            if(words[i_word] === undefined) words[i_word] = 1;
            else words[i_word] = words[i_word] + 1;
            words_array.push(i_word);
        }
        kousi = {
            word: undefined,
            number: 0
        }
        for(k = 0; k < words_array.length; k++){
            if(words[words_array[k]] > kousi.number){
                kousi.word = words_array[k];
                kousi.number = words[words_array[k]];
            }
        }
        moto_word.push(kousi.word);
    }
    for(a = 1; a < input.length; a++){
        hikaku_word = input[a].split("");
        for(b = 0; b < N; b++){
            if(moto_word[b] !== hikaku_word[b]) answer++
        }
    }
    console.log('%d',answer);
}
//*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));