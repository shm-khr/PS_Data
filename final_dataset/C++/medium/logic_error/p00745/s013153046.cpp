#include<complex>
#include<vector>
#include<iostream>
#include<stack>
#include<cstdlib>
#include<fstream>
#include<cmath>
#include<map>
#include<cassert>
#include<iomanip>

enum CCW{FRONT=0x01,RIGHT=0x02,BACK=0x04,LEFT=0x08,OVER=0x10};
#define sc second
#define fr first

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)

using namespace std;

typedef double elem;
typedef complex<elem> point, vec;
typedef pair<point, point> line, hline, seg, pp;

const elem infty = 1e40;
const elem eps = 1.0e-8;
const elem pi = acos(-1.0);
point base(0,0);
inline elem Round(elem a)
{
  return (elem)floor(eps+round(a));
}
bool eq(elem a, elem b){ return abs(a-b) < eps; }
bool eqv(vec a, vec b){ return eq( abs(b-a),0); }
bool far(point a, point b){ return abs(b-a)>0; }
bool near(point a, point b){ return abs(b-a)<=0; }
elem dot(vec a, vec b){ return (a.real() * b.real() + a.imag() * b.imag() ); }
elem cross(vec a, vec b){ return ( a.real() * b.imag() - a.imag() * b.real() ); }
elem dist(point a, point b){ return abs(a-b); }
elem dist_l(line l, point x){ return abs(cross(l.sc-l.fr,x-l.fr)) / abs(l.sc-l.fr); }
elem dist_seg(seg s, point x)
{
  if( dot(s.sc-s.fr,x-s.fr)<0 ) return abs(x-s.fr);
  if( dot(s.fr-s.sc,x-s.sc)<0 ) return abs(x-s.sc);
  return dist_l(s,x);
}
vec uvec(vec a){ return a / abs(a); }
vec nmr(vec a){ return a * vec(0,-1); }
vec nml(vec a){ return a * vec(0,1); }
vec unmr(vec a){ return uvec( nmr(a) ); }
vec unml(vec a){ return uvec( nml(a) ); }

inline int ccw(const point &a, point b, point x){
  b -= a;
  x -= a;
  if( eq(cross(b,x),0.0) && dot(b,x) < 0 ) return BACK;
  if( eq(cross(b,x),0.0) && abs(b) < abs(x) ) return FRONT;
  if( eq(cross(b,x),0.0) ) return OVER;
  if( cross(b,x) > 0 ) return LEFT;
  if( cross(b,x) < 0 ) return RIGHT;
}

inline bool intersectedSS(const seg &a, const seg &b)
{
  int cwaf=ccw(a.fr,a.sc,b.fr);
  int cwbf=ccw(b.fr,b.sc,a.fr);
  int cwas=ccw(a.fr,a.sc,b.sc);
  int cwbs=ccw(b.fr,b.sc,a.sc);
  if( cwaf==OVER || cwas==OVER || cwbf==OVER || cwbs==OVER ) return true;
  return ( cwaf | cwas ) == (LEFT|RIGHT) && ( cwbf | cwbs ) == (LEFT|RIGHT);
}

bool intersectedLL(line a, line b){ return !eq( cross(a.sc-a.fr,b.sc-b.fr), 0.0 ); }

point intersectionSS(seg a, seg b)
{
  elem d1 = dist_l(b,a.fr);
  elem d2 = dist_l(b,a.sc);
  return a.fr + ( d1 / (d1 + d2 ) ) * (a.sc-a.fr);
}
point intersectionLL(line a, line b)
{
  vec va = a.sc - a.fr;
  vec vb = b.sc - b.fr;
  return a.fr + va * ( cross(vb, b.fr - a.fr) / cross(vb,va) );
}

bool intersectionLL(line a, line b, point &ret){
  return intersectedLL( a, b ) ? ret = intersectionLL( a, b ), true : false;
}
bool intersectionLH(line a, hline b, point &ret){
  point tmp;
  return intersectionLL(a,b,tmp) ? ( ccw(b.fr,b.sc,tmp)&(OVER|FRONT) ? ret=tmp, true : false ) : false;
}
bool intersectionLS(line l, seg s, point &ret){
  point tmp;
  return intersectionLL(l,s,tmp) ? ( ccw(s.fr,s.sc,tmp)&OVER ? ret=tmp, true : false ) : false;
}
bool intersectionHH(hline a, hline b, point &ret){
  point tmp;
  return intersectionLL(a,b,tmp) ? ( ccw(a.fr,a.sc,tmp)&(OVER|FRONT)&&ccw(b.fr,b.sc,tmp)&(OVER|FRONT) ? ret = tmp, true : false ) : false;
}
bool intersectionHS(hline a, seg s, point &ret){
  point tmp;
  return intersectionLS(a,s,tmp) ? ( ccw(a.fr,a.sc,tmp)&(OVER|FRONT) ? ret = tmp, true : false ) : false;
}
bool intersectionSS(seg a, seg b, point &ret){
  return intersectedSS(a,b) ? ret = intersectionSS(a,b), true : false;
}

