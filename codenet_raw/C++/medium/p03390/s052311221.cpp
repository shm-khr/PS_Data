#include<algorithm>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using ll = long long;
enum : int { M = (int)1e9 + 7 };
enum : ll { MLL = (ll)1e18L + 9 };
using namespace std;
#ifdef LOCAL
#include"rprint2.hpp"
#include"debug_deque.hpp"
#define vector DebugDeque
#else
#define FUNC(name) template <ostream& out = cout, class... T> void name(T&&...){ }
FUNC(prints) FUNC(printe) FUNC(printw) FUNC(printew) FUNC(printb) FUNC(printd) FUNC(printde);
#endif
template <class S, class T>
istream& operator >> (istream& in, pair<S, T>& p){ in >> p.first >> p.second; return in; }
template <class T>
istream& operator >> (istream& in, vector<T>& v){ for(auto& e : v){ in >> e; } return in; }
template <char d = ' ', class T>
ostream& operator << (ostream& out, vector<T>& v){ for(auto& e : v){ out << e << d; } return out; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        ll a, b;
        cin >> a >> b;
        ll c = a * b - 1;
        ll c2 = sqrt(c);
        ll ans;
        // if(a < 10 && b < 10){
        //     int ans = 0;
        //     for(int i = 1; i <= 100; i++){
        //         for(int j = 1; j <= 100; j++){
        //             ans += i != j && i * j < a * b;
        //             if(i != j && i * j < a * b){
        //                 printd(a, b, ans, i * j, a * b);
        //                 // printd(a, b, ans, i != j && i * j < a * b);
        //             }
        //         }
        //     }
        //     cout << ans << '\n';
        //     continue;
        // }
        if((a == 1 && b == 3) || (a == 3 && b == 1)){
            cout << 1 << '\n';
            continue;
        }
        if(c2 * (c2 + 1) < c){
            ans = c2 * 2;
            ans -= a <= c2;
            ans -= b <= c2;
            // ans -= a <= c2 || b <= c2;
        }else{
            ans = c2 * 2 - 1;
            ans -= a <= c2;
            ans -= b <= c2;
            // ans -= a <= c2 || b <= c2;
        }
        // ll ans = c2 * 2 - 1;
        // ll ans = c2 * 2;
        // ans -= a < c2;
        // ans -= b < c2;
        // ans -= a <= c2;
        // ans -= b <= c2;
        // ans -= c2 * c2 == c;
        // ans += c2 * (c2 + 1) < c;
        // ans -= c2 * (c2 + 1) > c;
        cout << max(0ll, ans) << '\n';
        // prints(c2 * 2);
        // cout << c2 * 2 + (a == b ? 0 : a + b & 1 ? -2 : -1) << '\n';
        // ll ans = min(a - 1, c - (c >= b));
        // printd(ans, min(b - 1, c - (c >= a)));
        // ans = max(ans, min(b - 1, c - (c >= a)));
        // cout << ans << '\n';
    }
}
