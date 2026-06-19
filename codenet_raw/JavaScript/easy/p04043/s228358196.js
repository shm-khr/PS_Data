function main(input){
const texts = input.split(" ").join(""),
set = new Set(["755","575","557"]);
if(set.has(texts)){console.log("YES");}else{console.log("NO")}
}
main(require("fs").readFileSync('/dev/stdin','utf8'))