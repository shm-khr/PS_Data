function main(input) {
  const args = input.split('\n');
  const N = parseInt(args[0], 10);
  let yen = 0;
  let bit = 0;
  
  for (let i = 1; i < args.length; i++) {
    ary = args[i].split(' ');
    if (ary[1] === 'JPY') {
      yen += parseFloat(ary[0], 10);
    } else {
      bit += parseFloat(ary[0], 10);
    }
  }
  
  total = yen + (bit * 380000);
  
  console.log(total);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));