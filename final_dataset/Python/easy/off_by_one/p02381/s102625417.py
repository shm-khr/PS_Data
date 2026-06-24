scores = []
while True:
    n = int(input())
    if n == 0:
        break
    l = list(map(int, input().split()))
    scores.append(l)

for score in scores:
    print(pstdev(score))