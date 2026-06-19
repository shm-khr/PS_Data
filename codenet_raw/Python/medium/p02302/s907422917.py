def cross(a, b):
    return a.real * b.imag - a.imag * b.real


def cross_point(c, d):
    l = d - c
    v1 = cross(lv, l)
    v2 = cross(lv, lt - c)
    return c + v2 / v1 * l


n = int(input())
points = [complex(*map(int, input().split())) for _ in range(n)]
point0 = points.pop(0)
points.append(point0)

q = int(input())
while q:
    x1, y1, x2, y2 = map(int, input().split())
    ls, lt = (x1 + 1j * y1, x2 + 1j * y2)
    lv = lt - ls

    area = 0
    prev = point0
    prev_flag = cross(lv, prev - ls) >= 0
    cp1, cp2 = None, None
    for p in points:
        curr_flag = cross(lv, p - ls) >= 0
        if prev_flag and curr_flag:
            area += cross(prev, p)
        elif prev_flag != curr_flag:
            cp = cross_point(prev, p)
            if prev_flag:
                area += cross(prev, cp)
                cp1 = cp
            else:
                area += cross(cp, p)
                cp2 = cp
        prev, prev_flag = p, curr_flag
    area += cross(cp1, cp2)
    print(area / 2)
    q -= 1