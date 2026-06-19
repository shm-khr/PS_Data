S=input()
N=len(S)
X=(int(N)-1)/2
Y=(int(N)+3)/2
T=S(range(1,X))
U=S(range(Y,N))
if str(S)==str(S)[::-1] and str(T)==str(T)[::-1] and str(U)==str(U)[::-1]:
  print("Yes")
else:
  print("No")
  