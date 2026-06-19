from itertools import groupby
import heapq

N=int(input())
S=input()
mod=10**9+7

fact=[i for i in range(2*N+1)]
fact[0]=1
for i in range(1,2*N+1):
    fact[i]*=fact[i-1]
    fact[i]%=mod

inverse=[pow(fact[i],mod-2,mod) for i in range(2*N+1)]

data=["" for i in range(2*N)]
for i in range(2*N):
    if S[i]=="B" and i%2==1:
        data[i]="L"
    elif S[i]=="B" and i%2==0:
        data[i]="R"
    elif S[i]=="W" and i%2==1:
        data[i]="R"
    elif S[i]=="W" and i%2==0:
        data[i]="L"


if data[0]=="L" or data[-1]=="R":
    print(0)
    exit()

ans=fact[N]
data=groupby(data)
que=[]
heapq.heapify(que)
i=0
for key,group in data:
    g=len(list(group))
    heapq.heappush(que,(i,g))
    i+=1

rest=0
while que:
    i,R=heapq.heappop(que)
    j,L=heapq.heappop(que)
    if L>R+rest:
        print(0)
        break
    else:
        ans*=fact[R+rest]*inverse[R+rest-L]
        ans%=mod
        rest=R+rest-L
else:
    print(ans)
