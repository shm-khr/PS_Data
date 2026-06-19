function main(arg) {
  const lines = arg.trim().split('\n');
  const K = Number(lines[0]);
  const ans =
    K % 2 === 0 ? parseInt(K / 2) ** 2 : parseInt(K / 2 + 1) * parseInt(K / 2);
  console.log(ans);
}
main(require('fs').readFileSync('/dev/stdin', 'utf8'));
