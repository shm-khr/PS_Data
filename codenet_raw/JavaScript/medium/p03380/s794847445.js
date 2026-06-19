function main(input) {
    var lines = input.split('\n');
    var line1 = lines[0];
    var line2 = lines[1].split(' ');

    var N = parseInt(line1);

    var aList = line2.map(function (str) { return parseInt(str) });

    var max = aList.reduce(function(prev, curr){
        return Math.max(prev, curr);
    }, aList[0]);

    var halfMax = max / 2;
    var mostCloseToHalf = aList.reduce(function(prev, curr){
        return Math.abs(prev - halfMax) <= Math.abs(curr - halfMax) ? prev : curr;
    }, aList[0]);

    console.log(max + ' ' + mostCloseToHalf);
}
main(require('fs').readFileSync('/dev/stdin', 'utf8'));


