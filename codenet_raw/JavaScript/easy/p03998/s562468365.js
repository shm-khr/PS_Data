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
    let s = {}
    s["a"] = next()
    s['b'] = next()
    s['c'] = next()
    let p = {
        "a" : -1,
        "b" : 0, 
        "c" : 0
    }
    let turn = "a"
    while(true){
        p[turn]++
        if(p[turn] > s[turn].length){
            console.log(turn.toUpperCase())
            return
        }
        turn = s[turn][p[turn]]
    }

}
Main()
