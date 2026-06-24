#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
#define REP(i, j) for(int i = 0; i < j; i++)
#define FOR(i, j, k) for(int i = j; i < k; i++)
#define Pa pair<int, int>
#define Y first
#define X second
const int N = 7;
const int M = 7;
const int P = N * N * N;

int n, m, p, dx[N][N][N], cnt[N][N];
vector<Pa> v;

bool is_m(int type, int x, int y, int z, int mx, int my, int mz){
  REP(i, m){
    if(y >= n || x >= n || z >= n || dx[x][y][z] != type) return false;
    x += mx;
    y += my;
    z += mz;
  }
  return true;
}

Pa check(){
  int mx[] = {1, 0, 1, 0, 1, 1, 0, 1};
  int my[] = {0, 1, 0, 1, 1, 0, 1, 1};
  int mz[] = {0, 0, 1, 1, 1, -1, -1, -1};
  REP(turn, p){
    int type = turn % 2, y = v[turn].Y, x = v[turn].X;
    dx[x][y][cnt[y][x]] = type;
    ++cnt[x][y];
    REP(ny, n) REP(nx, n) REP(nz, n) REP(i, 8) if(is_m(type, nx, ny, nz, mx[i], my[i], mz[i])) return Pa(type, turn + 1);
  }
  return Pa(-1, -1);
}

int main(){
  while(cin >>n >>m >>p && n){
    REP(i, N) REP(j, N) REP(k, N) dx[i][j][k] = -1;
    memset(cnt, 0, sizeof(cnt));
    v = vector<Pa>(p);
    REP(i, p){
      cin >>v[i].X >>v[i].Y;
      --v[i].X;
      --v[i].Y;
    }
    Pa ans = check();
    if(ans.first == -1) cout <<"Draw" <<endl;
    else if(ans.first == 0) cout <<"Black " <<ans.second <<endl;
    else if(ans.first == 1) cout <<"White " <<ans.second <<endl;
  }
  return 0;
}