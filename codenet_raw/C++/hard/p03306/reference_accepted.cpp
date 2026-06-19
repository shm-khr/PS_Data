#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
#define ll long long
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rep1(i, n) FOR(i, 1, n+1)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define rwhole(x) (x).rbegin(), (x).rend()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define P pair<ll, ll>
#define debug(var) cerr << "[" << #var << "] " << var << '\n'
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define pr(s) cout << (s) << '\n'
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
const int INF = 1001001001;
const ll INFll = 1E+18;

struct Edge {
    ll to;
    ll co;
    Edge(ll to, ll co): to(to), co(co) {}
};

vector<Edge> to[100005];
P p[100005];
bool used[100005];


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    rep(i, m) {
        ll u, v, s;
        cin >> u >> v >> s;
        u--; v--;
        to[u].eb(v, s);
        to[v].eb(u, s);
    }
    queue<int> q;
    q.push(0);
    p[0] = P(1LL, 0LL);
    used[0] = true;
    ll upper_limit = INFll;
    ll lower_limit = 1LL;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        used[now] = true;
        vector<int> plus;
        vector<int> minus;
        for (Edge e: to[now]) {
            if (!used[e.to]) {
                q.push(e.to);
                continue;
            }
            P ico = p[e.to];
            if (ico.fi==1) {
                minus.pb(e.co-ico.se);
            }
            if (ico.fi==-1) {
                plus.pb(e.co-ico.se);
            }
        }
        sort(whole(plus)); sort(whole(minus));
        if (plus.size() && plus[0]!=plus.back()) {
            pr(0);
            return 0;
        }
        if (minus.size() && minus[0]!=minus.back()) {
            pr(0);
            return 0;
        }
        if (plus.size() && minus.size()) {
            ll val = minus[0] - plus[0];
            if (val<=0 || abs(val)%2!=0) {
                pr(0);
                return 0;
            }
            val /= 2;
            if (val<lower_limit || val>upper_limit) {
                pr(0);
                return 0;
            }
            lower_limit = val; upper_limit = val;
            p[now] = P(1, plus[0]);
        }
        else if (plus.size()) {
            ll val = -plus[0];
            p[now] = P(1, plus[0]);
            chmax(lower_limit, val+1);
        }
        else if (minus.size()) {
            ll val = minus[0];
            chmin(upper_limit, val-1);
            p[now] = P(-1, minus[0]);
        }
        if (lower_limit>upper_limit) break;
    }
    //debug(lower_limit);
    //debug(upper_limit);
    ll ans = max(0LL, upper_limit-lower_limit+1);
    
    pr(ans);
    return 0;
}
