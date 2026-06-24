N,K = map(int,input().split())
if K == 1:
    print(0)
else:
    if K%2 == 1:
        print((N//K)**3)
    else:
        K2 = K//2
        half = N//K2 - N//K
        print(half**3 + (N//K)**3)