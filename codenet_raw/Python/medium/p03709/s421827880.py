import sys

input=sys.stdin.readline

mod=10*9+7

N=int(input())
taka=[tuple(map(int,input().split())) for i in range(N)]
taka.sort()

V=[0]+[taka[i][1] for i in range(N)]+[10**15]
cummin=[V[i] for i in range(N+2)]
for i in range(N,-1,-1):
    cummin[i]=min(cummin[i],cummin[i+1])
cummax=[V[i] for i in range(N+2)]
for i in range(1,N+2):
    cummax[i]=max(cummax[i],cummax[i-1])

newV=[]
for i in range(1,N+1):
    if not (V[i]>cummax[i-1] and cummin[i+1]>V[i]):
        newV.append(V[i])

V=newV
N=len(V)
all=pow(2,N,mod)
highid,lowid=-1,-1
Vmax=cummax[-2]
Vmin=cummin[1]
for i in range(0,N):
    if V[i]==Vmax:
        highid=i+1
    elif V[i]==Vmin:
        lowid=i+1

if high!=-1 and low!=-1:
    high=pow(2,highid-1,mod)
    low=pow(2,N-lowid,mod)
    if highid>lowid:
        highlow=pow(2,N+1-highid-lowid,mod)
    else:
        highlow=1
    ans=all+highlow-high-low
    print(ans%mod)
elif high==-1 and low!=-1:
    low=pow(2,N-lowid,mod)
    ans=all-low
    print(ans%mod)
elif high!=-1 and low==-1:
    high=pow(2,highid-1,mod)
    ans=ans-high
    print(ans%mod)
else:
    print(all)