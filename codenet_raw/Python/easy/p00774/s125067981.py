def calc(puzzle,H,score):
    flag=False
    for i in range(H-1,-1,-1):
        stones=[]
        for j in range(5):
            now=puzzle[j][i]
            if (len(stones)==0 or stones[-1]==now) and now!=0: stones.append(now)
            elif len(stones)<3: stones=[now]
        if len(stones)>2:
            flag=True
            score+=sum(stones)
            for j in range(5):
                if puzzle[j][i]==stones[0]: 
                    puzzle[j].pop(i)
                    puzzle[j].append(0)
    if flag==True:
        return calc(puzzle,H,score)
    else:
        return score

if __name__=="__main__":
    while True:
        score=0
        H=int(input())
        if H==0:
            break
        puzzle=[[] for _ in range(5)]
        for i in range(H):
            temp=list(map(int,input().split()))
            for j in range(5):
                puzzle[j].insert(0,temp[j])
        score=calc(puzzle,H,score)
        print(score)
