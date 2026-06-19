# AOJ 1179: Millennium
# Python3 2018.7.14 bal4u

for cno in range(int(input())):
	y, m, d = map(int, input().split())
	ans = 195*y
	if y > 1: ans += 5*((y-1)//3)
	if y % 3: ans += 19*(m-1) + m//2
	else: ans += (m-1)*20
	print(196666-ans-d)

