from bisect import bisect_left
N, A, B, C, D = map(int, input().split())
A, B, C, D = A*2, B*2, C*2, D*2
M = C + (D - C) // 2
W = (D - C) // 2
arr = list(range(-(N-1)*M+A, N*M+A, C+D))

#s = []
#for n in arr:
#    s.append(str("%d-%s-%d" % ((n-W*(N-1))/2, n/2, (n+W*(N-1))/2)))
#print(', '.join(s))
    

idx = bisect_left(arr, B)
ans = 'NO'
if idx > 0:
    if B - arr[idx-1] <= W*(N-1):
        ans = 'YES'
if idx < N:
    if arr[idx] - B <= W*(N-1):
        ans = 'YES'
print(ans)
