# https://arc096.contest.atcoder.jp/tasks/arc096_c

import itertools

n, m = input().split(" ")
n = int(n)
m = int(m)

p = 2 ** n

pt = []
for i in range(p):
    l = format(i, "b").zfill(n)
    pt.append(list(map(int, list(l))))

# print(pt)

ok = 0

for i in range(1, p + 1):
    # print("i = " + str(i))
    for c in itertools.combinations(pt, i):
        eat = [0] * n

        # print(c)
        li = list(map(list, c))
        # print(li)
        for ramen in li:
            for e_index in range(len(ramen)):
                eat[e_index] += ramen[e_index]
        # print("eat = " + str(eat))
        enough = True
        for v in eat:
            if v < 2:
                enough = False
                break
        if enough:
            ok += 1

print(ok % m)

