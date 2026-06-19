import sys
# -*- coding: utf-8 -*-
# 整数の入力
n=int(input())
a=list(map(int, input().split()))
b=a[:]
c=a[:]
# 無変更チェック
if a[0]!=0:
  S=int(a[0])
  for i in range(1,n):
    if S<0 and S+a[i]<=0:
      break
    elif S>0 and S+a[i]>=0:
      break
    S+=a[i]
    if i==n-1:
      print(0)
      sys.exit()
# a[0]を1に変えた場合の計算
counter_2=abs(b[0]-1)
b[0]=1
S=b[0]
for i in range(1,n):
  if S<0 and S+b[i]<=0:
    counter_2+=-S-b[i]+1
    b[i]=-S+1
  elif S>0 and S+b[i]>=0:
    counter_2+=S+b[i]+1
    b[i]=-S-1
  S+=b[i]
# a[0]を-1に変えた場合の計算
counter_3=abs(c[0]+1)
c[0]=-1
S=c[0]
for i in range(1,n):
  if S<0 and S+c[i]<=0:
    counter_3+=-S-c[i]+1
    c[i]=-S+1
  elif S>0 and S+c[i]>=0:
    counter_3+=S+c[i]+1
    c[i]=-S-1
  S+=c[i]
print(min(counter_2,counter_3))