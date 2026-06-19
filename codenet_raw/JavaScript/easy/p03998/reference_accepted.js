function Main(input) {
  input=input.split("\n");
　var cards={};
  var next;
  cards['a']=input[0];
  cards['b']=input[1];
  cards['c']=input[2];
  var turn='a';
  while(true){
    if(cards[turn].length===0){
      console.log(turn.toUpperCase());
      return;
    }
    next=cards[turn][0];
    cards[turn]=cards[turn].slice(1);
    turn=next;
    //console.log(cards);
  }
}

//*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));
  
  
