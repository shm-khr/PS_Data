K = int(input())
if K % 2 == 0:
	print(int((K ** 2) / 4))
else:
	print((K + 1) * (K - 1) / 4)