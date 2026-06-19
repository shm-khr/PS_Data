N,K=map(int,input().split())
G=[[] for i in range(N)]
a=[0 for i in range(N-1)]
b=[0 for i in range(N-1)]
for i in range(N-1):
    a[i],b[i]=map(int,input().split())
    a[i]-=1;b[i]-=1
    G[a[i]].append(b[i])
    G[b[i]].append(a[i])
P=[-1 for i in range(N)]
rnk=[-1 for i in range(N)]
q=[0]
rnk[0]=0
while(len(q)>0):
    r=q[-1];q.pop()
    for p in G[r]:
        if rnk[p]!=-1:
            continue
        rnk[p]=rnk[r]+1
        P[p]=r
        q.append(p)
S=[[] for i in range(N)]
for i in range(N):
    S[i].append(P[i])
while(True):
    tmp=[0 for i in range(N)]
    flag=0
    for i in range(N):
        if S[i][-1]==-1:
            tmp[i]=-1
        else:
            flag=1
            tmp[i]=S[S[i][-1]][-1]
    if flag==0:
        break
    for i in range(N):
        S[i].append(tmp[i])
#pのk個上（存在しない場合は-1）
def bef(p,k):
    if rnk[p]<k:
        return -1
    else:
        m=str(bin(k))[2:][::-1]
        n=len(m)
        res=p
        for i in range(n):
            if m[i]=="1":
                res=S[res][i]
        return res
M=len(S[0])
def dist(x,y):
    if rnk[x]>rnk[y]:
        return (rnk[x]-rnk[y])+dist(bef(x,rnk[x]-rnk[y]),y)
    elif rnk[x]<rnk[y]:
        return (rnk[y]-rnk[x])+dist(x,bef(y,rnk[y]-rnk[x]))
    else:
        if x==y:
            return 0
        res=0
        tmpx=x
        tmpy=y
        while(True):
            j=0
            if tmpx==tmpy:
                return res
            for i in range(M-1):
                if S[tmpx][i]!=S[tmpy][i] and S[tmpx][i+1]==S[tmpy][i+1]:
                    j=i
                    break
            res+=2**(j+1)
            tmpx=S[tmpx][i]
            tmpy=S[tmpy][i]
'''
X=max(rnk)
leaf=[]
for i in range(N):
    if rnk[i]==X:
        leaf.append(i)
'''
d=[[dist(i,j) for i in range(N)] for j in range(N)]
#dia=max([max([d[i][j] for i in range(N)]) for j in range(N)])
if K%2==0:
    t=[[d[i][j] for i in range(N)] for j in range(N)]
    D=K//2
    ans=[0 for i in range(N)]
    for i in range(N):
        for j in range(N):
            if t[i][j]>D:
                ans[i]+=1
    print(min(ans))
else:
    t=[[min([d[a[i]][j],d[b[i]][j]]) for j in range(N)] for i in range(N-1)]
    ans=[0 for i in range(N-1)]
    D=(K-1)//2
    for i in range(N-1):
        for j in range(N):
            if t[i][j]>D:
                ans[i]+=1
    print(min(ans))
