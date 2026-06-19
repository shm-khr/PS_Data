from itertools import product
n, k = map(int, input().split())
dots = [list(map(int, input().split())) for _ in range(n)]

ans = float("inf")
for a, b, c, d in product(dots, repeat=4):
	upper = max(a[1], b[1], c[1], d[1])
	lower = min(a[1], b[1], c[1], d[1])
	left = min(a[0], b[0], c[0], d[0])
	right = max(a[0], b[0], c[0], d[0])

	area = (upper - lower) * (right - left)
	num = 0
	for dot in dots:
		if left <= dot[0] <= right and lower <= dot[1] <= upper:
			num += 1
	if num >= k and area < ans:
		ans = area

print(ans)