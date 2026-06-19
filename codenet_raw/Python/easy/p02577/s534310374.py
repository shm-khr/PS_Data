N = int(input())
i = 0
while(N >= 1):
    i += N % 10
    N = int(N/10)
if (i % 9 == 0):
    print("Yes")
else:
    print("No")