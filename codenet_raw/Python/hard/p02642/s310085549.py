N = int(input())
pi = [int(i) for i in input().split()]

res = {}

sorted_p = sorted(pi)
for p in sorted_p:
    flag = True
    for div in res.keys():
        if p == div:
            flag = False
            res[p] += 1
            break
        elif div > (p/2):
            break
        elif p % div == 0:
            flag = False
            break
    if flag:
        res[p] = 1

res_count = 0
if len(res) != 1:
    for v in res.values():
        res_count += v

print(res_count)
