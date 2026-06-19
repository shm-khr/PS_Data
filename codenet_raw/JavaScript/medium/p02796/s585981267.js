"use strict"
function main(arg) {
    arg = arg.trim().split("\n")
    arg.shift()
    var data = arg
    data = data.map(e => {
        var row = e.split(" ").map(Number)
        return [row[0]-row[1], row[1]+row[0]]
    }).sort((a, b) => {
        return a[0] - b[0]
    })
    var sum = 0
    var P = -900000000000;
    var N = data.length
    for (var i=0; i<data.length; i++) {
        if (P <= data[i][0]) {
            sum++
            P = data[i][1]
        }
    }
    console.log(sum)
}
main(require('fs').readFileSync('/dev/stdin', 'utf8'));