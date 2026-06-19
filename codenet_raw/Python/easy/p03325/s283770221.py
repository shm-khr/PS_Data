N = int(input())
a = [int(i) for i in input().split()]

counter = 0
for i in range(N):
    A = a[i]
    while 2 * 2 <= A:
        while A % 2 == 0:
            A /= 2
            counter += 1
        break
print(int(counter))
