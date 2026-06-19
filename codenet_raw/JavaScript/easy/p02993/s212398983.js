function main(input) {
 a = "Good";

 if (int S[0] == int S[1]){
  a = "bad";
 }

else if ( int S[1] == int S[2]){
 a = "bad"; 
}
else  if ( int S[2] == int S[3]){
 a = "bad";
}
else{
	a = "Good"
}
console.log(a);


}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));