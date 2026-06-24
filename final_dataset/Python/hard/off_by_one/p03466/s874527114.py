Q = int(input())
ans = []
for i in range(Q):
	a,b,c,d = map(int,input().split(" "))
	if a >= b:
		if (a % (b+1)) == 0:
			n = a // (b+1)
		else:
			n = (a // (b+1)) + 1

		times = a // n
		a_remain = a - times * n
		b_remain = b - times
		ans_str = ""
		for i in range(times):
			ans_str += (('A') * n)
			ans_str += 'B'

		ans_str += (('A') * (a_remain))
		ans_str += (('B') * (b_remain))

	else:
		if (b % (a+1)) == 0:
			n = b // (a+1)
		else:
			n = (b // (a+1)) + 1

		times = b // n
		b_remain = b - times * n
		a_remain = a - times
		if a_remain < 0:
			times -= 1
			b_remain += n

		ans_str = ""
		for i in range(times):
			ans_str += (('B') * n)
			ans_str += "A"

		ans_str += (('B') * (b_remain))
		ans_str += (('A') * (a_remain))
		ans_str = ans_str[::-1]

	ans.append(ans_str[c-1:d])

for i in ans:
	print(i)

