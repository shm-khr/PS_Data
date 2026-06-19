#include<bits/stdc++.h>
using namespace std;


#define EPS (1e-10)
#define equal(a,b) (fabs((a)-(b)) < EPS)

class Point {
  public:

  double x,y;
  
  Point (double x = 0, double y = 0) : x(x),y(y) {}
 
  Point operator + (Point p) {
    return Point( x+p.x , y+p.y );
  }
  Point operator - (Point p) {
    return Point( x-p.x , y-p.y );
  }
  Point operator * (double a) {
    return Point( a*x , a*y );
  }
 
  double abs() {
    return sqrt(norm());
  }
  double norm() {
    return x*x+y*y;
  }
 
  bool operator < (const Point &p) const {
    return x != p.x ? x < p.x : y < p.y;
  }
 
  bool operator == (const Point &p) const {
    return equal( x,p.x )&& equal( y,p.y );
  }
};

typedef Point Vector;
 
double dot(Vector a,Vector b) {
  return a.x*b.x + a.y*b.y;
}
 
double cross(Vector a,Vector b) {
  return a.x*b.y - b.x*a.y;
}

Vector rotation(Vector vec,double si,double co){
  Vector res;
  res.x = vec.x*co - vec.y*si;
  res.y = vec.x*si + vec.y*co;
  return res;
}

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;
 
int ccw( Point p0 , Point p1 , Point p2 ) {
  Vector a = p1 - p0;
  Vector b = p2 - p0;
  if( cross(a,b) > EPS ) return COUNTER_CLOCKWISE;
  if( cross(a,b) < -EPS ) return CLOCKWISE;
  if( dot(a,b) < -EPS ) return ONLINE_BACK;
  if( a.norm() < b.norm() ) return ONLINE_FRONT;
  return ON_SEGMENT;
}

class Segment{
    public:
    Point p1, p2;
    Segment(Point s = Point(), Point t = Point()): p1(s), p2(t){}
};
typedef Segment Line;

Point getCrossPointLL(Line l1,Line l2){
  Point p1=l1.p1,p2=l1.p2;
  Point q1=l2.p1,q2=l2.p2;
  Point res;
  res= p1+(p2-p1)*( cross(q2-q1,q1-p1)/cross(q2-q1,p2-p1) );
  return res;
}


vector<Point> andrewScan(vector<Point> s){
  vector<Point> u,l;
  int size = s.size();

  if(size < 3) return s;
  sort(s.begin(),s.end());

  u.push_back(s[0]);
  u.push_back(s[1]);
  l.push_back(s[size-1]);
  l.push_back(s[size-2]);

  for(int i = 2 ; i < size ; i++){
    for(int n = u.size() ; n >=2 && ccw(u[n-2],u[n-1],s[i]) != CLOCKWISE; n--){
      u.pop_back();
    }
    u.push_back(s[i]);
  }

  for(int i = size-3 ; i >= 0 ; i--){
    for(int n = l.size() ; n >=2 && ccw(l[n-2],l[n-1],s[i]) != CLOCKWISE; n--){
      l.pop_back();
    }
    l.push_back(s[i]);
  }

  reverse(l.begin(),l.end());

  for(int i = u.size() -2 ; i >= 1 ; i--){
    l.push_back(u[i]);
  }

  return l;
}

double calcArea(vector<Point> &po){
  int size=po.size();
  if(size<3)return 0.0;
  double res=0.0;
  for(int i=1;i+1<size;i++){
    res+=fabs(cross(po[i]-po[0],po[i+1]-po[0]));
  }
  return res*0.5;
}

vector<Point> cutC(vector<Point> &t,Line li){
  vector<Point> res;
  int n=t.size();
  for(int i=0;i<n;i++){
    int j=(i+1)%n;
    Segment se=Segment(t[i],t[j]);
    if(ccw(li.p1,li.p2,t[i])!=CLOCKWISE)res.push_back(t[i]);
    Point p=getCrossPointLL(se,li);
    if(ccw(se.p1,se.p2,p)==ON_SEGMENT)res.push_back(p);
  }
  
  return andrewScan(res);
}


int n,m;
double d,V;
vector<Point> G,G2;


int main(){
  cin>>n;
  G.resize(n);
  for(int i=0;i<n;i++)cin>>G[i].x>>G[i].y;
  Segment se;
  cin>>m;
  for(int i=0;i<m;i++){
    cin>>se.p1.x>>se.p1.y>>se.p2.x>>se.p2.y;
    G2=cutC(G,se);
    printf("%.10f\n",calcArea(G2));
  }
  return 0;
}