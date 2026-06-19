'''
包除原理
すべての条件を満たしている
2^{N-1}から「どれかの条件を満たしていない」を引けば良い
i番目の条件を満たしていない確率はかんたんに計算できる
Sに属していいないやつが全て条件を満たしていない確率については
Sに対応する辺が全て白となる確率を考えれば良い
'''
from collections import deque
N=int(input())
G=[[] for i in range(N)]
for i in range(N-1):
    a,b=map(int,input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)
M=int(input())
u=[0 for i in range(M)]
v=[0 for i in range(M)]
for i in range(M):
    u[i],v[i]=map(int,input().split())
    u[i]-=1;v[i]-=1
root=[set() for i in range(M)]
for i in range(M):
    q=deque([u[i]])
    parents=[-1 for i in range(N)]
    reached=[0 for i in range(N)]
    while(len(q)>0):
        r=q.popleft()
        reached[r]=1
        for p in G[r]:
            if reached[p]==1:
                continue
            parents[p]=r
            q.append(p)
    x=v[i]
    while(1):
        if parents[x]==-1:
            break
        s=min(x,parents[x])
        t=max(x,parents[x])
        root[i].add((s,t))
        x=parents[x]
#print(root)
ans=0
def cnt(x):
    ans=0
    for i in range(M):
        if x|(2**i)==x:
            ans+=1
    return ans
L=sorted(list(range(2**M)),key=lambda x:cnt(x))
S=[set() for i in range(2**M)]
for i in L:
    for j in range(M):
        if i&(2**j)==0:
            S[i|(2**j)]=S[i]|{k for k in root[j]}
    ans+=(-1)**(cnt(i))*2**(N-len(S[i])-1)
print(ans)

