import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
mod = 10**9 + 7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()


def main():
    h,w,k = LI()
    a = []
    st = None
    for i in range(h):
        s = S()
        if 'S' in s:
            st = [i, s.index('S')]
        a.append([c=='#' for c in s])

    def ns(k):
        i,j,t = k
        r = []
        if i < h-1:
            if a[i+1][j]:
                r.append((i+1,j,t+1))
            else:
                r.append((i+1,j,t))
        if j < w-1:
            if a[i][j+1]:
                r.append((i,j+1,t+1))
            else:
                r.append((i,j+1,t))
        if i > 0:
            if a[i-1][j]:
                r.append((i-1,j,t+1))
            else:
                r.append((i-1,j,t))
        if j > 0:
            if a[i][j-1]:
                r.append((i,j-1,t+1))
            else:
                r.append((i,j-1,t))
        return r


    def search(s):
        d = collections.defaultdict(lambda: inf)
        d[s] = 0
        q = []
        heapq.heappush(q, (0, s))
        v = collections.defaultdict(bool)
        while len(q):
            k, u = heapq.heappop(q)
            if v[u]:
                continue
            v[u] = True

            for nu in ns(u):
                if v[nu] or nu[2] > h+w:
                    continue
                if v[(nu[0],nu[1],nu[2]-2)]:
                    continue
                vd = k + 1
                if d[nu] > vd:
                    d[nu] = vd
                    heapq.heappush(q, (vd, nu))

        return d

    d = search(tuple(st+[0]))
    r = inf
    for g,v in d.items():
        if 0 < g[0] < h-1 and 0 < g[1] < w-1:
            continue
        t = (v+k-1) // k + (g[2]+k-1) // k
        if t < r:
            r = t
    return r


print(main())
