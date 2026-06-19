function main(mojiretu) {
    var kosuu = 0;
    var nagasa = mojiretu.length;
	for(i=0;i<Math.floor(mojiretu.length/2);i++){
		if(mojiretu.substr(i,1)!==mojiretu.substr(nagasa-i-1,1)){
			kosuu += 1;
		}
	}
	console.log(kosuu);
}
main(require('fs').readFileSync('/dev/stdin', 'utf8'));