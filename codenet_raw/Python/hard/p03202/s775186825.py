N = int(input())
A_raw = list(map(int, input().split()))

flg = 1
prev = 0
A = []
for i in range(N):
    if A_raw[i] <= prev:
        flg = 0
    prev = A_raw[i]
    if A_raw[i] > 50:
        A.append(50)
    else:
        A.append(A_raw[i])

ok = N
ng = 0
mid = (ok + ng) // 2
while ok - ng > 1:
    ng_flg = 0
    word = [1] * A[0]
    for i in range(1, N):
        if A[i] > A[i-1]:
            word.extend([1] * (A[i] - A[i-1]))
        else:
            word_prev = word[:A[i]]
            k = A[i] - 1
            while True:
                if k == -1:
                    ng_flg = 1
                    break
                if word_prev[k] != mid:
                    word_prev[k] += 1
                    word = word_prev
                    break
                else:
                    word_prev[k] = 1
                    k -= 1
        if ng_flg == 1:
            break
    if not ng_flg:
        ok = mid
    else:
        ng = mid
    mid = (ok + ng) // 2

print(ok)
