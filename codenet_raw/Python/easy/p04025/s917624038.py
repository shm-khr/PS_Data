def cost(n, a, m):

  hihumi = 0  #hihumi => 滝本ひふみ

  for i in range(n):
    hihumi += (a[i] - m) ** 2

  return hihumi

N = int(raw_input())
a = map(int, raw_input().split())

ans = 100

for i in range(min(a), max(a) + 1):
  if (ans > cost(N, a, i)):
    ans = const(N, a, i)

print ans