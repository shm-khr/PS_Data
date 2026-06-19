n = int(input())
ans = 0
flag = True
a = []
b = []
for _ in range(n):
    ai, bi = map(int, input().split())
    if ai != bi:
        flag = False
    if ai <= bi:
        ans += bi
    else:
        a.append(ai)
        b.append(bi)

import numpy as np
a = np.array(a, dtype=int)
b = np.array(b, dtype=int)
rank = np.argsort(a)[::-1]
loss = (b - a)[rank]
gain = a[rank]
room = ans
for i in range(len(a)-1):
    if loss[i] <= room:        
        ans += gain[i]
        room -= loss[i]

print(0) if flag else print(ans)