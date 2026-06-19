while True:
    count_shima=input()
    if count_shima==0: break
    A=[]
    A = [map(int,raw_input().split()) for i in range(count_shima)]

    A.sort()

    weight=0
    flag=True
    for takara,turi in A:
        weight +=takara
        if turi < weight:
            flag=False
    print("Yes" if flag else "No")