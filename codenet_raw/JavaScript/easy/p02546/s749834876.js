const main = (arg) => {
 
    console.log(arg[arg.length-1]==="s" ? arg + "es" : arg + "s")
    
}
main(require("fs").readFileSync("/dev/stdin", "utf8"));
