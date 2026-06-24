
N = input().split()
A = input().split()
intA = []
if int(N[0]) >= 2 and int(N[0]) <= 200000:
	intN = int(N[0])

for i in range(intN):
  if int(A[i]) >= 1 and int(A[i]) <= 2020202020:
  	intA.append(int(A[i]))

countA = len(intA)
sabun = []
right = 0
left = 0

for i in range(len(intA) - 1):
  left += intA[i]
  for k in range(len(intA) - 1, i, -1):
    right += intA[k]
  sabun.append(abs(right - left))
  right = 0
print(min(sabun))