function myin(){return require("fs").readFileSync("/dev/stdin", "utf8").trim();}
function myout(text){console.log(text);}//standard output
//[no]param
//0:noConvert	1:singleNum	2:spaceList	3:newLineList	4:spaceNumList	5:newLineNumList
function myconv(i,no){switch(no){case 0:return i;case 1:return parseInt(i);case 2:return i.split(" ");case 3:return i.split("\n");case 4:return i.split(" ").map((a)=>Number(a));case 5:return i.split("\n").map((a)=>Number(a));}}

function Main(input) {
  input = myconv(input,0);
  var output = "Yes";
  if((input.indexOf("N") != -1 && input.indexOf("S") == -1) || 
     (input.indexOf("N") == -1 && input.indexOf("S") != -1) || 
    (input.indexOf("E") != -1 && input.indexOf("W") != -1) || 
    (input.indexOf("E") == -1 && input.indexOf("W") != -1)){
     output = "No";
  }
  myout(output);
}

Main(myin());
