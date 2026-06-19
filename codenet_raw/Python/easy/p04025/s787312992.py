import sys

rl = sys.stdin.readline


def solve():
    N = int(rl())
    a = list(map(int, rl().split()))
    
    sum_a = sum(a)
    t = sum_a // N if sum_a % N == 0 else sum_a // N + 1
    ans = sum((ai - t) ** 2 for ai in a)
    print(ans)


if __name__ == '__main__':
    solve()
