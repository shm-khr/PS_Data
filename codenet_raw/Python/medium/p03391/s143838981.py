import sys

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

def main():
    n=int(input())
    min_b=10**10
    s=0
    for _ in range(n):
        a,b=map(int,input().split())
        s+=b
        if a>=b:
            min_b=min(min_b,b)
    print(s-min_b)

main()