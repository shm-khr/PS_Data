from collections import deque

def main():
    H, W, K = map(int, input().split())
    A = [input() for _ in range(H)]
    s = None
    for i in range(H):
        for j in range(W):
            if A[i][j] == "S":
                s = (i, j)
    q = deque()
    q.append((s[0], s[1], K))
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    visited = set()
    dst = float("inf")
    while(len(q)):
        i, j, m = q.popleft()
        dst = min([i, j, H-1-i, W-1-j])
        if m == 0:
            continue
        for d in directions:
            ni = i + d[0]
            nj = j + d[1]
            if 0 <= ni < H and 0 <= nj < W:
                if A[ni][nj] == "." and (ni, nj) not in visited:
                    q.append((ni, nj, m-1))
                    visited.add((ni, nj))
    ans = 1 - (-dst//K)
    print(ans)

        


if __name__ == "__main__":
    main()
