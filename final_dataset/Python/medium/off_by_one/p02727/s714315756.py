from collections import deque

x, y, a, b, c = map(int, input().split())
P = list(map(int, input().split()))
Q = list(map(int, input().split()))
R = list(map(int, input().split()))

P = sorted(P, reverse=True)[:x]

Q = sorted(Q, reverse=True)[:y]

P.extend(Q)
T = deque(sorted(P, reverse=True))
R = deque(sorted(R, reverse=True))

ans = 0
for i in range(x+y):
    if T[0] >= R[0] or len(R) == 0:
        ans += T.popleft()
    else:
        ans += R.popleft()

print(ans)
