n = int(input())
A = list(map(int, input().split()))

a = max(A)
A.sort(key=lambda x:abs(x-a/2))
b = A[0]
print(' '.join([str(a), str(b)]))