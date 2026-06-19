N, M, T = list(map(int,input().split()))
xy = [list(map(int,input().split())) for _ in range(M)]

UP = "^"
DW = "v"

if T == 1:
  x = 10 / 0

else:
  if N == 2:
    print(-1)

  L = [""] * M
  
  D = []
  for i in range(M):
    x, y = xy[i]
    if x <= 3 and y <= 3:
      D.append([i, x, y])
    else:
      L[i] = UP
    
  i = 0
  while i < len(D):
    T = []
    n, x, y = D[i]
    T.append(n)
    j = i + 1
    while j < len(D):
      n, xx, yy = D[j]
      if x == xx and y == yy:
        T.append(n)
        j += 1
      else:
        if x == xx:
          for k in T:
            L[k] = DW
        elif y == yy:
          for k in T:
            L[k] = UP
        elif x == yy:
          for k in T:
            L[k] = DW
        elif xx == y:
          for k in T:
            L[k] = UP
        i = j
        break
    else:
      break
  for k in T:
    L[k] = UP
  print("".join(L))

