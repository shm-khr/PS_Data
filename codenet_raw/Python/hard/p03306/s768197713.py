from collections import defaultdict, Counter, deque
def inpl(): return list(map(int, input().split()))

N, M = inpl()
D = defaultdict(list)
for _ in range(M):
    u, v, s = inpl()
    D[u].append((v, s))
    D[v].append((u, s))

L = [1] * (N+1)
U = [10**9] * (N+1)
searched = [0] * (N+1)
Q = deque([1])

while Q:
    p = Q.pop()
    for q, s in D[p]:
        updated = False
        if L[q] < s - U[p]:
            L[q] = s - U[p]
            updated = True
        if U[q] > s - L[p]:
            U[q] = s - L[p]
            updated = True
        if not searched[q]:
            searched[q] = True
            Q.append(q)

print(max(min([u-l+1 for u, l in zip(U, L)]), 0))