import sys
input = sys.stdin.readline
lines = sys.stdin.readlines()

#N = int(input())
#VW = [[0,0]] + [list(map(int,input().split())) for i in range(N)]
#Q = int(input())
#vL = [list(map(int,input().split())) for i in range(Q)]
#vs,Ls = zip(*vL)

N = int(lines[0])
Q = int(lines[N+1])
vL = [list(map(int,s.split())) for s in lines[N+2:]]
vs,Ls = zip(*vL)
VW = {}

appear = []
for v in vs:
    v *= 2
    while v:
        v //= 2
        appear.append(v)

appear = list(set(appear))
M = len(appear)+1
dic = {v:i for i,v in enumerate(appear)}

for v in appear:
    VW[v] = list(map(int, lines[v].split()))

def dpinit(ps, val=0):
    res = [val for i in [0]*ps[-1]]
    for i in ps[:-1][::-1]:
        res = [res[:] for k in [0]*i]
    return res

maxL = max(Ls)
dp = dpinit((M+1,maxL+2),0)
ans = []

visited = [False] * (M+1)
visited[0] = True
for v,L in vL:
    orgv = v
    seq = []
    v *= 2
    while v:
        v //= 2
        seq.append(v)
        rv = dic[v]
        if visited[rv]:
            break
        visited[rv] = True
    seq = seq[::-1]
    for s,ns in zip(seq,seq[1:]):
        V,W = VW[ns]
        s = dic[s]
        ns = dic[ns]
        for i in range(W):
            dp[ns][i] = dp[s][i]
        for i in range(W,maxL+2):
            dp[ns][i] = max(dp[s][i], dp[s][i-W] + V)
    ans.append(dp[dic[orgv]][L])

for a in ans:
    print(a)







