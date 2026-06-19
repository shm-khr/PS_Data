function Main(input) {
  input=input.split("\n");
  const N=input[0].split(' ')[0]-0;
  const M=input[0].split(' ')[1]-0;
  var price=input[1].split(' ').map(e=>{
    return e-0;
  });
  var numberOfDigits=new Array(N);
  var memo=new Array(N);
  price.forEach((e,i)=>{
    numberOfDigits[i]=Math.floor(Math.log2(price[i]));
    if(memo[Math.floor(Math.log2(price[i]))]===undefined){
      memo[Math.floor(Math.log2(price[i]))]=1;
    }else{
      memo[Math.floor(Math.log2(price[i]))]++;
    }
  });
  for(var i=0;i<memo.length;i++){
    if(memo[i]===undefined){
      memo[i]=0;
    }
  }
  var numberOfCounted=0;
  var sum=0;
  var threshold=0;
  for(var i=memo.length-1;i>=0;i--){
    numberOfCounted+=memo[i];
    sum+=numberOfCounted;
    //console.log(sum);
    if(sum>M){
      threshold=i;
      break;
    }
  }
  var remain=M;
  for(var i=0;i<price.length;i++){
    if(numberOfDigits[i]>threshold){
      price[i]=Math.floor(price[i]/2**(numberOfDigits[i]-threshold));
      remain-=numberOfDigits[i]-threshold;
    }
  }
  //console.log(threshold,remain,numberOfDigits);
  price.sort((a,b)=>{
    return -a+b;
  });
  //console.log(price);
  var ret=0;
  for(var i=0;i<price.length;i++){
    if(i<remain){
      ret+=Math.floor(price[i]/2);
    }else{
      ret+=price[i];
    }
  }
  console.log(ret);
  
}


//*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));
  
  
