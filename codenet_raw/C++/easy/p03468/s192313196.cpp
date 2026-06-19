#include <bits/stdc++.h>
using namespace std;

using s64 = long long;
using r32 = double;

const int MaxN = 6;
const int MaxM = 50;

int n, m;
int a[MaxN];

int per[MaxN - 1];

s64 f[MaxN * MaxM + 1][1 << MaxN - 1];

inline s64 solve()
{
	int all = 1 << n - 1;
	for (int i = 0; i <= n * m; ++i)
		fill(f[i], f[i] + all, 0);

	f[n * a[n - 1]][0] = 1;
	for (int i = 0; i < n * m; ++i)
		for (int j = i; j <= n * m; ++j)
			for (int s = 0; s < all; ++s)
			{
				if (i % n == 0)
					continue;

				int k = per[i % n - 1];
				int p = min(max(j, i + n * a[k]), n * m);
				int t = s | 1 << k;
				if (~s >> k & 1)
					f[p][t] += f[j][s];
			}

	return f[n * m][all - 1];
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort(a, a + n);

	for (int i = 0; i < n - 1; ++i)
		per[i] = i;

	s64 res = solve();
	while (next_permutation(per, per + n - 1))
		res += solve();

	s64 all = 1;
	for (int i = 1; i < n; ++i)
		all *= i * m;

	printf("%.8f\n", (r32)res / all);

	return 0;
}