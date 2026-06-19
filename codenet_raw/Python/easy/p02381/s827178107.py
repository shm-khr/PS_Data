daviations = []

while True:
    
    num = int(input())

    if num == 0:
        break
    
    scores = input().split()
    
    for i in range(num):
        scores[i] = float(scores[i])

    avr = sum(scores) / num
    
    daviation = 0
    
    for a in scores:
        disp = (a - avr)**2/num
        daviation += disp
        
        
        
    daviations.append(round(math.sqrt(daviation),8))
    
for b in daviations:
        print(b)
