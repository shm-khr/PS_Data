A, B, C, X = map(int, input().split())

count = 0
for a in range(A+1):
  for b in range(B+1):
     for c in range(C+1):
        if a+b+c= X:
          count += 1

print(count)