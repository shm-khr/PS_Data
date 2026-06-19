import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)

H, W = map(int, input().split())

if H > W:
    H, W = W, H

if H%3 == 0 or W%3 == 0:
    print(0)
elif H%2 == 0:
    H_div = H//2
    W_div = round(W/3)
    print(abs(H_div*(W-W_div) - H*W_div))
else:
    H_div = round(H/3)
    W_div = W//2
    H_div2 = H//2
    W_div2 = round(W/3)
    print(min(abs(H_div*W - (H-H_div)*W_div), abs(W_div*H - (W-W_div)*H_div)))