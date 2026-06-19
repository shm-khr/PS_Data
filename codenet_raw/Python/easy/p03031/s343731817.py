n, m = map(int, input().split())
k = []
s = []
for _ in range(m):
    ki, *si = map(int, input().split())
    k.append(ki)
    s.append(si)
p = list(map(int, input().split()))
cnt = 0
for i in range(2**n):
    flag = True
    for ki, si, pi in zip(k,s,p):
        if not list(bin(i & sum(si))).count("1") % 2 == pi:
            flag = False
            break
    if flag == True:
        cnt += 1
            
print(cnt)