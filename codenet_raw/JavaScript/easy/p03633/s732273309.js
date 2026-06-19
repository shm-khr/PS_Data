const fs = require('fs');
function gcd(m, n) { return n === 0 ? m : gcd(n, m % n); }
function lcm(m, n) { return m * n / gcd(m, n); }
function readSyncByfs(tips) {
    let response;
    process.stdout.write(tips||'');
    process.stdin.pause();
    response = fs.readSync(process.stdin.fd, 1000, 0, 'utf8');
    process.stdin.end();
    return response[0].trim();
}

var count = readSyncByfs();
var temp = 1;
for(var i=0;i<count;i++){
	let j = readSyncByfs();
	temp = j / gcd(j,temp) * temp;
}
console.log(temp);
