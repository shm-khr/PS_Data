process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    main();    
});

function readline() {
    return inputString[currentLine++];
}

function ti(a){
    for(let i = 0; i < a.length; i++)
        a[i] = parseInt(a[i]);

    return a;
}

function main(){
    let [n,k] = ti(readline().split(' '));
    let h = ti(readline().split(' '));

    let dp = new Array(n);
    dp.fill(999999999999999);
    dp[0] = 0;
    for(let i = 0; i < n; i++){
        for(let j = 1; j < k+1; j++){
            if(i-j >= 0)
                dp[i] = Math.min(dp[i], Math.abs(h[i]-h[i-j]) + dp[i-j]);
            else
                break;
        }
    }

    console.log(dp[n-1]);
}