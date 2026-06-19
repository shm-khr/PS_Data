function Main(input) {
    // 最後の文字を取得
    const last = input.split("\n")[0].slice(-1) ;
    const sufix = last === "s" ? "es" : "s";
	//出力
	console.log(`${input}${sufix}`);
}
//*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));