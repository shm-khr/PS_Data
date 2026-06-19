def main():
    import sys
    import bisect


    n = int(input())
    a = list(map(int, sys.stdin.readline().split()))

    b = list(accumulate(a))
    l = b[-1]
    i = bisect.bisect(b, l // 2)
    ans = min(abs(l - 2 * b[i - 1]), abs(l - 2 * b[i]))
    print(ans)


if __name__ == '__main__':
    main()
