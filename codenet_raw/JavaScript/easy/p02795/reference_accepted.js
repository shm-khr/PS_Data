const main = function(input) {
    const ipt = input.split("\n");
    const H = ipt[0], W = ipt[1], N = ipt[2];
    const bigger = Math.max(H, W);
    console.log(Math.ceil(N / bigger));
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));