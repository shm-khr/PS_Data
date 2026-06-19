if __name__ == '__main__':
    A, B, N = map(int, input().split())
    C = B - 1
    D = min(C, N)
    print((A*D) // B)