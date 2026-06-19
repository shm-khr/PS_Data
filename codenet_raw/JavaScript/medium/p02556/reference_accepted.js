const main = (input) => {
  let lines = input.split(/\n/);
  const N = lines.shift(); 
  const points = lines.slice(0,N).map(point => point.split(/\s/).map(v => +v));
  
  let min = Infinity;
  let max = -Infinity;
  let min_ = Infinity;
  let max_ = -Infinity;
  for (const point of points){
    min = Math.min(point[0] + point[1], min);
    max = Math.max(point[0] + point[1], max);
    min_ = Math.min(point[0] - point[1] , min_);
    max_ = Math.max(point[0] - point[1] , max_);
  }


  console.log(Math.max(max - min, max_ - min_));
  };
main(require('fs').readFileSync('/dev/stdin', 'utf8'))
