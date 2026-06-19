#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair <int, int> pii;

inline int Read()
{
	int x = 0, f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (;  isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x * f;
}

const int MAXN = 524290;
const int mod = 1e9 + 7;

int f[2][MAXN], n, m, k, a[25][25], cur;

inline void Inc(int &x, int y) { x += y; if (x >= mod) x -= mod; }
inline int Lowbit(int x) { return x & -x; }

inline int Trans(int x, int y, int z)
{
	if (x >> y & 1)
		return !z ? -1 : x;
	return !z ? x : ((x >> y) - Lowbit(x >> y) + 1) << y | (x & (1 << y) - 1);
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read() - 1, m = Read(), k = Read();
	mset(a, -1);
	for (int i = 1, x, y; i <= k; i ++)
		x = Read(), y = Read() - 1, a[x][y] = Read();
	f[0][0] = cur = 1;
	for (int i = 1; i <= m; i ++)
		for (int j = 0; j < n; j ++, cur ^= 1)
		{
			mset(f[cur], 0);
			for (int k = 0; k < (1 << n); k ++)
				if (f[cur ^ 1][k])
				{
					if (a[i][j] != 1 && ~Trans(k, j, 0))
						Inc(f[cur][Trans(k, j, 0)], f[cur ^ 1][k]);
					if (a[i][j] != 0 && ~Trans(k, j, 1))
						Inc(f[cur][Trans(k, j, 1)], f[cur ^ 1][k]);
				}
		}
	int ans = 0;
	for (int i = 0; i < (1 << n); i ++)
		Inc(ans, f[cur ^ 1][i]);
	return printf("%d\n", ans), 0;
}
