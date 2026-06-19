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
l = dim.index(1)
stack = [l]
col = [-1]*N
col[l] = 0
visited = set([l])
while stack:
    vn = stack.pop()
    for vf in Edge[vn]:
        if vf in visited:
            continue
        visited.add(vf)
        col[vf] = 1 - col[vn]
        stack.append(vf)
if col.count(0) != col.count(1):
    Fi()
print('Second')