import sys
input = sys.stdin.readline
mod = 10**9+7

n = int(input())
S = [s=="W" for s in input().rstrip()]
B = []
l, r = 0, 0
ans = 1
for i in range(n):
  ans *= i+1
  ans %= mod
for s in S:
  if (l+r+s)%2:
    if l == r or r == n:
      print(0)
      exit()
    ans *= (l-r)
    ans %= mod
    r += 1
  else:
    if l == n:
      print(0)
      exit()
    l += 1
print(ans)