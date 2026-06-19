A,B,M = map(int,input().split())
P = list(map(int,input().split()))
Q = list(map(int,input().split()))
S = P
T = Q
minimum = 99999999
K = 0
S.sort()
P.sort()
K = (S[0]+P[0])
for i in range(M):
    x,y,c = map(int,input().split())
    S = P[x-1]+Q[y-1]-c
    if S<minimum:
        minimum = S
if minimum<K:
    print(minimum)
else:
    print(K)