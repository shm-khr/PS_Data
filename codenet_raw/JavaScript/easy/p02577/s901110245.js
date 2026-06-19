function Main(input) {
    n = input.split("");
    total = 0;

    for (let i = 0; i < n.length; i++) {
        num = parseInt(n[i], 10);
        total += num;        
    }

    if (total % 9 === 0) {
        console.log("Yes");
    } else if(total % 9 != 0){
        console.log("No");
    }

}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));