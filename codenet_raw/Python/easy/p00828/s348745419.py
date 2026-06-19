import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
eps = 1.0 / 10**10
mod = 998244353

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()
def pf(s): return print(s, flush=True)


def main():
    rr = []

    dd = [(1,0,0),(0,1,0),(0,0,1),(1,1,0),(1,0,1),(0,1,1),(1,1,1)]

    while True:
        n,m,p = LI()
        if n == 0 and m == 0 and p == 0:
            break

        a = [LI() for _ in range(p)]
        r = 'Draw'
        d = collections.defaultdict(int)
        for i in range(p):
            ci,cj = a[i]
            t = i % 2 + 1
            ck = 0
            for k in range(p):
                if d[(ci,cj,k)] == 0:
                    d[(ci,cj,k)] = t
                    ck = k
                    break
            ff = False
            for di,dj,dk in dd:
                if ff:
                    break
                for k in range(-2,1):
                    f = True
                    for kk in range(k,k+3):
                        ni = ci + di*kk
                        nj = cj + dj*kk
                        nk = ck + dk*kk
                        if d[(ni,nj,nk)] != t:
                            f = False
                            break
                    if f:
                        ff = True
                        break

            if ff:
                if t == 1:
                    r = 'Black {}'.format(i+1)
                else:
                    r = 'White {}'.format(i+1)
                break

        rr.append(r)


    return '\n'.join(map(str, rr))


print(main())


