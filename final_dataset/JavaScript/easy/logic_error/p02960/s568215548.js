const main = (N,A,B) =>  {
    count = 0
    for(var i = 0;i<N;i++) {
        diff = Math.abs(A[i],B[i])
        count+=diff
        A[i] -= diff
        B[i] -= diff
        diff = Math.min(A[i+1],B[i])
        count+=diff
        A[i+1] -= diff
        B[i] -= diff
    }

    return count 

}


const input = require('fs').readFileSync('/dev/stdin','utf8').split("\n")
const N = Number(input[0])
const A = input[1].split(" ").map( x => Number(x))
const B = input[2].split(" ").map(x => Number(x))
console.log(main(N,A,B))