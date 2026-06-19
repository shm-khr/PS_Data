# -*- coding: utf-8 -*-
"""
Created on Sat May  7 22:31:12 2016

@author: kt
"""
def gcd(a,b): #?????§??¬?´???°???????????°??????
    r=0
    while True:
       r=a%b
       if r==0:
           break
       a=b
       b=r
    return b


a, b = map(int, input().split(" "))
g=gcd(a,b)
a=a/g
b=b/g
c=0
x1=1
x2=0
z1=a
y1=0
y2=1
z2=b
q=0

while True:
    if z2==1:
        break    
    q = (z1 - (z1 % z2)) / z2
    x3=(x1-q*x2)
    y3=(y1-q*y2)
    z3=z1-q*z2
    x1=x2
    x2=x3
    y1=y2
    y2=y3
    z1=z2
    z2=z3
   
if x3>y3:
    temp=y3
    y3=x3
    x3=temp
print ("%d %d" % (int(x3), int(y3)))