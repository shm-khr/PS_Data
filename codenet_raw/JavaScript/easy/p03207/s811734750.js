function sub(foo) {
    var num = foo.split(' ');
    var max = Math.max.apply(null, num);
    var i = 0;
    for (var o = 1; o < num.length; o++) {
        i = i + 1;
        if (parseInt(max) == parseInt(num[o])) {
            break;
        }
    }
    var nnn = 0;
    for (var n = 1; n < num.length; n++) {
        nnn += parseInt(num[n]);
    }
    var x = parseInt(num[i]) / 2;
    var y = nnn - parseInt(num[i]);
    return x + y;
}

function Main(ab) {
    console.log(sub(ab));
}

Main(require("fs").readFileSync("/dev/stdin", "utf8"));