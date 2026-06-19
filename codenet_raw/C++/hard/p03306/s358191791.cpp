#include <bits/stdc++.h>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define debug(x) cerr << #x << ": " << x << endl

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;

const ll MOD = 1000000007;
const long double EPS = 10e-10;

struct State{
    int node, a, depth;
    State(int node, int a, int depth): node(node), a(a), depth(depth) {}
};

bool used[100000];
int s[100000];
int n,m;
vector<Pii> G[100000];

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    int a,b,ss;
    rep(m){
        cin >> a >> b >> ss;
        a--; b--;
        G[a].emplace_back(b, ss);
        G[b].emplace_back(a, ss);
    }

    int upper_lim = INT_MAX, lower_lim = 0;
    queue<State> que;
    que.emplace(State(0, 0, 0));
    while(!que.empty()){
        State t = que.front(); que.pop();
        used[t.node] = true;
        for(Pii child: G[t.node]){
            if(used[child.first]) continue;
            int a = t.a;
            if(t.depth % 2){
                a -= child.second;
                lower_lim = max(lower_lim, a);
            }else{
                a += child.second;
                upper_lim = min(upper_lim, a);
            }
            que.emplace(State(child.first, a, t.depth+1));
        }
    }
    cout << (upper_lim>lower_lim?upper_lim-lower_lim-2:0) << "\n";
}