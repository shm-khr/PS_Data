function Main(input){
	var temp = input.trim().split("\n");
  	var K = parseInt(temp[0].split(" ")[0],10);
  	var N = parseInt(temp[0].split(" ")[1],10);
  	var maxd = 0;
  	var d = [];
    for(var i = 0 ;i<N;i++){
    	A = parseInt(temp[1].split(" ")[i],10);
      	if(i+1 == N){
          	maxd = Math.max(maxd,((K-A) + parseInt(temp[1].split(" ")[0],10)));
        }else{
          	maxd = Math.max(maxd,parseInt(temp[1].split(" ")[i+1],10) - A)
        }
    }
 	console.log(K-maxd)
}
Main(require("fs").readFileSync("/dev/stdin","utf8"));