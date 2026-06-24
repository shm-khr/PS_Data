# import time
from collections import defaultdict, Counter
# st = time.time()
N, M = map(int, input().split())
AB = defaultdict(list)
count_node = Counter()
for i in range(M):
    a, b = map(int, input().split())
    AB[a].append(b)
    AB[b].append(a)
    count_node[a] += 1
    count_node[b] += 1

if M % 2 == 1:
    print(-1)
else:
    for node, count in count_node.most_common()[::-1]:
        if count == 1:
            from_node = Ab[node][0]
            print(from_node, node)
            AB[from_node].remove(node)
        else:
            node_list = AB[node]
            if len(node_list) % 2 == 0:
                for to_node in node_list:
                    print(node, to_node)
                    AB[to_node].remove(node)
            else:
                for to_node in node_list[:-1]:
                    print(node, to_node)
                    AB[to_node].remove(node)

# print(time.time()-st)
