X, Y, A, B, C = map(int, input().split())
*P, = map(int, input().split())
*Q, = map(int, input().split())
*R, = map(int, input().split())
P, Q = sorted(P, reverse=True), sorted(Q, reverse=True)
P, Q = P[:A], Q[:B]
ans = sum(sorted(P + Q + R, reverse=True)[:A + B])
print(ans)