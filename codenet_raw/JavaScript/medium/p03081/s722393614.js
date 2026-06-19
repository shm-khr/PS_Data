var lines = [];
var readline = require('readline');

var rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.on('line', function(input) {
    lines.push(input);
});

rl.on('close', function() {
    var N = lines[0].split(' ')[0];
    var Q = lines[0].split(' ')[1];
    console.log('test here1');

    var cubesAsArr = lines[1].split('');
    var spellsAsArrays = lines.splice(2);

    console.log('test here', cubesAsArr);
    // convert cubesAsStr into map 
    var cubesAsMap = {};
    var counter = 0;
    cubesAsArr.forEach(function(cubeAsChar){
        cubesAsMap[cubeAsChar] = {
            count: 1,
            index: counter
        };
        counter++;
    });



    spellsAsArrays.forEach(function(spellAsStr) {
        var spellAsArr = spellAsStr.split(' ');
        var targetChar = spellAsArr[0];
        var targetDirection = spellAsArr[1];
        var targetCube = cubesAsMap[targetChar];
        targetCube.count--;
        if (targetDirection === 'L'){
            if (targetCube.index > 0){
                var neighborCubeIndex = targetCube.index - 1;
                var neighborCube = cubesAsMap[cubesAsArr[neighborCubeIndex]];
                neighborCube.count++;
            }
        } else {
            if (targetCube.index < N-1){
                var neighborCubeIndex = targetCube.index + 1;
                var neighborCube = cubesAsMap[cubesAsArr[neighborCubeIndex]];
                neighborCube.count++;
            }        
        }
    });

    var sum = 0;
    cubesAsArr.forEach(function(cubeAsChar){
        sum += cubesAsMap[cubeAsChar].count;
    })

    console.log(sum);
});
