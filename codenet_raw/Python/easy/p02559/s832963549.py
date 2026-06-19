code = r"""
# distutils: language=c++
# distutils: include_dirs=/home/contestant/.local/lib/python3.8/site-packages/numpy/core/include
# cython: boundscheck=False
# cython: wraparound=False
from libcpp cimport bool
from libcpp.vector cimport vector
cdef extern from "/opt/atcoder-stl/atcoder/fenwicktree.hpp" namespace "atcoder":
    cdef cppclass fenwick_tree[T]:
        fenwick_tree(int)
        void add(int, T)
        T sum(int, int)

from libc.stdio cimport scanf, printf
cdef int i
cdef int N, Q
cdef int t, u, v
scanf("%d%d", &N, &Q)
cdef fenwick_tree[long long] *ft = new fenwick_tree[long long](N);
for i in range(Q):
    scanf("%d%d%d", &t, &u, &v)
    if t == 0:
        ft.add(u, <long long> v)
    else:
        printf("%lld\n", ft.sum(u, v))
"""
import os
import sys
if sys.argv[-1] == 'ONLINE_JUDGE':
    open('solve.pyx', 'w').write(code)
    os.system('cythonize -i -3 -b solve.pyx')
import solve
