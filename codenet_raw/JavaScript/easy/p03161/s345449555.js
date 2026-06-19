function main(input){
  const lines = input.split('\n');
  const NK = lines.shift().split(' ').map(x => parseInt(x));
  const N = NK[0];
  const K = NK[1];  
  const H = lines.shift().split(' ').map(x => parseInt(x));

  const DP = Array(N).fill(Infinity);
  for(var i=0;i<=K && i<N;i++){
    DP[i]=Math.abs(H[0]-H[i]);
  }

//console.log(DP);
//console.log('==');

  for(var i=1;i<N;i++){
    var hops = [];
    for(var j=1;j<=K && i-j>=0;j++){
      hops.push( DP[i-j] + Math.abs(H[i-j] - H[i]) )
    }
    DP[i]=Math.min(...hops);

//console.log(hops);
//console.log(DP);
//console.log('---');

  }
//  console.log(DP);
  console.log(DP[N-1]);

}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));

