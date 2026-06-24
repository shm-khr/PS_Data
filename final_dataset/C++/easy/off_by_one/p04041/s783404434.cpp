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
	const int mod = 1e9 + 7;
	int n, x, y, z; cin >> n >> x >> y >> z;
	int len = x + y + z - 1;
	
	auto ok = [&](const vi &q, int sum){
		rep(i, n){
			int j = i, s = 0;
			for(; j < q.size() && s < x; j++) s += q[j];
			if(s != x) continue;
			for(s = 0; j < q.size() && s < y; j++) s += q[j];
			if(s != y) continue;
			for(s = 0; j < q.size() && s < z; j++) s += q[j];
			if(s == z) return 1;
			sum -= q[i];
			if(sum <= len) return 0;
		}
		return 0;
	};
	
	vector<set<int>> trans(100000);
	vector<vi> states;
	map<vi, int> id;
	
	queue<pair<vi, int>> q;
	q.emplace(vi(0), 0);
	states.pb({});
	id[{}] = 0;
	
	while(!q.empty()){
		vi v = q.front().first;
		int sum = q.front().second; q.pop();
		int cur = id[v];
		
		for(int d = 1; d <= 10; d++){
			v.pb(d);
			int s = sum + d;
			if(s <= len || !ok(v, s)){
				int i = 0;
				while(s > len) s -= v[i++];
				vi nv(v.begin() + i, v.end());
				
				if(!id.count(nv)){
					id[nv] = states.size();
					states.pb(nv);
					q.emplace(nv, s);
				}
				trans[cur].insert(id[nv]);
			}
			v.pop_back();
		}
	}
	
	dbg(states.size());
	
	vi dp(states.size());
	dp[id[{}]] = 1;
	rep(i, n){
		vi next(states.size());
		rep(j, states.size()) if(dp[j]) for(int k : trans[j]) (next[k] += dp[j]) %= mod;
		dp = next;
	}
	ll ans = 1;
	rep(i, n) ans = ans * 10 % mod;
	for(int i : dp) ans += mod - i;
	cout << ans % mod << endl;
	
	/*
	map<deque<int>, int> memo;
	auto ok = [&](const deque<int> q){
		if(memo.count(q)) return memo[q];
		rep(i, n){
			int j = i, s = 0;
			for(; j < q.size() && s < x; j++) s += q[j];
			if(s != x) continue;
			for(s = 0; j < q.size() && s < y; j++) s += q[j];
			if(s != y) continue;
			for(s = 0; j < q.size() && s < z; j++) s += q[j];
			if(s == z) return memo[q] = 1;
		}
		return memo[q] = 0;
	};
	map<deque<int>, vector<deque<int>>> trans;
	
	map<deque<int>, int> dp;
	dp[{}] = 1;
	rep(i, n){
		dbg(i, dp.size());
		map<deque<int>, int> nxt;
		for(const auto &p: dp){
			if(trans.count(p.first)){
				for(const auto &v : trans[p.first]) (nxt[v] += p.second) %= mod;
				continue;
			}
			for(int d = 1; d <= 10; d++){
				deque<int> q = p.first;
				q.pb(d);
				if(ok(q)) continue;
				int s = accumulate(all(q), 0);
				while(s > len){
					s -= q.front();
					q.pop_front();
				}
				trans[p.first].pb(q);
				(nxt[q] += p.second) %= mod;
			}
		}
		dp = nxt;
	}
	ll ans = 1;
	rep(i, n) ans = ans * 10 % mod;
	for(const auto &p : dp) ans += mod - p.second;
	cout << ans % mod << endl;
	*/
	return 0;
}