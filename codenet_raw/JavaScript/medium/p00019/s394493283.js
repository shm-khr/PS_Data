var input = require('fs').readFileSync('/dev/stdin', 'utf8');
function fact(input) {
   if(input==0) {
      return 1;
   }
   return input * fact(input-1);
}