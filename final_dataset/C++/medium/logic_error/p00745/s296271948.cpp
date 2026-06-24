#include<iostream>
#include<cassert>
#include<complex>
#include<set>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define pb push_back
#define ALL(C)  (C).begin(),(C).end()

const double eps = 1e-7;
const int LIM = 10000;

#define EQ(a,b)  (fabs((a)-(b)) < eps)
#define EQV(a,b) (EQ((a).real(),(b).real()) && EQ((a).imag(),(b).imag()))

typedef complex<double> P;
typedef vector<P> vp;

namespace std{
  bool operator<(const P &a,const P &b){
    if (!EQ(a.real(),b.real()))return a.real() < b.real();
    return a.imag() < b.imag();
  }
}

double myabs(P a){
  return sqrt(a.real()*a.real()+a.imag()*a.imag());
}

bool isp(P a,P b,P c){
  return myabs(a-c)+myabs(b-c) < myabs(a-b) + eps;
}

double cross(P a,P b){
  return a.real()*b.imag()-a.imag()*b.real();
}

double dot(P a,P b){
  return a.real()*b.real()+a.imag()*b.imag();
}

int ccw(P a,P b){
  if ( cross(a,b) <0)return -1;
  else return 1;
}

P intersection_ll(P a1,P a2,P b1,P b2){
  P a= a2-a1,b=b2-b1;
  return a1+ a*cross(b,b1-a1)/cross(b,a);
}

vp ConvexHull(int n,vp &inp){
  P out[200];
  int p;
  sort(ALL(inp));
  p=0;
  out[p++]=inp[0];out[p++]=inp[1];
  for(int i=2;i<n;i++){
    while(p>=2){
      if ( ccw(out[p-1]-out[p-2],inp[i]-out[p-2]) ==1)break;
      else {
	p--;
      }
    }
    out[p++]=inp[i];
  }
  for(int i=n-2,t=p+1;i>=0;i--){
    while(p>=t){//ツつキツづづ可禿環陛ッツづ可づ按づつスツ点ツづーツ湘つウツづ按つ「ツづヲツつ、ツづ可つキツづゥツ。
      if ( ccw(out[p-1]-out[p-2],inp[i]-out[p-2]) ==1)break;
      else p--;
    }
    out[p++]=inp[i];
  }
  
  vp ret(p-1);
  rep(i,p-1)ret[i]=out[i];
  return ret;
}

bool is_in(P* in,P a){
  int cnt =0;
  int n = 3;
  rep(i,n){
    P cur = in[i]-a,next=in[(i+1)%n]-a;
    if (cur.imag() > next.imag())swap(cur,next);
    if (cur.imag()<0 && 0<=next.imag() &&
	cross(next,cur)>=0)cnt++;
    if (isp(in[i],in[(i+1)%n],a))return true;
  }
  if (cnt %2 == 1)return true;
  else return false;
}

//return arranged convex
vp rotate(vp &in,P &a,P &b,int depth){
  if (depth == 2)assert(false);
  vp ret;
  int n=in.size();
  rep(i,n){
    if (EQV(in[i],b) && EQV(in[(i+1)%n],a)){
      rep(j,n){
	ret.pb(in[(i+1+j)%n]);
      }
      return ret;
    }
  }
  reverse(ALL(in));
  return rotate(in,a,b,depth+1);
}

vp getcand(P &a,P &b,P &c,vp cand){
  vp ret;
  static P tri[3];
  tri[0]=a;tri[1]=b;tri[2]=c;
  rep(i,(int)cand.size()){
    if (is_in(tri,cand[i]))ret.pb(cand[i]);
  }
  return ret;
}

void op(vp &a){
  cout <<"[";
  rep(i,a.size())cout << a[i]<<",";
  cout <<"]";
}

