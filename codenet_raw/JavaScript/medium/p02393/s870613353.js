process.stdin.resume();
process.stdin.setEncoding('utf-8');
process.stdin.on('data', function (chunk) {
	var tmp,i,j;
	var e = chunk.split(' ');
	b = parseInt(e[0],10);
	c = parseInt(e[1],10);
	d = parseInt(e[2],10);
	a = [b,c,d];
	a.sort();
	console.log(a[0]+' '+a[1]+' '+a[2]+'\n');
});