N = int(input())
A = list(map(int, input().split()))
ans = 0
for i in range(N):
  flg = True
  for j in range(N):
    if i != j and A[i] % A[j] == 0:
      flg = False
      break
  if flg:
    ans += 1
print(ans)