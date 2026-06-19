#include <algorithm>
#include <cstdio>
#include <cstring>
#define w(i, j) (c[j] - c[(i)-1])

typedef long long L;
const int N = 6e2 + 26, P = 1e9 + 7;

struct mod_t {
	static int norm(int x) { return x + (x >> 31 & P); }
	static void norm2(int& x) { x += x >> 31 & P; }
	int x;
	mod_t() {}
	mod_t(int v) : x(v) {}
	mod_t(long long v) : x(v) {}
	mod_t(char v) : x(v) {}
	mod_t operator+(const mod_t& rhs) const { return norm(x + rhs.x - P); }
	mod_t operator-(const mod_t& rhs) const { return norm(x - rhs.x); }
	mod_t operator*(const mod_t& rhs) const { return (L)x * rhs.x % P; }
	void operator+=(const mod_t& rhs) { norm2(x += rhs.x - P); }
	void operator-=(const mod_t& rhs) { norm2(x -= rhs.x); }
	void operator*=(const mod_t& rhs) { x = (L)x * rhs.x % P; }
};

mod_t f[N][N], g[N], ans;
int p[N], c[N];
int n, k;
int h(int l, int r) { return (r - l + 1) - w(l, r); }
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1, x, y; i <= k; i++) {
		scanf("%d%d", &x, &y);
		x[p] = y, y[p] = x, x[c] = y[c] = 1;
	}

	g[0] = g[1] = 1;
	for (int i = 2; i <= 2 * n; i++) g[i] = g[i - 2] * (i - 1);
	for (int i = 1; i <= 2 * n; i++) c[i] += c[i - 1];

	for (int l = 1; l <= 2 * n; l++)
		for (int r = l + 1; r <= 2 * n; r++)
			if ((l ^ r) & 1) {
				for (int x = l; x <= r; x++)
					if (x[p] && (x[p] < l || x[p] > r)) goto end;
				f[l][r] = g[h(l, r)];
				for (int x = l + 1; x < r; x++) f[l][r] -= f[l][x] * g[h(x + 1, r)];
				ans += f[l][r] * g[(n << 1) - (r - l + 1) - ((k << 1) - w(l, r))];
			end:;
			}
	printf("%d", ans.x);
}