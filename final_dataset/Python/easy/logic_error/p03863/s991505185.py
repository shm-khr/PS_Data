s = input()

flag = all(s[i] == s[i + 2] for i in range(len(s) - 2))
flag |= s[0] != s[-1] and len(s) % 2 == 0

if flag:
    print("Second")
else:
    print("First")
