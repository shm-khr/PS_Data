
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <functional>
#include <queue>
#include <deque>
#include <stack>
#include <limits>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <fstream>
#include <iterator>
#include <random>
#include <chrono>
 
 
#define forr(i,start,count) for (int i = (start); i < (start)+(count); ++i)
#define set_map_includes(set, elt) (set.find((elt)) != set.end())
#define readint(i) int i; cin >> i
#define readll(i) ll i; cin >> i
#define readdouble(i) double i; cin >> i
#define readstring(s) string s; cin >> s
 
typedef long long ll;
 
using namespace std;

ll modd = 1000*1000*1000+7;

template<class T>
class breadth_first_search_iterator {
  public:
    queue<pair<T,T>> todo;
    function<bool(T)> notvisited;
    function<void(T)> mark_visited;
    function<set<T>(T)> neighbors;

    breadth_first_search_iterator() {}

    breadth_first_search_iterator(T start, function<bool(T)> notv, function<void(T)> mark_v, function<set<T>(T)> neigh) :
      notvisited(notv), mark_visited(mark_v), neighbors(neigh), end_(false), current(start), prev(start) {
          todo.push(make_pair(start, start)); operator++();
    }

    void operator++() {
        end_ = true;
        while (!todo.empty()) {
            current = todo.front().first; prev = todo.front().second; todo.pop();
            if (notvisited(current)) {
                mark_visited(current);
                for (const T x : neighbors(current)) {  todo.push(make_pair(x, current));   }
                end_ = false;
                break;
            }
        }
    }

    T operator*() {     return current;    }

    T previous() {  return prev;  }

    bool end() {  return end_;  }

  private:
    T current;   // current node
    T prev;      // previous node
    bool end_;
};


template<class T>
class DirectedGraph {
    // allows only single connection between two vertices
    public:
      vector<T> vertices;
      vector<set<int>> neighbors;
      vector<bool> visited;

      DirectedGraph() {}

      DirectedGraph(int n) {  for (int i = 0; i < n; ++i) {  AddVertex(0);  }   }

      bool EdgeExists(int i_from, int j_to) {
          return (neighbors[i_from].find(j_to) != neighbors[i_from].end());
      }

      void AddVertex(T val) {
          vertices.push_back(val);
          neighbors.push_back(set<int>());      }

      void AddEdge(int i_from, int j_to) {
          if (!EdgeExists(i_from, j_to)) {     neighbors[i_from].insert(j_to);      }
      }

      T& operator[](int i) {      return vertices[i];      }

      int vertices_count() {   return vertices.size();  }


};


template<class T>
class DFST {
    public:
      vector<pair<int,int>> DFSTour;
      vector<int> to_v;  // contains index in DFSTour where the down edge to the vertex is contained
      vector<int> from_v;    // contains index in DFSTour where the up edge frrom the vertex is contained

      DFST(DirectedGraph<T>& g, int root) : from_v(vector<int>(g.vertices_count(), 0)), to_v(vector<int>(g.vertices_count(), 0)) {
          DFSTour.push_back(make_pair(-1, root));   // fake start in edge of the tour
          to_v[root] = 0;
          DFStourhelper(g, root);
          DFSTour.push_back(make_pair(root, -1));
          from_v[root] = DFSTour.size()-1;    // fake end out edge of the tour
      }

      void DFStourhelper(DirectedGraph<T>& g, int root) {
          for (auto n : g.neighbors[root]) {
              DFSTour.push_back(make_pair(root, n));
              to_v[n] = DFSTour.size()-1;
              DFStourhelper(g, n);
              DFSTour.push_back(make_pair(n, root));
              from_v[n] = DFSTour.size()-1;
          }
      }

/*   subtree count, depth examples of usage (if root == 0)
        DFST<int> dfst(g, 0);
        SegmentTree<int> subtree_count(2*n, [](int x, int y){return (x+y);}, 0);
        SegmentTree<int> depth(2*n, [](int x, int y){return (x+y);}, 0);
        for (auto v : dfst.to_v) {  if (v>=0) {   subtree_count.SetVal(v, 1); depth.SetVal(v, 1);  }  }
        for (auto v : dfst.from_v) {  if (v>=0) {   depth.SetVal(v, -1);  } }

        forr(i,1,n-1) {
            cout << i << " : " << subtree_count.GetIntervalEvaluation(dfst.to_v[i], dfst.from_v[i]+1) <<  " " <<
                                  depth.GetIntervalEvaluation(0, dfst.to_v[i]+1) << endl;
        }
*/

};


template<class T>
class Graph {
    // allows only single connection between two vertices
    public:
      vector<T> vertices;
      vector<set<int>> neighbors;
      breadth_first_search_iterator<int> bfs_iterator;
      vector<bool> visited;

      Graph() {}

