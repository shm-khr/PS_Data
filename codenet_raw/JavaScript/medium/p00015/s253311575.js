function bigAdd(A, B)
{
    var m, n, mn, i, j, carry, tmp;
    var buf, a1, a2;
    
    if(A.length > B.length){
        m = A.length;
        n = B.length;
        a1 = A.split("");
        a2 = B.split("");
    }
    else{
        m = B.length;
        n = A.length;
        a1 = B.split("");
        a2 = A.split("");
    }
    
    mn = m + 1;
    buf = new Array(mn);
    for(j=m-1,i=n-1,carry=0;i>=0;--i,--j){
        tmp = parseInt(a1[j]) + parseInt(a2[i]) + carry;
        buf[j+1] = tmp % 10;
        carry = parseInt(tmp / 10);
    }
    // Rest
    for(;j>=0;--j){
        tmp = parseInt(a1[j]) + carry;
        buf[j+1] = tmp % 10;
        carry = parseInt(tmp / 10);
    }
    buf[0] = carry;
    
    var merge = buf.join("");
    console.log(parseInt(merge));
}

process.stdin.resume();
process.stdin.setEncoding('utf8');
process.stdin.on('data', function(input){
    var line = input.trim().split("\n");
    var i = 0;
    var N = parseInt(line[i++].trim());
    {
        for(;N>0;--N){
            bigAdd(line[i], line[i+1]);
            i=i+2;
        }
    }
});