/************************************************
 * Au: Hany01
 * Prob: run
 * Email: hany01dxx@gmail.com & hany01@foxmail.com
 * Inst: Yali High School
************************************************/

#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
#define Rep(i, j) for (register int i = 0, i##_end_ = (j); i < i##_end_; ++ i)
#define For(i, j, k) for (register int i = (j), i##_end_ = (k); i <= i##_end_; ++ i)
#define Fordown(i, j, k) for (register int i = (j), i##_end_ = (k); i >= i##_end_; -- i)
#define Set(a, b) memset(a, b, sizeof(a))
#define Cpy(a, b) memcpy(a, b, sizeof(a))
#define X first
#define Y second
#define PB(a) push_back(a)
#define MP(a, b) make_pair(a, b)
#define SZ(a) ((int)(a).size())
#define ALL(a) a.begin(), a.end()
#define INF (0x3f3f3f3f)
#define INF1 (2139062143)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define y1 WoXiHuanNiA

template <typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, 1 : 0; }
template <typename T> inline bool chkmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
template <typename T> inline T read() {
	register T _, __; register char c_;
    for (_ = 0, __ = 1, c_ = getchar(); c_ < '0' || c_ > '9'; c_ = getchar()) if (c_ == '-') __ = -1;
    for ( ; c_ >= '0' && c_ <= '9'; c_ = getchar()) _ = (_ << 1) + (_ << 3) + (c_ ^ 48);
    return _ * __;
}
//EOT


const int MAXN = 2e6 + 5, MOD = 1e9 + 7;

inline void inc(int &x, int y) {
	if ((x += y) >= MOD) x -= MOD;
}
inline int add(int x, int y) {
	return (x += y) >= MOD ? x - MOD : x;
}

int n, v[MAXN], pos[MAXN];

void Input() {
	static PII a[MAXN];
	static vector<int> kp;

	n = read<int>();
	For(i, 1, n) {
		a[i].X = read<int>();
		kp.PB(a[i].Y = read<int>());
	}
	sort(a + 1, a + 1 + n);
	sort(ALL(kp));
	kp.resize(unique(ALL(kp)) - kp.begin());
	For(i, 1, n) {
		v[i] = lower_bound(ALL(kp), a[i].Y) - kp.begin() + 1;
		pos[v[i]] = i;
	}
}

struct Segment {
	int l, r;
	bool operator < (const Segment &rhs) const {
		return r != rhs.r ? r < rhs.r : l < rhs.l;
	}
}seg[MAXN];

struct BIT {
	int c[MAXN];
	void update(int x, int dt) {
		++ x;
		for ( ; x <= n + 1; x += (x & -x))
			inc(c[x], dt);
	}
	int query(int x) {
		++ x;
		if (x < 0) return 0;
		int ans = 0;
		for ( ; x; x -= (x & -x))
			inc(ans, c[x]);
		return ans;
	}
	int query(int l, int r) {
		return query(r) - query(l - 1);
	}
}bit;

void Solve() {
	static int dp[MAXN];
	int mx = 0, mn = INF;

	For(i, 1, n)
		chkmax(mx, v[i]), seg[i].r = mx;
	Fordown(i, n, 1)
		chkmin(mn, v[i]), seg[i].l = mn;
	sort(seg + 1, seg + 1 + n);

	bit.update(0, 1);
	For(i, 1, n) {
		int dt = bit.query(seg[i].l - 1, seg[i].r);
		inc(dp[seg[i].r], dt);
		bit.update(seg[i].r, dt);
	}
	printf("%d\n", dp[n]);
}

int main() {

	Input();

	Solve();

	return 0;
}