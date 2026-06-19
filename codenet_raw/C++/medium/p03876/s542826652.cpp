#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<P,int> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

int n;
vi a,c,x,y;

void Compless(){
	vi A,B;
	for(int i=0;i<n;i++){
		if(x[i]!=inf) A.push_back(x[i]);
		if(y[i]!=inf) B.push_back(y[i]);
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	A.erase(unique(A.begin(),A.end()),A.end());
	B.erase(unique(B.begin(),B.end()),B.end());
	map<int,int> ma,mb;
	ma[inf]=inf;mb[inf]=inf;
	for(int i=0;i<A.size();i++) ma[A[i]]=i*2;
	for(int i=0;i<B.size();i++) mb[B[i]]=i*2;
	for(int i=0;i<n;i++) x[i]=ma[x[i]];
	for(int i=0;i<n;i++) y[i]=mb[y[i]];
}

void Rec(int l,int r){
	int d=0;
	vi L,R;
	for(int i=l;i!=r;i=(i+1)%n){
		if(!d) L.push_back(i);
		d+=a[i];
		if(!d) R.push_back(i);
	}
	for(int i=0;i<L.size();i++){
		int D=c[r],cx=dx[D],cy=dy[D],cx_=dx[(D+3)%4],cy_=dy[(D+3)%4];
		x[L[i]]=x[r]+cx_;y[L[i]]=y[r]+cy_;
		x[R[i]]=x[L[i]]+cx;y[R[i]]=y[L[i]]+cy;
		x[r]+=cx;y[r]+=cy;
		Compless();
	}
	for(int i=0;i<L.size();i++) Rec((L[i]+1)%n,R[i]);
}

int main(){
	cin>>n;
	a=c=vi(n,-1);
	x=y=vi(n,inf);
	int t=0;
	for(int i=0;i<n;i++){
		int A;
		cin>>A;
		if(A==270) a[i]=1,t++;
	}
	if(n%2!=0||n/2-2!=t){
		cout<<-1<<endl;
		return 0;
	}
	int b[4],id=0,d=0,D=1;
	for(int i=0;i<n;i++){
		d+=a[i];
		D=(D+1+(a[i]==1?2:0))%4;
		c[i]=(D+2)%4;
		if(d==-1&&id<4) b[id++]=i,d=0;
	}
	for(int i=0;i<4;i++){
		x[b[i]]=(0<i&&i<3?2:0);
		y[b[i]]=(1<i?2:0);
	}
	for(int i=0;i<4;i++) Rec((b[i]+1)%n,b[(i+1)%4]);
	for(int i=0;i<n;i++) assert(x[i]!=inf&&y[i]!=inf);
	for(int i=0;i<n;i++) cout<<x[i]<<' '<<y[i]<<endl;
}