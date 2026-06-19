#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
//C++11
#if __cplusplus == 201103L
#include <tuple>
#endif

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cout<<*i<<" "; cout<<endl; }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
string piece[9];
int rot[9];
int check[12][4] = {
  {1, 3, 0, 1},
  {2, 3, 1, 1},
  {3, 0, 0, 2},
  {4, 0, 1, 2},
  {4, 3, 3, 1},
  {5, 0, 2, 2},
  {5, 3, 4, 1},
  {6, 0, 3, 2},
  {7, 0, 4, 2},
  {7, 3, 6, 1},
  {8, 0, 5, 2},
  {8, 3, 7, 1}
};
int toint(char c){
  if(isupper(c)) return c - 'A';
  else return c - 'a';
}
int dfs(int u){
  for(int i = 0; i < 12; i++){
    int p = check[i][0], q = check[i][2];
    int c1 = (check[i][1] + rot[p]) % 4, c2 = (check[i][3] + rot[q]) % 4;
    if(p >= u) break;
    if(toint(piece[p][c1]) != toint(piece[q][c2]) || piece[p][c1] == piece[q][c2]) return 0;
  }
  if(u == 10) return 1;
  int res = 0;
  for(int i = 0; i <= 3; i++){
    rot[u] = i;
    res += dfs(u + 1);
  }
  return res;
}
int main(){
  int T; cin>>T;
  while(T--){
    REP(i, 9) cin>>piece[i];
    sort(piece, piece + 9);
    int ans = 0;
    do{
      ans += dfs(0);
    }while(next_permutation(piece, piece + 9));
    cout<<ans/4<<endl;
  }
  return 0;
}