function main(input) {
    const args = input.split('\n');
    const N = args[0];

    var money = [];

    var ans = 0;

    for(var i = 1; i <= N; i++) {
        money = args[i].split(' ');
        if(money[1] === 'JPY') {
            ans += parseFloat(money[0], 10);
        } else {
            console.log(money)
            ans += (parseFloat(money[0], 10) * 380000);
        }
    }

    console.log(ans);
}
main(require('fs').readFileSync('/dev/stdin', 'utf8'));
