#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const double EPS = 1e-9;
bool EQ(double a, double b) { return abs(a - b) < EPS; }

double getHeight(double r, double x) {
	return sqrt(r * r - x * x);
}

int main(void) {
	int r, n;
	while(scanf("%d %d", &r, &n), r > 0) {
		int left[20], right[20], height[20];
		for(int i = 0; i < n; i++) scanf("%d %d %d", left + i, right + i, height + i);
		vector<double> xs;
		const double GAPEPS = 1e-7;
		xs.push_back(-r + GAPEPS);
		xs.push_back(r - GAPEPS);
		for(int i = 0; i < n; i++) {
			double cand = left[i] - GAPEPS;
			if(-r <= cand and cand <= r) xs.push_back(cand);
			cand = left[i] + GAPEPS;
			if(-r <= cand and cand <= r) xs.push_back(cand);
			cand = right[i] - GAPEPS;
			if(-r <= cand and cand <= r) xs.push_back(cand);
			cand = right[i] + GAPEPS;
			if(-r <= cand and cand <= r) xs.push_back(cand);
		}

		double s = 0, e = 100;
		for(int lv = 0; lv < 100; lv++) {
			double mid = (s + e) / 2;
			bool isAble = true;

			for(double x: xs) {
				bool isIncluded = false;

				for(int i = 0; i < n; i++)
					if(left[i] <= x and x <= right[i] and height[i] >= getHeight(r, x) - r + mid) {
						isIncluded = true;
						break;
					}

				if(!isIncluded) {
					isAble = false;
					break;
				}
			}

			if(isAble) s = mid;
			else e = mid;
		}

		printf("%.4lf\n", s);
	}

	return 0;
}