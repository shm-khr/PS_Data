A, B, C = map(int, input().split())
K = int(input())

while K > 0:
    if B < A:
        B *= 2
    if C < B:
        C *= 2
    K -= 1
if B > A and C > B:
    print('yes')
else:
    print('no')
