#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int,int> P;

class State{
public:
  vector<P> v;
  int cost;

  State(){}
  State(const vector<P> &v, const int &cost) : 
    v(v), cost(cost) {}
};

int n;
P goal;

vector<int> okBit;

set< vector<P> > closed;
set< P > rocks;

vector<int> dir[7][7];
int dx[] = { 0,  1, 1, 0, -1, -1};
int dy[] = {-1, -1, 0, 1,  1,  0};

int rd[3][3];

bool isAdj(const P &a, const P &b){
  for(int i = 0; i < 6; i++){
    P np(a.first + dx[i], a.second + dy[i]);
    if(np == b){
      return true;
    }
  }
  return false;
}

bool alive(const vector<P> &v){
  //障害物上に節が乗っていないかの判定
  for(int i = 0; i < n; i++){
    if(rocks.find(v[i]) != rocks.end()){
      return false;
    }
  }

  //同じ場所に複数の節が存在しないか判定
  for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){
      if(v[i] == v[j]){
	return false;
      }
    }
  }

  //ある節がくっついているべき節とだけくっついているか判定
  for(int i = 0; i < n; i++){
    if(i + 1 < n && !isAdj(v[i], v[i + 1])){
      return false;
    }

    for(int j = i + 2; j < n; j++){
      if(isAdj(v[i], v[j])){
	return false;
      }
    }
  }
  return true;
}

//ok
void rec(int idx, bool befUsed, State st, queue<State> &open){
  //ok
  if(idx == n){
    st.cost++;
    if(closed.find(st.v) == closed.end() && alive(st.v)){
      closed.insert(st.v);
      open.push(st);
    }
    return;
  }

  //ok
  rec(idx + 1, false, st, open);

  //ok
  if(befUsed){
    return;
  }

  //ok
  int x = st.v[idx].first;
  int y = st.v[idx].second;

  //ok
  int ldir = (idx - 1 < 0 ? 6 : rd[st.v[idx - 1].first - x + 1][st.v[idx - 1].second - y + 1]);
  int rdir = (idx + 1 >= n ? 6 : rd[st.v[idx + 1].first - x + 1][st.v[idx + 1].second - y + 1]);

  //ok
  for(int i = 0; i < dir[ldir][rdir].size(); i++){
    int dd = dir[ldir][rdir][i];
    P np(x + dx[dd], y + dy[dd]);
    st.v[idx] = np;
    rec(idx + 1, true, st, open);
  }
}

void solve(const State &st0){
  queue<State> open;
  open.push(st0);
  closed.clear();
  closed.insert(st0.v);

  int cnt = 0;

  while(!open.empty()){
    State st = open.front();
    open.pop();

    if(st.v[0] == goal){
      cout << st.cost << endl;
      return;
    }

    rec(0, false, st, open);
  }

  cout << -1 << endl;
}

int main(){
  //ok
  for(int i = 0; i < 6; i++){
    rd[dx[i] + 1][dy[i] + 1] = i;
  }

  //ok
  for(int i = 0; i < 7; i++){
    for(int j = 0; j < 7; j++){
      if(i == j) continue;

      for(int k = 0; k < 6; k++){
	if(i == k || j == k) continue;

	vector<P> v;
	if(i != 6) v.push_back(P(dx[i], dy[i]));
	v.push_back(P(dx[k], dy[k]));
	if(j != 6) v.push_back(P(dx[j], dy[j]));

	n = v.size();

	if(alive(v)){
	  dir[i][j].push_back(k);
	}
      }
    }
  }

  //ok
  while(cin >> n, n){
    vector<P> v;

    for(int i = 0; i < n; i++){
      P p;
      cin >> p.first >> p.second;
      v.push_back(p);
    }

    int k;
    cin >> k;
    rocks.clear();

    for(int i = 0; i < k; i++){
      P p;
      cin >> p.first >> p.second;
      rocks.insert(p);
    }

    cin >> goal.first >> goal.second;

    solve(State(v, 0));
  }
}