function Main(input){
    const arr = input.split('\n');
    const NQ = arr[0].split(' ').map(Number);
    const S = arr[1];
    const numArr = new Array(NQ[0]+1).fill(0);
    // 特定文字列の数をもったリストを作成する
    for(let i=0; i<NQ[0]; i++){
        const num = (S[i] == 'A' && S[i+1] == 'C') ? 1 : 0;
        numArr[i+1] = numArr[i] + num;
    }
    for(let i=0; i<NQ[1]; i++){
        const left = Number(arr[i+2].split(' ')[0]);
        const right  = Number(arr[i+2].split(' ')[1]);
        console.log(numArr[right-1] - numArr[left-1]);
    }
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));
