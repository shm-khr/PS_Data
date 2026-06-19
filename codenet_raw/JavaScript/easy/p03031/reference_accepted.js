//↓見なくていいよ！ここから--------------------------------------------------
var read = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout
});
var obj;
var inLine = [];
read.on('line', function(input){inLine.push(input);});
read.on('close', function(){
  obj = init(inLine);
  console.error("\n");
  var start = Date.now();
  Main();
  var end = Date.now() - start;
  myerr("time : " + (end) + "ms");
  myerr("memory : " + Math.round(process.memoryUsage().heapTotal / 1024) + "KB");
});
function makeClone(obj){return JSON.parse(JSON.stringify(obj));}
function nextInt(){return myconv(next(),1);} function nextStrArray(){return myconv(next(),2);}
function nextIntArray(){return myconv(next(),4);} function nextCharArray(){return myconv(next(),6);}
function next(){return obj.next();} function hasNext(){return obj.hasNext();}
function init(input){  
  var returnObj = {
    list : input, index : 0, max : input.length,
    hasNext : function(){return (this.index < this.max);},
    next : function(){if(!this.hasNext()){throw "ArrayIndexOutOfBoundsException これ以上ないよ";}else{var returnInput = this.list[this.index];this.index++;return returnInput;}}
  };
  return returnObj;
}
function myout(s){console.log(s);}
function myerr(s){console.error("debug:" + require("util").inspect(s,false,null));}
//[no]要素の扱い。数値型
//不明値、異常時:引数そのまま返す 1:数値へ変換
//2:半角SPで分割 4:半角SPで分割し、数値配列へ
//6:1文字で分割  7:1文字で分割し、数値配列へ
//8:半角SPで結合 9:改行で結合 0:文字なしで結合
function myconv(i,no){try{switch(no){case 1:return parseInt(i);case 2:return i.split(" ");case 4:return i.split(" ").map(Number);case 6:return i.split("");case 7:return i.split("").map(Number);case 8:return i.join(" ");case 9:return i.join("\n");case 0:return i.join("");default:return i;}}catch(e){return i;}}

//↑見なくていいよ！ここまで--------------------------------------------------
function Main(){
	var one = nextIntArray();
	var N = one[0];
	var M = one[1];
	
	var connect = new Array(M);
	for(var i = 0; i < M; i++){
		var tmp = nextIntArray();
		var connectCount = tmp[0];
		tmp.shift();
		connect[i] = {
			no : i,
			count : connectCount,
			list : tmp
		};
	}
	var onlist = nextIntArray();
	var output = 0;
	for(var i = 0; i < (1 << N); i++){
		var select = [];
		for(var j = 0; j < N; j++){
			if((i & (1 << j)) != 0){
				//選ぶ(j番目のスイッチをON)
				select.push(j);
			}
		}
		var onCount = 0;//すべての電球がON
			for(var k = 0; k < M; k++){
				var switchCount = 0;
				for(var l = 0; l < connect[k].count; l++){
					if(select.indexOf(connect[k].list[l] - 1) != -1){
						switchCount++;//つながってるスイッチがON
					}
				}
				if(switchCount % 2 == onlist[k]){
					onCount++;//電球を1個ON
				}
			}
		if(onCount == M){
			output++;
		}
	}
	myout(output);
}
