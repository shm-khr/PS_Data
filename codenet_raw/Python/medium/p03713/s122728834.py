h, w = map(int, input().split())

if h % 3 == 0 or w % 3 == 0:
    print(0)
else:
    area1 = min(h, w) // 2
    area2 = (max(h, w) - 1) * min(h, w)
    area3 = -(-min(h, w) // 2)
    ans = max(area1, area2, area3) - min(area1, area2, area3)
    for i in range(1, max(h, w) - 1):
        area1 += min(h, w) // 2
        area2 -= min(h, w)
        area3 += -(-min(h, w) // 2)
        ans = min(ans, max(area1, area2, area3) - min(area1, area2, area3))
    print(ans)
