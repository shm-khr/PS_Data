function main(input){
    tmp=input.split("\n");
    tmp2=tmp[0].split(" ");
    k=parseInt(tmp2[0]);
    n=parseInt(tmp2[1]);
    a=tmp[1].split(" ");
    a2=a.map(str => parseInt(str, 10));
    var d= new Array(n);
    t=0;
    for(i=0;i<n;i++){
        if(i==0){
            d[i]=k-a2[n-1]+a2[0];
            t+=k-a2[n-1]+a2[0];
        }else{
            d[i]=a2[i]-a2[i-1];
            t+=a2[i]-a2[i-1];
        }
    }
    max=Math.max.apply(null,d);
    console.log("%d",t-max);

}
main(require("fs").readFileSync("/dev/stdin", "utf8"));
