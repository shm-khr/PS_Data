main(require('fs').readFileSync('/dev/stdin', 'UTF-8'));
function main(N){
  var a = N.charAt(0);
  var b = N.charAt(1);
  var c = N.charAt(2);
  if(a==5&&b==7&&c==5){
    console.log("YES");
  }else{
    console.log("NO");
  }
}