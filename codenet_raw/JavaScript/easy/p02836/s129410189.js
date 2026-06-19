function main(arg) {
    var n = arg.length;
    var igenkai = Math.floor(n/2);
    var kekka = 0;
    for(i=0;i<igenkai;i++){
    	if(arg.charAt(i)!=arg.charAt(n-i-1)){
    		kekka += 1;
    	}
    }
    console.log(String(kekka));
}
main(require('fs').readFileSync('/dev/stdin', 'utf8'));