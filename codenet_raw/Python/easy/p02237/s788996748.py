import sys


class Graph:
    def __init__(self, nodes={}):
        self.nodes = nodes
    def printAdjMatrix(self):
        # assuming that nodes' indices are 1,2,3,...,n
        n = len(self.nodes)
        for node in range(n):
        out = ''
        for adj in range(n):
            if adj + 1 != n:
                out += '1 ' if adj + 1 in G.nodes[node + 1] else '0 '
            else:
                out += '1' if adj + 1 in G.nodes[node + 1] else '0'
        print(out)


n = int(input())
G = Graph()
for line in sys.stdin:
    numList = list(map(int, line.split()))
    G.nodes[numList[0]] = list(numList[2:])

G.printAdjMatrix()