import sys, os

f = lambda:list(map(int,input().split()))
if 'local' in os.environ :
    sys.stdin = open('./input.txt', 'r')

def solve():
    n, k = f()


    pts = []
    for i in range(n):
        x, y = f()
        pts.append((x,y))
    
    minarea = int(1e19)
    for i in range(n):
        for j in range(n):
            if i==j:
                continue
            minx = min(pts[i][0], pts[j][0])
            maxx = max(pts[i][0], pts[j][0])
            miny = min(pts[i][1], pts[j][1])
            maxy = max(pts[i][1], pts[j][1])
            cnt = 0
            for s in range(n):
                if pts[s][0] in range(minx, maxx+1) and pts[s][1] in range(miny, maxy+1):
                    cnt += 1

            if cnt>=k:
                minarea = min(minarea, (maxx - minx)*(maxy - miny))
        
    print(minarea)



solve()
