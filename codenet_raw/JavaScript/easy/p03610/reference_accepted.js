function main(input) {
  const S = input.toString();
  
  let ary = S.split('').filter((v, i) => { 
    if (i % 2 === 0) {
    	return v;
  	}
  });
  
  let result;
  
  for(let i = 0; i < ary.length; i++) {
    if (!result) {
      result = ary[i];
    } else {
      result = result + ary[i];
    }
  }
  console.log(result);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));