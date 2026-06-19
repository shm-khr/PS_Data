S = str(input(""))
S.lower()
if S.endswith(('o', 'ch', 's', 'sh', 'x', 'z')):
    print(S+"es")
else:
    print(S+"s")