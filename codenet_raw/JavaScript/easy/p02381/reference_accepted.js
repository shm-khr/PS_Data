var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var Arr=(input.trim()).split("\n");
for(var i=0;i<Arr.length;i=i+2){
   if(Arr[i]=="0")break;
   var val=Arr[i+1];
   var arr=val.split(" ").map(Number);
   var sum=arr.reduce(function(a,b){return a+b;});
   var ave=sum/arr.length;
   var a=0;
   arr.forEach(function(v){
      a+=Math.pow(v-ave,2);
   });
   console.log(Math.sqrt(a/arr.length).toFixed(4));
}