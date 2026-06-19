N = int(input())
A = [int(_) for _ in input().split() if int(_) < 19]
N = len(A)
while True:
    flag = True
    B = [A[0]]
    for i in range(N - 1):
        if A[i] >= A[i + 1]:
            B += [A[i + 1]]
        else:
            flag = False
    A = B.copy()
    N = len(A)
    if flag:
        break

if N == 1:
    print(1)
    exit()


def is_possible(K):
    dp = [0] * 19
    for i in range(N - 1):
        if B[i] >= B[i + 1]:
            dp = dp[: B[i + 1]] + [0] * (19 - B[i + 1])
            flag = True
            for j in range(B[i + 1] - 1, -1, -1):
                if dp[j] < K - 1:
                    dp[j] += 1
                    flag = False
                    break
                else:
                    dp[j] = 0
            if flag:
                return False
    return True


def bis(x, y):
    if y == x + 1:
        return y
    elif is_possible((x + y) // 2):
        return bis(x, (x + y) // 2)
    else:
        return bis((x + y) // 2, y)


print(bis(0, N))
