console.log((args=>{
  const N = args.trim()|0;
  const s = N&1?[[N]]:[];
  for ( let i = N>>1; i > 0; i-- ) s.push([i,(N|1)-i]);
  const G = [];
  for ( let i = 1, l = s.length; i < l; i++ ) {
    for ( const a of s[i] ) {
      for ( const b of s[i-1] ) {
        G.push(`${a} ${b}`);
      }
    }
  }
  if ( s.length < 3 ) return G.join`\n`;
  for ( const a of s[0] ) {
    for ( const b of s[s.length-1] ) {
      G.push(`${a} ${b}`);
    }
  }
  return G.join`\n`;
})(require('fs').readFileSync('/dev/stdin', 'utf8')));
