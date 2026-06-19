def resolve():
    '''
    code here
    '''
    num_S, num_c  = [int(item) for item in input().split()]

    delta = num_c - num_S

    if delta <= num_S:
        scc = num_c//2
    else:
        scc = num_S
        scc += delta//4

    print(scc)

if __name__ == "__main__":
    resolve()
