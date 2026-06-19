N, M = map(int,input().split())

ans = 0
if N * 2 <= M//2:
    ans += N
    nokori_c = M - N * 2
    ans += nokori_c // 4
    print(ans)
else:
    ans += M//2
    print(ans)