#Built?
import numpy as np
import sys

n = int(input())
p = []
for i in range(n):
    p.append(list(map(int, input().split())))
    
    
#最小木問題プリム法
c = p    #city point
v = []    #vertex
e = []    #edge
v.append(c[0])
c.remove(c[0])

sumcost=0
while 1:
    mincost = sys.float_info.max
    for vp in v:
        for cp in c:
            cost = min(abs(vp[0]-cp[0]),abs(vp[1]-cp[1]))
            if mincost > cost:
                mincost = cost
    if shortestlen > 0:
        sumcost+=mincost
    v.append(cp)
    c.remove(cp)
    if len(p) == 0:
        break
        
print(sumcost)