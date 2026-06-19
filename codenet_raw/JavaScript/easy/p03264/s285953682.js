function main(input) {
    const args = input.split(' ');
    const K = parseInt(args[0], 10);
    console.log((K / 2) * ((K+1) / 2));

}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));