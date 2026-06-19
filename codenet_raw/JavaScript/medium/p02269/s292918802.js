var input = require('fs').readFileSync('/dev/stdin', 'utf8'); 
var xs = input.trim().split('\n').slice(1).map(function(x){ return x.split(' '); 
var ys = {};
    xs.forEach(function(x){
        if(x[0] === 'insert'){
            ys[x[1]] = true;
        }else if(x[0] === 'find'){
            console.log(ys.hasOwnProperty(x[1]) ? 'yes' : 'no');
        }
    });
