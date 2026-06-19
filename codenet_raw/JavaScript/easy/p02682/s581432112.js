function Main(input){
    const arr = input.split(' ').map(Number);
    const num = arr[3]-arr[0];
    if(num>=0){
        let K =  num - arr[1];
        console.log(K>0 ? arr[0]-K:arr[0])
    } else {
        console.log(arr[0]+arr[3]);
    }
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));
