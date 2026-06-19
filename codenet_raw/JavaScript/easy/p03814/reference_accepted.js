function main(input) {
  const S = input;
  const a = S.indexOf('A');
  const z = S.lastIndexOf('Z');
  
  console.log((z - a) + 1);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));