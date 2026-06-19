function Main(input) {
    var input = input.split('\n').map((n) => {
        return parseInt(n);
    }) ;
    var a = input[0];
    var b = input[1];
    var c = input[2];
    var x = input[3];
    var count = null;
      for (i = 0; i <= a; i++){
        for (j = 0; j <= b; j++){
            for (k = 0; k <= c; k++){
               var t = 500 * i + 100 * j + 50 * k;
               t === x ? count++ : null; 
               }    
            }
        }

        console.log(count);
    }
    
    
Main(require('fs').readFileSync('/dev/stdin', 'utf8'));