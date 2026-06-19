n=int(input())
m=list(range(1,n+1))
even=[]
odd=[]
for x in range (0,len(m)):
    if m!=0:
        if m[x] % 2 == 0:
            even.append(m[x])
        else:
            odd.append(m[x])

    output = [[a, b] for a in even
              for b in odd]
    print(output)
    