double solve(int n,vp &pin,int m,vp &st){//pin and stable(kugyu)
  static P line[LIM];
  bool canuse[100];
  int p=0;
  line[p]=pin[0];
  REP(i,1,n-1){
    P go=pin[i];//get out?
    vp cand=getcand(line[p],go,pin[i+1],st);
    set<P> S;    
    while(p-1 >= 0){
      int direc_i =ccw(line[p]-line[p-1],go      -line[p-1]);
      int direc_i1=ccw(line[p]-line[p-1],pin[i+1]-line[p-1]);
      if (direc_i*direc_i1 == 1)break;
      /*
      if (dot(line[p]-line[p-1],go      -line[p-1])  > -eps ||
	  dot(line[p]-line[p-1],pin[i+1]-line[p-1])  > -eps){
	cout <<"1 "<<dot(line[p]-line[p-1],go      -line[p-1]) << endl;
	cout <<"2 "<< dot(line[p]-line[p-1],pin[i+1]-line[p-1]) <<endl;
	break;
      }
      */
      if (dot(line[p]-line[p-1],go      -line[p-1])  > -eps &&
	  dot(line[p]-line[p-1],pin[i+1]-line[p-1])  < eps
	  )break;
      bool isok=false;


      rep(j,(int)cand.size()){
	if (EQV(cand[j],line[p])||EQV(cand[j],line[p-1]))continue;
	//if (EQV(cand[j],line[p]))continue;
	if (ccw(line[p]-line[p-1],cand[j]-line[p-1]) == direc_i){
	  isok=true;
	  break;
	}
      }

      /*
      P tmp=intersection_ll(line[p],line[p-1],go,pin[i+1]);
      vp hoge=getcand(line[p],tmp,pin[i+1],st);
      rep(j,(int)hoge.size()){
	if (EQV(line[p],hoge[j])){
	  hoge.erase(hoge.begin()+j);
	  break;
	}
      }
      if (hoge.size() != 0)break;
      */  
      if (isok)break;
      //cout <<"go out " << line[p] << endl;
      go=intersection_ll(line[p],line[p-1],go,pin[i+1]);
      cand=getcand(line[p-1],go,pin[i+1],st);
      S.insert(line[p]);
      rep(j,(int)cand.size()){
	//	if (EQV(cand[j],line[p])||EQV(cand[j],line[p])){
	if(S.find(cand[j]) != S.end()){
	  cand.erase(cand.begin()+j);
	  j--;
	}
      }
      p--;
    }

    rep(j,cand.size()){
      if (EQV(cand[j],line[p])){
	cand.erase(cand.begin()+j);
	break;
      }
    }
    cand.pb(line[p]);
    cand.pb(pin[i+1]);
    //cout <<"tri " <<i <<" " <<  line[p] <<" " << go <<" " << pin[i+1] << endl;

    //cout <<"cand " << endl;rep(k,(int)cand.size())cout << cand[k] <<",";cout << endl;

    vp ins=ConvexHull((int)cand.size(),cand);
    //cout <<"ins " << endl;
    //rep(k,(int)ins.size())cout << ins[k] <<",";cout << endl;
    ins=rotate(ins,line[p],pin[i+1],0);
    REP(j,1,(int)ins.size()-1)line[++p]=ins[j];

    //    cout << "rotated ins " << endl;
    //rep(k,(int)ins.size())cout<<ins[k]<<",";cout<<endl;
    /*
    cout <<"op begin" << endl;
    cout <<"[";rep(k,p+1)cout<<line[k]<<",";cout << pin[i+1] <<"],"<< endl;
    cout <<"line[p] " << p <<" " << line[p] << endl;
    cout << endl;
    */

  }
  line[++p]=pin[n-1];
  double ret=0;
  rep(i,p)ret+=myabs(line[i]-line[i+1]);
  //cout <<"[";rep(i,p)cout << line[i]<<",";cout << line[p];cout << "],"<<endl;

  return ret;
}

main(){
  int n,m;
  while(cin>>n>>m &&n){
    vp pin(n),st(m);
    rep(i,n)cin>>pin[i].real()>>pin[i].imag();
    rep(i,m)cin>>st[i].real()>>st[i].imag();
    //op(pin);
    printf("%.10lf\n",solve(n,pin,m,st));
    //cout <<"this case is end " << endl;
  }
  return false;
}