# AOJ 1052: Old Bridges
# Python3 2018.7.7 bal4u

while True:
	n = int(input())
	if n == 0: break
	tbl = [list(map(int, input().split())) for i in range(n)]
	tbl.sort(key=lambda x:(x[1],x[0]))
	s, f = 0, True
	for v, w in tbl:
		s += v
		if s > w:
			f = False
			break
	print("Yes" if f else "No")

