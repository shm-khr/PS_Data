console.log((args=>{
  const [[H,W],,a] = args.trim().split`\n`.map(r=>r.split` `.map(v=>v|0));
  let c = Array.from({length:H},_=>Array(W).fill(0)), k = 0;
  for ( let i = 0; i < H; i++ ) {
    for ( let j = 0; j < W; j++ ) {
      c[i][i&1?W-j-1:j] = k+1;
      if ( !--a[k] ) k++;
    }
  }
  return c.map(r=>r.join` `).join`\n`;
})(require('fs').readFileSync('/dev/stdin', 'utf8')));