struct triangle{
  vector<point> p;
  triangle():p(3,point(0,0)){}
  triangle(point a,point b,point c){p.push_back(a);p.push_back(b);p.push_back(c);}
  bool contains(point t)const{
    int ccw01=ccw(p[0],p[1],t),ccw02=ccw(p[1],p[2],t),ccw03=ccw(p[2],p[0],t);
    return ccw01==ccw02&&ccw02==ccw03;
  }
};

point getHasMaximumDot(point base1, point base2, const vector<point> &vp)
{
  vec u = uvec(base2 - base1);
  int i0 = -1;
  elem maximumDot = -10;
  for(int i = 0; i < (int)vp.size(); ++i){
    vec v = uvec(vp[i] - base1);
    elem d = dot(u,v);
    if( !(-1<=d&&d<=1) ){
      cout << u << ' ' << v << endl;
      assert(-1<=d&&d<=1);
    }
    //assert(!eq(d,maximumDot));
    if( d >= maximumDot){
      maximumDot = d;
      i0 = i;
    }
  }
  assert(i0>=0);
  return vp[i0];
}

struct StringP{
  point p;
  bool fixed;
  vector<char> state;
  StringP(){}
  StringP(point ip, bool ifixed, vector<char> istate):p(ip),fixed(ifixed),state(istate.begin(),istate.end()){}
};

void printStrings(const vector<StringP> &V)
{
  cout << "PROGRESSING: STRING POINTS :"<<endl;
  for(int i = 0; i < (int)V.size(); ++i){
    cout << V[i].p << ' '  << V[i].fixed << ' ';
    for(int j = 0; j < (int)V[i].state.size(); ++j){
      cout << V[i].state[j];
    }
    cout << endl;
  }
  cout << "---------------------" << endl;
}

int tightenUp(vector<StringP> &V)
{
  for(int i = 1; i < (int)V.size()-1; ++i){
    StringP &a = V[i-1];
    StringP &b = V[i];
    StringP &c = V[i+1];

    int cw = ccw(a.p,b.p,c.p);
    assert(cw&(RIGHT|LEFT|OVER|FRONT));
    if( cw == OVER ){
      assert(near(a.p,c.p));
    }
    
    if( cw == RIGHT ){
      if( b.state.front()=='R' && b.state.size() == 1 ){
	b.fixed = false;
	return i;
      }
    }else if( cw == LEFT ){
      if( b.state.front()=='L' && b.state.size() == 1 ){
	b.fixed = false;
	return i;
      }
    }
  }
  return -1;
}

