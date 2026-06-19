s=list(input())
N=len(s)
tmp=s[0:int((N-1)/2)+1]
tmp_rev=tmp[::-1]

tmp2=s[int((N+3)/2)-1:]
tmp2_rev=tmp2[::-1]

if tmp==tmp_rev and tmp2==tmp2_rev:
  print("Yes")
else:
  print("No")