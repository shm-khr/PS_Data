n, k = map(int, input().split())
if k > 1:
  print (-1)
else:
  for i in range(n):
	print (k+i, k+n+i, k+2*n+i)