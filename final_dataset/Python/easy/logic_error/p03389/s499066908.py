import math

q = int(input())
for _ in range(q):
    a, b = map(int, input().split())
    c = int(math.sqrt(a * b))
    if a * b < 1000:
        ans = 0
        prv = a * b
        for i in range(1, a * b):
            if i == a:
                 continue
            for j in range(prv - 1, 0, -1):
                if j == b:
                    continue
                if i * j < a * b:
                    ans += 1
                    prv = j
                    break
    elif a == b:
        ans = 2 * c - 2
    elif a * b == c * c:
        ans = 2 * c - 1
    elif c * (c + 1) < a * b:
        ans = 2 * c - 1
    else:
        ans = 2 * c - 2
    print(ans)