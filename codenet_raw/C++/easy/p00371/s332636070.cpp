#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define dbg(...) do{cerr<<__LINE__<<": ";dbgprint(#__VA_ARGS__, __VA_ARGS__);}while(0);

using namespace std;

namespace std{template<class S,class T>struct hash<pair<S,T>>{size_t operator()(const pair<S,T>&p)const{return ((size_t)1e9+7)*hash<S>()(p.first)+hash<T>()(p.second);}};template<class T>struct hash<vector<T>>{size_t operator()(const vector<T> &v)const{size_t h=0;for(auto i : v)h=h*((size_t)1e9+7)+hash<T>()(i)+1;return h;}};}
template<class T>ostream& operator<<(ostream &os, const vector<T> &v){os<<"[ ";rep(i,v.size())os<<v[i]<<(i==v.size()-1?" ]":", ");return os;}template<class T>ostream& operator<<(ostream &os,const set<T> &v){os<<"{ "; for(const auto &i:v)os<<i<<", ";return os<<"}";}
template<class T,class U>ostream& operator<<(ostream &os,const map<T,U> &v){os<<"{";for(const auto &i:v)os<<" "<<i.first<<": "<<i.second<<",";return os<<"}";}template<class T,class U>ostream& operator<<(ostream &os,const pair<T,U> &p){return os<<"("<<p.first<<", "<<p.second<<")";}
void dbgprint(const string &fmt){cerr<<endl;}template<class H,class... T>void dbgprint(const string &fmt,const H &h,const T&... r){cerr<<fmt.substr(0,fmt.find(","))<<"= "<<h<<" ";dbgprint(fmt.substr(fmt.find(",")+1),r...);}
typedef long long ll;typedef vector<int> vi;typedef pair<int,int> pi;const int inf = (int)1e9;const double INF = 1e12, EPS = 1e-9;

int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	int n, m, T;
	cin >> n >> m >> T;
	vi a(T, -1);
	rep(i, n){
		int x; cin >> x;
		a[x % T] = max(a[x % T], x / T);
	}
	vi dp(T, -1);
	dp[0] = 0;
	
	auto mul = [](const vi &a, const vi &b){
		const int T = a.size();
		vi c(T, -1);
		rep(i, T) if(a[i] >= 0) rep(j, T) if(b[j] >= 0){
			if(i + j >= T) c[i + j - T] = max(c[i + j - T], a[i] + b[j] + 1);
			else c[i + j] = max(c[i + j], a[i] + b[j]);
		}
		return c;
	};
	for(; m; m /= 2){
		if(m & 1) dp = mul(a, dp);
		a = mul(a, a);
	}
	
	int Q; cin >> Q;
	while(Q--){
		int x, y; cin >> x >> y;
		int mx = -1;
		for(; x < T; x++) mx = max(mx, dp[x]);
		cout << (mx >= y ? "yes" : "no") << endl;
	}
	return 0;
}
