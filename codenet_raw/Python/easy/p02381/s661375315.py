import math
while True:
    n = int(input())
    score = [ int(i) for i in input().split(" ") ] 
    average = sum(score) / float(n)
    if n == 0:
        break
    print("{:.8f}".format(math.sqrt(sum([(x-average) ** 2]) / n ) 