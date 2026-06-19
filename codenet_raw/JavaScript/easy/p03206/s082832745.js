function main(input) {
    var args = input;
	
	switch (parseInt(args)) {
		case 25:
			console.log("Chritsmas");
			break;
			
		case 24:
			console.log("Christmas Eve");
			break;
			
		case 23:
			console.log("Chritsmas Eve Eve");
			break;
			
		case 22:
			console.log("Christmas Eve Eve Eve");
			break;
		
	}
	
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));