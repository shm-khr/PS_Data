# -*- coding: utf-8 -*-
import itertools


def filter_name(n):
    return n.startswith("M") or n.startswith("A") or n.startswith("R") or n.startswith("C") or n.startswith("H")


def filter_ok(l):
    dic = {'M': 0, 'A': 0, 'R': 0, 'C': 0, 'H': 0}
    for i in l:
        dic[i[0:1]] += 1
    for num in dic.values():
        if num >= 2:
            return False
    return True


n = input()
a = []
for i in range(n):
    a.append(raw_input())

r = filter(filter_name, a)
c = list(itertools.combinations(r, 3))
r = filter(filter_ok, c)
print len(r)
