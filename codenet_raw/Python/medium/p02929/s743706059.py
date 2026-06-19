import sys
sys.setrecursionlimit((10 ** 5) * 2)
 
def kai(a):
  if a == 1:
    return 1
  else:
    return a*kai(a-1)
  
N = int(input())
S = input()
count = 0
ans = 1
 
for i, s in enumerate(S):
  if ((s == "W") & (i%2 == 0)) or ((s == "B") & (i%2 == 1)):
    ans *= (i - (count*2))
    count += 1

other = N - count
if other != 0:
  ans *= (kai(other*2)//(2**other))
 
print((ans*kai(N))%(10**9 + 7))