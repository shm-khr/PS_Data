var IsTest = false;
var Main = function(Input){
  var Result = '';
  if(Input === '25'){
    Result = 'Christmas';
  } else if(Input == '24'){
    Result = 'Christmas Eve';
  } else if(Input == '23'){
    Result = 'Christmas Eve Eve';
  } else if(Input == '22'){
    Result = 'Christmas Eve Eve Eve';
  }
  console.log(Result);
}

if(IsTest){
  Main(require("fs").readFileSync(__dirname+'/in.txt', "utf8"));  
} else {
  Main(require('fs').readFileSync('/dev/stdin', 'utf8'));
}
