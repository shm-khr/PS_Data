function Main(input){
    input = input.split("\n");
    tmp = input[0].split(" ");
    var total = tmp[0];
    var shukudai = 0;
    input[1].split(" ").forEach(element => {
        shukudai + parseInt(element);
    });
    var ans = total - shukudai;
    if(ans < 0){
        ans = -1;
    }
    console.log(ans);
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));