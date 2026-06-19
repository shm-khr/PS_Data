def main():
    s = raw_input()
    check_b = lambda x: x=='B'
    check_w = lambda x: x=='W'
    if all(map(check_b, list(s))) or all(map(check_w, list(s))):
        return 0

    work = list(s)[:]
    print 1



if __name__ == '__main__':
    print main()