const gcd = (a,b)=>{
    if(a%b===0){
        return (b)
    }
    else {
        return (gcd(b,a%b))
    }
}

const lcm =(a,b)=>{
    return a/gcd(a,b)*b
}

function main(input) {
	const arr=input.split('\n')
	let ans=1;
	arr.forEach((el,index)=>{
      if(index==1){continue}
      else ans= lcm(ans,el)
    })
console.log(ans)
    
}
main(require('fs').readFileSync('/dev/stdin', 'utf8'));