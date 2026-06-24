"use strict"
const create = () => {
    const input = require("fs").readFileSync("/dev/stdin", "utf8").trim().split("\n");
    const res = {
        "list": input, "index": 0, "max": input.length,
        "hasNext": function() {return this.index < this.max},
        "next": function() { if (!this.hasNext()) {throw "ArrayIndexOutOfBoundsException";}else{return this.list[this.index++];}}
    };
    return res;
}
const o = create();
const next = () => o.next()
const nextInt = () => parseInt(o.next())
const nextStrArray = () => o.next().split(" ")
const nextIntArray = () => o.next().split(" ").map(el => parseInt(el))
const nextCharArray = () => o.next().split("")
const hasNext = () => o.hasNext()
const myout = (...x) => console.log(...x)
const Main = () => {
    const N = nextInt()
    const S = next()
    let es = []
    let ws = []
    if(S[0] == "W"){
        es[0] = 0
        ws[0] = 1
    } else {
        es[0] = 1
        ws[0] = 0 
    }
    for(let i = 1; i<S.length;i++){
        if(S[i] == "W") ws[i] = ws[i-1] + 1
        else ws[i] = ws[i-1]

        if(S[i] == "E") es[i]=es[i-1] + 1
        else es[i] = es[i-1] 
    }
    // leader = 0
    let min = es[S.length-1] - es[0]
    for(let i = 1; i<S.length-1; i++){
        let tmp = es[S.length-1] - es[i] + ws[i-1]
        min = Math.min(min, tmp)
    }
    let last = ws[S.length-2]
    min = Math.min(min, last)
    console.log(min)

}
Main()
