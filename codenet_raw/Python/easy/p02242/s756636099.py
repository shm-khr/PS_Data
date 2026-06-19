INF = float('inf')


def dijkstra(source):
    distance[source] = 0
    parent[source] = -1

    while True:
        mincost = INF
        for i in range(n):
            if color[i] != 'black' and distance[i] < mincost:
                mincost = distance[i]
                u = i

        if mincost == INF:
            break

        color[u] = 'black'

        for v in range(n):
            if color[v] != 'black' and adjMat[u][v] != INF:
                if distance[u] + adjMat[u][v] < distance[v]:
                    distance[v] = distance[u] + adjMat[u][v]
                    parent[v] = u
                    color[v] = 'gray'


n = int(input())
color = ['white'] * n
parent = [-1] * n
distance = [INF] * n

adjMat = [[INF] * n for _ in range(n)]
for i in range(n):
    inputList = list(map(int, input().split()))
    adjRow = inputList[0::2][1:]
    weightRow = inputList[1::2][1:]
    for v, weight in zip(adjRow, weightRow):
        adjMat[i][v] = weight

dijkstra(0)

for index, distance in enumerate(distance):
    print('{} {}').format(index, distance)