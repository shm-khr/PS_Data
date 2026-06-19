#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
sys.setrecursionlimit(10**7)
from pprint import pprint as pp
from pprint import pformat as pf
# @pysnooper.snoop()
#import pysnooper # debug

import math
#from sortedcontainers import SortedList, SortedDict, SortedSet # no in atcoder
import bisect

class Graph:

    def __init__(self, size):
        self.size = size
        self.vertices = [0] * size
        self.edges = [None] * size
        for i in range(size):
            self.edges[i] = []

    def add_edge(self, frm, to):
        self.edges[frm].append(to)
        self.edges[to].append(frm)

    def get_connect(self, v):
        return self.edges[v]

def calc(value):
    return value * (value + 1) // 2



def solve(graph, color, stack):
    ans = calc(graph.size)
    stack_key = 0
    stack[stack_key] = 0
    #print('stack') # debug
    #print(stack) # debug
    def dfs(v, parent):
        nonlocal ans, stack, stack_key
        #print('v', v) # debug
        if graph.vertices[v] == color:
            stack_key += 1
            stack[stack_key] = 0
        else:
            stack[stack_key] += 1
        for to in graph.edges[v]:
            if to == parent:
                continue
            dfs(to, v)
            if graph.vertices[v] == color:
                ans -= calc(stack[stack_key])
                stack[stack_key] = 0
        if graph.vertices[v] == color:
            stack_key -= 1
    dfs(0, -1)
    ans -= calc(stack[stack_key])
    return ans





if __name__ == '__main__':
    n = int(input())
    graph = Graph(n)
    graph.vertices = list(map(int, input().split()))
    for i in range(n - 1):
        frm, to = list(map(int, input().split()))
        frm -= 1
        to -= 1
        graph.add_edge(frm, to)

    stack = [None] * (graph.size + 1)
    for i in range(1, n + 1):
        ans = solve(graph, i, stack)
        print(ans)

    #print('\33[32m' + 'end' + '\033[0m') # debug
