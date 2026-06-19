// inputに入力データ全体が入る
function Main(input) {
    var map = {};
    var ans = 0;
    input.filter((v,i)=>i>0).forEach(v=>{
        if(!map[v]) ans++
        map[v]=true;
    });
    console.log(ans);
}

Main(require("fs").readFileSync("/dev/stdin", "utf8").split("\n"));