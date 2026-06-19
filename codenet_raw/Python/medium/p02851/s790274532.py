N, K = map(int, input().split())
ls = list(map(int, input().split()))

count = 0
for i in range(0, len(ls)):
    for j in range(i+1, len(ls)+1):
        tg = ls[i:j]
        if sum(tg)%K == len(tg):
            count += 1

print(count)