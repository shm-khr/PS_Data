class Lexicograph:
    def __init__(self):
        self.str_dic = {}
        self.length = 0
        self.ans = 1
        return

    def plus(self, n):
        for i in reversed(range(n)):
            self.str_dic[i] = self.str_dic.get(i, 0) + 1
            if self.str_dic[i] == self.ans:
                self.str_dic.pop(i)
            else:
                break
        else:
            self.ans += 1
            self.str_dic[0] = self.ans - 1
        return


n = int(input())
A = list(map(int, input().split()))

lex = Lexicograph()
lex.length = A[0]
for a in A[1:]:
    if lex.length < a:
        lex.length = a
    else:
        lex.length = a
        if lex.ans == 1:
            lex.ans += 1
            lex.str_dic[a - 1] = 1
        else:
            lex.str_dic = {k: v for k, v in lex.str_dic.items() if k < a}
            lex.plus(a)
    # print(lex.str_dic)
print(lex.ans)