# -*- coding: utf-8 -*-

def main():
     x, y, a, b, c = map(int, input().split())

     # A個の赤いりんごの美味しさ
     p = list(map(int, input().split()))
     # B個の緑のりんごの美味しさ
     q = list(map(int, input().split()))
     # C個の無色のりんごの美味しさ
     r = list(map(int, input().split()))

     p = sorted(p)
     q = sorted(q)
     r = sorted(r, reverse=True)

     p_cut = p[-x:]
     q_cut = q[-y:]

     # print(p_cut)
     # print(q_cut)

     # 無色を1つも使わない場合をベースにする
     red_del = sum(p_cut)
     gre_del = sum(q_cut)
     base_ans = red_del + gre_del

     red_eat = 0
     gre_eat = 0
     cle_eat = 0
     # 交換できる無色を計算
     for i in range(c):
          if p_cut[red_eat] < q_cut[gre_eat]:
               change = p_cut[red_eat]
               if change < r[cle_eat]:
                    cle_eat += 1
                    red_eat += 1
               else:
                    break
          else:
               change = q_cut[gre_eat]
               if change < r[cle_eat]:
                    cle_eat += 1
                    gre_eat += 1
               else:
                    break
     
     ans = sum(p_cut[red_eat:]) + sum(q_cut[gre_eat:]) + sum(r[:cle_eat])
     print(ans)

if __name__ == "__main__":
    main()
