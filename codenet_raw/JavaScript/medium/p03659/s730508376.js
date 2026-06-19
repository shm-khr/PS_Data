    // inputに入力データ全体が入る
function Main(input) {
	input = input.split("\n");
 
	var line1 = input[0].split(" ");
	var num = Number(line1[0])
	var data = input[1].split(" ");
	for(var i = 0; i<num; i++){
	    data[i] = Number(data[i]);
	}
	
	var index = Math.floor(num/2);
	var left = 0;
	var right = num;
	
	var leftSum = 0;
	var rightSum = 0;
	var temp = ["",""]
	var diff = 10e20;
	for(var ite = 0; ite<30; ite++){
    	for(var i = 0; i<index; i++){
    	    leftSum += data[i]
    	    temp[0] += data[i] + ",";
    	}
//	    console.log(temp[0]);
	
	    for(var i = index; i<num; i++){
	     rightSum += data[i]
	     temp[1] += data[i] + ",";
	    }
//	    console.log(temp[1]);
	
//    	console.log(leftSum, "-", rightSum);
	
	    if(leftSum>rightSum){
	     right = index;
	     index = Math.ceil((left+right)/2);
	    } else {
	        left = index;
	     index = Math.ceil((left+right)/2);
	    }
	    
	    if(diff>Math.abs(leftSum-rightSum)){
	        diff = Math.abs(leftSum-rightSum);
	    }
	    
//	    console.log("index:"+index);
	    temp = temp = ["",""]
	    rightSum = 0;
	    leftSum = 0;
//	    console.log("--------------------------------")
	}	
    
    console.log(diff);
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));