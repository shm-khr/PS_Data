'use strict';
(function(stdin) {

    var inputs = stdin.toString().trim().split(' ');

   inputs.sort(function(a,b){
        if( a < b ) return -1;
        if( a > b ) return 1;
        return 0;
});
   console.log(inputs);

}(require('fs').readFileSync('/dev/stdin', 'utf8')));