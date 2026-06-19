a,b,c,d = map(float,input().split())
a = complex(a,b)
b = complex(c,d)
q=int(input())
for i in range(q):
  x,y=map(int,input().split())
  c=complex(x,y)
  q = b-a
  c -= a
  p = a+q*(c/q).conjugate()
  print("{:.10} {:.10}".format(p.real, p.imag))

