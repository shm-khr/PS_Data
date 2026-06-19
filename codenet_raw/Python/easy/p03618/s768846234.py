S = input()
N = len(S)
ans = N * (N - 1) // 2
a = []
for c in [chr(i) for i in range(97, 97+26)]:
    a.append(S.count(c))
ans -= sum(a)
print(ans)