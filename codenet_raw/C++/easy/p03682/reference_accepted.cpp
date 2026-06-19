#include<bits/stdc++.h>
using namespace std;
#pragma region atcoder

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
  public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

using namespace atcoder;
#pragma endregion
#pragma region macros
using ll = long long;
using vi = vector<int>;
using vs = vector<string>;
using vl = vector<ll>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvc = vector<vector<char>>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rrep(i, n) for(int i = n - 1; i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#pragma endregion
#pragma region debug for var, v, vv
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){cout << endl;int cnt = 0;for(const auto& v : vv){cout << cnt << "th : "; view(v); cnt++;} cout << endl;}
#pragma endregion
const ll mod = 1000000007;
const int inf = 1001001001;
const ll INF = 1001001001001001001;
const int MAX = 2000005;
template<class T>bool chmax(T &a, const T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T b) { if (b<a) { a=b; return 1; } return 0; }
ll modpow(ll a, ll p){ll ret = 1; while(p){if(p & 1){ret = ret * a % mod;} a = a * a % mod; p >>= 1;} return ret;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

/*-----------------------------------------------------------------------------------------------------*/
struct coor{
    int x, y, idx;
};
/**
 * Minimum spanning tree
 * CAUTION : Use this with ACL's dsu
 * You can use this if the form of input is an adjacency list
 * You can ask for the answer by hoge.sum
 **/
struct Edge{
    ll from;
    ll to; 
    ll cost;
};
bool comp_e(const Edge &e1, const Edge &e2) { return e1.cost < e2.cost; }

struct Kruskal{
    dsu tree;
    ll sum;
    vector<Edge> edges;
    int V;
    Kruskal(const vector<Edge> &edges_, int V_) : edges(edges_), V(V_) {init();}
    void init(){
        sort(all(edges), comp_e);
        tree = dsu(V);
        sum = 0;
        for(auto e : edges){
            if(!tree.same(e.from, e.to)){
                tree.merge(e.from, e.to);
                sum += e.cost;
            }
        }
    }
};

int main(){
    int n; cin >> n;
    vector<coor> p(n);
    rep(i,n){
        cin >> p[i].x >> p[i].y;
        p[i].idx = i;
    }
    vector<Edge> edges;
    sort(all(p), [](auto &a, auto &b){return a.x < b.x;});
    rep(i,n - 1){
        edges.push_back(Edge{p[i].idx, p[i + 1].idx, p[i + 1].x - p[i].x});
    }
    sort(all(p), [](auto &a, auto &b){return a.y < b.y;});
    rep(i,n - 1){
        edges.push_back(Edge{p[i].idx, p[i + 1].idx, p[i + 1].y - p[i].y});
    }
    Kruskal G(edges, n);
    cout << G.sum << endl;
}
