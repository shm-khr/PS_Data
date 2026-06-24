n, m = [int(x) for x in input().split()]

ar = [0] * n
lis = list()

for i in range(m):
    a, b = [int(x) for x in input().split()]
    ar[a-1] += 1
    ar[b-1] += 1
    lis.append((a, b))

val = True
for x in ar:
    if (x % 2):
        val = False
        break

if (not val):
    print("-1")
else:
    for x in lis:
        print(x[0], x[1])