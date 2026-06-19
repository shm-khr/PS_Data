function Main(input){
  var In = input.split('\n');
  
  var count = 0;
  
  for(var i = 0; i < In[0]; i++){
    for (var j = 0; j < In[1]; j++){
      for (var k = 0; k < In[2]; k++){
        var total = (500 * i) + (100 * j) + (50 * k);
        
        if(total == In[3]){
          count = count + 1;
        }
      }
    }
  }
  
  console.log(count);
}

Main(require("fs").readFileSync("/dev/stdin", "utf8"));