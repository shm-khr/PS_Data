#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>

using namespace std;

class S{
public:
  int y, x, d;
  S(){}
  S(int y, int x, int d) : y(y), x(x), d(d) {}
  bool operator < (const S &s) const {
    if(y == s.y){
      if(x == s.x){
        return d < s.d;
      }
      return x < s.x;
    }
    return y < s.y;
  }
};

typedef pair<int, S> P;

const int N = 1000;
const int M = 1000001;
const int MAX_V = N * N * 4;
const int INF = 1 << 28;

int V, h, w, n, gx, gy;
int G[M][4];
int d[N][N][4];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
char dat[N][N];

bool dijkstra(S s){
  priority_queue<P, vector<P>, greater<P> > que;
  fill(d[0][0], d[N][0], INF);
  d[s.y][s.x][s.d] = 0;
  que.push(P(0, s));
  while(!que.empty()){
    P p = que.top(); que.pop();
    S v = p.second;
    if(v.y == gy && v.x == gx) return true;
    if(d[v.y][v.x][v.d] < p.first) continue;
    for(int i=0;i<4;i++){
      int cost = G[p.first][i];
      if(cost == -1) continue;
      int ny = v.y + dy[i];
      int nx = v.x + dx[i];
      if(ny < 0 || ny >= h) continue;
      if(nx < 0 || nx >= w) continue;
      if(dat[ny][nx] == '#') continue;
      if(d[ny][nx][i] > d[v.y][v.x][v.d] + cost){
        d[ny][nx][i] = d[v.y][v.x][v.d] + cost;
        que.push(P(d[ny][nx][i], S(ny, nx, i)));
      }
    }
  }
  return false;
}

void init(){
  fill(G[0], G[M], -1);
}

main(){
  while(cin >> h >> w >> n && (h|w|n)){
    init();
    string L;
    cin >> L;
    int sy, sx;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        cin >> dat[i][j];
        if(dat[i][j] == 'S'){
          sy = i;
          sx = j;
          dat[i][j] = '.';
        }
        if(dat[i][j] == 'G'){
          gy = i;
          gx = j;
          dat[i][j] = '.';
        }
      }
    }
    vector<int> vec[4];
    vec[0].push_back(0);
    int dir = 0;
    for(int i=0;i<n;i++){
      if(L[i] == 'L'){
        dir = (dir + 3) % 4;
      }else{
        dir = (dir + 1) % 4;
      }
      vec[dir].push_back(i+1);
    }
    for(int i=0;i<4;i++){
      for(int j=0;j<vec[i].size();j++){
        for(int k=0;k<4;k++){
          int p = lower_bound(vec[k].begin(), vec[k].end(), vec[i][j]) - vec[k].begin();
					int tmp = -1;
					if(p < vec[k].size()){
						tmp = vec[k][p];
					}
          G[vec[i][j]][k] = tmp;
        }
      }
    }
    cout << (dijkstra(S(sy, sx, 0)) ? "Yes" : "No") << endl;
  }
}