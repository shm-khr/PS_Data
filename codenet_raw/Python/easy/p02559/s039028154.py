library = """
# distutils: language=c++
# distutils: include_dirs=[/home/contestant/.local/lib/python3.8/site-packages/numpy/core/include, /opt/atcoder-stl]
# cython: boundscheck=False
# cython: wraparound=False
from libcpp cimport bool
cdef extern from "/opt/atcoder-stl/atcoder/dsu.hpp" namespace "atcoder":
    cdef cppclass dsu:
        dsu(int n)
        int merge(int a, int b)
        bool same(int a, int b)
        int leader(int a)
        int size(int a)
cdef extern from "/opt/atcoder-stl/atcoder/fenwicktree.hpp" namespace "atcoder":
    cdef cppclass fenwick_tree[T]:
        fenwick_tree() except +
        fenwick_tree(int n) except +
        void add(int p, T x)
        T sum(int l, int r)
cdef class DSU:
    cdef dsu *_thisptr
    def __cinit__(self, int n):
        self._thisptr = new dsu(n)
    def __dealloc__(self):
        del self._thisptr
    cpdef int merge(self, int a, int b):
        return self._thisptr.merge(a, b)
    cpdef bool same(self, int a, int b):
        return self._thisptr.same(a, b)
    cpdef int leader(self, int a):
        return self._thisptr.leader(a)
    cpdef int size(self, int a):
        return self._thisptr.size(a)
cdef class BIT:
    cdef fenwick_tree[long] *_thisptr
    def __cinit__(self, int n = 0):
        if n == 0:
            self._thisptr = new fenwick_tree[long]()
        else:
            self._thisptr = new fenwick_tree[long](n)  
    def __dealloc__(self):
        del self._thisptr
    cpdef void add(self, int p, long x):
        self._thisptr.add(p, x)
    cpdef long sum(self, int l, int r):
        return self._thisptr.sum(l, r)
"""
import os,sys
if True or sys.argv[-1] == 'ONLINE_JUDGE':
    open('atcoder.pyx','w').write(library)
    os.system('cythonize -i -3 -b atcoder.pyx')
 
# ↑ここまでライブラリ↓ここから解法
 
import sys
import atcoder
input = sys.stdin.buffer.readline
n, q = map(int, input().split())
dummy = atcoder.BIT()
bit = atcoder.BIT(n)
*map(bit.add, range(n), map(int, input().split())),
res = []
for i in range(q):
    t, u, v = map(int, input().split())
    if t: res.append(bit.sum(u, v))
    else: bit.add(u, v)
print('\n'.join(map(str, res)))