import sys
n = int(input())
a = [int(x) for x in input().split()]
list(set(a))#重複を削除
a.sort()#ソート
count = 0
if(n == 1):
  print(1)
  sys.exit()
for i in range(1,n):
  if(a.count(a[i]) >= 2):
    continue
  if(2 in a and a[i] % 2 == 0):
    continue
  flg = False
  for j in range(i):
    #他の要素で割り切れる場合リストから削除
    if(a[j] % a[i] == 0):
      flg = True
      a.pop(j)
      j -= 1
      break
  if(flg == False):
    count += 1

if(a[0] != a[1]):
  count += 1
print(count)


