#(x,y)...xt+yが書かれる
from collections import deque
N,M=map(int,input().split())
G=[{} for i in range(N)]
for i in range(M):
    u,v,s=map(int,input().split())
    u-=1;v-=1
    G[u][v]=s;G[v][u]=s
H=[(0,0) for i in range(N)]
t=None
q=deque([0])
H[0]=(1,0)
while(q):
    r=q.pop()
    for p in G[r]:
        s=G[r][p]
        tmp=(-H[r][0],s-H[r][1])
        if H[p]==(0,0):
            H[p]=tmp
            q.append(p)
        elif H[p]==tmp:
            pass
        else:
            if H[p][0]==tmp[0]:
                print(0)
                exit()
            else:
                a=H[p][1]
                b=tmp[1]
                if H[p][0]==-1:
                    a,b=b,a
                #t+a=-t+b
                #2t=b-a
                if (b-a)%2:
                    print(0)
                    exit()
                else:
                    t=(b-a)//2
'''
t+a>=0:t>=-a
-t+b>=0:t<=b
inf=max(a)
sup=min(b)
'''
if t==None:
    inf=0
    sup=10**18
    for i in range(N):
        if H[i][0]==1:
            inf=max(inf,-H[i][1])
        else:
            sup=min(sup,H[i][1])
    print(max(sup-inf-1,0))
else:
    ans=[None for i in range(N)]
    q=deque([0])
    ans[0]=t
    while(q):
        r=q.pop()
        for p in G[r]:
            if ans[p]==None:
                ans[p]=G[r][p]-ans[r]
                q.append(p)
    flag=1
    for i in range(N):
        for j in G[i]:
            if ans[i]+ans[j]!=G[i][j]:
                flag=0
                break
        if flag==0:
            break
    if flag and min(ans)>0:
        print(1)
    else:
        print(0)
