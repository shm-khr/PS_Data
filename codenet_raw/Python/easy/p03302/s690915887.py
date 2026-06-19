string = input()
num = int(input())
if num == 0:
    print(string)
else:
    count=1
    out=string[0]

    for i,s in zip([i for i in range(len(string))],string):
        if i != 0:
            if i%num == 0:
                out=out+string[i]
    print(out)
