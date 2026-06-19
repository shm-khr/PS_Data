const main = input =>{

    const arr = input.split("\n");
    const num = arr[0];
    const high = arr[1].split(" ");
    var result = 0;
    var max = 0;
    var result = 0;
    for(var i=0; i < num; i++){
        max = 0;
        if(high[i] > high[i+1]){
            for(var j=i; j < num; j++){
                if(high[j] >= high[j+1]){
                    max ++;
                }
            }
        }
        if(result < max){
            result = max;
        }
    }

    console.log(result);
};
main(require('fs').readFileSync('/dev/stdin', 'utf8'));
