from math import ceil


def solve(a, b, c, d):
    l_max = int(ceil(max(a, b) / (min(a, b) + 1)))
    # lB-A = (l^2-1)r2 + l^2 - m
    tmp = l_max * b - a - l_max ** 2
    div = l_max ** 2 - 1
    if not div:
        # AB交互
        if b > a:
            c += 1
            d += 1
        e = d - c + 1
        base = 'AB' if c & 1 else 'BA'
        ans = base * (e // 2)
        if e & 1:
            ans += base[0]
        return ans
    r2 = ceil(tmp / (l_max ** 2 - 1))
    m = r2 * (l_max ** 2 - 1) - tmp
    r1 = b - l_max * (r2 + 1)
    border = (l_max + 1) * r1 + m
    if d <= border:
        sr, sp = divmod(c - 1, l_max + 1)
        er, ep = divmod(d, l_max + 1)
        base = 'A' * l_max + 'B'
        btwn = max(0, er - sr - 1)
        ans = base[sp:] + base * btwn + base[:ep]
        if m == 0:
            if d == border:
                if len(ans) > 1:
                    ans = ans[:-2] + 'BA'
                else:
                    ans = 'A'
            elif d == border - 1:
                ans = ans[:-1] + 'B'
        return ans
    elif c > border:
        c -= border
        d -= border
        sr, sp = divmod(c - 1, l_max + 1)
        er, ep = divmod(d, l_max + 1)
        base = 'B' * l_max + 'A'
        btwn = max(0, er - sr - 1)
        return base[sp:] + base * btwn + base[:ep]
    d -= border
    sr, sp = divmod(c - 1, l_max + 1)
    er, ep = divmod(d, l_max + 1)
    base1 = 'A' * l_max + 'B'
    base2 = 'B' * l_max + 'A'
    ans = base1[sp:] + base1 * (r1 - sr - 1) + 'A' * m + base2 * er + base2[:ep]
    if m == 0:
        if c == border:
            ans = 'A' + ans[1:]
        else:
            ans = ans[:border - c - 1] + 'BA' + ans[border - c + 1:]
    return ans


q = int(input())
buf = [solve(*map(int, input().split())) for _ in range(q)]
print('\n'.join(buf))
