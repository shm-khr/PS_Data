#標準入力からKを求めるまで
N = int(input())
node = [0] * N
AB = []
for i in range(N-1):
    ab = list(map(int, input().split()))
    node[ab[0] - 1] += 1
    node[ab[1] - 1] += 1
    AB.append(ab)
K = max(node)
print(K)

#各辺の色を求めていく
color = [[ i for i in range(1, K + 1)] for i in range(N)]
for i in range(N-1):
    now = list(set(color[AB[i][0]-1]) & set(color[AB[i][1] - 1]))
    tmp = now[0]
    color[AB[i][0]-1].remove(tmp)
    color[AB[i][1]-1].remove(tmp)
    print(tmp)
