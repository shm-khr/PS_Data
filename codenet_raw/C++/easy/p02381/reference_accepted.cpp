#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using VI = vector<int>;
using PI = pair<int, int>;

int main() {
	int n;
	while (cin >> n) {
		if (!n) break;
		vector<double> s(n, 0);
		double m = 0;
		for (auto & e : s) {
			cin >> e;
			m += e;
		}
		m /= n;
		double a = 0;
		for (int i = 0; i < n; i++) {
			a += pow(s[i] - m, 2);
		}
		cout << setprecision(8) << fixed << sqrt(a / n) << endl;
	}


	return 0;
}

