while True:
  must1 = 1
  for mi in range(m):
    onoff = 0
    for ni in range(n):
      onoff += li[mi][ni]*yyy[ni]
    should1 = bool(onoff%2 == p[mi])
    must1 *= should1
  if must1 == 1:
    score += 1
  yyy[0] += 1
  for ni in range(n-1):
    if yyy[ni] == 2:
      yyy[ni] = 0
      yyy[ni+1] += 1
  if yyy[n-1] == 2:
    break
print(score)