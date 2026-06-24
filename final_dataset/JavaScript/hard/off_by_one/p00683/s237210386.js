function forwardChar(){
   arr.some(function(v,i){
      if(v=="^" && arr.length-1!=i){
         arr[i]=arr[i+1];
         arr[i+1]="^";
         return true;
      }
   });
}

function forwardWord(){
   arr.some(function(v,i){
      if(v=="^" && i!=arr.length-1){
         arr[i]=arr[i+1];
         arr[i+1]="^";
         i++;
         while(true){
            if(i==arr.length-1)return true;
            if(arr[i+1]==" ")return true;
            arr[i]=arr[i+1];
            arr[i+1]="^";
            i++;
         }
         return true;
      }
   });
}

function backwardChar(){
   arr.some(function(v,i){
      if(v=="^" && i!=0){
         arr[i]=arr[i-1];
         arr[i-1]="^";
      }
   });
   var str=arr.join("");
   arr=str.split("");
}

function backwardWord(){
   arr.some(function(v,i){
      if(v=="^" && i!=0){
         arr[i]=arr[i-1];
         arr[i-1]="^";
         i--;
         while(true){
            if(i-1<0)return true;
            if(arr[i-1]==" ")return true;
            arr[i]=arr[i-1];
            arr[i-1]="^";
            i--;
         }
         return true;
      }
   });
}

function insert(x){
   var str=arr.join("");
   str=str.replace(/\^/,x+"^");
   arr=str.split("");
}

function deleteChar(){
   arr.some(function(v,i){
      if(v=="^" && i!=arr.length-1){
         arr[i+1]="";
         return true;
      }
   });
   var str=arr.join("");
   arr=str.split("");
}

function deleteWord(){
   arr.some(function(v,i){
      if(v=="^" && i!=arr.length-1){
         i++;
         arr[i]="";
         while(true){
            i++;
            if(i>arr.length-1)return true;
            if(arr[i]==" ")return true;
            arr[i]="";
         }
         return true;
      }
   });
   var str=arr.join("");
   str=str.replace(/\^ +/,"^ ");
   arr=str.split("");
}

var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var ARR=input.trim().split("\n");
var L=ARR.shift()-0;
while(L--){
   var arr=("^"+ARR.shift()).split("");
   var C=ARR.shift()-0;
   while(C--){
      var ary=ARR.shift().split(" ");
      if(ary[0]=="forward" && ary[1]=="char")forwardChar();
      else if(ary[0]=="forward" && ary[1]=="word")forwardWord();
      else if(ary[0]=="backward" && ary[1]=="char")backwardChar();
      else if(ary[0]=="backward" && ary[1]=="word")backwardWord();
      else if(ary[0]=="insert")insert(ary[1].replace(/\"/g,""));
      else if(ary[0]=="delete" && ary[1]=="char")deleteChar();
      else if(ary[0]=="delete" && ary[1]=="word")deleteWord();
   }
   console.log(arr.join(""));
}