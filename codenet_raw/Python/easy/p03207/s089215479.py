S = input()
if S[0] != 'A':
    print('WA')
    exit()
if S[2:].count('C') != 1:
    print('WA')
    exit()
for i in range(len(S)):
    if i in [0, 2]:
        if S[i] != S[i].upper():
            print('WA')
            exit()
        continue
    if S[i] != S[i].lower():
        print('WA')
        exit()
print('AC')
