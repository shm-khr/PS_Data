function main (input) {
  var inputs = input.split("\n");
  var th = inputs[0].split(" ");
  var h = inputs[1].split(" ").slice(0,th[0]-1);
  
  console.log(h.filter(elm => {return elm >= th[1]}).length);     
}

main(require("fs").readFileSync("/dev/stdin", "utf8"));