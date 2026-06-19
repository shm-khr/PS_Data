function Main(input) {
    keyence = ["k", "e", "y", "e", "n", "c", "e"];
    answer = "NO";
    if(input[0] === keyence[0]){
        if(input[input.length-1] === "e"&&
        input[input.length-2] === "c"&&
        input[input.length-3] === "n"&&
        input[input.length-4] === "e"&&
        input[input.length-5] === "y"&&
        input[input.length-6] === "e")answer = "YES"
    }
    if(input[0] === keyence[0] && input[1] === keyence[1]){
        if(input[input.length-1] === "e"&&
        input[input.length-2] === "c"&&
        input[input.length-3] === "n"&&
        input[input.length-4] === "e"&&
        input[input.length-5] === "y")answer = "YES"
    }
    if(input[0] === keyence[0] && input[1] === keyence[1] && input[2] === keyence[2]){
        if(input[input.length-1] === "e"&&
        input[input.length-2] === "c"&&
        input[input.length-3] === "n"&&
        input[input.length-4] === "e")answer = "YES"
    }
    if(input[0] === keyence[0] && input[1] === keyence[1] && input[2] === keyence[2] && input[3] === keyence[3]){
        if(input[input.length-1] === "e"&&
        input[input.length-2] === "c"&&
        input[input.length-3] === "n")answer = "YES"
    }
    if(input[0] === keyence[0] && input[1] === keyence[1] && input[2] === keyence[2] && input[3] === keyence[3] && input[4] === keyence[4]){
        if(input[input.length-1] === "e"&&
        input[input.length-2] === "c") answer = "YES"
    }
    if(input[0] === keyence[0] && input[1] === keyence[1] && input[2] === keyence[2] && input[3] === keyence[3] && input[4] === keyence[4] && input[5] === keyence[5]){
        if(input[input.length-1] === "e")answer = "YES"
    }
    if(input[0] === keyence[0] && input[1] === keyence[1] && input[2] === keyence[2] && input[3] === keyence[3] && input[4] === keyence[4] &&input[5]===keyence[5] && input[6] === keyence[6]){
        answer = "YES"
    }
    if(input[input.length-1] === "e"){
        if(input[input.length-1] === "e"&&
        input[input.length-2] === "c"&&
        input[input.length-3] === "n"&&
        input[input.length-4] === "e"&&
        input[input.length-5] === "y"&&
        input[input.length-6] === "e"&&
        input[input.length-7] === "k")answer = "YES"
    }
    console.log(answer);
}

Main(require("fs").readFileSync("/dev/stdin", "utf8"));
