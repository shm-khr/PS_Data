n,k = map(int, input().split())
A = list(map(int, input().split()))
A.sort()

k -= 1
cnt = -(-(n-1)//k)

print(cnt)