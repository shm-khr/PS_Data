n = int(input())
A_ = [int(i) for i in input().split(None,n)[:n]]
A = sorted(A)

cand = set()
dup = set()

for a in A:
  if a in cand:
    dup.add(a)
  for c in cand:
    if a % c != 0:
      cand.add(a)
cand -= dup
print(len(cand))