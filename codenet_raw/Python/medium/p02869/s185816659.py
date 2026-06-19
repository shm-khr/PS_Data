n, k = map(int, input().split())
s = 0
for i in range(k, k + 2 * n):
    s -= i
for i in range(k + 2 * n, k + 3 * n):
    s += i
if s >= 0:
    a = [0] * n
    b = list(range(k + n, k + 2 * n))
    c = [0] * n
    for i in range(n // 2):
        c[i * 2 + 1] = k + 2 * n + i
    for i in range(n - n // 2):
        c[i * 2] = k + 2 * n + n // 2 + i
    for i in range(n // 2):
        a[i * 2 + 1] = k + i
    for i in range(n - n // 2):
        a[i * 2] = k + n // 2 + i
    a.reverse()
    for i in range(n):
        print(a[i], b[i], c[i])
else:
    print(-1)
