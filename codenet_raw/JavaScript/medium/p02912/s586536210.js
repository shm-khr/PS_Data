function heapPush(arr,value){
  arr.push(value);
  n = arr.length - 1;
  	while(n != 0){
  	  i = Math.trunc((n - 1) / 2);
   	  if(arr[n] > arr[i]){
   	    tmp = arr[n];
   	    arr[n] = arr[i];
   	    arr[i] = tmp;
   	  }
      n = i;
    }
}

function heapPop(arr){
  maxValue = Math.trunc(arr[0]/2);
  arr[0] = arr.pop();
  n = arr.length - 1;
  
  for(i = 0;(j =  2 * i + 1) < n;){
  	if((j != n) && arr[j] - arr[j + 1] < 0){
      j++;
    }
    
    if(arr[i] - arr[j] < 0){
      tmp = arr[j];
      arr[j] = arr[i];
      arr[i] = tmp;
    }
    i = j;
  }
  return maxValue;
}

function main(input){
  M = Number(input.split('\n')[0].split(' ')[1]);
  input = input.split('\n')[1].split(' ').map(parseFloat);
  
  arrResult = [];
  input.map(value =>{
    heapPush(arrResult,value);
  });
  
  for(k = 0;k < M;k++){
    maxNum = heapPop(arrResult);
    heapPush(arrResult,maxNum);
  }
  
  console.log(arrResult.reduce((acc,cur) => acc + cur));
}
main(require('fs').readFileSync('/dev/stdin','utf8'));