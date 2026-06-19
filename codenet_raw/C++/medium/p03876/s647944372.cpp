#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "functional"
#include "ctime"

using namespace std;

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	vector<int>v(N);
	for (auto &i : v)cin >> i;

	if (accumulate(v.begin(), v.end(), 0) != N * 180 - 360) {
		cout << -1 << endl;
		return 0;
	}

	vector<int>st;
	vector<int>p(N, -1);
	vector<vector<int>>edge(N);
	for (int i = N * 2 - 1; i >= 0; i--) {
		if (i >= N && v[i%N] == 270)st.push_back(i%N);
		if (v[i%N] == 90 && !st.empty()) {
			p[st.back()] = i % N;
			p[i%N] = st.back();
		//	cout << "pair " << i % N << " " << p[i%N] << endl;
			st.pop_back();
			for (auto j : st) {
				edge[j].push_back(p[i%N]);
			}
		}
	}
	vector<long long int>x(N, MOD * 2);
	vector<long long int>y(N, MOD * 2);
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (p[i] == -1) {
			x[i] = (cnt % 2) ^ (cnt / 2);
			y[i] = cnt / 2;
			x[i] *= 2;
			y[i] *= 2;
			cnt++;
		}
	}
	vector<int>dir(N);
	queue<int>Q;
	for (int i = 0; i < N; i++) {
		for (auto j : edge[i])dir[j]++;
	}
	for (int i = 0; i < N; i++) {
		if (v[i] == 270 && !dir[i])Q.push(i);
	}
	assert (!Q.empty());
	while (!Q.empty()) {
		int cn = Q.front();
		//	cout << "cn" << cn << endl;
		Q.pop();
		for (auto i : edge[cn]) {
			dir[i]--;
			if (!dir[i])Q.push(i);
		}
		L = p[cn];
		R = cn;
		while (x[L] == MOD * 2) {
			L--;
			if (L < 0)L += N;
		}
		while (x[R] == MOD * 2) {
			R++;
			R %= N;
		}
		//	cout << L << " " << R << endl;
		if (x[L] < x[R]) {
			x[p[cn]] = x[cn] = x[L] + 1;
			y[p[cn]] = y[cn] = y[L];
			y[cn]++;
			y[R]++;
		}
		else if (x[L] > x[R]) {
			x[p[cn]] = x[cn] = x[L] - 1;
			y[p[cn]] = y[cn] = y[L];
			y[cn]--;
			y[R]--;
		}
		else if (y[L] < y[R]) {
			y[p[cn]] = y[cn] = y[L] + 1;
			x[p[cn]] = x[cn] = x[L];
			x[cn]--;
			x[R]--;
		}
		else if (y[L] > y[R]) {
			y[p[cn]] = y[cn] = y[L] - 1;
			x[p[cn]] = x[cn] = x[L];
			x[cn]++;
			x[R]++;
		}
		int xodd = 0;
		for (auto i : x) {
			if (i & 1)xodd = i;
		}
		for (auto &i : x) {
			if (i >= xodd && i < MOD * 2) {
				if (i & 1)i++;
				else i += 2;
			}
		}
		int yodd = 0;
		for (auto i : y) {
			if (i & 1)yodd = i;
		}
		for (auto &i : y) {
			if (i >= yodd && i < MOD * 2) {
				if (i & 1)i++;
				else i += 2;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		//assert(x[i] != MOD * 2);
		cout << x[i] << " " << y[i] << endl;
	}
}