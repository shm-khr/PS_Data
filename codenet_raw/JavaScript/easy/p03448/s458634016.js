// 500, 100, 50
function main(input) {
  const input_array = input.split("\n");
  const coins_count = input_array.slice(0,3);
  const desired_sum = parseInt(input_array.slice(-1), 10);

  const a = parseInt(coins_count[0], 10);
  const b = parseInt(coins_count[1], 10);
  const c = parseInt(coins_count[2], 10);
  
  var answer = 0;
  for(i=0; i<=a; ++i){
    for(j=0; j<=b; ++j){
      for(k=0; k<=c; ++k){
        if (500 * i + 100 * j + 50 * k == desired_sum){
          answer+=1;
        }
      }
    }
  }
  
  console.log(answer);
}
 
main(require('fs').readFileSync('/dev/stdin', 'utf8'));
