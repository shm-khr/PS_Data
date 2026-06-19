Q = int(input())

def oldChain(index, blockLength):
    if index%blockLength==0:
        return "B"
    else:
        return "A"

def newChain(index, blockLength):
    if index%blockLength==0:
        return "A"
    else:
        return "B"

def residueChain(index, residueAyy):
    if index>residueAyy:
        return "B"
    else:
        return "A"

for i in range(Q):
    line = [int(i) for i in input().split()]
    A = line[0]
    B = line[1]
    C = line[2]
    D = line[3]
    maxLength = int((max(A, B)-1)/(min(A, B)+1))+1
    equalisers = A+B
    residueDifference = A-B
    if maxLength!=1:
        residueDifference = abs(A-B)%(maxLength - 1)
        residueDifference *= (A>B)-(A<B)
        equalisers = int(abs(A-B)/(maxLength-1))*(maxLength+1)
    neutral = int((A+B-equalisers)/(2*maxLength+2))
    residue = (A+B-equalisers)%(2*maxLength+2)
    print(-34%6)
    intersectionStart = (neutral*(maxLength+1)+equalisers)*(A>=B)+(A+B-equalisers-neutral*(maxLength+1)-residue)*(A<B)
    if residue>maxLength+1:
        if residueDifference>=0:
            intersectionStart += (maxLength + 1)
            residueDifference -= (maxLength - 1)
        else:
            residueDifference += (maxLength - 1)
        residue -= (maxLength + 1)
    residueAyy = int((residue+residueDifference)/2)
    ans = [0 for i in range(D-C+1)]
    for i in range(C,D+1):
        if i<intersectionStart+1:
            ans[i-C]=oldChain(i,maxLength+1)
        elif i>intersectionStart+residue:
            ans[i-C]=newChain(A+B-i+1,maxLength+1)
        else:
            ans[i-C]=residueChain(i-intersectionStart,residueAyy)
    print("".join(ans)+"\n")
