#include <bits/stdc++.h>
using namespace std;
using ld = long double;

int main()
{
	cout << fixed << setprecision(8);
	int n, r;
	while (cin >> r >> n, r | n) {
		vector<int> h(40);
		for (int i = 0, xl, xr, hi; i < n; i++) {
			cin >> xl >> xr >> hi;
			for (int j = xl + 20; j < xr + 20; j++) {
				h[j] = hi;
			}
		}
		int cnt = 1000;
		ld lb = 0, ub = 30;
		while (cnt--) {
			ld c = (lb + ub) / 2.0;
			bool flag = true;
			for (int i = 20 - r; i < 20 + r; i++) {
				if (max(sqrtl(r * r - (i - 20) * (i - 20)), sqrtl(r * r - (i - 19) * (i - 19))) - r + c > h[i]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				lb = c;
			}
			else {
				ub = c;
			}
		}
		cout << lb << endl;
	}
	return 0;
}