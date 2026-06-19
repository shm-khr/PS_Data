function Main(input) {
	input = input.split("\n");
	tmp = input[0].split(" ");
    var n=parseInt(tmp[0]);
    var q=parseInt(tmp[1]);
    var s=input[1];
    for(var i=2;i<q+2;i++){
        t=input[i].split(" ");
        l=t[0];
        r=t[1];
        console.log("%s",((s.slice(l-1,r)).match(/AC/g) || []).length);
    }
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));