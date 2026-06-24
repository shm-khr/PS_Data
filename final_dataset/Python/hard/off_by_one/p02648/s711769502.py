import sys


def main():
    input = sys.stdin.readline
    n = int(input())
    vw = [list(map(int, input().split())) for _ in range(n)]

    n2 = max(1, min(n, int(n ** 0.5)))

    ma = 10 ** 5 + 1
    tab = [[0] * ma for _ in range(n2)]
    for i in range(vw[0][1], ma):
        tab[0][i] = vw[0][0]

    # for i in range(1, n2):
    #     j = (i - 1) // 2
    #     l = 0
    #     aa, bb = vw[i]
    #     a = tab[j]
    #     for k in range(bb):
    #         tab[i][k] = a[k]
    #     for k in range(bb, ma):
    #         l = max((l, a[k - bb] + aa, a[k]))
    #         tab[i][k] = l

    q = int(input())
    for _ in range(q):
        u, l = map(int, input().split())
        u -= 1
        if u < n2:
            print(tab[u][l])
        else:
            a = [(0, 0)]
            while u >= n2:
                for i in a[:]:
                    if i[0] + vw[u][1] <= l:
                        a.append((i[0] + vw[u][1], i[1] + vw[u][0]))
                u = (u - 1) // 2
            ans = 0
            b = tab[u]
            for i, j in a:
                ans = max(ans, b[l - i] + j)
            print(ans)


if __name__ == "__main__":
    main()
