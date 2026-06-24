import numpy as np


def main():
    n = int(input())
    a = [int(x) for x in input().split()]

    best, solution = int(-1e9), []
    for p in range(2):
        c = a.copy()
        indexes = list(range(p, n, 2))

        maks = max([c[i] for i in indexes])
        pick = next((i for i in indexes if c[i] == maks), None)

        if pick is None:
            continue

        chosen = set([pick] if maks <= 0 else [i for i in range(p, n, 2) if c[i] > 0])
        tot, res = sum([c[i] for i in chosen]), []

        for i in reversed(range(n)):
            if i not in chosen:
                if i == 0 or i + 1 == len(c):
                    res += [i]
                    del c[i]
                else:
                    if ((i - 1) in chosen) == ((i + 1) in chosen):
                        res += [i]
                        c[i - 1] += c[i + 1]
                        del c[i + 1], c[i]

        if tot > best:
            best, solution = tot, np.array(res) + 1

    print(best, len(solution), *solution, sep='\n')


if __name__ == '__main__':
    main()