      Graph(int n) {  for (int i = 0; i < n; ++i) {  AddVertex(0);  }   }

      void AddVertex(T val) {
          vertices.push_back(val);
          neighbors.push_back(set<int>());      }

      bool EdgeExists(int i, int j) {
          return (neighbors[i].find(j) != neighbors[i].end());
     }

      void AddEdge(int i, int j) {
          if (!EdgeExists(i,j)) {
            neighbors[i].insert(j);
            if (i != j) {         neighbors[j].insert(i);         } 
          }
      }

      T& operator[](int i) {      return vertices[i];      }

      void bfs_init(int start) {
          visited = vector<bool>(vertices.size(), false);
          bfs_iterator = breadth_first_search_iterator<int>(start, [this](int x){ return !visited[x]; }, [this](int x) { visited[x] = true;  },
            [this](int x) {  return neighbors[x];  } );
      }

};

template<class T>
struct SegmentData {
    int left, right;    // node represents interval [left, right)
    T max_in_interval;   // func of all elements in this interval 
    int prev;           // index of parent node -- equals -1 for root node
};

template<class T>
class SegmentTree : public DirectedGraph<SegmentData<T>> {
        // creates segment tree, with func(kao max) values at nodes; edges go from root down to children
    public:
      int root;        // index of root
      int data_size;   // size of data array
      vector<T> data;                    // data

    SegmentTree(int n, function<T(T,T)> f, T zero_v) : 
       default_val(zero_v), data(vector<T>(n, zero_v)), data_size(n), singleton_index(vector<int>(n, 0)), func(f)  {  
        // creates func segment tree
      root = HelperCreate(0, data.size());
      HelperSetPrev(root, -1);
    }

    T GetIntervalEvaluation(int x, int y) {  // returns func of interval [x,y)
      if (x >= y)  {   return default_val;  }  // this is where you determine what should be returned for empty interval
      return GetMaxHelper(x, y, root);
    }

    void SetVal(int index, T val) {
        data[index] = val;
        int curr = singleton_index[index];
        this->vertices[curr].max_in_interval = val;
        while (this->vertices[curr].prev >= 0) {
            curr = this->vertices[curr].prev;
            T ret = this->vertices[*(this->neighbors[curr].begin())].max_in_interval;
            if (this->neighbors[curr].size() > 1) {
                if (  this->vertices[*(this->neighbors[curr].begin())].left < this->vertices[ *next(this->neighbors[curr].begin())].right  ) {
                  ret = func(ret, this->vertices[ *next(this->neighbors[curr].begin())].max_in_interval );
                } else {
                  ret = func( this->vertices[ *next(this->neighbors[curr].begin())].max_in_interval, ret );
                }
            }
            this->vertices[curr].max_in_interval = ret;
        }
    }

    T operator[](int i) {    return data[i];     }

    private:
      T default_val;                     // zero/default value for data array
      function<T(T,T)> func;             // node is func of both children -- func should be associative
      vector<int> singleton_index;       // singleton_index[i] gives index of node in the graph for singleton [i,i+1)

      void HelperSetPrev(int root, int prev_) {
          this->vertices[root].prev = prev_;
          for (auto x : this->neighbors[root]) {      HelperSetPrev(x, root);       }
      }

      int HelperCreate(int left, int right) {
          if (right-left == 1) {
              this->AddVertex({left, right, default_val, 0});
              singleton_index[left] = this->vertices.size()-1;
              return this->vertices.size()-1;
          }
          int mid = (left+right)/2;
          int l1 = HelperCreate(left, mid);
          int r1 = HelperCreate(mid, right);
          this->AddVertex({left, right, default_val, 0});
          this->AddEdge(this->vertices.size()-1, l1); this->AddEdge(this->vertices.size()-1, r1);

          return this->vertices.size()-1;
      }

      T GetMaxHelper(int x, int y, int root) {
          if ((x == this->vertices[root].left) && (y == this->vertices[root].right)) {   return this->vertices[root].max_in_interval;   }
          int left = *(this->neighbors[root].begin());
          int right = *next(this->neighbors[root].begin());
          if (this->vertices[left].left > this->vertices[right].left) {  swap(left, right);   }
          int mid = this->vertices[left].right;
          if ((x < mid) && (y > mid))  {      return func(GetMaxHelper(x, mid, left), GetMaxHelper(mid, y, right));  }
          if ((x < mid) && (y <= mid)) {      return GetMaxHelper(x, y, left);      }
          if ((x >= mid) && (y > mid)) {      return GetMaxHelper(x, y, right);     }
      }
};

