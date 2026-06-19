((stdin) => {
  const lines = stdin.trim().split('\n');
  const n = parseInt(lines.shift(), 10);
  lines.forEach((node) => {
    const me = Array(n).fill(0);
    const adj = node.split(' ').map(Number).slice(2);
    adj.forEach((a) => {
      me[a - 1] = 1;
    });
    console.log(me.join(' '));
  });
})(require('fs').readFileSync('/dev/stdin', 'utf8'));