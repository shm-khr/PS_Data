import sys


def solve(k, aaa):
    if k == 1:
        return [1] * aaa[0]

    min_a = min(aaa)
    max_a = max(aaa)
    if min_a * 2 < max_a:
        return [-1]

    ans = []
    while True:
        min_a = min(aaa)
        max_a1 = max(aaa[1:])
        max_a = max(aaa[0], max_a1)

        if min_a <= 0:
            assert max_a == 0
            break

        if (min_a - 1) * 2 < max_a - 1:
            must_use = [i for i, a in enumerate(aaa) if a - 1 > (min_a - 1) * 2]
            next_max = max_a - 2
        elif (aaa[0] - 2) * 2 >= max_a1 - 1:
            must_use = []
            next_max = max(aaa[0] - 2, max_a1 - 1)
        else:
            ans.extend(range(1, k + 1))
            for i in range(k):
                aaa[i] -= 1
            continue

        can_use = []
        cant_use = []

        for i in range(k):
            if i in must_use:
                pass
            elif (aaa[i] - 2) * 2 >= next_max:
                can_use.append(i)
            else:
                cant_use.append(i)

        double = []
        if len(must_use) == 0:
            double.append(can_use[0] + 1)
        else:
            max_use = must_use[-1]
            use = must_use + can_use
            use.sort()
            double = [i + 1 for i in use if i <= max_use]
        single = [i for i in range(1, k + 1) if i not in double]

        for i in double:
            aaa[i - 1] -= 2
        for i in single:
            aaa[i - 1] -= 1

        ans.extend(double)
        ans.extend(single)
        ans.extend(double)

    return ans


k, *aaa = map(int, sys.stdin.buffer.read().split())
print(*solve(k, aaa))
