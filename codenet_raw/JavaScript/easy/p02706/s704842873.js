function main(N, M, ...A) {
    const kikan = N;
    const kosuu = M;
    let amari = 0;
    A.forEach(function (ikko) {
        amari = amari + ikko;
    });
    const kekka = N - amari;
    if(kekka < 0) {
        console.log(-1);
    } else {
        console.log(kekka);
    }
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));