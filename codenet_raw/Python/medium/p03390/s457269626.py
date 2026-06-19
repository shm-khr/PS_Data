import math
import random
Q = int(input()) 


for _ in range(Q):
    a,b = [int(x) for x in input().split()]
    seki = a*b - 1
    saidai = math.floor(seki**0.5)
    result = saidai*2
    if saidai*(saidai+1) > seki:
        result -= 1
    if a <= saidai or b <= saidai:
        result -= 1
    print(result)