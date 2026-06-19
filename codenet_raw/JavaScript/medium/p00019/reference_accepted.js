var input = require('fs').readFileSync('/dev/stdin', 'utf8');
input=input-0;
var num=1;
for(var i=input;i>=1;i--)num*=i;
console.log(num);