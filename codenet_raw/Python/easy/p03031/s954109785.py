import itertools

N,M = map(int, input().split())
S = [list(map(int, input().split()))[1:] for _ in range(M)]
P = list(map(int, input().split()))

switch = range(1,N+1)
pattern = []
for i in range(1,N+1):
    pattern.extend(tuple(itertools.combinations(switch, i)))

count = 0
for swp in pattern:
    for p, s in zip(P,S):
        match = len(set(s) & set(swp))
        if match == 0:
            break
        if match % 2 != p:
            break
    else:
        count += 1
print(count)