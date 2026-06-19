function Main(input) {
    input = input.split("\n");
  
    var H = parseInt(input[0], 10);
    var W = parseInt(input[1], 10);
    var N = parseInt(input[2], 10);
	var max = H > W ? H : W
    var min = max === H ? W : H
    var i = 1
  	for(; i <= min; i++) {
    	if(i * max > N) {
          break
        }
    }
  
    console.log(i);
}

Main(require("fs").readFileSync("/dev/stdin", "utf8"));