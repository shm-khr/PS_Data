#include<iostream>
#include<cstdio>
#include<cfloat>
#include<cassert>
#include<cmath>
#include<vector>
#include<set>
#include<algorithm>
   
using namespace std;
#define rep(i,n)for ( int i = 0; i < n; i++)
   
#define EPS (1e-12)
#define equals(a, b) (fabs((a) - (b)) < EPS )
#define dle(a, b) (equals(a, b) || a < b )
   
static const double PI = acos(-1);
   
class Point{
    public:
    double x, y;
    Point ( double x = 0, double y = 0): x(x), y(y){}
    Point operator + ( Point p ){ return Point(x + p.x, y + p.y); }
    Point operator - ( Point p ){ return Point(x - p.x, y - p.y); }
    Point operator * ( double a ){ return Point(x*a, y*a); }
    Point operator / ( double a ){ return Point(x/a, y/a); }
    Point operator / ( Point p ) { return Point((x*p.x+y*p.y)/(p.x*p.x+p.y*p.y), (y*p.x-x*p.y)/(p.x*p.x+p.y*p.y)); }
   
    double abs() { return sqrt(norm());}
    double norm() { return x*x + y*y; }
   
    bool operator < ( const Point &p ) const {
    return x != p.x ? x < p.x : y < p.y;
    }
   
    bool operator == ( const Point &p ) const {
    return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS;
    }
};
   
typedef Point Vector;
   
class Segment{
    public:
    Point p1, p2;
    Segment(Point s = Point(), Point t = Point()): p1(s), p2(t){}
};
   
typedef Segment Line;
typedef vector<Point> Polygon;
   
double norm( Vector a ){ return a.x*a.x + a.y*a.y; }
double abs( Vector a ){ return sqrt(norm(a)); }
Point polar( double a, double r ){ return Point(cos(r)*a, sin(r)*a);}
double getDistance( Vector a, Vector b ){ return abs(a - b); }
double dot( Vector a, Vector b ){ return a.x*b.x + a.y*b.y; }
double cross( Vector a, Vector b ){ return a.x*b.y - a.y*b.x; }
double arg(Vector p){ return atan2(p.y, p.x); }
   
bool isOnSegment( Point a, Point b, Point c){
    if ( a == c || b == c ) return true;
    return (abs(a-c) + abs(c-b) < abs(a-b) + EPS );
}
   
static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;
   
int ccw( Point p0, Point p1, Point p2 ){
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if ( cross(a, b) > EPS ) return COUNTER_CLOCKWISE;
    if ( cross(a, b) < -EPS ) return CLOCKWISE;
    if ( dot(a, b) < -EPS ) return ONLINE_BACK;
    if ( norm(a) < norm(b) ) return ONLINE_FRONT;
    return ON_SEGMENT;
}
   
bool isIntersect(Point p1, Point p2, Point p3, Point p4){
    return ( ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
         ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0 );
}
   
bool isIntersect(Segment s1, Segment s2){
    return isIntersect(s1.p1, s1.p2, s2.p1, s2.p2);
}
   
Point getCrossPoint(Segment s1, Segment s2){
    assert( isIntersect(s1, s2) );
    // for boundary touch (end-point to end-point)
    if ( s1.p1 == s2.p1 ) return s1.p1;
    if ( s1.p1 == s2.p2 ) return s1.p1;
    if ( s1.p2 == s2.p1 ) return s1.p2;
    if ( s1.p2 == s2.p2 ) return s1.p2;
    Vector base = s2.p2 - s2.p1; 
    double d1 = abs(cross(base, s1.p1 - s2.p1));
    double d2 = abs(cross(base, s1.p2 - s2.p1));
    double t = d1/(d1 + d2);
    return s1.p1 + (s1.p2 - s1.p1)*t;
}
   
/*
 IN 2
 ON 1
 OUT 0
 */
int contains(vector<Point>pol,Point p){
  bool in=false;
  for(int i=0;i<pol.size();i++){
    Point a=curr(pol,i)-p,b=next(pol,i)-p;
    if(a.y>b.y)swap(a,b);
    if(a.y<EPS && EPS<b.y && cross(a,b)>EPS)in=!in;
    if(abs(cross(a,b))<EPS && dot(a,b)<EPS)return 2;
  }
  return in?1:0;
} 
class Edge{
public:
  int target;
  double dist;
  Edge(){}
  Edge(int target, double dist): target(target), dist(double(dist)){}
};
   
