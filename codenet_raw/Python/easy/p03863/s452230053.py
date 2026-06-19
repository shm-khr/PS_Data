S = input()
N = len(S)

x = S[0]
y = S[1]
for i in range(2, N):
    if i % 2 == 0:
        if S[i] != x:
            break
    else:
        if S[i] != y:
            break
else:
    print("Second")
    exit()

if N % 2 == 0 and S[0]==S[-1]:
    print("First")
elif N % 2 == 0:
    print("Second")
else:
    print("First")
