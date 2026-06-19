#!/usr/bin/env python3
# DSL_2_H: RMQ and RAQ
# Range Minimum Query and Range Add Query
# Lazy propagate segment tree

import sys


class SegmentTree:
    MAXV = 1000 * 10**5 + 1

    def __init__(self, n):
        size = 1
        while size < n:
            size *= 2
        self.size = 2*size - 1
        self.data = [0] * self.size
        self.lazy = [0] * self.size

    def add(self, lo, hi, v):
        def _add(r, i, j, lz):
            left, right = r*2 + 1, r*2 + 2
            if lazy[r]:
                lz += lazy[r]
                lazy[r] = 0

            if j < lo or i > hi:
                if lz:
                    data[r] += lz
                    if i < j:
                        lazy[left] += lz
                        lazy[right] += lz
            elif lo <= i and j <= hi:
                lz += v
                if lz:
                    data[r] += lz
                    if i < j:
                        lazy[left] += lz
                        lazy[right] += lz
            else:
                mid = (i + j) // 2
                lv = _add(left, i, mid, lz)
                rv = _add(right, mid+1, j, lz)

                if lv < rv:
                    data[r] = lv
                else:
                    data[r] = rv

            return data[r]

        lazy = self.lazy
        data = self.data
        _add(0, 0, self.size//2, 0)

    def min(self, lo, hi):
        def _min(r, i, j, lz):
            left, right = r*2 + 1, r*2 + 2
            if lazy[r]:
                lz += lazy[r]
                lazy[r] = 0
            if lz:
                data[r] += lz

            if j < lo or i > hi:
                if lz and i < j:
                    lazy[left] += lz
                    lazy[right] += lz
                return self.MAXV
            elif lo <= i and j <= hi:
                if lz and i < j:
                    lazy[left] += lz
                    lazy[right] += lz
                return data[r]
            else:
                mid = (i + j) // 2
                lv = _min(left, i, mid, lz)
                rv = _min(right, mid+1, j, lz)
                if lv < rv:
                    return lv
                else:
                    return rv

        lazy = self.lazy
        data = self.data
        return _min(0, 0, self.size//2, 0)


def run():
    n, q = [int(i) for i in input().split()]

    tree = SegmentTree(n)

    ret = []
    for line in sys.stdin:
        com, *args = line.split()
        if com == '0':
            s, t, x = map(int, args)
            tree.add(s, t, x)
        elif com == '1':
            s, t = map(int, args)
            ret.append(tree.min(s, t))

    sys.stdout.write("\n".join([str(i) for i in ret]))
    sys.stdout.write("\n")


if __name__ == '__main__':
    run()

