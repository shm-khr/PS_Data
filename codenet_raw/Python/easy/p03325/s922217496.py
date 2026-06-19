num = int(input())
flag_list = [int(i) for i in input().split()]


ans = 0
cont_game = True

while cont_game:
    no_change = 0
    for i in range(num):
        if flag_list[i] % 2 == 0:
            flag_list[i] //= 2
            break
        else:
            no_change += 1
            pass

    if no_change == num:
        break
    ans += 1

print(ans)