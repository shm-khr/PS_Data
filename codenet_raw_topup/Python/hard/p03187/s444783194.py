l,n = tuple([int(i) for i in input().split()])
trees = []

for i in range(n):
  tree = int(input())
  trees.append(tree)
  
length = 0
for tree in trees:
  length += max(tree,l-tree)
  
print(length)