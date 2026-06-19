A, B, C, K = [int(i) for i in input().split()]

import sys

if A >= K:
  print(K)
  sys.exit()

r1 = K - A
cnt = A

if B >= r1:
  print(cnt)
  sys.exit()

r2 = r1 - B
print(cnt - r2)
