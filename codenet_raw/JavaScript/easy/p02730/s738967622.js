function Main(input) {
    var tmp = input.split(" ");
    var N = parseInt(tmp[0],10);
    var M =parseInt(tmp[1],10);

    //強い回文
    //文字列自体が回文であり、その前半部と後半部もそれぞれ回文となり文字列

    //-input
    //奇数であり英字小文字で与えられる

    //-output
    //強い回文であれば"Yes",そうであれば"No"

    function judgePlindrome(plind){
        leng = plind.length;

        console.log("mozi;"+plind);
        console.log(plind.slice(0,Math.floor(leng/2))+"+"+plind.slice(leng-Math.floor(leng/2),leng).split("").reverse().join(""));

        if(plind.slice(0,Math.floor(leng/2)) == plind.slice(leng-Math.floor(leng/2),leng).split("").reverse().join("")){return 1;}else{return 0;};
    }

    function hardPlndrome(plind){

        if(judgePlindrome(plind)==1 && judgePlindrome(plind.slice(0,Math.floor(plind.length/2)))==1 && judgePlindrome(plind.slice(plind.length-Math.floor(plind.length/2)))==1 ){return 1;}else{return 0}
    }

    if(hardPlndrome(input)==1){console.log("Yes");}else{console.log("No");}
}
//*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));

