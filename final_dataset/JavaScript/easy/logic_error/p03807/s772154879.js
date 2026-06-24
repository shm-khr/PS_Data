function Main(input) {
 var a=0;b=0;
 for(i=0;i<input[0];i++){
  if(input[i*2]%2)a++;
  else b++;
 }   
 if(b%2)console.log("YES");
 else console.log("NO");

}
 
Main(require("fs").readFileSync("/dev/stdin", "utf8"));