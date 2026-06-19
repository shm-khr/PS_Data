n, k = map(int, input().split())
if n>1: print(-1); quit()
for i in range(k): print(i+1, 2*k-i, 2*k+i+1)