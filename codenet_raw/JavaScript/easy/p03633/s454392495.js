function gcd(a,b){
    if(a<b){
        var tmp = a;
        a = b;
        b = tmp;
    }
    if(b==0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

function lcm(a,b){
    var g = gcd(a,b);
    return a/g*b;
}

function main(input){
    var num = input.split(/\r\n|\r|\n/);
    for (var i = 0; i<num.length; i++){
        num[i] = Number(num[i]);
    }
    if(num.length==2){
        console.log(num[1]);
    }else{
        var res = lcm(num[1], num[2]);
        for(var i=3; i<num.length; i++){
            res = lcm(res, num[i]);
        }
        console.log(res);
    }


}

main(require("fs").readFileSync("/dev/stdin", "utf8"));