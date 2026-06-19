def main():
  A,B,M = [int(i) for i in input().split()]
  a = [int(i) for i in input().split()]
  b = [int(i) for i in input().split()]

  C = {}
  for i in range(M):
    x,y,c = [int(i) for i in input().split()]
    t = "%s,%s" % (x-1 ,y-1)
    m = 0
    if t in C:
      if C[t] < c:
        C[t] = c
    else:
    	C[t] = c
    if m < c:
      m = c;
  r = 100000;
  for i in range(A):
    for j in range(B):
      z = a[i] + b[j]
      if r < m + z:
        continue
      t = "%s,%s" % (i,j)
      if t in C:
        z = z - C[t]
      if z < r:
        r = z
  print(r)

if __name__ == "__main__":
  main()