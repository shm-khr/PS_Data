"use strict";
const Main = (input) =>{
   let xs = input.trim().split('');
   let len = Math.floor(xs.length/2);
   let len1 = xs.length;
   
   let ans ='';
   for(let i=0; i<len; i++){
      ans += xs[i];
   } 
   
   let ans1 =[];
   for(let i=len1-1; i>len; i--){
      ans1 +=xs[i];
   }
  
   if(ans==ans1){
     console.log('Yes');
   }else{
     console.log('No');
   }
}
Main(require('fs').readFileSync('/dev/stdin','utf8'));