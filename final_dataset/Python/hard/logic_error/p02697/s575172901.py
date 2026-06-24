import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    n, m = map(int, readline().split())
    if m % 2 == 0:
        rem = m
        for i in range(m // 2):
            print(1 + i, m - i)
            rem -= 1
            if rem == 0:
                return
        for i in range(n):
            print(m + 1 + i, n - i)
            rem -= 1
            if rem == 0:
                return
    else:
        rem = m
        for i in range((m - 1) // 2):
            print(1 + i, m - i)
            rem -= 1
            if rem == 0:
                return
        for i in range(n):
            print(m + 1 + i, n - i)
            rem -= 1
            if rem == 0:
                return


if __name__ == '__main__':
    main()
