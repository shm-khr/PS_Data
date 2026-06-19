import sys
input = sys.stdin.readline

MOD = 10**9 + 7

N = int(input())
ball = [tuple(int(x) for x in input().split()) for _ in range(N+N)]

U = N+N+10
fact = [1] * (U+1); fact_inv = [1] * (U+1)
for n in range(1,U+1):
    fact[n] = fact[n-1] * n % MOD
fact_inv[U] = pow(fact[U],MOD-2,MOD)
for n in range(U,0,-1):
    fact_inv[n-1] = fact_inv[n] * n % MOD

X_to_Y = [[] for _ in range(N+1)]
Y_to_X = [[] for _ in range(N+1)]
for x,y in ball:
    X_to_Y[x].append(y)
    Y_to_X[y].append(x)

# とりあえず連結成分に分けよう
visited_x = set()
visited_y = set()
components = []
for x,y in ball:
    if x in visited_x:
        continue
    V = set()
    V_x = set()
    V_y = set()
    q = [(x,y)]
    while q:
        x,y = q.pop()
        V.add((x,y))
        if x not in V_x:
            V_x.add(x)
            for t in X_to_Y[x]:
                q.append((x,t))
        if y not in V_y:
            V_y.add(y)
            for t in Y_to_X[y]:
                q.append((t,y))
        V_x.add(x)
        V_y.add(y)
    visited_x |= V_x
    visited_y |= V_y
    components.append((V,V_x,V_y))

def make_get_patterns(V_x,V_y):
    assert len(V) == len(V_x) + len(V_y)
    rest_xy = {x:set(X_to_Y[x]) for x in V_x}
    rest_yx = {y:set(Y_to_X[y]) for y in V_y}
    deg1_x = set(x for x in V_x if len(rest_xy[x]) == 1)
    deg1_y = set(y for y in V_y if len(rest_yx[y]) == 1)
    get = {},{}
    while deg1_x or deg1_y:
        while deg1_x:
            x = deg1_x.pop()
            y = rest_xy[x].pop()
            se = rest_yx[y]; se.remove(x)
            if len(se) == 1: deg1_y.add(y)
            elif len(se) == 0: deg1_y.remove(y)
            get[0][(x,y)] = 0; get[1][(x,y)] = 0
        while deg1_y:
            y = deg1_y.pop()
            x = rest_yx[y].pop()
            se = rest_xy[x]; se.remove(y)
            if len(se) == 1: deg1_x.add(x)
            elif len(se) == 0: deg1_x.remove(x)
            get[0][(x,y)] = 1; get[1][(x,y)] = 1
    for x in V_x:
        if rest_xy[x]:
            y = rest_xy[x].pop()
            break
    get[0][(x,y)] = 0; get[1][(x,y)] = 1
    rest_yx[y].remove(x); deg1_y.add(y)
    while deg1_x or deg1_y:
        while deg1_x:
            x = deg1_x.pop()
            y = rest_xy[x].pop()
            se = rest_yx[y]; se.remove(x)
            if len(se) == 1: deg1_y.add(y)
            elif len(se) == 0: deg1_y.remove(y)
            get[0][(x,y)] = 0; get[1][(x,y)] = 1
        while deg1_y:
            y = deg1_y.pop()
            x = rest_yx[y].pop()
            se = rest_xy[x]; se.remove(y)
            if len(se) == 1: deg1_x.add(x)
            elif len(se) == 0: deg1_x.discard(x)
            get[0][(x,y)] = 1; get[1][(x,y)] = 0
    return get

def F(V,V_x,V_y):
    # 連結成分上の順序がうまくいっている確率を返す
    if len(V) != len(V_x) + len(V_y):
        return 0
    V = sorted(V)
    ret = 0
    for get in make_get_patterns(V_x,V_y):
        den = 1
        dp_x = {x:0 for x in V_x}
        dp_y = {y:0 for y in V_y}
        for x,y in V:
            if get[(x,y)] == 0: # x軸でとる
                k = dp_x[x] + 1
            else:
                k = dp_y[y] + 1
            dp_x[x] += k
            dp_y[y] += k
            den *= k
            den %= MOD
        ret += pow(den,MOD-2,MOD)
    return ret % MOD

prob = 1
for c in components:
    prob *= F(*c)
    prob %= MOD
answer = prob * fact[N+N] % MOD
print(answer)

