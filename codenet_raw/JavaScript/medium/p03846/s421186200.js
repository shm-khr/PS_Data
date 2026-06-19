function Main(input){

    input = input.split('\n')
    var n = parseInt(input[0])
    var As = input[1].split(' ')

    var pairs = {}
    for(var i=0; i<n; i++){
        var val = As[i]
        pairs[val] = pairs[val] === undefined
            ? 1
            : pairs[val]+1
    }

    for(var i=n-1; i>0; i-=2){
        if(pairs[i] !== 2){
            console.log(0)
            return
        }
    }
    console.log(Math.pow(2, Math.floor(n/2)))
}

//var input = require("fs").readFileSync("hoge.txt", "utf8")
var input = require('fs').readFileSync('/dev/stdin', 'utf8')
Main(input)
