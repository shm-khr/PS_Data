// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;

const int N = (int) 1e6 + 6, mod = (int) 0;
vector<int> adj[N];
int dp[N][2];
void dfs(int v, int p = -1) {
	int sum = 0;
	for (int u : adj[v]) if (u != p) {
		dfs(u, v);
		dp[v][0] += dp[u][1];
		sum += dp[u][1];
	}
	dp[v][1] = dp[v][0];
	for (int u : adj[v]) {
		dp[v][1] = max(dp[v][1], sum - dp[u][1] + 1);
	}
	
	
}
int main() {
	int n;
	cin >> n;
	if (n & 1) {
		cout << "First" << endl;
		return 0;
	}
	for (int j = 1; j < n; ++j) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0);
	if (max(dp[0][0], dp[0][1]) < n / 2) {
		cout << "First" << endl;	
	} else {
		cout << "Second" << endl;
	}
}

