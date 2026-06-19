while True:
    h = int(input())
    if h == 0:
        break
    arr = [[-1 for i in range(h)], [-1 for i in range(h)], [-1 for i in range(h)], [-1 for i in range(h)], [-1 for i in range(h)]]
    midlen = h
    for i in range(h - 1, -1, -1):
        inp = list(map(int, input().split()))
        for j, e in enumerate(inp):
            arr[j][i] = e
    
    score = 0
    za = True
    while za:
        za = False
        for i, e in list(enumerate(arr[2]))[::-1]:
            for j in range(3):
                ge = 0
                for h in range(j, 5):
                    if len(arr[h]) > i:
                        if arr[h][i] == e:
                            ge += 1
                            continue
                    break
                if ge > 2:
                    za = True
                    for h in range(j, j + ge):
                        score += arr[h].pop(i)
    print(score)

