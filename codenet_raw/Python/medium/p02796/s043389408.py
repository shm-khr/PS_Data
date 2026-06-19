def have_common(di, dj):
    """2つの区間di, djが共通部分を持つかどうかを判定
    """
    if dj[0] < di[0]:
        di, dj = dj, di
    if dj[0] < di[1]:
        return True
    else:
        return False

N = int(input())

X, L, D = [0] * N, [0] * N, [[0, 0]] * N
for i in range(N):
    X[i], L[i] = map(int, input().split())
    D[i] = [[X[i]-L[i], X[i]+L[i]], L[i]]

# 区間の長さが小さいものからみる
D.sort(key=lambda x:x[1])

ans = N
j = 0
while (j < len(D) - 1):
    k = j + 1
    while (k < len(D)):
        if have_common(D[j][0], D[k][0]):
            D.remove(D[k])
            ans -= 1
        else:
            k += 1
    j += 1

print(ans)
