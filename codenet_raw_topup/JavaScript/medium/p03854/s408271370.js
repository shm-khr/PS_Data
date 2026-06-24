function Main(input){
  var word = input.split('').reverse();
  word.shift();
  var words = ["dream","dreamer","erase","eraser"];
  var rwords = [];
  for(var i of words){
    rwords.push(i.split('').reverse());
  }
  while((word!='')&&(NG!=4)){
    var NG = 0;
    r: for(var i of rwords){
      for(var j=0;j<i.length;j++){
        if(word[j]!=i[j]){
          NG++;
          break;
        }
        if(j==i.length-1){
          word.splice(0,i.length);
          break r;
        }
      }
    }

  }
  if(word==''){
    console.log('YES');
  }else{
    console.log('NO');
  }
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));