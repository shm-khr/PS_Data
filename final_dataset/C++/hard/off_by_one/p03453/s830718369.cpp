#include "bits/stdc++.h"
using namespace std;
#define fi first
#define se second
#define ll long long
#define dbg(v) cerr<<#v<<" = "<<v<<'\n'
#define vi vector<int>
#define vl vector <ll>
#define pii pair<int,int>
#define mp make_pair
#define db long double
#define pb push_back
#define all(s) s.begin(),s.end()
#define int ll
template < class T > T smin(T &a,T b) {if (a > b) a = b;return a;}
template < class T > T smax(T &a,T b) {if (a < b) a = b;return a;}
const int mod = 1e9 + 7;
const int N = (int)(1e6) + 5;
vector < pii > g[N];
ll D1[N],D2[N];
ll W1[N],W2[N];
int mult(int a,int b)
{
    return (1ll * a * b) % mod;
}
void add(int &a,int b)
{
    a = (a + b) % mod;
}
const ll oo = 1e18 + 5;
int was[N];
void go(int n,int S,ll D[],ll W[])
{
    memset(was,0,sizeof(was));
    for (int i = 1;i <= n;++i)
        D[i] = 1e18;
    priority_queue < pair < ll , ll > , vector < pair < ll , ll > > , greater < pair < ll , ll > > > Q;
    D[S] = 0;
    W[S] = 1;
    Q.push(mp(0,S));
    while (!Q.empty())
    {
        int node = Q.top().se;
        Q.pop();
        if (was[node]) continue;
        was[node] = 1;
        for (auto it : g[node])
        {
            if (D[it.fi] == D[node] + it.se)
                W[it.fi] = (W[it.fi] + W[node]) % mod;
            else
            if (D[it.fi] > D[node] + it.fi)
                D[it.fi] = D[node] + it.se,W[it.fi] = W[node],Q.push(mp(D[it.fi],it.fi));
        }
    }
}
int32_t main(void)
{
    int n,m;
    cin>>n>>m;
    int S,T;
    cin>>S>>T;
    while (m --)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a].pb(mp(b,c));
        g[b].pb(mp(a,c));
    }
    go(n,S,D1,W1);
    go(n,T,D2,W2);
    int ans = mult(W1[T],W1[T]);
    for (int i = 1;i <= n;++i)
        if (D1[i] == D2[i])
            add(ans,mod - mult(W1[i],W2[i]));
    for (int i = 1;i <= n;++i)
        for (auto it : g[i])
        if (D1[it.fi] == D1[i] + it.se)
            if (2 * D1[i] < D1[T] && 2 * D2[it.fi] < D1[T])
                add(ans,mod - mult(W1[i],W2[it.fi]));
    cout << ans << '\n';
    return 0;
}
