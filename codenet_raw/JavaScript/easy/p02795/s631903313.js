function main(input) {
    const args = input.split("\n");
    const h = parseInt(args[0], 10);
    const w = parseInt(args[1], 10);
    const n = parseInt(args[2], 10);
    let res = Math.min(Math.ceil(n/h), Math.ceil(n/w));
    console.log(res);
}
main(require("fs").readFileSync("/dev/stdin", "utf8"));