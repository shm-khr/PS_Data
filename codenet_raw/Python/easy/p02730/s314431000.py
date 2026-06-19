from fractions import gcd
# from datetime import date, timedelta
# from heapq import *
import heapq
import math
from collections import defaultdict, Counter, deque
from bisect import *
import itertools
import fractions
import sys
sys.setrecursionlimit(10 ** 7)
MOD = 10 ** 9 + 7
# input = sys.stdin.readline


def make_divisors(n):
    divisors = []
    for i in range(1, int(n**0.5)+1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n//i)

    divisors.sort()
    return divisors

import random
def main():
    s = list(input())
    n = len(s)
    if n == 3:
        if s[0] == s[2]:
            print("Yes")
        else:
            print("No")
        exit()
    
    a = s[:(n - 1) // 2]
    b = s[(n + 3) // 2-1:]
    print(a,b)
    for i in range(len(a) // 2):
        if (a[i] != a[len(a) - 1 - i]):
            print("No")
            exit()


    for i in range(len(b) // 2):
        if (b[i] != b[len(b) - 1 - i]):
            print("No")
            exit()
    print("Yes")

if __name__ == '__main__':
    main()
