import sys
sys.setrecursionlimit(10**6)

debug_mode = True if len(sys.argv) > 1 and sys.argv[1] == "-d" else False
if debug_mode:
    import os
    infile = open(os.path.basename(__file__).replace(".py", ".in"))

    def input():
        return infile.readline()


# ==============================================================

from math import sqrt


def main():
    Q = int(input().strip())
    AB = [list(map(int, input().strip().split())) for _ in range(Q)]
    for a, b in AB:
        score = a * b
        root = sqrt(score)
        pivot = int(root)
        cnt = 2 * (pivot - 1) if pivot == root else 2 * (pivot - 1) + 1
        print(cnt)


main()

# ==============================================================

if debug_mode:
    infile.close()
