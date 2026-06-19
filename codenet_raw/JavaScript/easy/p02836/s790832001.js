function main(input) {
    var reverse = input.split("").reverse().join("")
    var size = input.split("").length
    var count = 0
    for (var i=0; i< size/2-1; i++) {
      var a = input.split("")[i]
      var b = reverse.split("")[i]
      if (a !== b) {
        count = count + 1
      }
    }
    console.log(count)
}
main(require('fs').readFileSync('/dev/stdin', 'utf8'));
