const fs = require('fs')
 
function Main(input) {

  var max = input.length -1
  var i = 0
  var cnt = 0


  while(i < max)
  {
    if(input[i] !== input[max]) cnt++;
    i++;
    max--;
  }

console.log(cnt)

}
 
Main(fs.readFileSync('/dev/stdin', 'utf8'))