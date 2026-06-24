#include <bits/stdc++.h>
#define FOR(v, a, b) for(int v = (a); v < (b); ++v)
#define FORE(v, a, b) for(int v = (a); v <= (b); ++v)
#define REP(v, n) FOR(v, 0, n)
#define REPE(v, n) FORE(v, 0, n)
#define REV(v, a, b) for(int v = (a); v >= (b); --v)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define ITR(it, c) for(auto it = (c).begin(); it != (c).end(); ++it)
#define RITR(it, c) for(auto it = (c).rbegin(); it != (c).rend(); ++it)
#define EXIST(c,x) ((c).find(x) != (c).end())
#define LLI long long int
#define fst first
#define snd second
#define popcount __builtin_popcount

#ifdef DEBUG
#include <misc/C++/Debug.cpp>
#else
#define dump(x) ((void)0)
#endif

#define gcd __gcd

using namespace std;
template <class T> constexpr T lcm(T m, T n){return m/gcd(m,n)*n;}

template <typename I> void join(ostream &ost, I s, I t, string d=" "){for(auto i=s; i!=t; ++i){if(i!=s)ost<<d; ost<<*i;}ost<<endl;}
template <typename T> istream& operator>>(istream &is, vector<T> &v){for(auto &a : v) is >> a; return is;}
template <typename T, typename U> istream& operator>>(istream &is, pair<T,U> &p){is >> p.first >> p.second; return is;}

template <typename T, typename U> bool chmin(T &a, const U &b){return (a>b ? a=b, true : false);}
template <typename T, typename U> bool chmax(T &a, const U &b){return (a<b ? a=b, true : false);}
template <typename T, size_t N, typename U> void fill_array(T (&a)[N], const U &v){fill((U*)a, (U*)(a+N), v);}


template <typename Cost = int> class Edge{
public:
  int from,to;
  Cost cost;
  Edge() {}
  Edge(int to, Cost cost): to(to), cost(cost){}
  Edge(int from, int to, Cost cost): from(from), to(to), cost(cost){}

  Edge rev() const {return Edge(to,from,cost);}
  
  static bool cmp_to_lt(const Edge &e1, const Edge &e2){return e1.to < e2.to;}
  static bool cmp_cost_lt(const Edge &e1, const Edge &e2){return e1.cost < e2.cost;}
  static bool cmp_to_gt(const Edge &e1, const Edge &e2){return e1.to > e2.to;}
  static bool cmp_cost_gt(const Edge &e1, const Edge &e2){return e1.cost > e2.cost;}
  friend ostream& operator<<(ostream &os, const Edge &e){
    os << "(FROM: " << e.from << "," << "TO: " << e.to << "," << "COST: " << e.cost << ")";
    return os;
  }
};

template <typename T> using Tree = vector<vector<Edge<T>>>;


class TreeUtils{
public:
  template <typename T> static pair<int,T> farthest(const Tree<T> &tree, int cur, int par = -1){
    auto d = make_pair(cur, 0);
    for(auto &next : tree[cur]){
      if(next.to == par) continue;
      auto t = farthest(tree, next.to, cur);
      t.second += next.cost;
      if(t.second > d.second) d = t;
    }
    return d;
  }

  template <typename T> static void distance(const Tree<T> &tree, int cur, int par, vector<T> &dist, T d){
    dist[cur] = d;
    for(auto &next : tree[cur]){
      if(next.to == par) continue;
      distance(tree, next.to, cur, dist, d+next.cost);
    }
  }
  
  template <typename T> static tuple<T,int,int> diameter(const Tree<T> &tree, int cur=0){
    auto a = farthest(tree, cur);
    auto b = farthest(tree, a.first);
    return make_tuple(b.second, a.fst, b.fst);
  }

  template <typename T> static vector<T> height(const Tree<T> &tree){
    auto a = farthest(tree, 0);
    auto b = farthest(tree, a.first);

    int n = tree.size();
    vector<T> d1(n), d2(n), h(n);

    distance(tree, a.first, -1, d1, 0);
    distance(tree, b.first, -1, d2, 0);

    REP(i,n) h[i] = max(d1[i], d2[i]);
    
    return h;
  }
};



int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N,K;
  while(cin >> N >> K){
    Tree<int> tree(N);
    REP(i,N-1){
      int A,B; cin >> A >> B;
      --A, --B;

      tree[A].push_back(Edge<int>(A,B,1));
      tree[B].push_back(Edge<int>(B,A,1));
    }

    int ans = 0;

    int cur = 0;
    while(1){
      auto t = TreeUtils::diameter(tree, cur);
      dump(t);

      int d,a,b;
      tie(d,a,b) = t;

      if(d <= K) break;
      ++ans;

      // if remove a
      {
	Tree<int> tree2(N);
	REP(i,N){
	  for(auto &e : tree[i]){
	    if(e.from == a or e.to == a) continue;
	    tree2[i].push_back(e);
	  }
	}

	auto p = TreeUtils::diameter(tree2, b);

	if(get<0>(p) < d){
	  tree = tree2;
	  cur = b;
	  continue;
	}
      }

      // if remove b
      {
	Tree<int> tree2(N);
	REP(i,N){
	  for(auto &e : tree[i]){
	    if(e.from == b or e.to == b) continue;
	    tree2[i].push_back(e);
	  }
	}

	auto p = TreeUtils::diameter(tree2, a);

	tree = tree2;
	cur = a;
	continue;
      }
    }
    

    cout << ans << endl;
  }
  
  return 0;
}
