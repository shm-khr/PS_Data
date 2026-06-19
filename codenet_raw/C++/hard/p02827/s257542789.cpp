#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_int.hpp>
//typedef boost::multiprecision::cpp_int ll;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
////////////////////////////

class UnionFind {
public:
    vector < ll > par; // 各元の親を表す配列
    vector < ll > siz; // 素集合のサイズを表す配列(1 で初期化)
    // Constructor
    UnionFind(ll sz_): par(sz_), siz(sz_, 1) {
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1);
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    // Member Function
    // Find
    ll root(ll x) { // 根の検索
        while (par[x] != x) {
            x = par[x] = par[par[x]]; // x の親の親を x の親とする
        }
        return x;
    }
    // Union(Unite, Merge)
    bool merge(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        // merge technique（データ構造をマージするテク．小を大にくっつける）
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }
    bool issame(ll x, ll y) { // 連結判定
        return root(x) == root(y);
    }
    ll size(ll x) { // 素集合のサイズ
        return siz[root(x)];
    }
};
/////////////////////////////////////

int main(){fastio
    ll n,m,t;cin>>n>>m>>t;
    if(t==2){
        cout<<-1<<endl;return 0;
    }
    ll x[m],y[m];rep(i,0,m-1)cin>>x[i]>>y[i];
    ll last=y[m-1];
    ll ans[m];rep(i,0,m-1)ans[i]=2;
    UnionFind uf(n+1);
    ll bpos=m-1;
    rep(i,0,m-1){
        uf.merge(x[i],y[i]);
        if(uf.size(x[i])==n){
            bpos=i;break;
        }
    }
    bool use[n+1];memset(use,false,sizeof(use));
    for(ll sta=m-1;sta>=bpos;sta--){
        if(use[x[sta]]||use[y[sta]])continue;
        uf.init(n+1);
        uf.merge(x[sta],y[sta]);ans[sta]=2;
        for(ll i=sta-1;i>=0;i--){
            if(uf.issame(last,x[i])){
                ans[i]=1;
                uf.merge(x[i],y[i]);
            }else if(uf.issame(last,y[i])){
                ans[i]=2;
                uf.merge(x[i],y[i]);
            }else{
                ans[i]=2;
            }
            /*
            rep(i,1,n)rep(j,i+1,n)cout<<uf.issame(i,j);
            cout<<endl;
             */
        }
        bool ok=true;
        rep(i,1,n){
            if(!uf.issame(i,last)){
                ok=false;break;
            }
        }
        if(ok){
            rep(i,0,m-1){
                if(ans[i]==1)cout<<'^';
                else cout<<'v';
            }cout<<endl;
            return 0;
        }
        use[x[sta]]=true;use[y[sta]]=true;
    }
    cout<<-1<<endl;
    return 0;
}
