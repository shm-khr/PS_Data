N = int(input())
ans = 0
for i in range(N):
    a, b = map(int, input().split())
    if a < b:
        ans += b
print(ans)