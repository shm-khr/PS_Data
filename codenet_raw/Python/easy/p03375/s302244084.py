# coding: utf-8
# Your code here!

import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline #文字列入力のときは注意

n,MOD = [int(i) for i in readline().split()]

SIZE=3001; #MOD=10**9+7 #998244353 #ここを変更する

inv = [0]*(SIZE+1)# inv[j] = j^{-1} mod MOD
fac = [0]*(SIZE+1)# fac[j] = j! mod MOD
finv = [0]*(SIZE+1)# finv[j] = (j!)^{-1} mod MOD
inv[1] = 1
fac[0] = fac[1] = 1
finv[0] = finv[1] = 1
for i in range(2,SIZE+1):
    inv[i] = MOD -(MOD//i)*inv[MOD%i]%MOD
    fac[i] = fac[i-1]*i%MOD
    finv[i]= finv[i-1]*inv[i]%MOD

def choose(n,r): # nCk mod MOD の計算
    if 0 <= r <= n:
        return (fac[n]*finv[r]%MOD)*finv[n-r]%MOD
    else:
        return 0


"""
make the table of Sterling numbers of the second kind
Sterling[ball][box]
"""
SIZE = n
Sterling2 = [[0]*(SIZE+1) for _ in range(SIZE+1)]
Sterling2[0][0] = Sterling2[1][1] = 1
for i in range(2,SIZE+1):
    for k in range(1,i+1):
        Sterling2[i][k] = (Sterling2[i-1][k-1] + k*Sterling2[i-1][k])%MOD





SIZE = n
f = [[0]*(SIZE+1) for _ in range(SIZE+1)]
f[0][0] = 1
for i in range(1,SIZE+1):
    for k in range(i+1):
        f[i][k] = (f[i-1][k] + f[i-1][k-1] + k*f[i-1][k])%MOD

#print(f)

def size(s):
    res = 0
    for b in range(n+1):
        res += f[s][b]*pow(2,b*(n-s),MOD)
    return res*pow(2,pow(2,n-s,MOD-1),MOD)%MOD

#for i in range(n+1):
#    print(size(i))

ans = 0
sgn = 1
for j in range(n+1):
    ans += sgn*choose(n,j)*size(j)
    ans %= MOD
    sgn *= -1

print(ans)






