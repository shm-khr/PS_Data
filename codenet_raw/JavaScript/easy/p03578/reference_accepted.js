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
    let n = nextInt()
    let d = nextIntArray()
    let m = nextInt()
    let t = nextIntArray()
    let map = {}
    for(let i = 0; i< d.length; i++){
        if(!map[d[i]]) map[d[i]] = 1
        else map[d[i]]++
    }
    for(let i = 0; i<t.length; i++){
        if(!map[t[i]]){
            console.log("NO")
            return
        }
        map[t[i]]--
        if(map[t[i]] < 0){
            console.log("NO")
            return
        }
    }
    console.log("YES")

}
Main()

