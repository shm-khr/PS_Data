n, m = list(map(int, input().split()))
a = list(map(int, input().split()))

for _ in range(m):
    maxindex = a.index(max(a))
    a[maxindex] = int(a[maxindex] / 2)

print(sum(a))