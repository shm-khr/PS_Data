import sys, math, itertools, collections, bisect 
input = lambda: sys.stdin.buffer.readline().rstrip().decode('utf-8') 
inf = float('inf') ;mod = 10**9+7 
mans = inf ;ans = 0 ;count = 0 ;pro = 1

a, b, c = map(int, input().split())
k = int(input())
for i in range(k):
    if a > b:
        b *= 2
    elif b > c:
        c *= 2
if a < b and b < c:
    print("Yes")
else:
    print("No")