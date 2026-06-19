N = int(input())
num = list()

for i in range (0,N-1):
  d = int (input())
  num.append(d)
  
print(len(set(num)))