import sys
fin = sys.stdin.readline
from heapq import heappop, heappush


# assuming that the vertices are 0, 1, ..., N - 1
# if V^2 >> E, use a hashmap representation of w
# time complexity: O(ElgE)
# space complexity: O(E)
def prim(adj, w):
    num_vertices = len(adj)
    # initialize
    min_cost = [float('inf')] * num_vertices
    min_cost[0] = 0
    used = [False] * num_vertices
    priority_queue = [(0, 0)]
    total_cost = 0

    while priority_queue:
        cost, vertex = heappop(priority_queue)
        if cost > min_cost[vertex] or used[vertex]:
            continue
        used[vertex] = True
        total_cost += cost

        for neighbor in adj[vertex]:
            cost_v_to_n = w[(vertex, neighbor)]
            if min_cost[neighbor] > cost_v_to_n:
                min_cost[neighbor] = cost_v_to_n
                heappush(priority_queue, (cost_v_to_n, neighbor))

    return total_cost


N = int(fin())
coords = [[int(elem) for elem in fin().split()] + [i] for i in range(N)]

adj = [set() for _ in range(N)]
w = {}

# sort coords in increasing order of x
coords.sort(key=lambda x: x[0])
for i, (x, _, vertex) in enumerate(coords[:-1]):
    next_x, _, next_idx = coords[i + 1]
    adj[vertex].add(next_idx)
    adj[next_idx].add(vertex)
    weight = next_x - x
    w[(vertex, next_idx)] = weight
    w[(next_idx, vertex)] = weight

# sort coods in increasing order of y
coords.sort(key=lambda x: x[1])
for i, (_, y, vertex) in enumerate(coords[:-1]):
    _, next_y, next_idx = coords[i + 1]
    adj[vertex].add(next_idx)
    adj[next_idx].add(vertex)
    weight = next_y - y
    w[(vertex, next_idx)] = weight
    w[(next_idx, vertex)] = weight


print(prim(adj, w))
