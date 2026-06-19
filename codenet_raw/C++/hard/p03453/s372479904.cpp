#include <bits/stdc++.h>
#define SORT(x) sort((x).begin(), (x).end())
#define RSORT(x) sort((x).rbegin(), (x).rend())
#define ALL(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < n; i++)
#define reps(i, m, n) for (ll i = m; i < n; i++)
#define repr(i, m, n) for (ll i = m; i >= n; i--)
#define de(x) cout << #x << "=" << x << endl;
#define SP << " " <<
template <class T> bool maxi(T &a, const T &b) {
    if (a < b) { a = b; return 1;} return 0;}
template <class T> bool mini(T &a, const T &b) {
    if (b < a) { a = b; return 1;} return 0;}
#define dame {cout<< "-1" <<"\n"; return;}
#define INF2 1000000000000000037
#define INF  1000000007
#define MOD  1000000007
using namespace std;
using ll = long long;
using ld = long double;
using P  = pair<ll,ll>;
//--GLOBAL---------------------------------
vector<ll> ct(303030,0);
vector<ll> ct2(303030,0);
ll tyu;
struct edge{ll to, cost, num;};
struct graph{
    ll N;
    vector<vector<edge> > G;
    vector<ll> d;
    vector<ll> now;

    graph(ll n): N(n), G(N), d(n,INF2), now(n,0) {}

    void ade(ll s, ll t, ll cost, ll num){
        G[s].emplace_back((edge){t, cost, num});
        G[t].emplace_back((edge){s, cost, num}); //無向ならON
    }

    void dijkstra(ll s){
        d[s] = 0;
        priority_queue<P,vector<P>, greater<P> > que;
        que.emplace(0,s); // P < ans , Node >
        while(!que.empty()){
            P p = que.top(); que.pop();
            ll v = p.second;
            if(d[v] < p.first) continue;
            rep(i,G[v].size()){
                edge& E = G[v][i];
                if(mini(d[E.to], d[v]+E.cost)){
                    que.emplace(d[E.to], E.to);
                }
            }
        }
    }
    void dijkstra2(ll s){
        rep(i,N) d[i]=INF2;
        rep(i,N) now[i]=0;
        d[s] = 0;
        now[s]=1;
        priority_queue<P,vector<P>, greater<P> > que;
        que.emplace(0,s); // P < ans , Node >
        while(!que.empty()){
            P p = que.top(); que.pop();
            ll v = p.second;
            if(d[v] < p.first) continue;
            if(d[v]*2==tyu) ct[v]=now[v];
            rep(i,G[v].size()){
                edge& E = G[v][i];
                if(mini(d[E.to], d[v]+E.cost)){
                    now[E.to]=now[v];
                    que.emplace(d[E.to], E.to);
                }
                else if(d[E.to]==d[v]+E.cost){
                    now[E.to]+=now[v];
                    now[E.to]%=MOD;
                }
                if(d[v]*2<tyu and (d[v]+E.cost)*2>tyu) ct[E.num]=now[v];
            }
        }
    }
    void dijkstra3(ll s){
        rep(i,N) d[i]=INF2;
        rep(i,N) now[i]=0;
        d[s] = 0;
        now[s]=1;
        priority_queue<P,vector<P>, greater<P> > que;
        que.emplace(0,s); // P < ans , Node >
        while(!que.empty()){
            P p = que.top(); que.pop();
            ll v = p.second;
            if(d[v] < p.first) continue;
            if(d[v]*2==tyu) ct2[v]=now[v];
            rep(i,G[v].size()){
                edge& E = G[v][i];
                if(mini(d[E.to], d[v]+E.cost)){
                    now[E.to]=now[v];
                    que.emplace(d[E.to], E.to);
                }
                else if(d[E.to]==d[v]+E.cost){
                    now[E.to]+=now[v];
                    now[E.to]%=MOD;
                }
                if(d[v]*2<tyu and (d[v]+E.cost)*2>tyu) ct2[E.num]=now[v];
            }
        }
    }
};

template< int mod >
struct ModInt {
    int x;

    ModInt() : x(0) {}
    ModInt(ll y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    ModInt &operator+=(const ModInt &p) {
        if((x += p.x) >= mod) x -= mod;
        return *this;
    }
    ModInt &operator-=(const ModInt &p) {
        if((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }
    ModInt &operator*=(const ModInt &p) {
        x = (int) (1LL * x * p.x % mod);
        return *this;
    }
    ModInt &operator/=(const ModInt &p) {
        *this *= p.inv();
        return *this;
    }

    ModInt operator-() const { return ModInt(-x); }

    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
    bool operator==(const ModInt &p) const { return x == p.x; }
    bool operator!=(const ModInt &p) const { return x != p.x; }

    ModInt operator+(const ll &q) const {return ModInt(*this) += (ModInt)q; }
    ModInt operator-(const ll &q) const {return ModInt(*this) -= (ModInt)q; }
    ModInt operator*(const ll &q) const {return ModInt(*this) *= (ModInt)q; }
    ModInt operator/(const ll &q) const {return ModInt(*this) /= (ModInt)q; }
    bool operator==(const ll &q) const {return x == q; }
    bool operator!=(const ll &q) const {return x != q; }

    ModInt operator++(){ if(++x == mod) x = 0; return *this; }
    ModInt operator--(){ x = (x == 0 ? mod-1 : x-1); return *this; }
    ModInt operator++(int){ const ModInt res(*this); ++*this; return res; }
    ModInt operator--(int){ const ModInt res(*this); --*this; return res; }

    ModInt inv() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while(b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(ll n, bool inv=false) const {
        ModInt ret(1), mul(x);
        while(n > 0) {
        if(n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        if(inv) ret=ret.inv();
        return ret;
    }

    friend ostream &operator<<(ostream &os, const ModInt &p) {
        return os << p.x;
    }
    friend istream &operator>>(istream &is, ModInt &a) {
        ll t;
        is >> t;
        a = ModInt< mod >(t);
        return (is);
    }
};
using mint = ModInt< MOD >;
mint mpow(ll x, ll n, bool inv=false) {
    mint ret(1), mul(x);
    while(n > 0) {
    if(n & 1) ret *= mul;
        mul *= mul;
        n >>= 1;
    }
    if(inv) ret=ret.inv();
    return ret;
}

//--MAIN-----------------------------------
void Main() {
    ll N,M,S,T;
    cin>>N>>M>>S>>T; --S,--T;
    graph g(N);
    rep(i,M){
        ll u,v,d; cin>>u>>v>>d; --u,--v;
        g.ade(u,v,d,i+N);
    }
    g.dijkstra(S);
    tyu=g.d[T];

    g.dijkstra2(S);
    g.dijkstra3(T);

    mint sum=0;

    rep(i,N+M){
        if(!ct[i] or !ct2[i]){
            ct[i]=0; ct2[i]=0;
        }
        else{
            sum+=(mint)ct[i]*ct2[i];
        }
    }

    mint ans=sum*sum;
    rep(i,N+M){
        ans-=(mint)ct[i]*ct2[i]*(mint)ct[i]*ct2[i];
    }
    cout<< ans <<"\n";
}

//--START----------------------------------
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
//-----------------------------------------
