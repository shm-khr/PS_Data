const main = input =>{

    const arr = input.split("\n");
    const N = arr[0];
    const H = arr[1].split(" ").map(n => Number(n));

    var resultArray = [];
    for(var i=0; i < N; i++){
        var num = H[i];
        var count = 0;
        for(var j=i; j < N; j++){
            if(num >= H[j+1]){
                count ++;
                num = H[j+1];
            }
            else{
                console.log(j +"："+count);
                console.log();
                resultArray.push(count);
                break;
            }
        }
    }

    console.log(resultArray.reduce((a,b)=>a>b?a:b));
};
main(require('fs').readFileSync('/dev/stdin', 'utf8'));