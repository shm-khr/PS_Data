var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var Arr=(input.trim()).split("\n");
var N=Arr.shift()-0;
for(var i=0;i<N;i++){
   var ymd=Arr[i].split(" ").map(Number);
   var y=ymd[0];
   var m=ymd[1];
   var d=ymd[2];
   var day=0;
   for(var j=1;j<y;j++){
      day+=(j%3==0)?200:195;
   }
   if(y%3==0){
      day+=20*(m-1);
   }else{
      for(var j=1;j<m;j++)day+=(j%2==0)?19:20;
   }
   day+=d;
   console.log(196471-day);
}