#!/usr/bin/env python
# -*- coding: utf-8 -*-

while True:
    n = int(raw_input())
    island = []
    if n == 0:
        break
    for i in range(n):
        g,b = map(int,raw_input().split())
        island.append((g,b,b-g))
    island = sorted(island,key = lambda x:(x[2],x[0],x[1]))
    
    gem = 0
    for g,b,c in island:
        gem += g
        if b < gem:
            break
    else:
        print 'Yes'
        continue
    print 'No'
        