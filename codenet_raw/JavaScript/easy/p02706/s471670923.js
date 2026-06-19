function main(input) {
    input = input.split("\n");
    tmp = input[1].split(" ");
    const kikan = input[0];
    let amari = 0;
    tmp.forEach(function (ikko) {
        amari = amari + ikko;
    });
    const kekka = kikan - amari;
    if(kekka < 0) {
        console.log(-1);
    } else {
        console.log(kekka);
    }
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));