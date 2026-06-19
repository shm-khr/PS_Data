s=require("fs").readFileSync("/dev/stdin","utf8");
a = []
for (i = 0; i < s.split('\n')[0]; i++) {
	a.push(s.split('\n')[i + 1])
}
m = Math.max(...a)
a = a.map(n => m == n ? m / 2 : n)
b = 0;
a.forEach(n => b += n | 0);
console.log(b);