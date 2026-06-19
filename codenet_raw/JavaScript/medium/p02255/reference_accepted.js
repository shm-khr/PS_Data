var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var Arr=input.split("\n");
var A=Arr[1].split(" ").map(Number);
var N=Arr[0]-0;
/*
1 insertionSort(A, N) // N個の要素を含む0-オリジンの配列A
2   for i が 1 から N-1 まで
3     v = A[i]
4     j = i - 1
5     while j >= 0 かつ A[j] > v
6       A[j+1] = A[j]
7       j--
8     A[j+1] = v
*/
console.log(A.join(" "));
for(var i=1;i<=N-1;i++){
   var v=A[i];
   var j=i-1;
   while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
      A[j+1]=v;
}
console.log(A.join(" "));
}