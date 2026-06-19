def solve():
    n = int(input())
    arr = [0] + [int(i) for i in input().split()]
    arrset = set(arr)

    if max(arrset) == 0:
        print(0)
        return
    
    ans = 12
    for i in arrset:
        for j in arrset:
            i24 = 24 - i
            j24 = 24 - j
            t = [e for e in [abs(i - j), abs(i24 - j), abs(i - j24), abs(i24 - j24)] if e > 0]
            if t:
                ans = min(ans, min(t))
    print(ans)


if __name__ == "__main__":
    solve()