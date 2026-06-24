#include<bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pi M_PI
#define inf 1<<30
#define eps (1e-11)
#define MAX 1000
#define equals(a,b) (fabs((a)-(b))<eps)
using namespace std;

class Point{
public:
  double x,y;
  Point(double x=0,double y=0):x(x),y(y){}

  Point operator+(Point p){ return Point(x+p.x,y+p.y);}
  Point operator-(Point p){ return Point(x-p.x,y-p.y);}
  Point operator*(double k){ return Point(x*k,y*k);}
  Point operator/(double k){ return Point(x/k,y/k);}
  bool operator<(Point p)const{ return (x!=p.x ? x<p.x : y<p.y);}
  bool operator==(Point p)const{ return fabs(x-p.x)<eps && fabs(y-p.y)<eps;}

  double abs(){ return sqrt(norm());}
  double norm(){ return (x*x+y*y);}
};
typedef Point Vector;
typedef vector<Point> Polygon;

class Segment{
public:
  Point p1,p2;
  Segment(Point p1=Point(),Point p2=Point()):p1(p1),p2(p2){}
};
typedef Segment Line;

double norm(Vector a){ return (a.x*a.x+a.y*a.y);}
double abs(Vector a){ return sqrt(norm(a));}
double dot(Vector a,Vector b){ return (a.x*b.x+a.y*b.y);}
double cross(Vector a,Vector b){ return (a.x*b.y-a.y*b.x);}

int ccw(Point p0,Point p1,Point p2){
  Vector a=p1-p0;
  Vector b=p2-p0;
  if(cross(a,b)>eps)return 1;
  if(cross(a,b)<-eps)return -1;
  if(dot(a,b)<-eps)return 2;
  if(a.norm()<b.norm())return -2;
  return 0;
}

bool intersect(Point p1,Point p2,Point p3,Point p4){
  return (ccw(p1,p2,p3)*ccw(p1,p2,p4)<=0 &&
          ccw(p3,p4,p1)*ccw(p3,p4,p2)<=0);
}

bool intersect(Segment s1,Segment s2){
  return intersect(s1.p1,s1.p2,s2.p1,s2.p2);
}

Point getCrossPointSS(Segment s1,Segment s2){
  Vector base=s2.p2-s2.p1;
  double d1=abs(cross(base,s1.p1-s2.p1));
  double d2=abs(cross(base,s1.p2-s2.p1));
  double t=d1/(d1+d2);
  return (s1.p1+(s1.p2-s1.p1)*t);
}

int contains(Polygon g,Point p){
  int n=g.size();
  bool x=false;
  for(int i=0;i<n;i++){
    Vector a=g[i]-p,b=g[(i+1)%n]-p;
    if(abs(cross(a,b))<eps && dot(a,b)<eps)return 1;
    if(a.y>b.y)swap(a,b);
    if(a.y<eps && eps<b.y && cross(a,b)>eps)x=!x;
  }
  if(x)return 2;
  return 0;
}

typedef vector<vector<int> > Graph;

Graph SegmentArrangement(vector<Segment> v,vector<Point> &ps){
  for(int i=0;i<v.size();i++){
    ps.push_back(v[i].p1);
    ps.push_back(v[i].p2);
    for(int j=i+1;j<v.size();j++){
      if(intersect(v[i],v[j]))ps.push_back(getCrossPointSS(v[i],v[j]));
    }
  }
  sort(ps.begin(),ps.end());
  ps.erase(unique(ps.begin(),ps.end()),ps.end());
  Graph g(ps.size());
  for(int i=0;i<v.size();i++){
    vector<pair<double,int> > list;
    for(int j=0;j<ps.size();j++)
      if(ccw(v[i].p1,v[i].p2,ps[j])==0)
        list.push_back(mp(norm(v[i].p1-ps[j]),j));
    sort(list.begin(),list.end());
    for(int j=0;j<list.size()-1;j++){
      int a=list[j].s,b=list[j+1].s;
      g[a].push_back(b);
      g[b].push_back(a);
    }
  }
  return g;
}

Graph g;
vector<Point> vp;
bool checked[MAX];
bool visited[MAX];
vector<int> v;
string ans="no";

void dfs(int now,int before){
  v.push_back(now);
  if(visited[now]){
    int s;
    for(int i=0;i<v.size();i++){
      if(v[i]==now){
        s=i+1;
        break;
      }
    }
    Polygon p;
    for(int i=s;i<v.size();i++)p.push_back(vp[v[i]]);
    if(contains(p,Point(0,0))!=0)ans="yes";
  }
  else {
    visited[now]=true;
    for(int i=0;i<g[now].size();i++){
      int next=g[now][i];
      if(next==before)continue;
      if(!checked[next])dfs(next,now);
    }
    visited[now]=false;
  }
  v.pop_back();
  checked[now]=true;
}

int main()
{
  int n;
  
  while(1){
    cin>>n;
    if(n==0)break;
    vector<Segment> v;
    for(int i=0;i<n;i++){
      int a,b,c,d;
      cin>>a>>b>>c>>d;
      v.push_back(Segment(Point(a,b),Point(c,d)));
    }
    vp.clear();
    g=SegmentArrangement(v,vp);
    ans="no";
    fill(checked,checked+MAX,0);
    for(int i=0;i<vp.size();i++){
      fill(visited,visited+MAX,0);
      v.clear();
      if(!checked[i])dfs(i,-1);
    }
    cout<<ans<<endl;
  }
  return 0;
}