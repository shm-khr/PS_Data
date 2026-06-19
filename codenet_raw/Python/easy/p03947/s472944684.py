from sys import stdin
input = stdin.readline
N,T = map(int,input().split())
prices = list(map(int,input().split()))
last = 10000000000
highestTally = [prices[-1]]
highestCount = [1]

for price in prices[-2:-N-1:-1]:
    if price==highestTally[-1]:
        highestCount.append(highestCount[-1]+1)
    else:
        highestCount.append(1)
    highestTally.append(max(highestTally[-1],price))
highestTally.reverse()
highestCount.reverse()

indexOfHighest={}
for i in range(N-1,-1,-1):
    if highestTally[i]==prices[i]:
        indexOfHighest[highestTally[i]]=i

biggestJump=0
sellingPriceForBiggestJump=0
HPcount=0
LPcount=0
for index,price in enumerate(prices):
    if index==N-1:
        break
    bestSellingPrice = highestTally[index+1]
    jump = bestSellingPrice-price
    #print(jump,bestSellingPrice,biggestJump)
    if jump>biggestJump:
        biggestJump = jump
        LPcount+=1
        sellingPriceForBiggestJump = bestSellingPrice
        HPcount=highestCount[indexOfHighest[bestSellingPrice]]
    elif jump==biggestJump:
        if bestSellingPrice!=sellingPriceForBiggestJump:
            sellingPriceForBiggestJump = bestSellingPrice
            HPcount+=highestCount[indexOfHighest[bestSellingPrice]]
        LPcount+=1
count = min(LPcount,HPcount)            
if T//2>=count:
    print(count)
else:
    print(int(T//2))