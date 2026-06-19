# バケット法を用いる
def kagamiMochi():
	N = int(input())
	d = []
	for _ in range(0, N):
		d.append(int(input()))

	num = [0] * 100
	for i in range(0, N):
		num[d[i]] += 1

	count = 0
	for j in num:
		if j:
			count += 1
	print(count)

kagamiMochi()