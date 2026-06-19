
s = raw_input()
cnt = 0
last = s[0]
 
for c in s[1:]:
    if c != last:
        cnt = cnt+1
    last = c
print cnt+1