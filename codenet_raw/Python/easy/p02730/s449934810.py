def f(x):
  return x==x[::-1]
S=str(input())
N=len(S)
S1=S[:(N-3)/2]
S2=S[(N+1)/2:]
if f(S) and f(S1) and f(S2):
  print('Yes')
else:
  print('No')
  