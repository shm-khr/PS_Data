#!/usr/bin/env python
# -*- coding: utf-8 -*-

while True:
    n = int(raw_input())
    island = []
    if n == 0:
        break
    for i in range(n):
        g,b = map(int,input().split())
        island.append((g,b,b-g))
    sorted(island,key = lambda x:(x[2],[0],[1]))
    
    gem = 0
    for g,b,c in island:
        gem += g
        if b < gem:
            break
    else:
        print 'Yes'
        continue
    print 'No'
        