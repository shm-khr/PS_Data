s=input()

Aindex = s.find("A")
Zindex = -1

for index,character in enumerate(s[Aindex:]):
    if character == "Z":
        Zindex = index

print(len(s[Aindex:Zindex+1]))