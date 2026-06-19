process.stdin.resume();
process.stdin.setEncoding('utf8');

var lines = []
var reader = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout
});

reader.on('line', (line) => {
  lines.push(line);
});

reader.on('close', () => {
 var abck = lines[0].split(' ');
 var a = Number(abck[0]);
 var b = Number(abck[1]);
 var c = Number(abck[2]);
 var k = Number(abck[3]);
 var ans = 0;

 for(i=0; i<k; i++){
   if(a !== 0){
     ans++;
     a--;
     continue;
   }
   if(b !== 0){
     b--;
     continue;
   }
   if(c !== 0){
     ans--;
     c--;
   }
 }

 console.log(ans);
});