#include<iostream>
#include<algorithm>
#include<cmath>
#include<cassert>
#include<vector>
#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define EPS (1e-10)
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1 
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0
#define equals(a,b) (fabs((a)-(b)) < EPS)
#define inf (1<<28)
using namespace std;

class Point
{
  public:
  double x,y;

  Point(double x = -1,double y = -1): x(x),y(y){}

  Point operator + (Point p ){return Point(x+p.x,y+p.y);}
  Point operator - (Point p){return Point(x-p.x,y-p.y);}
  Point operator * (double a){return Point(a*x,a*y);}
  Point operator / (double a){return Point(x/a,y/a);}//※イケメンに限る

  bool operator < (const Point& p) const
  {
    return x != p.x?x<p.x:y<p.y;
  }

  bool operator == (const Point& p)const
  {
    return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS;
  }

//必要に応じて
double norm()
{
return x*x+y*y;
}

};

struct Segment
{
  Point p1,p2;
  Segment(Point p1 = Point(-1,-1),Point p2 = Point(-1,-1)):p1(p1),p2(p2){}
};
typedef Point Vector;
typedef Segment Line;
typedef vector<Point> Polygon;


double dot(Point a,Point b)
{
  return a.x*b.x + a.y*b.y;
}
double cross(Point a,Point b)
{
  return a.x*b.y - a.y*b.x;
}

double norm(Point a)
{
  return a.x*a.x+a.y*a.y;
}

bool pequals(Point a,Point b)
{
  return equals(a.x,b.x) && equals(a.y,b.y);
}

//rad は角度をラジアンで持たせること
Point rotate(Point a,double rad)
{
  return Point(cos(rad)*a.x - sin(rad)*a.y,sin(rad)*a.x + cos(rad)*a.y);
}

// 度をラジアンに変換
double toRad(double agl)
{
  return agl*M_PI/180.0;
}

int ccw(Point p0,Point p1,Point p2)
{
  Point a = p1-p0;
  Point b = p2-p0;
  if(cross(a,b) > EPS)return COUNTER_CLOCKWISE;
  if(cross(a,b) < -EPS)return CLOCKWISE;
  if(dot(a,b) < -EPS)return ONLINE_BACK;
  if(norm(a) < norm(b))return ONLINE_FRONT;
  return ON_SEGMENT;
}

bool isIntersect(Point p1,Point p2,Point p3,Point p4)
{
  return (ccw(p1,p2,p3) * ccw(p1,p2,p4) <= 0 &&
          ccw(p3,p4,p1) * ccw(p3,p4,p2) <= 0 );
}

bool isIntersect(Segment s1,Segment s2)
{
return isIntersect(s1.p1,s1.p2,s2.p1,s2.p2);
}


Point getCrossPoint(Point a1,Point a2,Point b1,Point b2)
{
  assert(isIntersect(a1,a2,b1,b2));
  Point base = b2 - b1;
  double d1 = abs(cross(base,a1-b1));
  double d2 = abs(cross(base,a2-b1));
  double t = d1/(d1+d2);
  return a1+(a2-a1)*t;
}

// Line Line 上と同じ assertなし
Point getCrossPointLines( Line s1, Line s2){
    Point a = s1.p2 - s1.p1;
    Point base = s2.p2 -s2.p1;
    return s1.p1 + a * (cross(base, s2.p1 - s1.p1)/cross(base, a));
}


int n;
int area;
int max_x,min_x;

int calc_x(Point *ps,double *reg,double *reg2,double y)
{
  double maxico = -inf;
  double mixico = inf;
  int index1 = 0;
  int index2 = 0;
  rep(i,n-1)
    {
      //cout << reg[i].y << " " << reg[i+1].y << " " << y << " " << y +1 << endl;
      if(!(min(ps[i].y,ps[i+1].y) <= y && max(ps[i].y,ps[i+1].y) >= y+1))continue;
      reg[index1++] = getCrossPoint(Point(-3000,y),Point(3000,y),ps[i],ps[i+1]).x;
      maxico = max(reg[index1-1],maxico);
      mixico = min(reg[index1-1],mixico);
      reg2[index2++] = getCrossPoint(Point(-3000,y+1),Point(3000,y+1),ps[i],ps[i+1]).x;
      maxico = max(reg2[index2-1],maxico);
      mixico = min(reg2[index2-1],mixico);
    }
  max_x = maxico;
  min_x = mixico;
  sort(reg,reg+index1);
  sort(reg2,reg2+index2);
  assert(index1 == index2);
  double prex = -3000;
  /*
  cout << "reg = " << endl;
  rep(i,index1)cout << reg[i] << " ";
  cout << endl;
  cout << "reg2 = " << endl;
  rep(i,index2)cout << reg2[i] << " ";
  cout << endl << endl;
  */
  for(int i=0;i<index1-1;i+=2)
    {
      area += ceil(max(reg[i+1],reg2[i+1])) - floor(max(min(reg[i],reg2[i]),prex));
      prex = max(reg[i+1],reg2[i+1]);
    }

  //cout << "in calc, : " << __LINE__ << " ::: "  << mixico << " - " << maxico << endl;
}

int main()
{
  while(cin >> n,n)
    {
      area = 0;
      n++;
      Point ps[n];
      int maxico = -inf;
      int mixico = inf;
      rep(i,n-1)
	{
	  cin >> ps[i].x >> ps[i].y;
	  ps[i].x += 2000,ps[i].y += 2000;
	  maxico = max(maxico,(int)ps[i].y);
	  mixico = min(mixico,(int)ps[i].y);
	}
      ps[n-1] = ps[0];

      for(int y = mixico;y<maxico;y++)
	{
	  double reg[1000];
	  double reg2[1000];
	  //cout << "+++++" << endl;
	  calc_x(ps,reg,reg2,y);
	}
      

      cout << area << endl;

    }
  return 0;
}