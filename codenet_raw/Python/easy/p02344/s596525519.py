import sys

def simplefindset(x,element,resultPos=0):
    if(x != element[x]):
        resultPos = simplefindset(element[x],element,resultPos)
    else:
        resultPos = x
    return resultPos

def findset(x,element,weight,resultPos=0,sumW=0):
    if(x != element[x]):
        resultPos,sumW = findset(element[x],element,weight,resultPos,sumW)
    else:
        resultPos = x
    sumW += weight[x]
    return resultPos,sumW

def union(x,y,element,weight,w):
    x,wx = findset(x,element,weight)
    y,wy = findset(y,element,weight)
    link(x,wx,y,wy,w,element)

def link(x,wx,y,wy,z,element):
    element[x] = y
    weight[x] = z - (wx+wy)

n,q = map(int, input().split());

element = [i for i in range(n)]
weight = [0 for i in range(n)]

for i in range(q):
    inp = map(int, input().split());
    inp = list(inp)    
    if(inp[0] == 0):
        x,y,w = inp[1],inp[2],inp[3]
        union(x,y,element,weight,w)
    else:
        x,y = inp[1],inp[2]
        if(simplefindset(x,element) == simplefindset(y,element)):
            x,wx = findset(x,element,weight)
            y,wy = findset(y,element,weight)
            print(wx-wy)
        else:
            print('?')
