l,n = map(int, input().split())
x = []
for i in range(n):
  x.append(int(input()))
y = 0
c = 0
for i in range(n):
  if x[0] >= y >= 0:
    if x[0] - y >= l - x[-1] + y:
      c += x[0] - y
      y = x[0]
      x.pop(0)
    else:
      c += l - x[-1] + y
      y = x[-1]
      x.pop(-1)
  else:
    if l - y + x[0] >= y - x[-1]:
      c += l - y + x[0]
      y = x[0]
      x.pop(0)
    else:
      c += y - x[-1]
      y = x[-1]
      x.pop(-1)
print(c)