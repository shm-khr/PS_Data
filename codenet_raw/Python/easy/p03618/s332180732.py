a=raw_input()
l=len(a)
n=0
for i in range(l):
    for j in range(min(i,l-i-1)+1):
        if a[i-j]==a[i+j]:
            n+=1
        else:
            break
for i in range(l-1):
    for j in range(min(i,l-i-2)+1):
        if a[i-j]==a[i+j+1]:
            n+=1
        else:
            break
print l*(l+1)/2-n+1