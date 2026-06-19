def dot(a, b):
  return a.real * b.real + a.imag * b.imag

def projection(s,p):
  base=b-a
  r=dot(p-a,base)/(abs(base)**2)
  return a+base*r

def reflect(s,p):
  return p+(projection(s,p)-p)*2

x0,y0,x1,y1 = map(float,input().split())
a = complex(x0,y0)
b = complex(x1,y1)
n=int(input())

for i in range(n):
  x,y=map(int,input().split())
  c=complex(x,y)
  p=reflect(a,c)
  print("{:.10} {:.10}".format(p.real, p.imag))
