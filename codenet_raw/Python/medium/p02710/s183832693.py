import sys
input = lambda : sys.stdin.readline().rstrip()
from collections import defaultdict
n = int(input())
sys.setrecursionlimit(max(1000, n))
# 小さすぎても怒られるので
 
cs = [0] + [int(c) for c in input().split()]
ns = defaultdict(set)
for _ in range(n-1):
    a,b = [int(c) for c in input().split()]
    ns[a].add(b)
    ns[b].add(a)
 
toru = [0] * (n+1)
def dfs(ns, prev, now, toru):
    end = defaultdict(int)
    k = cs[now]
    end[k] = 1
    s = 1 # nowで終わるパスの種類
    for u in ns[now]:
        if u==prev:
            continue
        tmp_end, tmp_toru, tmp_s = dfs(ns, now, u, toru)
        # toruの更新
        for kk, vv in tmp_end.items():
            if kk not in end:
                toru[kk] += vv * s
            else:
                toru[kk] += vv * s + end[kk] * (tmp_s+1) - ((vv+1) * end[kk])
        for kk, vv in end.items():
            if kk not in tmp_end:
                toru[kk] += vv * tmp_s
        # end, sの更新
        end[k] += tmp_s
        for kk,vv in tmp_end.items():
            if k!=kk:
                end[kk] += tmp_end[kk]
        s += tmp_s
    toru[k] += 1
#     print(now, prev, end, toru, s)
    return end, toru, s
end, toru, s = dfs(ns, prev=-1, now=1, toru=toru)
 
for item in toru[1:]:
    print(item)
    sys.stdout.write(str(item) + "\n")
