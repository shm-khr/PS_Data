import math

H, W = map(int, input().split())

m = min(H, W)
m1 = max(H, W)

if (m % 3) == 0:
    print("0")
else:
    round=lambda x:(x*2+1)//2
    y = round(m1 / 3)
    print(abs(int((m*y) - (m1-y)*math.floor(m/2))))
