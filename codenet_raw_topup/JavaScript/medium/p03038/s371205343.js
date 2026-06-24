function Main(input) {
    input = input.trim().split("\n");
    tmp = input[0].split(" ");
    var N = parseInt(tmp[0],10);
    var M = parseInt(tmp[1],10);
    var A = [];
    for(var i = 0; i < N; i++){
        A[i] = parseInt(input[1].split(" ")[i],10);
    }
    A.sort(function(a,b){
        if( a < b ) return -1;
        if( a > b ) return 1;
        return 0;
    });

    for(var j = 2; j <= M+1; j++){
        var B = parseInt(input[j].split(" ")[0],10);
        var C = parseInt(input[j].split(" ")[1],10);
        var k = 0;

        for(var i = 0; i < N; i++){
            if(A[i] < C){
                A[i] = C;
                k++;
            }
            else{
                A.sort(function(a,b){
                    if( a < b ) return -1;
                    if( a > b ) return 1;
                    return 0;
                });
                break;
            }
        
            if(k == B || i == N - 1){
                A.sort(function(a,b){
                    if( a < b ) return -1;
                    if( a > b ) return 1;
                    return 0;
                });
                break;
            }
        }
    }

    var output = 0;
    for(var i = 0; i < N; i++){
        output += A[i];
    }
    console.log(output);
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));