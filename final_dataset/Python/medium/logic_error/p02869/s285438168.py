N, K = map(int, input().split())
if (N*3+1)*3*N//2-N*(N*2+1)>=N*K:
    print('No')
else:
    print('Yes')