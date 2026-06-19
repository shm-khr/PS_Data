#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T x,Args... args) {cout<<x<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    map<pii, int> cnt;
    while (k--) {
        int y, x;
        cin >> y >> x;
        
        int a = max(1, y-2), b = min(n-2, y);
        int c = max(1, x-2), d = min(m-2, x);
        
        forn(i, a, b+1) {
            forn(j, c, d+1) {
                cnt[{i, j}]++;
            }
        }
    }
    
    ll ans[10] = {};
    ans[0] = 1ll*(n-2)*(m-2);
    for (auto &x : cnt) {
        ans[x.S]++;
        ans[0]--;
    }
    
    forn(i, 0, 10) {
        cout << ans[i] << endl;
    }
}
