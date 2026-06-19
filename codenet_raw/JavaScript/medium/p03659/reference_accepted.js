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
    const n = nextInt()
    const a = nextIntArray()
    let y = 0
    for(let i = 0; i<a.length; i++){
        y += a[i]
    }
    let x = 0
    let min = Number.POSITIVE_INFINITY
    for(let i = 0;i<a.length-1; i++){
        x += a[i]
        y -= a[i]
        min = Math.min(min, Math.abs(x-y))
    }
    console.log(min)
}
Main()
