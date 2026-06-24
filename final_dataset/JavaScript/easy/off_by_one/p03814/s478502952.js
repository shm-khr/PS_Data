const main =(standardInput) =>{
  const s = standardInput;
  var start=0,end=0,i=0;
  while(s[i]){
    if(s[i]=='A' && start ==0){
    start=i;
    }else if(s[i]=='Z'){
    end=i;
    }
    i++;
  }
  var out;
  for(i= start;i<end;i++){
  out=s.slice(start,end+1);
  }
  console.log(out);
  
}
main(require('fs').readFileSync('/dev/stdin', 'UTF-8'));