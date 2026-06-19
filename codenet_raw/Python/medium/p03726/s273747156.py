from collections import deque
from sys import exit
def Fi():
    print('First')
    exit()

N = int(input())
dim = [0]*N
Edge = [[] for _ in range(N)]
for _ in range(N-1):
    a, b = map(int, input().split())
    dim[a-1] += 1
    dim[b-1] += 1
    Edge[a-1].append(b-1)
    Edge[b-1].append(a-1)
par = [None] + [0]*(N-1)
stack = [0]
visited = set([0])
while stack:
    vn = stack.pop()
    for vf in Edge[vn]:
        if vf in visited:
            continue
        visited.add(vf)
        par[vf] = vn
        stack.append(vf)

L = [i for i in range(1,N) if dim[i] == 1]
used = set(L)
stack = L[:]
while stack:
    vn = stack.pop()
    if not vn:
        Fi()
    pv = par[vn]
    if pv in used:
        Fi()
    used.add(pv)
    if not pv:
        continue
    ppv = par[pv]
    dim[pv] -= 1
    dim[ppv] -= 1
    if dim[ppv] == 1 or (not ppv and dim[ppv] == 0):
        stack.append(ppv)
print('Second')