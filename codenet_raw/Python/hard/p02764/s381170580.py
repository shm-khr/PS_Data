n,k  = map(int,input().split())
meets = []
for _ in range(n):
  x,y,c = map(int,input().split())
  meets.append((x,y,c))

from itertools import combinations
import math
cands = list(combinations(range(n),k))

ans = float('inf')

for cand in cands:
  xs = 0
  ys = 0
  cs = 0
  for c in cand:
    xs += meets[c][0] * meets[c][2]
    ys += meets[c][1] * meets[c][2]
    cs += meets[c][2]
  xi = xs/k/cs
  yi = ys/k/cs
  latest = 0
  for c in cand:
    x,y,c = meets[c]
    time = math.sqrt((x-xi)**2 + (y-yi)**2) *c
    latest = max(latest,time)
  ans = min(ans,latest)
print(ans)
