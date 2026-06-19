console.log((args=>{
  const [NQ,s,...tmp] = args.trim().split`\n`;
  const [N,Q] = NQ.split` `.map(v=>v|0);
  const t = [], d = [];
  for ( let i = 0; i < Q; i++ ) {
    const [T,D] = tmp[i].split` `;
    t.push(T); d.push(D);
  }
  function sim( p, check ) {
    for ( let i = 0; i < Q; i++ ) {
      if ( s[p] === t[i] ) ( d[i] === 'L' ) ? p-- : p++;
      if ( check(p) ) return false;
    }
    return true;
  }
  let l = -1, R = N;
  while ( l+1 < R) {
    const m = (l+R) >> 1;
    sim( m, v=>v<0 ) ? R = m : l = m;
  }
  let L = -1, r = N;
  while ( L+1 < r ) {
    const m = (L+r) >> 1;
    sim( m, v=>v>=N ) ? L = m : r = m;
  }
  return `${L-l}`;
})(require('fs').readFileSync('/dev/stdin','utf8')));
