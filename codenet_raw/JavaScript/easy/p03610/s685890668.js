function main(input){
    var tmp = input.split(" ");
    var s = String(tmp[0]);
    console.log(s.slice(1:1));
  
   
}

main(require("fs").readFileSync("/dev/stdin","utf8"));