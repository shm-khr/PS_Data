n = int(input())
A = [int(x) for x in input().split() 
     if int(x) % 2 == 1 or int(x) % 6 == 0 or int(x) % 10 == 0 ]
if len(A) == N:
    print("APPROVED")
else:
    print("DENIED")