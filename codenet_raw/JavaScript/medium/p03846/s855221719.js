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

    // if n is odd, there should be one 0
    // if n is even, there should be no 0s
    if((n%2 === 1 && pairs[0] !== 1)
      || n%2 === 0 && pairs[0] !== undefined){
        console.log(0)
        return
    }

    var ans = Math.pow(2, Math.floor(n/2))
    ans = ans % (Math.pow(10, 9) + 7)
    console.log(ans)
}

// var input = require("fs").readFileSync("hoge.txt", "utf8")
var input = require('fs').readFileSync('/dev/stdin', 'utf8')
Main(input)
