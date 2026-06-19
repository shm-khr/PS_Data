import numpy as np
N, M = map(int, input().split())
mat = np.zeros((M,N))
for i in range(M):
    slist = list(map(int, input().split()))
    for j in slist[1:]:
        mat[i,j-1] = 1
plist = list(map(int, input().split()))
mat = np.append(mat, np.array([plist]).T, axis=1)
def power_set(N):
    p_sets = [[]]
    item = [i for i in range(N)]
    for i in item:
        temp = []
        for j in p_sets:
            temp += [ j+[i] ]
        p_sets += temp
    return p_sets
ret = 0
for swi in power_set(N)[1:]:
    tm_mat = mat[:,swi+[N]]
    if sum([(np.sum(i) % 2) == 0 for i in tm_mat]) == M:
        ret += 1
print(ret)