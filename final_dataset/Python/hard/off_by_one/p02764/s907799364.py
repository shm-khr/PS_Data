import sys
sys.setrecursionlimit(10**9)

N, K = map(int,input().split())
niku = list(list(map(int,input().split()))for _ in range(N))
ans = float('inf')

def func(l,r):
    if r-l <= 10**(-12):
        return l
    mid = (l+r)/2
    hoge = [[0]*N for _ in range(N)]
    count = N
    for i in range(N):
        hoge[i][i] = 1
        for j in range(i+1,N):
            if ((niku[i][1]-niku[j][1])**2 + (niku[i][0]-niku[j][0])**2) <= (mid/niku[i][2] + mid/niku[j][2])**2:
                hoge[i][j] = 1
                hoge[j][i] = 1
    while 1:
        dex = 0
        num = 0
        zero = 0
        for i in range(N):
            fuga = N-sum(hoge[i])
            if fuga > num:
                num = fuga
                dex = i
            zero += fuga
        if zero == 0:
            break
        for i in range(N):
            if hoge[i][dex] == 0:
                hoge[i][dex] = 1
                hoge[dex][i] = 1
                zero -= 2
        count -= 1

    if count >= K:
        return func(l,mid)
    else:
        return func(mid,r)
print(func(0,10**9))
