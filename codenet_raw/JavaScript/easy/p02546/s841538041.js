function Main(input) {
	var end = input.substr(-1, 1);
    if (end === "s"){
      console.log( input + "es");
    }else{
      console.log( input + "s");
    }
}
//*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));