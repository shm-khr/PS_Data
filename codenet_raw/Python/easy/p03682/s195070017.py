import sys
import heapq
n = int(input())
v_ls = []
x_ls = []
y_ls = []
for i in range(n):
    x, y = [int(i) for i in sys.stdin.readline().split()]
    v_ls.append((i, x, y))

graph = {i:[] for i in range(n)}
v_ls.sort(key=lambda x:x[1])
for i, v in enumerate(v_ls[:-1]):
    _from = v
    _to = v_ls[i + 1]
    diff = _to[1] - _from[1]
    graph[_from[0]].append((_to[0], diff))
    graph[_to[0]].append((_from[0], diff))

v_ls.sort(key=lambda x:x[2])
for i, v in enumerate(v_ls[:-1]):
    _from = v
    _to = v_ls[i + 1]
    diff = _to[2] - _from[2]
    graph[_from[0]].append((_to[0], diff))
    graph[_to[0]].append((_from[0], diff))

v_ls.sort(key=lambda x:x[0])
already = set()
cur = [(0, 0, 0)]
cost = 0
while len(cur) > 0:
    cur_cost, cur_ind, plus = heapq.heappop(cur)
    _, cur_x, cur_y = v_ls[cur_ind]
    if cur_ind in already:
        continue
    already.add(cur_ind)
    cost += plus
    for _next, next_cost in graph[cur_ind]:
        if _next in already:
            continue
        heapq.heappush(cur, (cur_cost + next_cost, _next, next_cost))
    if len(already) == n:
        break
print(cost)