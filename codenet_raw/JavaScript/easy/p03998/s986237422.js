function Main(input) {
    input = input.split("\n");
    var line = input[0].split(" ");
    var aa = input[0];
    var bb = input[1];
    var cc = input[2];
    var count = [0,0,0];
    var limit = [aa.length,bb.length,cc.length];
    var current = aa[0];
    var last = "";
    var counta = 0
    while(1){
        if(current!=="a" && current!=="b" && current!=="c"){
            console.log(last);
            break;
        }
        if(current==="a"){
            count[0]++;
            current = aa[count[0]];
            last="A";
//            if(count[0]>=limit[0]){
//                console.log("a");
//                break;
//            }
        } else if (current==="b"){
            count[1]++;
            current = bb[count[1]];
            last="B";
//            if(count[1]>=limit[1]){
//                console.log("b");
//                break;
//            }
        } else if (current==="c"){
            count[2]++;
            current = cc[count[2]];
            last="C";
//            if(count[2]>=limit[2]){
//                console.log("c");
//               break;
//            }
        }
    }

}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));