void Solve(SegmentTree<tuple<int,int,ll>>& joyf_count_n, DFST<int>& dfst, int root, vector<pair<int,ll>>& comm) {
  int from = dfst.to_v[root], to = dfst.from_v[root]+1;
  auto joyf_min = joyf_count_n.GetIntervalEvaluation(from+1, to);
  if (get<0>(joyf_min) == modd) {
      comm.push_back(make_pair(-root-1, from+1));
      joyf_count_n.SetVal(from, make_tuple(modd, 0, 0));
//      g[root] = 0;
//      if (dfst.DFSTour[dfst.to_v[root]].first>=0) {    g[dfst.DFSTour[dfst.to_v[root]].first]--; }
      return;
  }
  ll subtreebelow = get<2>(joyf_count_n.GetIntervalEvaluation(dfst.to_v[get<1>(joyf_min)], dfst.from_v[get<1>(joyf_min)]+1));
  ll subtree_complement = get<2>(joyf_count_n.GetIntervalEvaluation(from, to)) - subtreebelow;
//  ll subtreebelow = g[get<1>(joyf_min)];
//  ll subtree_complement = g[root] - subtreebelow;
  comm.push_back(make_pair(dfst.to_v[get<1>(joyf_min)], subtree_complement * (ll)get<0>(joyf_min) - subtreebelow * (ll)get<0>(joyf_min)));
  comm.push_back(make_pair(dfst.from_v[get<1>(joyf_min)], - subtree_complement * (ll)get<0>(joyf_min) + subtreebelow * (ll)get<0>(joyf_min)));
  comm.push_back(make_pair(from, subtreebelow * (ll)get<0>(joyf_min)));
  comm.push_back(make_pair(to-1, - subtreebelow * (ll)get<0>(joyf_min)));

  Solve(joyf_count_n, dfst, get<1>(joyf_min), comm);
  Solve(joyf_count_n, dfst, root, comm);
}

int main()   {

    ios_base::sync_with_stdio(false);

    cout.precision(17);
//    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//    uniform_int_distribution<int> rand_gen(0, modd);   // rand_gen(rng) gets the rand no
 
//    auto start = chrono::steady_clock::now();
  
//    readint(test_cases);
    int test_cases = 1;
    forr(t, 1, test_cases) {
        readint(n);
        Graph<int>* g = new Graph<int>(n);
        map<pair<int,int>,int>* joy = new map<pair<int,int>,int>;
        forr(i,0,n-1) {
            readint(u); readint(v); readint(j);
            g->AddEdge(u-1, v-1);
            (*joy)[make_pair(u-1,v-1)] = j;
        }

        DirectedGraph<int>* g_dir = new DirectedGraph<int>(n);
        g->bfs_init(0); ++(*g).bfs_iterator;
        while (!(*g).bfs_iterator.end()) {
            g_dir->AddEdge((*g).bfs_iterator.previous(), *(*g).bfs_iterator);
            ++(*g).bfs_iterator;
        }
        delete g;

        DFST<int>* dfstour = new DFST<int>(*g_dir, 0);

        SegmentTree<tuple<int,int,ll>>* joyfulness = new SegmentTree<tuple<int,int,ll>>(dfstour->DFSTour.size(), [](tuple<ll,int,ll> x, tuple<ll,int,ll> y){
            tuple<ll,int,ll> ret;
            if (get<0>(x) < get<0>(y)) {
                get<0>(ret) = get<0>(x); get<1>(ret) = get<1>(x);
            } else {
                get<0>(ret) = get<0>(y); get<1>(ret) = get<1>(y);
            }
            get<2>(ret) = get<2>(x)+get<2>(y);
            return ret; }, make_tuple(modd,0,0));

        for (auto e : (*joy)) {
            int vert;
            if (g_dir->EdgeExists(e.first.first, e.first.second)) {
                vert = e.first.second;
            } else {
                vert = e.first.first;
            }
            joyfulness->SetVal(dfstour->to_v[vert], make_tuple(e.second, vert, 0));
        }
        for (auto v : dfstour->to_v) {  joyfulness->SetVal(v, make_tuple(get<0>(joyfulness->data[v]), get<1>(joyfulness->data[v]), 1));   }
        delete joy;
        delete g_dir;

        vector<pair<int,ll>>* commands = new vector<pair<int,ll>>;
        Solve(*joyfulness, *dfstour, 0, *commands);

        forr(i,0,dfstour->DFSTour.size()) {
            joyfulness->SetVal(i, make_tuple(0,0,0));
        }
        delete dfstour;
        vector<ll>* output = new vector<ll>(n);
        for(auto x : *commands) {
            if (x.first<0) {
                (*output)[-x.first-1] = get<2>(joyfulness->GetIntervalEvaluation(0, x.second));
            } else {
                joyfulness->SetVal(x.first, make_tuple(0,0,get<2>(joyfulness->data[x.first]) + x.second));
            }
        }
        delete commands;
        delete joyfulness;

        for(auto x : *output) {
            cout << x << endl;
        }
        delete output;

    }
 
//    auto end = chrono::steady_clock::now();
//    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;
 
    return 0;
}
