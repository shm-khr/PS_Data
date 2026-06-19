#
# AIZU ONLINE JUDGE: National Budget
# cf. http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0015&lang=jp
#

import sys


def to_list(n):
    l = list(n)
    ls = len(l)
    l = ['0'] * (80 - ls) + l
    l.reverse()
    return l


def add(a, b, c):
    x = a + b + c
    if x >= 10:
        y = x / 10
        x = x % 10
    else:
        y = 0
    return (x, y)


def str_add(a, b):
    s = a[0]
    k = a[1]
    i = int(b[0])
    j = int(b[1])
    (x, y) = add(i, j, k)
    return (s + str(x), y)


def str_format(s):
    l = list(s)
    l.reverse()
    s = ''.join(l)
    return s.lstrip('0')


def solv(a, b):
    la = to_list(a)
    lb = to_list(b)
    z = map((lambda x, y: (x, y)), la, lb)
    r = reduce((lambda a, b: str_add(a, b)), z, ('', 0))
    if r[1] > 0:
        return "overflow"
    else:
        result = str_format(r[0])
        return result


def make_pair(lis):
    ps = []
    while lis:
        a = lis.pop(0).rstrip("\r\n")
        b = lis.pop(0).rstrip("\r\n")
        ps.append((a, b))
    return ps



lines = sys.stdin.readlines()
lines.pop(0)
pairs = make_pair(lines)
for p in pairs:
    result = solv(p[0], p[1])
    print result