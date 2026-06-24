L, N = map(int, raw_input().split())
X = [input() for _ in range(N)]

def f(T):
  n = len(T)
  S = [0]*(2*n+1)
  for i in range(2*n):
    S[i+1] = S[i]+T[i%n]
  a = S[n-1]
  ans = 0
  for i in range(n-2):
    a += 2*(S[2*n-i*2-3]-S[n-i-1])
    a -= 2*(S[2*n-i-2]-S[2*n-i*2-2])
    a -= T[n-i-2]
    ans = max(ans, a)
  return ans

A = [X[0]]+[X[i+1]-X[i] for i in range(N-1)]+[L-X[-1]]
print max(f(A), f(A[::-1]))
