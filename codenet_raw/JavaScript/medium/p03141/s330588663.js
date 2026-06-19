function main(input) {
  const args = input.split('\n');
  const N = parseInt(args[0], 10);
  const A = []
  const B = []
  for(var i=1;i <= N;i++){
    A[i-1] = parseInt(args[i].split(' ')[0], 10)
    B[i-1] = parseInt(args[i].split(' ')[1], 10)
  }
  var output = 0
  
  for(var j = 0;j<N;j++){
   if(j%2==0){
     var ch = add(A,B)
     output += A[ch]
     A[ch] = 0
     B[ch] = 0
   }else{
     var ch = add(B,A)
     output -= B[ch]
     A[ch] = 0
     B[ch] = 0
   }
  }
  console.log(output)
}

function add (a,b){
  var chA = 0
  for(var k = 1;k<=a.length;k++){
    if(a[chA] == a[k]){
      if(b[chA] <= b[k]) chA = k
    }else if(a[chA] < a[k]){
      chA = k
    }
  }
  return chA
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));