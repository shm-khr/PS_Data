from sys import stdin
readline = stdin.readline


from enum import Enum
direction = Enum('direction', 'CCW CW CAB ABC ACB')


class vector:
    def cross(a, b):
        return a.real * b.imag - a.imag * b.real

    def dot(a, b):
        return a.real * b.real + a.imag * b.imag

    def ccw(a, b, c):
        b -= a
        c -= a
        if vector.cross(b, c) > 0:
            return direction.CCW
        if vector.cross(b, c) < 0:
            return direction.CW
        if vector.dot(b, c) < 0:
            return direction.CAB
        if vector.abs(b) < abs(c):
            return direction.ABC
        return direction.ACB

    def polygon(p):
        if len(p) < 3:
            return 0
        return 0.5 * sum(vector.cross(p[i - 1], p[i]) for i in range(len(p)))

    def intersection(p1, p2, p3, p4):
        a1 = p4 - p2
        b1 = p2 - p3
        b2 = p1 - p2
        s1 = vector.cross(a1, b2) / 2
        s2 = vector.cross(a1, b1) / 2
        c1 = p1 + (p3 - p1) * s1 / (s1 + s2)
        return c1


def main():
    n = int(readline())
    p = [map(float, readline().split()) for _ in range(n)]
    p = [x + y * 1j for x, y in p]
    q = int(readline())

    for _ in range(q):
        p1x, p1y, p2x, p2y = map(float, readline().split())
        p1, p2 = p1x + p1y * 1j, p2x + p2y * 1j

        pre_tmp = vector.ccw(p[-1], p1, p2)
        left = []
        for i in range(len(p)):
            tmp = vector.ccw(p[i], p1, p2)
            if pre_tmp != tmp and all(i in (direction.CW, direction.CCW) for i in (pre_tmp, tmp)):
                c1 = vector.intersection(p1, p[i - 1], p2, p[i])
                left.append(c1)
            if tmp != direction.CW:
                left.append(p[i])

            pre_tmp = tmp
        print('{:.6f}'.format(vector.polygon(left)))
main()