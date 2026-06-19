N,W = map(int,input().split())
v = [0]*N;w = [0]*N

for i in range(N):
    v[i],w[i] = map(int,input().split())

value = [0 for i in range(W+1)]
for i in range(N):
    for j in range(W,-1,-1):
        if j>=w[i]:
            value[j] = max(value[j],value[j-w[i]]+v[i])

print(value[W])