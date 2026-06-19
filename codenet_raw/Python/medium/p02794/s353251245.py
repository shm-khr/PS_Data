N=int(input())
edge={i:[] for i in range(1,N+1)}
for i in range(0,N-1):
    a,b=map(int,input().split())
    edge[a].append((b,i))
    edge[b].append((a,i))

parent={i:-1 for i in range(1,N+1)}
depth={i:-1 for i in range(1,N+1)}
parent[1]=(0,-1)
depth[1]=0
q=set([1])
sub=set([])
while q:
    while q:
        x=q.pop()
        for b,i in edge[x]:
            if parent[b]==-1:
                parent[b]=(x,i)
                depth[b]=depth[x]+1
                sub.add(b)

        if not q:
            q=sub
            sub=set([])
            break

M=int(input())
condition=[[] for i in range(0,M)]
for i in range(0,M):
    u,v=map(int,input().split())
    ans=set([])
    while depth[u]!=depth[v]:
        if depth[u]>depth[v]:
            U,j=parent[u]
            ans.add(j)
            u=U
        else:
            V,j=parent[v]
            ans.add(j)
            v=V

    while u!=v:
        U,j=parent[u]
        ans.add(j)
        u=U
        V,j=parent[v]
        ans.add(j)
        v=V
    condition[i]=ans

ans=2**(N-1)
ban=0
for i in range(1,2**M):
    num=bin(i).count('1')
    s=set([])
    for j in range(0,M):
        if i>>j &1==1:
            for k in condition[j]:
                s.add(k)

    n=len(s)
    if num%2==1:
        ban+=2**(N-1-n)
    else:
        ban-=2**(N-1-n)

print(ans-ban)