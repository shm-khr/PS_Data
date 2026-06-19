n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

for i in range(n):
    if(sum(a[i+1:]) < sum(b[i:-1])):
        print(sum(a[:i+1]) + sum(b[i:]))
        exit()
print(sum(a) + b[n-1])