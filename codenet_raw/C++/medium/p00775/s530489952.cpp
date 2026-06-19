#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <functional>
#include <algorithm>
#include <iomanip>

using namespace std;

void solve(int r, int n) {
	vector<int> interval_height(42, 0);
	for (int i = 0; i < n; i++) {
		int left, right, h;
		cin >> left >> right >> h;
		for (int j = left + 21; j < right + 21; j++) {
			if (interval_height[j] < h) {
				interval_height[j] = h;
			}
		}
	}
	vector<int> height(r + 1, 0);
	for (int i = 0; i < r; i++) {
		int left_min = min(interval_height[-i + 21 - 1], interval_height[-i + 21]);
		int right_min = min(interval_height[i + 21 - 1], interval_height[i + 21]);
		height[i] = min(left_min, right_min);
	}

	double t = 2 << 15;
	for (int i = 0; i < r; i++) {
		double tt = height[i] + r - sqrt(r * r - i * i);
		if (tt < t) {
			t = tt;
		}
	}

	cout << fixed << setprecision(4) << t << endl;
}

int main() {
	int r, n;
	while (cin >> r >> n && r && n) {
		solve(r, n);
	}
}