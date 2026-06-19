function Main(input) {
    input = input.split("\n");
  	var pre=input[0].split(" ");
  	var distance=parseInt(pre[0],10);
  	var count=parseInt(pre[1],10);
  	var minute=input[1].split(" ");
  	var array=[];
    for(var i=0;i<count-1;i++){
      var num=parseInt(minute[i+1],10)-parseInt(minute[i],10);
      array.push(num);
    }
  	var last=distance+parseInt(minute[0],10)-parseInt(minute[count-1],10);
  	array.push(last);
  	/*array.sort(
  		function(x,y){
    	return (x < y ? -1 : 1);
  		}
	);*/
  	var total=0;
  	for(var j=0:j<count-1;j++){
      total+=array[j];
    }
  	console.log(total);
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));