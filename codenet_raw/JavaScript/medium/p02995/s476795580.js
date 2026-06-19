function Main(input) {
  var A = parseInt(input.split(" ")[0]) - 1;
  var B = parseInt(input.split(" ")[1]);
  var C = parseInt(input.split(" ")[2]);
  var D = parseInt(input.split(" ")[3]);
  
  var output = 0;
  
  var AC = parseInt(A / C);
  var AD = parseInt(A / D);
  var ACD = parseInt(A / (C * D));
  var Awarenai = A  - (AC + AD) + ACD;
  
  var BC = parseInt(B / C);
  var BD = parseInt(B / D);
  var BCD = parseInt(B / (C * D));
  var Bwarenai = B  - (BC + BD) + BCD;
  
  output = Bwarenai - Awarenai;
  console.log(output);
}

Main(require("fs").readFileSync("/dev/stdin", "utf8"));
