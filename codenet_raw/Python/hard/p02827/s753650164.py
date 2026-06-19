n,m,t = map(int, input().split())
xy = [list(map(int, input().split())) for i in range(m)]
now = [0] + [1] * n
ans = ""
if n == 2:
  print(-1)
  exit()
for x,y in reversed(xy):
  if now[x] >= 2:
    ans = "v" + ans
    now[x] -= 1
    now[y] += 1
  else:
    ans = "^" + ans
    now[x] += 1
    now[y] -= 1
print(ans)