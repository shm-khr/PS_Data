import sys
from fractions import gcd
from operator import itemgetter


class Bit:
    def __init__(self, n):
        self.size = n
        self.tree = [0] * (n + 1)
        self.depth = n.bit_length()

    def sum(self, i):
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s

    def add(self, i, x):
        while i <= self.size:
            self.tree[i] += x
            i += i & -i

    def lower_bound(self, x):
        sum = 0
        pos = 0
        for i in range(self.depth, -1, -1):
            k = pos + (1 << i)
            if k <= self.size and sum + self.tree[k] < x:
                sum += self.tree[k]
                pos += 1 << i
        return pos + 1, sum


def solve(n, dec, inc):
    # dec: 距離を縮められる平均台
    # inc: 離される平均台
    if len(dec) == 0:
        print(0, 1)
        return

    # 基本は縮められる平均台を左に、離される平均台を右に。
    # 右突入までに追いつけるかが勝負。
    # ただし、離されてもすぬけくんの所要時間が短いものは、
    # りんごさんの初期位置の確率UPのため左に持っていく価値があるものもある

    _rng_list = rng_list
    _rng_dict = rng_dict

    dec.sort(key=itemgetter(1))
    inc.sort()

    dec_snk, dec_rng = zip(*dec)
    inc_snk, inc_rng = zip(*inc)
    dec_snk_sum = sum(dec_snk)

    ld = len(dec)
    lr = len(_rng_list)

    bit = Bit(lr)
    for b in dec_rng:
        bit.add(_rng_dict[b] + 1, b)

    # 左に inc の平均台が1つも無い状態
    j, full = bit.lower_bound(dec_snk_sum)
    best_denominator = 1
    best_numerator = ld - (j - 1)
    if j <= lr:
        best_denominator = _rng_list[j - 1]
        best_numerator = best_numerator * best_denominator - (dec_snk_sum - full)
    best = best_numerator / best_denominator

    for i in range(len(inc)):
        # inc の i 番目の平均台を左で使う
        dec_snk_sum += inc_snk[i]
        b = inc_rng[i]
        bit.add(_rng_dict[b] + 1, b)
        j, full = bit.lower_bound(dec_snk_sum)
        denominator = 1
        numerator = ld + (i + 1) - (j - 1)
        if j <= lr:
            denominator = _rng_list[j - 1]
            numerator = numerator * denominator - (dec_snk_sum - full)
        tmp_best = numerator / denominator

        if best < tmp_best:
            best = tmp_best
            best_denominator = denominator
            best_numerator = numerator

    best_denominator *= n
    g = gcd(best_numerator, best_denominator)
    print(best_numerator // g, best_denominator // g)


n = int(input())
dec = []
inc = []
compress = set()

for line in sys.stdin:
    a, b = map(int, line.split())
    if a < b:
        dec.append((a, b))
    else:
        inc.append((a, b))
    compress.add(b)

rng_list = sorted(compress, reverse=True)
rng_dict = {b: i for i, b in enumerate(rng_list)}
# print(rng_list)
# print(rng_dict)

solve(n, dec, inc)
