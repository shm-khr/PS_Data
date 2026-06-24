function Main(input) {
    var N = parseInt(input[0], 10);
    var M = parseInt(input[1], 10);
    var A = input.slice(2).map(n => parseInt(n));

    var sortedA = A.sort((a, b) => b - a);
    var top = 0;

    for (var i = 0; i < M; i++) {
        top = Math.floor(sortedA[0] / 2);
        sortedA.shift();

        sortedA.splice(sortedA.findIndex(a => top >= a), 0, top);
    }

    var sum = 0;
    for (var i = 0; i < N; i++) {
        sum += sortedA[i];
    }
    console.log(sum);
}

Main(require("fs").readFileSync("/dev/stdin", "utf8").trim().split(/\n|\s/));