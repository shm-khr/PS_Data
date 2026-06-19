function Main(input) {

	// 1行目がinput[0], 2行目がinput[1], …に入る
	input = input.split("\n");
    input.shift();
    
    let xy = input.map(val => val.split(" ").map(Number))
    let arr = xy.map(val => [val[0]-val[1],val[0]+val[1]])

    arr = arr.reduce((pre,current) => {pre.push(...current);return pre},[]);
    arr = arr.sort();
 
    console.log(arr[arr.length-1]-arr[0])
}

Main(require("fs").readFileSync("/dev/stdin", "utf8"));