class Graph{
public:
  vector<vector<Edge> > adjList;
  int start;
  Graph(){}
  Graph(int n){
    adjList.resize(n);
    rep(i, n) adjList[i].clear();
  }
  void connect( int i, int j, double d ){
    adjList[i].push_back(Edge(j, d));
  }
};
   
Graph segmentArrangement(vector<Segment> S, vector<Point> &P){
  P.clear();
  for ( int s = 0; s < S.size()-1; s++ ){
    P.push_back(S[s].p1);
    P.push_back(S[s].p2);
    for ( int t = s+1; t < S.size(); t++ ){
      if ( !isIntersect(S[s], S[t]) ) continue;
      P.push_back(getCrossPoint(S[s], S[t]));
    }
  }
  sort(P.begin(), P.end()); P.erase(unique(P.begin(), P.end()), P.end());
   
  Graph g = Graph(P.size());
   
  for ( int i = 0; i < S.size(); i++ ){
    vector<pair<double, int> > L;
    for ( int j = 0; j < P.size(); j++ ){
      if ( ccw(S[i].p1, S[i].p2, P[j]) == ON_SEGMENT || isOnSegment(S[i].p1, S[i].p2, P[j]) ) {
    L.push_back(make_pair(norm(S[i].p1-P[j]), j));
      }
    }
    sort(L.begin(), L.end());
    for ( int j = 0; j+1 < L.size(); j++ ){
      int a = L[j].second;
      int b = L[j+1].second;
      g.connect(a, b, 0.0);
      g.connect(b, a, 0.0);
    }
  }
   
  // sort by angle
  for ( int k = 0; k < g.adjList.size(); k++ ){
    for ( int e = g.adjList[k].size()-2; e >= 0; e-- ){
      for ( int j = 0; j <= e; j++ ){
    int t1 = g.adjList[k][j].target;
    int t2 = g.adjList[k][j+1].target;
    double angle1 = atan2(P[t1].y - P[k].y, P[t1].x - P[k].x);
    double angle2 = atan2(P[t2].y - P[k].y, P[t2].x - P[k].x);
    if ( angle1 > angle2 ) swap( g.adjList[k][j], g.adjList[k][j+1]);
      }
    } 
  }
   
  return g;
}
   
bool ans;
   
void parse(Graph &g, int s, int t, set<pair<int, int> > &V, vector<Point> &P){
  int cur1 = s, cur2 = t;
  vector<int> p;
   
  while(1){
    if ( V.find(make_pair(cur1, cur2)) != V.end() ){
      reverse(p.begin(), p.end());
      vector<Point> pl;
      for ( int i = 0; i < p.size(); i++ ) pl.push_back(P[p[i]]);
      if ( contains(pl, Point(0,0)) == 1 ) ans = true;
      break;
    }
    p.push_back(cur1);
    V.insert(make_pair(cur1, cur2));
    int nx;
    for ( int i = 0; i < g.adjList[cur2].size(); i++ ){
      if ( g.adjList[cur2][i].target == cur1 ){ nx = i; break; }
    }
    nx = (nx+1)%g.adjList[cur2].size();
    cur1 = cur2;
    cur2 = g.adjList[cur2][nx].target;
  }
}
   
int main(){
  int sn;
   
  while(1){
    cin >> sn;
    if ( sn == 0 ) break;
    double x1, y1, x2, y2;
    vector<Segment> S;
    for ( int i = 0; i < sn; i++ ){
      cin >> x1 >> y1 >> x2 >> y2;
      S.push_back(Segment(Point(x1, y1), Point(x2, y2)));
    }
       
    vector<Point> P;
    Graph g = segmentArrangement(S, P);
   
    set<pair<int, int> > V;
   
    ans = false;
    for ( int s = 0; s < g.adjList.size(); s++ ){
      for ( int j = 0; j < g.adjList[s].size(); j++ ){
    int t = g.adjList[s][j].target;
    if ( s == t ) continue;
    if ( V.find(make_pair(s, t) ) == V.end() )  parse(g, s, t, V, P);
      }
    }
    if ( ans ) cout << "yes" << endl;
    else cout << "no" << endl;
  }
}