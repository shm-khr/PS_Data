function Main(input) {
	// 1行目がinput[0], 2行目がinput[1], …に入る
	input = input.split("\n");
 　  tmp0 = input[0].split(" ");
    var A= parseInt(tmp0[0],10);
    var B=  parseInt(tmp0[1],10);
    var M=  parseInt(tmp0[2],10);
  //２行目、３行目を配列としてうけとる
      aList = input[1].split(" ").map(Number);
      bList = input[2].split(" ").map(Number);
  //配列の最小値をたす
     mab=Math.min.apply(null, aList)+Math.min.apply(null, bList);
     console.log(mab);

    for(i=3;i<3+M;i++){
  
      tmp1 = input[i].split(" ");
      var x = parseInt(tmp1[0], 10);
      var y = parseInt(tmp1[1], 10);
      var c = parseInt(tmp1[2], 10);
      var tt=aList[x-1]+bList[y-1]-c;
      console.log(x,y,c,tt);
      if (mab>tt){mab=tt;}
        }
  console.log(mab);
    }
//*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));