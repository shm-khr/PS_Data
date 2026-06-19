N,K=map(int,input().split())
A=list(map(int,input().split()))
for i in range(1,N):
  A[i]+=A[i-1]
A=[(A[i]-i-1)%K for i in range(N)]
A=[0]+A
from collections import Counter
if K>N:
  a=Counter(A)
  ans=0
  for v in a.values():
    ans+=v*(v-1)/2
  print(int(ans))
else:
  ans=0
  d={}
  for i in range(K):
    if A[i] in d:
      ans+=d[A[i]]
      d[A[i]]+=1
    else:
      d[A[i]]=1
  for i in range(K,N+1):
    d[A[i-K]]-=1
    if A[i] in d:
      ans+=d[A[i]]
      d[A[i]]+=1
    if A[i] not in d or d[A[i]]==0:
      d[A[i]]=1
  print(ans) 
