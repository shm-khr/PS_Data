function Main(input) {

	input = input.split("\n");
	tmp = input[0].split(" ");

	var rd = tmp[0];
	var gr = tmp[1];
	var bl = tmp[2];
	var k = input[1];
  
  	var result = false;

	for (var i = 0; i <= k; i++){
    	if (gr > rd && bl > gr){
        	result = true;
        } else if (gr < rd) {
        	gr = gr * 2;
        } else if (bl < gr) {
        	bl = bl * 2;
        }
    }
  
  	if (result) console.log('Yes');
  	else console.log('No');
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));