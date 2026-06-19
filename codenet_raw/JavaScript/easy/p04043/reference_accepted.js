
let _inputLines;
let _lineNumber = 0;
let inputReader = _inputReader ();

function _main() {
	
	_inputLines = _inputData.trim().split('\n').map((string) => {
		return string.trim();
	});;
	
	let [a, b, c] = inputReader.readArray();
	//console.log(typeof c);
	a = parseInt(a);
	b = parseInt(b);
	c = parseInt(c);
	
	let obj={};
	obj[a]=obj[a] +1 ||1; 
	obj[b]=obj[b] +1 ||1; 
	obj[c]=obj[c] +1 ||1;
	if(obj[5]===2 && obj[7]===1)
		console.log('YES');
	else
		console.log("NO");
	
	
	
	// let input = inputReader.readLine().split(' ');
	// let a = input[0];
	// let b = input[1];
	// //let b = inputReader.readLine().split('');
	// //console.log(a,b);
	
	// let res = '';
	// for(let i=0;i<size;i++){
	//     res +=a[i];
	//     res+=b[i];
	// }
	// console.log(res);
	
	//console.log(noOfTestCases,typeof noOfTestCases);
	// while(noOfTestCases--){
	//     let [a,b] = inputReader.readNumberArray();
	//     let count = 1;
	//     if(a<=2){
	//         console.log(1);
	//         continue;
	//     }
	//     let floor;
	//     if((a-2)%b===0)
	//         floor = (a-2)/b +1;
	//     else
	//          floor = Math.ceil((a-2)/b)+1;
	//     console.log(floor);
	
	// }

}

var _inputData = '';
function cacheInput(data) {
	_inputData += data;
}

process.stdin.resume();
process.stdin.setEncoding('utf8');
process.stdin.on('data', cacheInput).on('end', _main);

function _inputReader () {
	function readArray() {
		return _inputLines[_lineNumber++].split(' ');
	}
		
	function readLine(){
		return _inputLines[_lineNumber++];
	}
		
	function readNumberArray(){
		return _inputLines[_lineNumber++].split(' ').map(val => Number(val));
	}
		
	
	return {
		readArray,
		readLine,
		readNumberArray,
	}
}