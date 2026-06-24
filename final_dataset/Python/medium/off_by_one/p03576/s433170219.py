# -*- coding: utf-8 -*-

N, K = map(int, input().split())
P = [tuple(map(int, input().split())) for _ in range(N)]
answers = {}

for s in P:
    for t in P:
        for r in P:
            for u in P:
                xs = [s[0], t[0], r[0], u[0]]
                ys = [s[1], t[1], r[1], u[1]]
                xs.sort(reverse=True)
                ys.sort(reverse=True)
                size = abs(xs[0] - xs[-1]) * abs(ys[0] - ys[-1])
                num_point = 0
                for v in P:
                    if xs[-1] <= v[0] <= xs[0] and ys[-1] <= v[1] <= ys[0]:
                        num_point += 1
                if num_point >= K:
                    answers[num_point] = size
for k, v in sorted(answers.items()):
    print(v)
    break
