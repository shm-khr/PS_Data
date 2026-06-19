import bisect
import collections
import sys

sys.setrecursionlimit(1000000)
input = sys.stdin.readline
ACMOD = 1000000007
INF = 1 << 62


def lmi():
    return list(map(int, input().split()))


def llmi(n):
    return [lmi() for _ in range(n)]


N = int(input())
c_raw = lmi()
ab = llmi(N - 1)

adj = collections.defaultdict(list)
for a, b in ab:
    adj[a - 1].append(b - 1)
    adj[b - 1].append(a - 1)

total = N * (N + 1) // 2

visited = [False] * N

visited[0] = True
stacks = [[[0, 0]] for i in range(N)]
ans = [0] * N
curr = 1

# dfs = [0]
# while dfs:
#     node = dfs[-1]
#     prev, rem = stacks[c[node]][-1]
#     diff = curr - prev - rem
#     ans[c[node]] += (diff * (diff + 1)) // 2
#     stacks[c[node]][-1][1] += diff
#     if adj[node]:
#         next_node = adj[node].pop()
#         if not visited[next_node]:
#             visited[next_node] = True


color_stack = [[0, N] for _ in range(N)]
color_groups = [[] for _ in range(N)]


class Tree:
    def __init__(self, i, _c):
        self.i = i
        self.color = _c
        self.child_count = 0
        self.children = []

    def set_child_count(self, parent=-1):
        for node_index in adj[self.i]:
            if node_index == parent:
                continue
            self.children.append(node_index)
            trees[node_index].set_child_count(self.i)
            self.child_count += trees[node_index].child_count + 1

    def dfs(self):
        color_stack[self.color][-1] -= self.child_count + 1
        if not self.children:
            color_stack[self.color].append(self.child_count)
        for node_index in self.children:
            if trees[node_index].color == self.color:
                raise
            color_stack[self.color].append(trees[node_index].child_count + 1)
            trees[node_index].dfs()
        color_groups[self.color].append(color_stack[self.color].pop())


# print(color_stack)
trees = [Tree(i, c - 1) for i, c in enumerate(c_raw)]
trees[0].set_child_count()
trees[0].dfs()

for color in range(N):
    v = color_groups[color] + color_stack[color]
    # print(v)
    print(N + N * (N - 1) // 2 - sum(map(lambda x: x + x * (x - 1) // 2, v)))
    # print(v, N + N * (N - 1) // 2)
