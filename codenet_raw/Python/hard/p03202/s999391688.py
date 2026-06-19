class Lexicograph:
    def __init__(self, num):
        self.str_dic = {}
        self.length = 0
        self.num_str = num
        return

    def plus(self, n):
        for i in reversed(range(n)):
            self.str_dic[i] = self.str_dic.get(i, 0) + 1
            if self.str_dic[i] == self.num_str:
                self.str_dic.pop(i)
            else:
                break
        else:
            return False
        return True

    def check(self):
        self.length = A[0]
        for a in A[1:]:
            if self.length < a:
                self.length = a
            else:
                self.length = a
                if self.num_str == 1:
                    return False
                else:
                    self.str_dic = {k: v for k,
                                    v in self.str_dic.items() if k < a}
                    if self.plus(a) is False:
                        return False
            # print(lex.str_dic)
        return True


n = int(input())
if n == 1:
    print(1)
    exit()
A = [10 ** 10] + list(map(int, input().split())) + [0]
if n == 2:
    print(2 if A[1] < A[2] else 1)
    exit()
A = [j for i, j, k in zip(A, A[1:], A[2:]) if not i < j < k]
# print(A)

lex_high = Lexicograph(1)
lex_low = Lexicograph(1)
c_dic = {}
high, low = len(A), 1
while high - low > 1:
    lex_high.__init__(high)
    lex_low.__init__(low)

    if high not in c_dic:
        c_dic[high] = lex_high.check()
    if low not in c_dic:
        c_dic[low] = lex_low.check()

    if c_dic[low] is True:
        high, low = low, low - (high - low) // 2
    else:
        low += (high - low) // 2
    # print(c_dic)


lex_high.__init__(high)
print(high if lex_high.check is True else low)