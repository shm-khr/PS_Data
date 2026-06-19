s = input()
if len(s) %2 == 0 and s[0] == s[-1] or s[0] != s[-1] and len(s) %2 != 0:
    print("First")
else:
    print("Second")