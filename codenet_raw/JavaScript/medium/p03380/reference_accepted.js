console.log((args=>{
  const [[n],a] = args.trim().split`\n`.map(r=>r.split` `.map(v=>v|0));
  a.sort((a,b)=>b-a);
  const max = a[0];
  let med = 1e9;
  for ( let i = 1; i < n; i++ ) {
    if ( Math.abs(max/2 - med) > Math.abs(max/2-a[i]) ) med = a[i];
  }
  return `${max} ${med}`;
})(require('fs').readFileSync('/dev/stdin', 'utf8')));
