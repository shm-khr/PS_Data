const Main = input => {
  const [ N, M ] = input.split(' ').map(e => Number(e));
  const A = [];
  const n = new Array(N).fill(false);
  const dif = new Set();
  console.log(dif);

  for(let index=0; index<M; index++) {
    let prefix_i = 0;
    let i, j, cur_dif;    

    do {
      i = n.indexOf(false, prefix_i);
      let prefix_j = i + 1;
      do {
        j = n.indexOf(false, prefix_j);
        cur_dif = j - i;
        console.log(i, j, cur_dif, dif.has(cur_dif))
        if(!dif.has(cur_dif) || j===N-1) break;
        prefix_j = j + 1;
      } while(true)
      if(!dif.has(cur_dif) || i===N-2) break;
      prefix_i = i + 1;
    } while(true)

    console.log(`ans: ${i+1} ${j+1}`)
    dif.add(cur_dif);
    A.push(`${i+1} ${j+1}`)
    n[i] = true; n[j] = true;
  }

  console.log(A.join('\n'));
};

Main(require('fs').readFileSync('/dev/stdin', 'utf8').trim());
/*Main(`4 1`);
Main(`7 3`)*/