bool fixNext(vector<StringP> &str,
	     int &now,
	     const vector<point> &pins)
{ 
  if( str[now].fixed ){
    ++now;
    return false;
  }

  point sa = str[now-1].p;
  point sb = str[now].p;
  point sc = str[now+1].p;
  
  //cout << now << ' ' << sa << ' ' << sb << ' ' << sc << endl;
  assert(ccw(sa,sb,sc)&(LEFT|RIGHT|FRONT));
  if(ccw(sa,sb,sc)&(OVER|FRONT|BACK)){
    str.erase(str.begin()+now);
    now=0;
    return false;
  }
  triangle tri(sa,sb,sc);
  vector<point> in;
  for(int i = 0; i < (int)pins.size(); ++i){
    if(tri.contains( pins[i] )){
      in.push_back(pins[i]);
    }
  }

  if( in.size() == 0 ){
    if( now > 1 ){
      point prepre = str[now-2].p;
      seg s(sb,sc);
      line ls(sa,prepre);
      point dam;
      if(intersectionLS(ls,s,dam)&&ccw(sa,prepre,dam)&(OVER|FRONT)){
	int cw = ccw(prepre,sa,sb);
	assert(cw&(RIGHT|LEFT|OVER));
	if( cw==RIGHT ){
	  if( str[now-1].state.back() == 'l' ){
	    str[now-1].state.pop_back();
	  }else{
	    str[now-1].state.push_back('r');
	  }
	}else if( cw==LEFT ){
	  if( str[now-1].state.back() == 'r' ){
	    str[now-1].state.pop_back();
	  }else{
	    str[now-1].state.push_back('l');
	  }
	}else if( cw==OVER ){
	  int cwc = ccw(prepre,sa,sc);
	  assert(cwc&(RIGHT|LEFT));
	  if( (str[now-1].state.front() == 'L' || str[now-1].state.size()>1) && cwc == RIGHT ){
	    if( str[now-1].state.back() == 'r' ){
	      str[now-1].state.pop_back();
	    }else{
	      str[now-1].state.push_back('l');
	    }
	  }else if( (str[now-1].state.front() == 'R' || str[now-1].state.size()>1) && cwc == LEFT ){
	    if( str[now-1].state.back() == 'l' ){
	      str[now-1].state.pop_back();
	    }else{
	      str[now-1].state.push_back('r');
	    }
	  }
	}
      }
    }
    str.erase(str.begin()+now);
    now = max(0,now-2);
    return true;
  }else{
    point nextFixed = getHasMaximumDot( sa, sb, in );
    int cw = ccw(sa,nextFixed,sb);
    line l(sa,nextFixed);
    seg s(sb,sc);
    point is;

    assert(intersectionLS(l,s,is));
    assert(far(is,s.first)&&far(is,s.second));

    str[now]=StringP(is,false,vector<char>(0));

    assert(ccw(sa,nextFixed,is)==FRONT);
    assert(cw&(RIGHT|LEFT));

    if( now > 1 ){
      point prepre = str[now-2].p;
      seg s(sb,is);
      line ls(sa,prepre);
      point dam;
      if(intersectionLS(ls,s,dam)&&ccw(sa,prepre,dam)&(OVER|FRONT)){
	int cw = ccw(prepre,sa,sb);
	assert(cw&(RIGHT|LEFT|OVER));
	if( cw==RIGHT ){
	  if( str[now-1].state.back() == 'l' ){
	    str[now-1].state.pop_back();
	  }else{
	    str[now-1].state.push_back('r');
	  }
	}else if( cw==LEFT ){
	  if( str[now-1].state.back() == 'r' ){
	    str[now-1].state.pop_back();
	  }else{
	    str[now-1].state.push_back('l');
	  }
	}else if( cw==OVER ){
	  int cwc = ccw(prepre,sa,is);
	  assert(cwc&(RIGHT|LEFT));
	  if( (str[now-1].state.front() == 'L' || str[now-1].state.size()>1) && cwc == RIGHT ){
	    if( str[now-1].state.back() == 'r' ){
	      str[now-1].state.pop_back();
	    }else{
	      str[now-1].state.push_back('l');
	    }
	  }else if( (str[now-1].state.front() == 'R' || str[now-1].state.size()>1) && cwc == LEFT ){
	    if( str[now-1].state.back() == 'l' ){
	      str[now-1].state.pop_back();
	    }else{
	      str[now-1].state.push_back('r');
	    }
	  }
	}
      }
    }

    if( cw == RIGHT ){
      str.insert( str.begin()+now, StringP(nextFixed,true,vector<char>(1,'R')));
    }else if( cw == LEFT ){
      str.insert( str.begin()+now, StringP(nextFixed,true,vector<char>(1,'L')));
    }
    now = max(0,now-2);
    return true;
  }
}

point roundPoint(point p){
  return point(Round(p.real()),Round(p.imag()));
}

double getLength(const vector<StringP> &V){
  double ret = 0;
  for(int i = 0; i < (int)V.size()-1; ++i){
    ret += abs(roundPoint(V[i].p)-roundPoint(V[i+1].p));
  }
  return ret;
}

inline void drawLine(ofstream &of, point a, point b){
  of << "line("<<a.real()<<","<<a.imag()<<","<<b.real()<<","<<b.imag()<<");"<<endl;
}

inline void drawPoint(ofstream &of, point a){
  drawLine(of,a,a+point(2,2));
}

int main(){
  //ofstream ofs("vis");
  while(true){
    int m,n;
    vector<point> pins;
    vector<StringP> str;

    cin >> m >> n;
    if(m==0&&n==0)break;
    for(int i = 0; i < m; ++i){
      elem x,y;
      cin >> x >> y;
      str.push_back(StringP(point(x,y),false,vector<char>(0)));
    }
    for(int j = 0; j < n; ++j){
      elem x,y;
      cin >> x >> y;
      //pins.push_back(point(x,y));
      pins.push_back(point(x+0.0017,y+0.0022));
      pins.push_back(point(x-0.0011,y+0.0035));
      pins.push_back(point(x+0.0019,y-0.0043));
      pins.push_back(point(x-0.0023,y-0.0027));
    }
    str.front().fixed = true;
    str.back().fixed = true;
    str.front().state.push_back('X');
    str.back().state.push_back('X');

    int now = 0;
    int next;
    while(now<(int)str.size()){
      //printStrings(str);
      fixNext(str,now,pins);
	 //{ now=0; }
      next= tightenUp(str);
      if( next >= 0 ) now = next;
    }
    //    printStrings(str);
    
    /*
    cout << "FIXED POINTS :"<<endl;
    for(int i = 0; i < (int)str.size(); ++i){
      cout << str[i].p << endl;
    }
    */

    cout << fixed << setprecision(11) << getLength(str) << endl;
  }
  return 0;
}