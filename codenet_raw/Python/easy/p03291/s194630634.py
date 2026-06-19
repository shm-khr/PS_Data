S = input()
N = len(S)
MOD = 10 ** 9 + 7

Qs = 3 if S[0] == '?' else 1
A = [0] * N
AB = [0] * N
ABC = [0] * N
if S[0] in 'A?':
    A[0] = 1
for i in range(1, N):
    s = S[i]
    if s == '?':
        A[i] = A[i - 1] * 3 + Qs
        AB[i] = AB[i - 1] * 3 + A[i - 1]
        ABC[i] = ABC[i - 1] * 3 + AB[i - 1]
        Qs *= 3
    elif s == 'A':
        A[i] = A[i - 1] + Qs
        AB[i] = AB[i - 1]
        ABC[i] = ABC[i - 1]
    elif s == 'B':
        A[i] = A[i - 1]
        AB[i] = AB[i - 1] + A[i - 1]
        ABC[i] = ABC[i - 1]
    elif s == 'C':
        A[i] = A[i - 1]
        AB[i] = AB[i - 1]
        ABC[i] = ABC[i - 1] + AB[i - 1]

ans = ABC[-1] % MOD
print(ans)