n = int(input())
a = list(map(int, input().split()))
ans1 = sum([a[i] for i in range(0, n, 2) if a[i] > 0])
ans2 = sum([a[i] for i in range(1, n, 2) if a[i] > 0])
if max(ans1, ans2) == 0:
	print(0)
	print(n)
	print(*list(range(n, 0, -1)), sep="\n")

elif ans1 >= ans2:
	print(ans1)
	op = []
	left = 0
	while a[left] <= 0:
		left += 2

	right = True
	in_seg = False
	for i in range(n-1, -1, -1):
		if right:
			if i%2 == 1 or a[i] <= 0:
				op.append(i+1)
			else:
				right = False
		elif i < left:
			op += [1] * (i+1)
			break
		else:
			if in_seg == False and i%2 == 1:
				in_seg = True
				seg_right = i
			elif i%2 == 0 and a[i] > 0:
				in_seg = False
				op += list(range((i+seg_right+3)//2, i+1, -1))

	print(len(op))
	print(*op, sep="\n")

else:
	print(ans2)
	op = []
	left = 1
	while a[left] <= 0:
		left += 2

	right = True
	in_seg = False
	for i in range(n-1, -1, -1):
		if right:
			if i%2 == 0 or a[i] <= 0:
				op.append(i+1)
			else:
				right = False
		elif i < left:
			op += [1] * (i+1)
			break
		else:
			if in_seg == False and i%2 == 0:
				in_seg = True
				seg_right = i
			elif i%2 == 1 and a[i] > 0:
				in_seg = False
				op += list(range((i+seg_right+3)//2, i+1, -1))

	print(len(op))
	print(*op, sep="\n")