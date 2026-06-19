def manha(p1, p2):
    return abs(p1[0]-p2[0]) + abs(p1[1] - p2[1])

N = int(input())
x = [0] * N
y = [0] * N

for i in range(N):
    x_, y_ = map(int, input().split())
    x[i], y[i] = x_, y_

MAX = 0
MIN = 10 ** 10
x_min = (MIN, 0)
x_max = (MAX, 0)
y_min = (0, MIN)
y_max = (0, MAX)

for i in range(N):
    tmp_x = x[i]
    tmp_y = y[i]

    if tmp_x < x_min[0]:
        x_min = (tmp_x, tmp_y)

    if x_max[0] < tmp_x:
        x_max = (tmp_x, tmp_y)

    if tmp_y < y_min[1]:
        y_min = (tmp_x, tmp_y)

    if y_max[1] < tmp_y:
        y_max = (tmp_x, tmp_y)

result = max(manha(x_min, y_min), manha(x_min, x_max), manha(x_min, y_max), manha(y_min, y_max), manha(y_min, x_max), manha(y_max, x_max))
print(result)
