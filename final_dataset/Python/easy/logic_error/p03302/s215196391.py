string = input()
num = int(input())
if num == 0:
    print(string)
else:
    out=string[0]
    for i in [i for i in range(len(string))]:
        if i != 0:
            if i%num == 0:
                out=out+string[i]
    print(out)
