import sys


def solve():
    input = sys.stdin.readline
    mod = 10 ** 9 + 7
    n, k = list(map(int, input().rstrip('\n').split()))
    ls = list(map(lambda x: int(x) % k, input().rstrip('\n').split()))
    cnt = 0
    print(ls)
    for i in range(min(n, k)):
        t = sum(ls[:i+1])
        if t % k == i + 1:
            cnt += 1
            print(i, j)
        for j in range(i+1, n):
            t -= ls[j-i-1]
            t += ls[j]
            if t % k == i + 1:
                cnt += 1
                print(i, j)
            elif t % k > k:
                break
    print(cnt)


if __name__ == '__main__':
    solve()
