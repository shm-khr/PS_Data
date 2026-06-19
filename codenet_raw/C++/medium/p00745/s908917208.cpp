// Enjoy your stay.

#include <bits/stdc++.h>

#define EPS 1e-9
#define INF 1070000000LL
#define MOD 1000000007LL
#define fir first
#define foreach(it,X) for(auto it=(X).begin();it!=(X).end();it++)
#define ite iterator
#define mp make_pair
#define mt make_tuple
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define pb push_back
#define sec second
#define sz(x) ((int)(x).size())

using namespace std;

typedef istringstream iss;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef stringstream sst;
typedef vector<ll> vi;

// geometry library from hos

const double PI = acos(-1);

int sig(double r) { return (r < -EPS) ? -1 : (r > +EPS) ? +1 : 0; }

struct Pt{
	double x, y;
	Pt() {}
	Pt(double x, double y) : x(x), y(y) {}
	Pt operator+(const Pt &a) const { return Pt(x + a.x, y + a.y); }
	Pt operator-(const Pt &a) const { return Pt(x - a.x, y - a.y); }
	Pt operator*(const Pt &a) const { return Pt(x * a.x - y * a.y, x * a.y + y * a.x); }
	Pt operator-() const { return Pt(-x, -y); }
	Pt operator*(const double &k) const { return Pt(x * k, y * k); }
	Pt operator/(const double &k) const { return Pt(x / k, y / k); }
	double abs() const { return sqrt(x * x + y * y); }
	double abs2() const { return x * x + y * y; }
	double arg() const { return atan2(y, x); }
	double dot(const Pt &a) const { return x * a.x + y * a.y; }
	double det(const Pt &a) const { return x * a.y - y * a.x; }
	bool operator<(const Pt &a) const { return x < a.x || x == a.x && y < a.y; }
	bool operator==(const Pt &a) const { return x == a.x && y == a.y; }
	bool operator!=(const Pt &a) const { return x != a.x || y != a.y; }
};

ostream &operator<<(ostream &os, const Pt &a) { os << "(" << a.x << ", " << a.y << ")"; return os; }

double tri(const Pt &a, const Pt &b, const Pt &c) { return (b - a).det(c - a); }

int iSP(Pt a, Pt b, Pt c) {
	int s = sig((b - a).det(c - a));
	if (s) return s; // +1 or -1
	if (sig((b - a).dot(c - a)) < 0) return -2; // c-a-b
	if (sig((a - b).dot(c - b)) < 0) return +2; // a-b-c
	return 0;
}
int iLL(Pt a, Pt b, Pt c, Pt d) {
	if (sig((b - a).det(d - c))) return 1; // intersect
	if (sig((b - a).det(c - a))) return 0; // parallel
	return -1; // correspond
}
bool iLS(Pt a, Pt b, Pt c, Pt d) {
	return (sig(tri(a, b, c)) * sig(tri(a, b, d)) <= 0);
}
bool iSS(Pt a, Pt b, Pt c, Pt d) {
	return (iSP(a, b, c) * iSP(a, b, d) <= 0 && iSP(c, d, a) * iSP(c, d, b) <= 0);
}
bool iSSstrict(Pt a, Pt b, Pt c, Pt d) {
	return (sig(tri(a, b, c)) * sig(tri(a, b, d)) < 0 && sig(tri(c, d, a)) * sig(tri(c, d, b)) < 0);
}
Pt pLL(Pt a, Pt b, Pt c, Pt d) { // intersection
	b = b - a; d = d - c; return a + b * (c - a).det(d) / b.det(d);
}
double dLP(Pt a, Pt b, Pt c) {
	return abs(tri(a, b, c)) / (b - a).abs();
}
double dSP(Pt a, Pt b, Pt c) {
	if (sig((b - a).dot(c - a)) <= 0) return (c - a).abs();
	if (sig((a - b).dot(c - b)) <= 0) return (c - b).abs();
	return abs(tri(a, b, c)) / (b - a).abs();
}
double dLL(Pt a, Pt b, Pt c, Pt d) {
	return iLL(a, b, c, d) ? 0 : dLP(a, b, c);
}
double dLS(Pt a, Pt b, Pt c, Pt d) {
	return iLS(a, b, c, d) ? 0 : min(dLP(a, b, c), dLP(a, b, d));
}
double dSS(Pt a, Pt b, Pt c, Pt d) {
	return iSS(a, b, c, d) ? 0 : min(min(dSP(a, b, c), dSP(a, b, d)), min(dSP(c, d, a), dSP(c, d, b)));
}

