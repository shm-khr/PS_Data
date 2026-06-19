# -*- coding: utf-8 -*-
N, K = map(int, input().split())
tree = [[] for _ in range(N)]
edges = []
for n in range(1, N):
    a, b = map(int, input().split())
    tree[a - 1].append(b - 1)
    tree[b - 1].append(a - 1)
    edges.append((a - 1, b - 1))


def dfs(i, now_v):
    dias[i] = now_v
    for next_node in tree[i]:
        if dias[next_node] == -1:
            dfs(next_node, now_v + 1)


ans = int(1e18)
if K % 2 == 0:
    for i in range(N):
        dias = [-1 for _ in range(N)]
        dfs(i, 0)
        print(dias)
        over_count = sum([1 if dias[j] > K / 2 else 0 for j in range(N)])
        ans = min(ans, over_count)
    print(ans)
else:
    dias_lst = []
    for i in range(N):
        dias = [-1 for _ in range(N)]
        dfs(i, 0)
        dias_lst.append(list(dias))
    # print(dias_lst)
    for edge in edges:
        x = sum(int(min(x, y) > (K - 1) / 2)
                for x, y in zip(dias_lst[edge[0]], dias_lst[edge[1]]))
        ans = min(ans, x)
    print(ans)
