n, k = map(int,input().split())
if n < 3:
    print(0)
    exit()

table = [[0] * 5 for i in range(11)]
for i in range(11):
    for j in range(5):
        t = 9 * (j + 2 + 7 * (i + 1))
        table[i][j] = t % 11

c = [0]
for row in table:
    c.append(c[-1] + row.count(k))

d, m = divmod(n - 2, 11)
ans = c[m] + c[-1] * d
print(ans)
