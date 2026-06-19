#include <bits/stdc++.h>
//#include <chrono>
//#pragma GCC optimize("Ofast")
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second

using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;

ll N,M,H,W,Q,K,A,B;
string S;
typedef pair<ll, ll> P;
const ll INF = (1LL<<58);

template <unsigned long long mod > class modint{
public:
    ll x;
    constexpr modint(){x = 0;}
    constexpr modint(ll _x) : x((_x < 0 ? ((_x += (LLONG_MAX / mod) * mod) < 0 ? _x + (LLONG_MAX / mod) * mod : _x) : _x)%mod){}
    constexpr modint set_raw(ll _x){
        //_x in [0, mod)
        x = _x;
        return *this;
    }
    constexpr modint operator-(){
        return x == 0 ? 0 : mod - x;
    }
    constexpr modint& operator+=(const modint& a){
        if((x += a.x) >= mod) x -= mod;
        return *this;
    }
    constexpr modint operator+(const modint& a) const{
        return modint(*this) += a;
    }
    constexpr modint& operator-=(const modint& a){
        if((x -= a.x) < 0) x += mod;
        return *this;
    }
    constexpr modint operator-(const modint& a) const{
        return modint(*this) -= a;
    }
    constexpr modint& operator*=(const modint& a){
        (x *= a.x)%=mod;
        return *this;
    }
    constexpr modint operator*(const modint& a) const{
        return modint(*this) *= a;
    }
    constexpr modint pow(unsigned long long pw) const{
        modint res(1), comp(*this);
        while(pw){
            if(pw&1) res *= comp;
            comp *= comp;
            pw >>= 1;
        }
        return res;
    }
    //以下、modが素数のときのみ
    constexpr modint inv() const{
        if(x == 2) return (mod + 1) >> 1;
        return modint(*this).pow(mod - 2);
    }
    constexpr modint& operator/=(const modint &a){
        (x *= a.inv().x)%=mod;
        return *this;
    }
    constexpr modint operator/(const modint &a) const{
        return modint(*this) /= a;
    }
};
#define mod2 1000000007
using mint = modint<mod2>;

ostream& operator<<(ostream& os, const mint& a){
    os << a.x;
    return os;
}
using vm = vector<mint>;

int X, Y, Z;
bool ng(int j){
    return (j>>(Z-1))&1 && (j>>(Y+Z-1))&1 && (j>>(X+Y+Z-1))&1;
}

int main() {
    cin>>N>>X>>Y>>Z;
    vector<vm> dp(N + 1, vm(1<<16, 0));
    dp[0][0] = 1;
    rep(i, N){
        rep(j, 1<<16){
            rep(k, 10){
                int nxt = (j<<(k + 1)) + (1 << k);
                if(!ng(nxt)) dp[i+1][nxt & ((1<<16) - 1)] += dp[i][j];
            }
        }
    }
    cout<<mint(10).pow(N) - accumulate(ALL(dp[N]), mint(0))<<endl;
}
