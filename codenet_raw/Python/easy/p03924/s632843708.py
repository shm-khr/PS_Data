import numpy as np
N, M = map(int, raw_input().split())
# one way path from 1, no path from 1
status_mat = np.zeros((N, N), dtype='int')
status_mat[0, N-1] = 1

bothM = np.zeros((N, N), dtype='int')
for i in range(N):
    for j in range(N):
        bothM[i, j] = N-i-j

diagM = np.diag(range(N))



def update_status_mat(status_mat):
    status_mat[0, 0] = 0
    new_status_mat = diagM.dot(status_mat)
    new_status_mat[0, :] += (bothM*status_mat).sum(axis=0)
    new_status_mat[1:, :(N-1)] += status_mat.dot(diagM)[:(N-1), 1:]
    return new_status_mat % 1000000007

for m in range(M):
    status_mat = update_status_mat(status_mat)

print status_mat[0,0]