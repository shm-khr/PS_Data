s = input()
n = len(s)

def isKaibun(s, length):
    flag = True
    if len(s) < 3:
        return False
    for i in range(int((length-1)/2)):
        if s[i] != s[length-1-i]:
            flag = False
            break
    return flag



orta = int((n+1)/2)-1

if isKaibun(s, n) and isKaibun(s[:orta], orta) and isKaibun(s[orta+1:], orta):
    print("Yes")
else:
    print("No")