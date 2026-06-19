function Main(input) {
  input = input.split("\n");
  let str = input[1].split(" ");
  let array = [];
  for (let i = 0; i < str.length; i++) {
    array.push(parseInt(str[i]))
  }
  let count = 0;
  for (let ite = 0; ite < array.length; ite++) {
    let isDivisible = false;
    for (let t = 0; t < array.length; t++) {
      if (t == ite) continue;
      if (array[ite] % array[t] == 0) {
        isDivisible = true;
        break;
      }
    }
    if (!isDivisible) {
      count++;
    }
  }
  console.log(count);
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));