import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

n = int(readline())
data = list(map(int,read().split()))

V = tuple(data[:2*n:2])
W = tuple(data[1:2*n:2])
q = data[2*n]
v = tuple(data[2*n+1::2])
L = tuple(data[2*n+2::2])

if(n==1):
    ans = []
    for i,j in zip(v,L):
        if(W[i-1] <= j):
            ans.append(V[0])
        else:
            ans.append(0)
    print('\n'.join(map(str,ans)))
    exit()

# 前処理　最大2**9まで前計算
b_len = min(9, n.bit_length()-1)
max_bef = 2**b_len
bef = [ [0]*(10**5 + 1) for _ in range(max_bef)]

for i in range(1,max_bef):
    iw,iv = W[i-1],V[i-1]
    par = i//2
    for j in range(1,10**5+1):
        if(j>=iw):
            bef[i][j] = max(bef[par][j] , bef[par][j-iw]+iv)
        else:
            bef[i][j] = bef[par][j]

ans = []
for vi,Li in zip(v,L):
    if(vi==1):
        if(W[0] <= Li):
            ans.append(V[0])
        else:
            ans.append(0)
        continue

    par = vi
    while(par>= max_bef):
        par //= 2

    max_ans = bef[par][Li]
    aft = [(0,0)]
    x = vi
    while(x >= max_bef):
        xw,xv = W[x-1],V[x-1]
        x //= 2
        if(x >= max_bef):
            for jw,jv in aft:
                lim_w = Li - (jw+xw)
                if(lim_w >= 0):
                    max_ans = max(max_ans, bef[par][lim_w]+jv+xw)
            break

        aft2 = []
        for jw,jv in aft:
            jw += xw
            jv += xv
            lim_w = Li - (jw)
            if(lim_w >= 0):
                max_ans = max(max_ans, bef[par][lim_w]+jv)
                aft2.append((jw,jv))

        aft = aft + aft2

    ans.append(max_ans)

print('\n'.join(map(str,ans)))