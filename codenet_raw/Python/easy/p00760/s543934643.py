
def da(Y,M,D):
    day = (Y / 3) * 590
    if Y % 3 == 2:
        day = day + 390 + (M - 1)*20 + D
    else:
        day = day + (Y%3 - 1) * 195
        if M%2 == 1:
            day = day + (M/2 * 39) + D
        else:
            day = day + (M/2 - 1) * 39 + 20 + D
    return day
n = int(raw_input())
for i in range(n):
        l = map(int,raw_input().split())
        Y = l[0]
        M = l[1]
        D = l[2]
        print da(1000,1,1) - da(Y,M,D)
    