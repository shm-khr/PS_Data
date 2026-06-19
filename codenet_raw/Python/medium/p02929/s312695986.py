M = 10**9+7
N = int(input())
S = list(input())
s = [0]*(2*N)

#0ならW、1ならB
for i in range(2*N):
    if S[i] == "B":
        s[i] = 1

#端が0なら0を返す
if s[0] == 0 or s[2*N-1] == 0:
    print(0)
    exit()

ans = 0
lis = [0]+[1]*(2*N-1) #0なら左、1なら右
#全て0にする

for j in range(1,2*N):
    if s[j-1] ^ s[j] == 1:
        lis[j] = lis[j-1]
    else:
        lis[j] = lis[j-1] ^ 1

#左と右の数が違ったら0を返す
if lis.count(0) != lis.count(1):
    print(0)
    exit()

#"右"が選べる"左"の選択肢を掛けていく
cnt = 1
ans = 1
for k in range(1,2*N):
    if lis[k] == 0:
        cnt += 1
    else:
        ans *= cnt
        cnt -= 1

#N!をかける
for l in range(1,N+1):
    ans *= l
    ans %= M
print(ans)