int iCC(Pt a, double r, Pt b, double s) {
	double d = (b - a).abs();
	if (sig(d) == 0 && sig(r - s) == 0) return -1; // correspond
	if (sig(r - s - d) > 0) return +2; // r > s
	if (sig(s - r - d) > 0) return -2; // s > r
	return (sig(r + s - d) >= 0) ? 1 : 0;
}
bool iCS(Pt a, double r, Pt b, Pt c) {
	return (sig(r - dSP(b, c, a)) >= 0 && sig(r - max((b - a).abs(), (c - a).abs())) <= 0);
}
pair<Pt,Pt> pCC(Pt a, double r, Pt b, double s) {
	double d = (b - a).abs();
	double x = (d * d + r * r - s * s) / (d * 2);
	Pt e = (b - a) / d, w = e * Pt(0, 1) * sqrt(max(r * r - x * x, 0.0));
	return mp(a + e * x - w, a + e * x + w);
}
pair<Pt,Pt> pCL(Pt a, double r, Pt b, Pt c) {
	Pt h = b + (c - b) * (c - b).dot(a - b) / (c - b).abs2();
	// perp(b, c, a)
	double d = (h - a).abs();
	double y = sqrt(max(r * r - d * d, 0.0));
	Pt e = (c - b) / (c - b).abs();
	return mp(h - e * y, h + e * y);
}
pair<Pt,Pt> tCP(Pt a, double r, Pt b) {
	double d2 = (b - a).abs2();
	double x = sqrt(max(d2 - r * r, 0.0));
	Pt h = a + (b - a) * (r * r / d2);
	Pt w = (b - a) * Pt(0, 1) * (x * r / d2);
	return mp(h - w, h + w);
}
double aCC(Pt a, double r, Pt b, double s) {
	double d = (a - b).abs();
	if (sig(r - s - d) >= 0) return s * s * PI;
	if (sig(s - r - d) >= 0) return r * r * PI;
	if (sig(r + s - d) <= 0) return 0;
	double x = (d * d + r * r - s * s) / (d * 2);
	double h = sqrt(r * r - x * x);
	return r * r * atan2(h, x) + s * s * atan2(h, d - x) - d * h;
}

int convexHull(int n, Pt p[], Pt q[]){ // can replace sig&tri, <= with iSP, <
	int m=0, i, r;
	sort(p, p+n);
	for(i=0;        i<n;  q[m++]=p[i++]) for(; m>1 && sig(tri(q[m-2], q[m-1], p[i])) <= 0; --m);
	for(i=n-2, r=m; i>=0; q[m++]=p[i--]) for(; m>r && sig(tri(q[m-2], q[m-1], p[i])) <= 0; --m);
	return m-1;
}

int convexCut(int n, Pt p[], Pt a, Pt b, Pt q[]){
	int m=0, i;
	p[n] = p[0];
	rep(i, n){
		if(sig(tri(a, b, p[i])) > 0) q[m++] = p[i];
		if(sig(tri(a, b, p[i])) * sig(tri(a, b, p[i+1])) < 0) q[m++] = pLL(a, b, p[i], p[i+1]);
	}
	q[m] = q[0];
	return m;
}

int sGP(int n, Pt p[], Pt a) {
	int side = -1, i;
	p[n] = p[0];
	for (i = 0; i < n; ++i) {
		Pt p0 = p[i] - a, p1 = p[i + 1] - a;
		if (sig(p0.det(p1)) == 0 && sig(p0.dot(p1)) <= 0) return 0;
		if (p0.y > p1.y) swap(p0, p1);
		if (sig(p0.y) <= 0 && 0 < sig(p1.y) && sig(p0.det(p1)) > 0) side = -side;
	}
	return side;
}
int sVP(int n, Pt p[], Pt a) {
	Pt o = (p[0] + p[n / 2]) / 2;
	int lo = 0, ho = n, fl = sig(tri(o, p[lo], a));
	p[n] = p[0];
	for (; lo + 1 < ho; ) {
		int mo = (lo + ho) / 2, fm = sig(tri(o, p[mo], a));
		(fl - fm - sig(tri(o, p[lo], p[mo])) < 0) ? (lo = mo, fl = fm) : ho = mo;
	}
	return sig(tri(p[lo], p[ho], a));
}

int sAP(Pt a, Pt b, Pt c) {
	return sig(a.det(c)) - sig(b.det(c)) - sig(a.det(b));
}

