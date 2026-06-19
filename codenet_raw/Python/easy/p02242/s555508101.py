n = input()
inf = 1000000000
M = [[inf for i in range(n)] for i in range(n)]
for i in range(n):
  str = map(int, raw_input().split())
  u = str[0]
  k = str[1]
  for j in range(k):
#    v = str[2+j]
#    c = str[3+j]
    M[u][str[2+j]] = str[3+j]
d = [inf for i in range(n)]
color = [0 for i in range(n)]
 
d[0] = 0
color[0] = 1
 
while 1:
  minv = inf
  u = -1
  for i in range(n):
    if minv>d[i] and color[i]!=2:
      u = i
      minv = d[i]
    print minv
  if u == -1:
    break
  color[u] = 2
  for v in range(n):
    if color[v]!=2 and M[u][v]!=inf:
      if d[v]>d[u]+M[u][v]:
        d[v] = d[u] + M[u][v]
        color[v] = 1
for i in range(n):
  if d[i]==inf:
    print '%d -1' % i
  else:
    print '%d %d' % (i, d[i])