#
import sys
import math
import numpy as np
import itertools

# いくつか入力
a, b, m = (int(i) for i in input().split())  

aprice = [int(i) for i in input().split()] 
bprice = [int(i) for i in input().split()] 
c = [[int(i) for i in input().split()] for i in range(m)] 
print(aprice,bprice,c)
amin=999999
for i in range(a):
    amin = min(amin,aprice[i])
bmin=999999
for i in range(b):
    bmin = min(bmin,bprice[i])

p=[]
for i in range(m):
    print(c[i][0],c[i][1],c[i][2])
    p.append(aprice[c[i][0]-1]+bprice[c[i][1]-1]-c[i][2])

answer = amin+bmin
for i in p:
    answer = min(answer, i) 

print(answer)
