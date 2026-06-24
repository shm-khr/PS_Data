#ifndef LOCAL
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif

#define _SCL_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#define push_back pb
#define make_pair mp
#define first x
#define second y

#include <cassert>
#include <ciso646>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <array>
#include <bitset>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <complex>
#include <functional>
#include <initializer_list>
#include <iterator>
#include <limits>
#include <locale>
#include <numeric>
#include <regex>
#include <string>
#include <utility>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#ifdef LOCAL
//#include <vld.h>
#endif //LOCAL 
using namespace std;

typedef long long ll;
typedef long double ld;

#define speedup cout.tie(nullptr);cin.tie(nullptr);ios_base::sync_with_stdio(false)
#define coutdouble cout<<setprecision(20);cout<<fixed

#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()

/*------CommentInInteractive--------*/
#ifndef LOCAL
#define endl "\n"
#endif //LOCAL
/*----------------------------------*/
const int INF = 1000 * 1000 * 1000 + 322;
const ll LLINF = 2LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL + 57;
const ll MOD = 1000 * 1000 * 1000 + 7;
const int RMOD = MOD - 2;
const int N = 100 * 1000 + 57;
const int P1M = 1336337; //Large prime ( ~1M )
const int P1K = 1009; //Big prime ( ~1K )
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932384626433832795;
/*------------------------------------------------IO_OPERATORS---------------------------------------------*/
template<typename T, typename U> inline ostream &operator << (ostream &_out, const pair<T, U> &_p) { _out << _p.first << " " << _p.second; return _out; }
template<typename T, typename U> inline istream &operator >> (istream &_in, pair<T, U> &_p) { _in >> _p.first >> _p.second; return _in; }
template<typename T> inline ostream &operator << (ostream &_out, const vector<T> &_v) { if (_v.empty()) return _out; _out << _v.front(); for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline istream &operator >> (istream &_in, vector<T> &_v) { for (auto &_i : _v) _in >> _i; return _in; }
template<typename T> inline ostream &operator << (ostream &_out, const set<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline ostream &operator << (ostream &_out, const multiset<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline ostream &operator << (ostream &_out, const unordered_set<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline ostream &operator << (ostream &_out, const unordered_multiset<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T, typename U> inline ostream &operator << (ostream &_out, const map<T, U> &_m) { if (_m.empty()) return _out; _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) _out << ", (" << _it->first << ": " << _it->second << ')'; return _out; }
template<typename T, typename U> inline ostream &operator << (ostream &_out, const unordered_map<T, U> &_m) { if (_m.empty()) return _out; _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) _out << ", (" << _it->first << ": " << _it->second << ')'; return _out; }
/*--------------------------------------------------IO_FILES-----------------------------------------------*/
const char * infile =
#ifdef LOCAL
"input.txt"
#else
""
#endif //LOCAL
;
const char * outfile =
#ifdef LOCAL
""
#else
""
#endif //LOCAL
;

/*-------------------------------------------------ALLOCATOR----------------------------------------------*/
//#define ALLOC_LOCAL
#ifdef ALLOC_LOCAL
const int ML_ = 200;
char mem_[ML_ * 1000000];
size_t ptr = 0;
void * operator new(size_t cnt) { if (ptr + cnt < sizeof mem_) { ptr += cnt; return  mem_ + ptr - cnt; } else { ptr = cnt; return mem_; } }
void operator delete(void *) {}
#endif //ALLOC_LOCAL
/*----------------------------------------------------MATHS------------------------------------------------*/
inline ll gcd(ll a, ll b) { while (b) { a %= b; swap(a, b); } return a; }
inline ll lcm(ll a, ll b) { return a*b / gcd(a, b); }
inline ll pwm(ll xx, ll pow, ll MD = MOD) { ll mlt = 1; while (pow) { if (pow & 1) { mlt *= xx; xx *= xx; pow >>= 1; xx %= MD; mlt %= MD; } else { pow >>= 1; xx *= xx; xx %= MD; } }return mlt; }
inline ll pw(ll xx, int pow) { ll mlt = 1; while (pow) { if (pow & 1) { mlt *= xx; xx *= xx; pow >>= 1; } else { pow >>= 1; xx *= xx; } }return mlt; }
inline ll inv(ll r) { return pwm(r, RMOD); }
/*--------------------------------------------------------------------------------------------------------*/

vector<pair<int,ll>> g[N];
ll ds[N], dt[N];
pair<int, int> edg[2 * N];
ll lngth[2 * N];
vector<int> h[N], rh[N];
ll dps[N], dpt[N], dp[N];



///
int n;
bool useds[N];
vector<int> anss;

void dfss(int v) {
	useds[v] = true;
	for (size_t i = 0; i<h[v].size(); ++i) {
		int to = h[v][i];
		if (!useds[to])
			dfss(to);
	}
	anss.pb(v);
}

void topological_sorts() {
	for (int i = 1; i <= n; ++i)
		useds[i] = false;
	anss.clear();
	for (int i = 1; i <= n; ++i)
		if (!useds[i])
			dfss(i);
	reverse(anss.begin(), anss.end());
}


bool usedt[N];
vector<int> anst;

void dfst(int v) {
	usedt[v] = true;
	for (size_t i = 0; i<rh[v].size(); ++i) {
		int to = rh[v][i];
		if (!usedt[to])
			dfst(to);
	}
	anst.pb(v);
}

void topological_sortt() {
	for (int i = 1; i <= n; ++i)
		usedt[i] = false;
	anst.clear();
	for (int i = 1; i <= n; ++i)
		if (!usedt[i])
			dfst(i);
	reverse(anst.begin(), anst.end());
}
///


inline void solve(ld tt) {
	int m;
	int s, t;
	set<pair<ll, int>> q;
	cin >> n >> m;
	cin >> s >> t;
	int ptr = 0;
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].pb({ v,w });
		g[v].pb({ u,w });
		edg[ptr++] = { u,v };
		lngth[ptr - 1] = w;
	}
	for (int i = 0; i < N; ++i) ds[i] = LLINF;
	ds[s] = 0LL;
	q.insert(mp(ds[s], s));
	while (!q.empty()) {
		int v = q.begin()->y;
		q.erase(q.begin());

		for (size_t j = 0; j<g[v].size(); ++j) {
			int to = g[v][j].x;
			ll len = g[v][j].y;
			if (ds[v] + len < ds[to]) {
				q.erase(mp(ds[to], to));
				ds[to] = ds[v] + len;
				//p[to] = v;
				q.insert(mp(ds[to], to));
			}
		}
	}

	for (int v = 1; v <= n; ++v) {
		for (auto u : g[v]) {
			if (ds[u.x] == ds[v] + u.y) {
				h[v].pb(u.x);
			}
		}
	}

	///

	for (int i = 0; i < N; ++i) dt[i] = LLINF;
	dt[t] = 0LL;
	q.insert(mp(dt[t], t));
	while (!q.empty()) {
		int v = q.begin()->y;
		q.erase(q.begin());

		for (size_t j = 0; j<g[v].size(); ++j) {
			int to = g[v][j].x;
			ll len = g[v][j].y;
			if (dt[v] + len < dt[to]) {
				q.erase(mp(dt[to], to));
				dt[to] = dt[v] + len;
				//p[to] = v;
				q.insert(mp(dt[to], to));
			}
		}
	}

	for (int v = 1; v <= n; ++v) {
		for (auto u : g[v]) {
			if (dt[u.x] == dt[v] + u.y) {
				rh[v].pb(u.x);
			}
		}
	}
	topological_sortt();
	topological_sorts();
	dps[s] = 1;
	dpt[t] = 1;
	for (int i = 0; i < sz(anss); ++i) {
		for (auto u : h[anss[i]]) {
			dps[u] = (dps[u] + dps[anss[i]]) % MOD;
		}
	}
	for (int i = 0; i < sz(anst); ++i) {
		for (auto u : rh[anst[i]]) {
			dpt[u] = (dpt[u] + dpt[anst[i]]) % MOD;
		}
	}
	for (int i = 0; i < N; ++i) {
		dp[i] = dps[i] * dpt[i] % MOD;
	}

	ll ans = dp[s] * dp[s] % MOD;
	for (int i = 0; i < N; ++i) {
		if (2 * ds[i] == ds[t] && ds[i] + dt[i] == ds[t]) {
			ans = ((ans - dp[i] * dp[i]) % MOD + MOD) % MOD;
		}
	}
	for (int i = 0; i < m; ++i) {
		int u = edg[i].x, v = edg[i].y;
		ll w = lngth[i];
		if (ds[u] > ds[v]) {
			swap(u, v);
		}
		if (ds[u] + w + dt[v] > ds[t]) {
			continue;
		}
		if (ds[v] <= dt[v] || ds[u] >= dt[u]) {
			continue;
		}
		ans = (ans - (dps[u] * dpt[v]) * (dps[u] * dpt[v])) % MOD;
		ans = (ans + MOD) % MOD;
	}
	cout << ans << endl;
}


int main() {
	ld tt = clock();

	if (*infile != '\0')
		freopen(infile, "r", stdin);
	if (*outfile != '\0')
		freopen(outfile, "w", stdout);

	speedup;
	coutdouble;

	//int tst = 1;
	//srand(time(NULL));
	//cin >> tst;
	//scanf("%d", &tst);
	//while (tst-- > 0) {
	//while(true) {
	solve(tt);
	//cout << "/*-----------------*/\n";
	//}

#ifdef LOCAL
	cout << "Time: " << ((ld)clock() - tt) / CLOCKS_PER_SEC << endl;
	while (true);
#endif // LOCAL
	return 0;
}