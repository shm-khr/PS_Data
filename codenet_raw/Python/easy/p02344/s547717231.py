
n, q = map(int, input().split())

p = [i for i in range(n)]
rank = [0 for i in range(n)]
diff_weight = [0 for i in range(n)]


def link(x, y, z):
 if rank[x] > rank[y]:
  p[y] = x
  diff_weight[y] = z
 else:
  p[x] = y
  diff_weight[x] = -z
  if rank[x] == rank[y]:
   rank[y] = rank[y] + 1

def findSet(x):
 if x != p[x]:
  p[x] = findSet(p[x])
  diff_weight[x] += diff_weight[p[x]]
 return p[x]


def relate(x, y, z):
 rootx = findSet(x)
 rooty = findSet(y)
 z += diff_weight[x]
 z -= diff_weight[y]
 link(rootx, rooty, z)


def same(x, y):
 x = findSet(x)
 y = findSet(y)

 if x == y:
  return 1
 else :
  return 0

def weight(x):
 findSet(x)
 return diff_weight[x]

def diff(x, y):
 if same(x, y) != 1:
  return '?'
 else :
  return diff_weight[y] - diff_weight[x]


output = []

for i in range(q):
 line = list(map(int, input().split()))

 if line[0] == 0:
  relate(line[1], line[2], line[3])

 else :
  output.append(diff(line[1],line[2]))


for ans in output:
 print(ans)
