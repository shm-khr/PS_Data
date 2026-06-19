function Main(input) {
  input=input.split("\n");
  if(input[input.length-1]===''){
    input.pop();
  }
  const N=input[0]-0;
  const array=input[1].split(' ').map(e=>{
    return e-0;
  });
  if(array.every(e=>{
    return e%2!==0||e%3===0||e%5===0;
  })){
    console.log('APPROVED');
  }else{
    console.log('DENIED');
  }

}


//*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));
  



  