// end of library

int m,n;
Pt p[222];

vector<pair<Pt,double>> v;

double normalize(double t){
	while(t>=PI)t-=2*PI;
	while(t<-PI)t+=2*PI;
	return t;
}

pair<int,int> pull(int i0){
	int i1=i0+1,i2=i0+2;
	Pt a=v[i0].fir,b=v[i1].fir,c=v[i2].fir;
	Pt d(-INF,-INF);
	if(i0<sz(v)-3)d=v[i2+1].fir;
	Pt tri[4]={a,b,c};
	int dir=iSP(a,b,c);
	if(dir==-1)swap(tri[1],tri[2]);
	vector<Pt> inner;
	rep(i,n){
		if(sVP(3,tri,p[i])==+1){
			inner.pb(p[i]);
		}
	}
	//cerr<<i0<<" - "<<i1<<" - "<<i2<<":"<<endl;
	rep(i,sz(inner)){
		//cerr<<inner[i]<<endl;
	}
	v.erase(v.begin()+i1,v.begin()+i1+2);
	vector<Pt> line;
	line.pb(a);
	Pt from=a;
	inner.pb(c);
	while(from!=c){
		Pt next;
		rep(i,sz(inner)){
			Pt to=inner[i];
			if(to==from)continue;
			int ok=1;
			rep(j,sz(inner)){
				int pos=iSP(from,to,inner[j]);
				if(pos!=0 && pos!=dir){
					ok=0;break;
				}
			}
			if(ok){
				next=to;break;
			}
		}
		line.pb(next);
		from=next;
	}
	rep(i,sz(line)){
		//cerr<<line[i]<<(i==sz(line)-1?"\n":" - ");
	}
	rep2(i,1,sz(line)){
		double t=0;
		if(i<sz(line)-1){
			Pt l0=line[i]-line[i-1], l1=line[i+1]-line[i];
			t=normalize(l1.arg()-l0.arg());
			//cerr<<l0<<" "<<l1<<" "<<t<<endl;
		}else if(d!=Pt(-INF,-INF)){
			Pt l0=line[i]-line[i-1], l1=d-line[i];
			t=normalize(l1.arg()-l0.arg());
			//cerr<<v[i2].fir<<"->"<<v[i2+1].fir<<endl;
			//cerr<<l0<<" "<<l1<<" "<<t<<endl;
		}
		v.insert(v.begin()+i0+i,mp(line[i],t));
	}
	int unhooked=0;
	if(i0!=0){
		Pt l0=v[i0].fir-v[i0-1].fir, l1=v[i1].fir-v[i0].fir;
		double t=normalize(l1.arg()-l0.arg());
		//cerr<<"i0: "<<v[i0-1].fir<<"-"<<v[i0].fir<<"-"<<v[i1].fir<<" "<<t<<endl;
		double dt=normalize(t-v[i0].sec);
		double nt=v[i0].sec+dt;
		//cerr<<v[i0].sec<<" -> "<<nt<<endl;
		if(sig(v[i0].sec) != sig(nt)){
			unhooked=1;
		}
		v[i0].sec=nt;
	}
	return mp(sz(line)-2,unhooked);
}

int main2(){
	v.clear();
	rep2(i,n,n+m){
		v.pb(mp(p[i],0));
	}
	
	for(int i0=0;i0<sz(v)-2;){
		int next=i0;
		while(1){
			rep(i,sz(v)){
				//cerr<<v[i].fir<<" "<<v[i].sec<<(i==sz(v)-1?"\n":" - ");
			}
			//cerr<<"Pulling "<<i0<<" "<<i0+1<<" "<<i0+2<<endl;
			pi res=pull(i0);
			next+=res.fir;
			if(res.sec){
				//cerr<<"Unhooked"<<endl;
				next--;
				i0--;
			}
			else break;
		}
		i0=next;
	}
	rep(i,sz(v)){
		//cerr<<v[i].fir<<" "<<v[i].sec<<(i==sz(v)-1?"\n":" - ");
	}
	double ans=0;
	
	rep(i,sz(v)-1){
		ans+=(v[i].fir-v[i+1].fir).abs();
	}
	cout<<setprecision(16)<<ans<<endl;
	
	return 0;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(cin>>m>>n && m){
		rep(i,m)cin>>p[n+i].x>>p[n+i].y;
		rep(i,n)cin>>p[i].x>>p[i].y;
		main2();
	}
}