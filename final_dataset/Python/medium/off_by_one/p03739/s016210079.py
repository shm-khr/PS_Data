n = int(input())

a = list(map(int, input().split()))
s = [a[0]]

for i in range(1, n):
    s.append(s[-1]+a[i])


cnt_a = 0
base = 0
for i in range(n):
    if (base + s[i] > 0) != (i % 2 == 0):
        cnt_a += (1 + abs(base + s[i]))
        base += (1 + abs(base + s[i])) * (-1) ** i


cnt_b = 0
base = 0
for i in range(n):
    if (base + s[i] > 0) == (i % 2 == 0):
        cnt_b += (1 + abs(base + s[i]))
        base -= (1 + abs(base + s[i])) * (-1) ** i

print(min(cnt_a, cnt_b))