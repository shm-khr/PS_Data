N,M,T = map(int, input().split())
L = [[int(l) for l in input().split()] for _ in range(M)]

class UnionFind():
    def __init__(self, n):
        self.n = n
        self.root = [-1]*(n+1)
        self.rnk = [0]*(n+1)
        
    def find_root(self, x):
        if self.root[x] < 0:
            return x
        else:
            self.root[x] = self.find_root(self.root[x])
            return self.root[x]
        
    def unite(self, x, y):
        x = self.find_root(x)
        y = self.find_root(y)
        if x == y:
            return
        elif self.rnk[x] > self.rnk[y]:
            self.root[x] += self.root[y]
            self.root[y] = x
        else:
            self.root[y] += self.root[x]
            self.root[x] = y
            if self.rnk[x] == self.rnk[y]:
                self.rnk[y] += 1
                
    def isSameGroup(self, x, y):
        return self.find_root(x) == self.find_root(y)
    
    def count(self, x):
        return -self.root[self.find_root(x)]

if T == 1:
    uf = UnionFind(N)
    for i in range(M):
        uf.unite(L[i][0]-1, L[i][1]-1)
    
    ans = 0
    for i in range(N):
        if uf.isSameGroup(0, i):
            continue
        ans = -1
        break
    
    if ans == 0:
        uf2 = UnionFind(N)
        X = L[-1][0]-1
        ans = [0]*M
        for i in range(M-1, -1, -1):
            if L[i][0]-1 == X:
                ans[i] = "^"
                uf2.unite(X, L[i][1]-1)
            elif L[i][1]-1 == X:
                ans[i] = "v"
                uf2.unite(X, L[i][0]-1)
            elif uf2.isSameGroup(X, L[i][0]-1):
                ans[i] = "^"
                uf2.unite(X, L[i][1]-1)
            elif uf2.isSameGroup(X, L[i][1]-1):
                ans[i] = "v"
                uf2.unite(X, L[i][0]-1)
            else:
                ans[i] = "^"
            
        print("".join(ans))
    else:
        print(ans)
else:
    print(-2)