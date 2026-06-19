X =int(input())

pattern = [x+y+z for z in range(0,X+1,50) for y in range(0,X+1,100) for x in range(0,X+1,500)]
print(len(list(filter(lambda x:x==X,pattern))))

