n = int(input())
xl = [[0]*2 for _ in range(n+1)]
xl[0][0] = -10**9
xl[0][1] = -10**9
for i in range(n):
  a,b = list(map(int,input().split()))
  xl[i+1][0] = a - b
  xl[i+1][1] = a + b
xl = sorted(xl)

def dist(bit):
  pre = 0
  for i in range(1,n+1):
    if bit & 1<<i:
      if xl[pre][1] > xl[i][0]:
        return False
      pre = i
  return True

if dist((1<<(n+1))-1):
  print(n)
  exit()

def bi():
  for bit in range(1<<(n+1))[::-1]:
    if bit & 1<<n:
      if dist(bit):
        print(sum([1 for i in range(n+1) if bit & 1<<i])-1)
        #print(bin(bit),sum([1 for i in range(n+1) if bit & 1<<i])-1)
        exit()
bi()