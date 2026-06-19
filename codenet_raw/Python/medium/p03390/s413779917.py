# D
import math
Q = int(input())
A_list = []
B_list = []
for _ in range(Q):
    A, B = map(int, input().split())
    A_list.append(min(A, B))
    B_list.append(max(A, B))
    
for i in range(Q):
    A = A_list[i]
    B = B_list[i]
        
    if A == B:
        print(A+B-2)
        continue
        
    R = int(math.sqrt(A*B-1))
    Q = (A*B-1) // R
    
    if Q <= R+1:
        add = min(Q - A - 1, B - R - 1)    
    elif (Q - R)**2 - 4*(A*B-Q*R) > 0:
        add = int(((Q - R) - math.sqrt((Q - R)**2 - 4*(A*B-Q*R))) / 2)
        if (R + add)*(Q-add) == A*B:
            add -= 1
    else:
        add = 0
    print((A-1) + R + add)
    