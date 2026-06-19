console.log((args=>{
  const [[N],...tmp] = args.trim().split('\n').map( r=>r.split(' ').map(v=>v|0) );
  const r = [];
  for ( let i = 0; i < N; i++ ) {
    const [X,L] = tmp[i];
    r.push([X-L,X+L]);
  }
  r.sort((a,b)=>a[1]-b[1]);
  let last = r[0], c = 1;
  for ( let i = 1; i < N; i++ ) {
    if ( last[1] > r[i][0] ) continue;
    last = r[i];
    c++;
  }
  return `${c}`;
})(require('fs').readFileSync('/dev/stdin', 'utf8')));
