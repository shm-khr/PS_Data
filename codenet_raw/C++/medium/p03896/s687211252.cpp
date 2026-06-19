#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fst first
#define snd second
#define all(v) begin(v), end(v)
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
typedef vector<char> vc;
typedef vector<vector<char> > vvc;
typedef vector<double> vd;
typedef vector<vector<double> > vvd;
template<class T> using vv=vector<vector< T > >;
typedef deque<int> di;
typedef deque<deque<int> > ddi;
typedef deque<bool> db;
typedef deque<deque<bool> > ddb;

vvi solve_body(int len, int offset) {
  vvi ret(len, vi(len-1));
  if (len == 4) {
    ret[0] = {2, 3, 4};
    ret[1] = {3, 1, 4};
    ret[2] = {4, 2, 1};
    ret[3] = {1, 2, 3};
    return ret;
  }
  if (len % 2 == 1) {
    rep (i, len) {
      rep (j, len-1) {
        ret[i][j] = (i+j+1) % len + 1;
        ret[i][j] += offset;
      }
    }
    return ret;
  }
  int le = len / 2;
  vvi lu = solve_body(le, offset);
  vvi rb = solve_body(le, offset + le);
  rep (i, le) {
    rep (j, le-1) {
      ret[i][j] = lu[i][j];
      ret[i+le][j+le-1] = rb[i][j];
    }
  }
  rep (i, le) {
    rep (j, le-1) {
      ret[i][j+le-1] = le + (i + j + 1) % le + 1;
      ret[i+le][j] = (i + j + 2) % le + 1;
    }
  }
  rep (i, le) {
    ret[i][len-2] = le + i + 1;
    ret[i+le][len-2] = (i + 1) % le + 1;
  }
  return ret;
}

vvi solve(vi &part) {
  int len = part.size();
  int offset = part[0];
  vvi ret = solve_body(len, offset);
  return ret;
}

int main() {
  int n;
  cin >> n;
  if (n == 2) {
    printf("-1\n");
    return 0;
  }
  vi orig(n);
  rep (i, n) {
    orig[i] = i;
  }

  vvi ans = solve(orig);

  rep (i, n) {
    rep (j, n-2) {
      printf("%d ", ans[i][j]);
    }
    printf("%d\n", ans[i][n-2]);
  }

  return 0;
}
