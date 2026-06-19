#N A B C D
s = input().split()
N = int(s[0])
A = int(s[1])
B = int(s[2])
C = int(s[3])
D = int(s[4])

operation = [-D , -C , +C , +D]

#A に opeをすると 4通りの答えがかえってくる
#残り演算回数を出す
#答えと残り演算回数から、到達可能な数字の範囲を出す
#答えがあればopeを行う
#答えがなければそこで終了
#最後まで到達できれば終了

def Kanousei(x , left) : 
    return [x - left * D , x - left * C , x + left * C , x + left * D]

def Kanousei_hantei(kanousei , left) : 
    if left == 1 : 
        return ( (B >= kanousei[0])  & (B <= kanousei[1]) ) |  ( (B >= kanousei[2]) & (B <= kanousei[3]) ) 
    else : 
        return ( (B >= kanousei[0])  ) |  (  (B <= kanousei[3]) ) 

turn = 1
left = N - turn
kanousei = Kanousei(A , left)
kanousei_hantei = Kanousei_hantei(kanousei , left)

def search(x , turn) : 
    left = N - turn
    kanousei = Kanousei(x , left)
    kanousei_hantei = Kanousei_hantei(kanousei , left)
    if kanousei_hantei == True :   #可能性があったらopeする
        if left == 1 :
            print(x)
            return True
        else : 
            for ope in operation : 
                flag = search(x + ope , turn + 1 )
                return flag
    return False

if search(A , turn) : print("YES")
else : print("NO")