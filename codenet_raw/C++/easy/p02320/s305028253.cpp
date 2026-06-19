#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int n, wt;
int v[100], w[100], m[100], f[10001];
long a[101][10001];

int main()
{
	cin >> n >> wt;

	for (int i = 0; i < n; i++)
		cin >> v[i] >> w[i] >> m[i];

	memset(a, 0, sizeof(a));

	for (int i = 1; i <= n; i++) {
		memset(f, 0, sizeof(f));
		for (int j = 1; j <= wt; j++) {
			if(j < w[i - 1])
				a[i][j] = a[i - 1][j];
			else {
				if (f[j - w[i - 1]] < m[i - 1]) {
					a[i][j] = max(a[i][j - w[i - 1]] + v[i - 1], a[i - 1][j]);
					f[j] = f[j - w[i - 1]] + 1;
				}
				else {
					a[i][j] = max(a[i - 1][j - w[i - 1] * m[i - 1]] + v[i - 1] * m[i - 1], a[i - 1][j]);
					f[j] = m[i - 1];
				}
			}
		}
	}

	cout << a[n][wt] << endl;

	return 0;
}
