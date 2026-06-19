"""AtCoder"""

import sys
input = sys.stdin.readline

N = int(input())

if N % 2 == 0:
    print(int(N/2)*int(N/2))
else:
    print(int(N/2)*int(N/2+1))
