var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var result=i=1;
for(i<=input;i++){
 result*=i;
}
console.log(result);