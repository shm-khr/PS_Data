import bisect

n, m = map(int, input().split())
a = map(int, input().split())
a = sorted(list(a))
for _ in range(m):
    max_num = a.pop()
    bisect.insort(a, max_num // 2)
print(sum(a))
