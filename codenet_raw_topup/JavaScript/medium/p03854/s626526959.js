function Main(input){
  var S = input[0].toString();
  
  var revS = S.split('').reverse().join('');
  var divide = ['dream', 'dreamer', 'erase', 'eraser'].map(s => {
    return s.split('').reverse().join('');
  });
  
  var stringN = 0;
  
  while(stringN < revS.length){
    var word = divide.find(w => {
      return revS.startsWith(w, stringN);
    });
    
    if(word　!== false){
      console.log('NO');
    } else {
      stringN += word.length;
    }
  }
  
  console.log('YES');
}

Main(require("fs").readFileSync("/dev/stdin", "utf8"));