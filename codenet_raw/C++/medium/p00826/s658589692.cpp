#include <iostream>
#include <complex>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
using P = complex<double>;
using L = pair<P,P>;
#define X real()
#define Y imag()
const double EPS = 1e-6, INF = 1e12;

double dot(P &a, P &b){ return a.X*b.X + a.Y*b.Y;}
double cross(P &a, P &b){ return a.X*b.Y - a.Y*b.X;}

int ccw(P a, P b, P c){
  b -= a, c -= a;
  if(cross(b,c) > EPS) return 1;
  if(cross(b,c) < -EPS) return -1;
  if(dot(b,c) < EPS) return 2;
  if(norm(b) - EPS < norm(c)) return -2;
  return 0;
}

bool is_cross(L a, L b){
  P af = a.first, as = a.second, bf = b.first, bs = b.second;
  return (ccw(af,as,bs)*ccw(af,as,bf) <= 0) and (ccw(bf,bs,af)*ccw(bf,bs,as) <= 0);
}

int main(){
  int n;
  while(cin >> n, n){
    vector<L> Lines;
    for(int i = 0; i < n; ++i){
      double x, y, z, w;
      cin >> x >> y >> z >> w;
      x *= 100;
      y *= 100;
      z *= 100;
      w *= 100;
      Lines.emplace_back(P(x,y),P(z,w));
    }
    for(int i = 0; i < n; ++i){
      P d = Lines[i].second - Lines[i].first;
      d /= abs(d);
      Lines[i].second += d*(3*EPS);
      Lines[i].first -= d*(3*EPS);
    }
    vector< vector<int> > Adj(2*n+2, vector<int>(2*n+2,true));
    int M = 2*n + 2;
    vector<P> Points(M);
    for(int i = 0; i < n; ++i){
      Points[2*i] = Lines[i].first;
      Points[2*i+1] = Lines[i].second;
    }
    Points[2*n] = P(0,0);
    Points[2*n+1] = P(100000,100000);
    for(int i = 0; i < M; ++i){
      for(int j = 0; j < i; ++j){
        if(i == j) continue;
        if(i < 2*n and i%2 == 0 and (j-i) == 1) continue;
        for(int k = 0; k < n; ++k){
          if(is_cross(L(Points[i],Points[j]),Lines[k])){
            Adj[i][j] = false;
            Adj[j][i] = false;
            break;
          }
        }
      }
    }
    for(int k = 0; k < M; ++k){
      for(int i = 0; i < M; ++i)
        for(int j = 0; j < M; ++j)
          Adj[i][j] |= Adj[i][k]&Adj[k][j];
    }
    if(Adj[M-1][M-2]) cout << "no" << endl;
    else cout << "yes" << endl;
  }
}

