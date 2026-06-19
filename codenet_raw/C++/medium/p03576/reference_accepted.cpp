#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) ((int)(x).size())
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<typename T> void view(T e){std::cout << e << std::endl;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

const int inf = 1 << 30;
const ll INF = 1LL << 62;

int main(){
    int n, k;
    cin >> n >> k;
    VL x(n), y(n);
    vector<pair<ll, ll>> c(n);
    rep(i,n){
        cin >> x[i] >> y[i];
        c[i].first = x[i];
        c[i].second = y[i];
    }
    sort(all(x));
    sort(all(y));

    ll ans = INF;
    for(int xi = 0; xi < n; xi++){
        for(int xj = xi+1; xj < n; xj++){
            for(int yi = 0; yi < n; yi++){
                for(int yj = yi+1; yj < n; yj++){
                    ll xl = x[xi], xr = x[xj];
                    ll yl = y[yi], yh = y[yj];

                    int cnt = 0;
                    rep(i,n){
                        bool inx = xl <= c[i].first && c[i].first <= xr;
                        bool iny = yl <= c[i].second && c[i].second <= yh;
                        if (inx && iny) cnt++;
                    }
                    if (cnt >= k){
                        ll area = (xr - xl) * (yh - yl);
                        ans = min(ans, area);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}