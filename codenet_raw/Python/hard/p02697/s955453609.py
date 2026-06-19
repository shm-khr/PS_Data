n, m = map(int, input().split(' '))

highest = n // 2 * 2
for i in range(0, m, 2):
    print("{0} {1}".format(1 + i // 2, highest - i // 2))
    if i + 1 < m:
        print("{0} {1}".format(n // 2 - i // 2, n // 2 + 1 + i // 2))
