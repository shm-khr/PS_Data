#include <bits/stdc++.h>
#define inf 1000000005
#define mod 1000000007
#define eps 1e-10
#define rep(i,n) for(int i = 0; i < (n); ++i) /*0からn-1までのrepeat*/
#define rrep(i,n) for(int i = 1; i <= (n); ++i) /*1からnまでのrepeat*/
#define drep(i,n) for(int i = (n)-1; i >= 0; --i) /*n-1から0までのrepeat*/
#define srep(i,s,t) for (int i = s; i < t; ++i) /*sからt-1までのrepeat*/
#define isin(x,l,r) ((l) <= (x) && (x) < (r)) /*l以上r未満のx*/
#define each(a,b) for(auto& (a): (b)) /*よくわからん*/
#define pct __builtin_popcountll /*1bitの数*/
#define all(a) a.begin(),a.end() /*範囲*/
#define sz(v) (int)(v).size() /*大きさ*/
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end()) /*重複削除*/
#define cmx(x,y) x=max(x,y) /*最大*/
#define cmn(x,y) x=min(x,y) /*最小*/
#define rev(v) reverse((v).begin(),(v).end()); /*逆順*/
#define so(v) sort((v).begin(), (v).end()); /*ソート*/
#define yn {puts("Yes");}else{puts("No");} /*はい・いいえ*/
#define dame { puts("-1"); return 0;}/*だめ*/
#define fi first
#define se second
#define pb push_back
#define eb emplace_back

using namespace std;

using ll = long long;
using unit = unsigned;
using ull = unsigned long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vd = vector<double>;
using vp = vector<P>;
using vt = vector<T>;
using vs = vector<string>;

int main() {
    string a;
    cin >> a;
    int ct=0;
    int b = sz(a);
    rep(i,b) {
        if (a.at(i) == 'x') {
            ct++;
        }
    }
    if (ct < 8) {
        cout<<"YES"<<endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}