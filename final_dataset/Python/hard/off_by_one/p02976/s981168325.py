import sys
from collections import deque
def input():
	return sys.stdin.readline()[:-1]
sys.setrecursionlimit(10**6)

n, m = map(int, input().split())
adj = [[] for _ in range(n)]
eff = [0 for _ in range(n)]
edges = []
is_reversed = [0 for _ in range(m)]

for i in range(m):
	a, b = map(int, input().split())
	adj[a-1].append([b-1, i])
	adj[b-1].append([a-1, i])
	edges.append([a, b])
	eff[a-1] += 1

if m%2 == 1:
	print(-1)
	sys.exit()

visited = [False for _ in range(m)]
def bfs(start):
	prev = [(-1, -1) for _ in range(n)]
	prev[start] = (start, -1)
	q = deque([start])
	while q:
		l = q.pop()
		if l != start and eff[l]%2 == 1:
			eff[start] += 1
			eff[l] += 1
			break
		for v, i in adj[l]:
			if prev[v][0] < 0 and not visited[i]:
				prev[v] = (l, i)
				visited[i] = True
				q.appendleft(v)
	s, t = l, prev[l][1]
	while t >= 0:
		is_reversed[t] ^= 1
		s = prev[s][0]
		t = prev[s][1]

odd = [i for i in range(n) if eff[i]%2 == 1]
for o in odd:
	if eff[o]%2 == 1:
		bfs(o)

for i in range(m):
	if is_reversed[i]:
		print(*edges[i][::-1])
	else:
		print(*edges[i])