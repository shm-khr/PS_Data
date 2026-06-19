words = raw_input()
N = len(words)
word = list(words)
print word

ans = 0


def before_after(i, j):
  count = 0
  print "関数呼び出し"
  print i
  print j
  for k in range (0, j-i+1):
    print word[i+k-1]
    print word[j-k-1]
    if(word[i+k-1] == word[j-k-1]):
      count += 1
      print "count is " + str(count)


  if(count == j-i+1): #変更前と変更後が同じ
    return 1
  else:
    print "plus one"
    return 0


for i in range(1, N+1):
  for j in range(i+1, N+1):
    #ここで関数を呼び出して前と後が同じ文字列かどうかの判定を行う関数を作る。
    if(before_after(i, j) == 1):
      continue
    ans += 1
    print ans

print "Answer is " + str(ans+1)
