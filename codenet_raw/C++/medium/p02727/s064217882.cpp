#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
#define SZ(a) int((a).size())
#define _REP(_1,_2,_3,_4,name,...) name
#define _REP4(i,b,e,s) for(decltype(e) _b=(b),_e=(e),i=_b+(0<(s)?0:(s));(0<(s)?i<_e:_e<=i);i+=(s))
#define _REP3(i,b,e) for(decltype(e) _b=(b),_e=(e),i=(_b<_e?_b:_b-1);(_b<_e?i<_e:_e<=i);(_b<_e?i++:i--))
#define _REP2(i,n) for(decltype(n) i=0,_n=(n);i<_n;i++)
#define _REP1(n) for(decltype(n) _i=0,_n=(n);_i<_n;_i++)
#define REP(...) _REP(__VA_ARGS__,_REP4,_REP3,_REP2,_REP1)(__VA_ARGS__)
#define FOR(it,c) for(auto&& it=begin(c);it!=end(c);it++)
#define ROF(it,c) for(auto&& it=rbegin(c);it!=rend(c);it++)
#define EB emplace_back
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define INT(n) int n;assert(0<scanf("%d",&n))
#define VI(v,n) vector<int> v(n);REP(i,n){assert(0<scanf("%d",&v[i]));}

int main(){
  INT(x); INT(y); INT(a); INT(b); INT(c); VI(ps, a); VI(qs, b); VI(rs, c);
  sort(ps.rbegin(), ps.rend());
  sort(qs.rbegin(), qs.rend());
  sort(rs.rbegin(), rs.rend());
  vector<ll> vp(a + 1, 0), vq(b + 1, 0), vr(c + 1, 0);
  vp[0] = 0; REP(i, 1, a + 1){vp[i] = vp[i - 1] + ps[i - 1];}
  vq[0] = 0; REP(i, 1, b + 1){vq[i] = vq[i - 1] + qs[i - 1];}
  vr[0] = 0; REP(i, 1, c + 1){vr[i] = vr[i - 1] + rs[i - 1];}
  ll ans = 0;
  REP(i, c + 1){
    vector<ll> score(c, 0);
    REP(j, i + 1){
      if (x < j || y < i - j){
        score[j] = -1;
      } else {
        score[j] = vp[x - j] + vq[y - i + j] + vr[i];
      }
    }
    int l = 0, r = i, m, n;
    ll tmp = max(score[l], score[r]);
    while (l + 2 < r){
      m = (2 * l + r) / 3;
      n = (l + 2 * r) / 3;
      tmp = max(tmp, max(score[m], score[n]));
      if (score[m] < score[n]) {
        l = m;
      } else if (score[m] > score[n]) {
        r = n;
      } else {
        l = m; r = n;
      }
    }
    ans = max(ans, tmp);
  }
  printf("%lld\n", ans);
  return 0;
}