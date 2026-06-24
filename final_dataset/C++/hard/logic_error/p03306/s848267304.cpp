#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define INF 1000000000
#define mod 1000000007
using ll=long long;
const ll LINF=1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}

// 木じゃないならたかだか1個

struct edge{
    int to;ll s;
    edge(int to,ll s):to(to),s(s){}
    edge(){}
};

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n,m;cin>>n>>m;
    vector<vector<edge>> g(n);
    rep(i,m){
        int u,v;ll s;cin>>u>>v>>s;u--,v--;
        g[u].push_back(edge(v,s));
        g[v].push_back(edge(u,s));
    }

    vector<ll> con(n,0);// 定数項
    vector<bool> pos(n);// rの符号が正か

    vector<bool> check(n,false);
    ll r=-1;
    function<void(int,int)> dfs=[&](int pre,int now){
        // cout<<pre<<" -> "<<now<<endl;
        for(auto &e:g[now]){
            if(e.to==pre) continue;
            if(check[e.to]){
                // 成立するかチェック
                // 式now + 式to = e.sが成立すればrをチェック
                if(pos[now]!=pos[e.to]){
                    if(con[now]+con[e.to]!=e.s){
                        cout<<0<<endl;
                        exit(0);
                    }
                }else{
                    // 2*(±r) + con[now]+con[e.to]=e.s
                    ll tmp=e.s-con[now]-con[e.to];
                    if(tmp%2!=0){
                        cout<<0<<endl;
                        exit(0);
                    }
                    ll rtmp=tmp/2;
                    if(!pos[now]) rtmp=-rtmp;
                    if(rtmp<=0){
                        cout<<0<<endl;
                        exit(0);
                    }
                    // 既存のrと一致するか
                    if(r<0){
                        r=rtmp;
                    }else{
                        if(r!=rtmp){
                            cout<<0<<endl;
                            exit(0);
                        }
                    }
                }
            }else{
                // go
                ll c=e.s-con[now];
                con[e.to]=c;
                pos[e.to]=(1^pos[now]);
                check[e.to]=true;
                dfs(now,e.to);
            }
        }
    };

    con[0]=0;
    pos[0]=true;
    check[0]=true;
    dfs(-1,0);

    // debug(pos);
    // debug(con);
    

    if(r<0){
        // 未決定なら範囲を調べる
        ll lw=1,hi=LINF;
        rep(i,n){
            if(pos[i]){
                // lw
                // r+con[i]>=1
                chmax(lw,1-con[i]);
            }else{
                // hi
                // -r+con[i]>=1
                chmin(hi,con[i]-1);
            }
        }
        cout<<max(0ll,hi-lw+1)<<endl;
    }else{
        //決定済みならそれ1個のみ
        cout<<1<<endl;
    }
    return 0;
}
