var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var arr=input.trim().split("\n");
var n=arr.shift()-0;
var a=arr.shift().split(" ").map(Number);
var b=a.slice().sort((a,b)=> a-b).join("");
var q=arr.shift()-0;
var xy=arr.map(v=> v.split(" ").map(Number).map(v=>v-1));
xy.unshift([0,0]);
var flag=false;
for(var i=0;i<=q;i++){
   [a[xy[i][0]],a[xy[i][1]] ]= [a[xy[i][1]],a[xy[i][0]]];
   if(a.join("")==b){
      flag=true;
      break;
   }
}
if(flag)console.log(i);
else console.log(-1);
