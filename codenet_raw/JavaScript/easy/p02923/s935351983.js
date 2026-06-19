function Main(arg) {
 
    var N = arg.split("\n")[0]-0;
    var H = arg.split("\n")[1].split(" ");

    var ans = new Array();
    var a = 0;
    for (var i = 0; i < N; i++){
        a = 0;
        for (var j = i; j < N-1; j++){
            var s = H[j] - 0;
            var t = H[j+1] - 0;
            if (s < t) break;
            a++;
        }
        ans.push(a);
    }

    console.log(Math.max.apply(null, ans));
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));