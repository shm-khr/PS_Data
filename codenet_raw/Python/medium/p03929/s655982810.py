n, k = map(int, input().split())
d = [11, 16, 10, 25, 9, 24, 19, 13, 18, 12, 17]
print(len([x for x in range(d[k], 7 * (n - 1), 11) if x % 7 > 1]))
