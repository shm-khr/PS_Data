N, M = map(int, input().split())
s = [list(map(int, input().spllit())) for i in range(M)]
p = list(map(int, input().split()))
total = 0
flag = 1
for i in range(2 ** N):
  now = format(i, "0{}b".format(n))
  for k in range(M):
    tmp = 0
    for l in range(s[k][0]):
      if now[s[k][l+1]-1] == '1':
        tmp += 1
    if tmp % 2 == p[k]:
      continue
    else:
      flag = 0
      break
  if flag == 1:
    total += 1
  flag = 1
print(total)
