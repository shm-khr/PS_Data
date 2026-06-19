function Main(input) {
    input = parseInt(input);
    n = input.toString(10).replace(/\D/g, '0').split('').map(Number);
  
    total = 0;

    
    for (let i = 0; i < n.length; i++) {
        num = n[i];
        total += num;        
    }

    if (total % 9 == 0 && input % 9 == 0) {

        console.log("Yes");
        
    } else{
        console.log("No");
    }

}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));