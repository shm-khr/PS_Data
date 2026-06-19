from sys import stdin
import sys
import itertools as it

A, B, C = [int(x) for x in stdin.readline().rstrip().split()]
K = int(input())
if C > B and B > A:
    print("Yes")
    sys.exit()
for i in range(K):
    c1 = C*(2**i)
    b1 = B*(2**(K-i))
    if c1 > b1 and b1 > A:
        print("Yes")
        sys.exit()
print("No")
