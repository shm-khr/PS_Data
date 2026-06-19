// inputに入力データ全体が入る
function Main(input) {
  
   input = input.split("\n");
  var n= parseInt(input[0], 10);
 
   var tmp = input[1].split(" ");
     var a = [];
for (var i = 0; i <n ; i++){
  var r= parseInt(tmp[i], 10);
 
  a[i] = r;}
  
 console.log(a);
 var ct = 0;
 var b = [];
 for (var i = 0;i <n ;i ++){for (var I = i;I <n;I++)
                              { if( a[I] >= a[I+1]){ct = ct + 1;}
                                               var p =ct;
                                               b[I]=p;
                                               var ct = 0;}
                               }
                               console.log(b);
 
 

 

}
 
  
  //*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));
  