import sys

sys.setrecursionlimit(10000)

def search(a, b, left, right):
    mid = int(left + (left - right) / 2)
    if(b[mid] == a):
        return b[mid]
    if(b[mid] >= a and a >= b[mid+1]):
        if(b[mid]- a >= a - b[mid+1]):
            return  b[mid+1]
        else:
            return b[mid]
    if(b[mid] >= a):
        return search(a, b, 0, mid)
    else:
        return search(a, b, mid, right)

n = int(input())
a = list(map(int, input().split(" ")))

b = sorted(a, reverse=True)
for i in b:
    m = i/2
    j = search(m, b, 0, len(b))
    print("%d %d" %(i, j))
    break