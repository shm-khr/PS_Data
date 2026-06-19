function main(input){
	var data=inpu.split("\n");
	var num = parseInt(data[0]);
	var array =data[1].split(" ");
	
	insertionSort(array,num);
}

function insertionSort(array,num){
	for(var i = 0;i < num;i++){
		var v=array[i];
		var j = i-1;
		while(j >= 0 && array[j] > v){
			array[j + 1] = array[j];
			j--;
		}
		array[j+1]=v;
	}
}

function showLog(array){
	for(var i =0;i < num;i++){
		console.log(array[i]);
		if(i != array.length - 1){
			console.log(" ");
		}
	}
}

main(require("fs").readFileSync("/dev/stdin","utf8"));