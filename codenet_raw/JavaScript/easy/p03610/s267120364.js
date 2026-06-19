function main(input) {
  input=input.trim();
  var s=input
  var ans=[]
  for(var i=0; i<Math.floor(s.length/2)+Math.floor(s.length%2); i++){
    ans.push(s.substr(i*2+1,1))
  }
  console.log(ans.join(""));
}
main(require('fs').readFileSync('/dev/stdin', 'utf8'));