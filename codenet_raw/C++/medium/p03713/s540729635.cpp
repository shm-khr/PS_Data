#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
long long m[4][3];
long long a[10][7];
long long ans[10];
int main(){
	long long h, w;
	cin >> h >> w;
	m[0][1] = h / 2;
	m[1][1] = (h + 1) / 2;
	m[2][1] = w;
	m[0][2] = h;
	m[1][2] = w / 2;
	m[2][2] = (w + 1) / 2;
	a[0][1] = m[0][1] / 2;
	a[0][2] = (m[0][1] + 1) / 2;
	a[0][3] = m[1][1];
	a[0][4] = m[2][1];
	a[1][1] = m[0][1];
	a[1][2] = m[1][1] / 2;
	a[1][3] = (m[1][1] + 1) / 2;
	a[1][4] = m[2][1];
	a[2][1] = m[0][1];
	a[2][2] = m[1][1];
	a[2][3] = m[2][1] / 2;
	a[2][4] = (m[2][1] + 1) / 2;
	a[3][1] = m[0][2] / 2;
	a[3][2] = (m[0][2] + 1) / 2;
	a[3][3] = m[1][2];
	a[3][4] = m[2][2];
	a[4][1] = m[0][2];
	a[4][2] = m[1][2] / 2;
	a[4][3] = (m[1][2] + 1) / 2;
	a[4][4] = m[2][2];
	a[5][1] = m[0][2];
	a[5][2] = m[1][2];
	a[5][3] = m[2][2] / 2;
	a[5][4] = (m[2][2] + 1) / 2;
	ans[0] = (max(max(a[0][1], a[0][2]), a[0][3]) - min(min(a[0][1], a[0][2]), a[0][3]))* a[0][4];
	ans[1] = (max(max(a[1][1], a[1][2]), a[1][3]) - min(min(a[1][1], a[1][2]), a[1][3])) * a[1][4];
	ans[2] = a[2][1] * w - a[2][2] * min(a[2][3], a[2][4]);
	ans[3] = a[2][2] * w - a[2][1] * min(a[2][3], a[2][4]);
	ans[4] = a[3][3] * h - min(a[3][1], a[3][2]) * a[3][4];
	ans[5] = a[3][4] * h - min(a[3][1], a[3][2]) * a[3][3];
	ans[6] = a[4][1] * (max(max(a[4][4], a[4][2]), a[4][3]) - min(min(a[4][4], a[4][2]), a[4][3]));
	ans[7] = a[5][1] * (max(max(a[5][4], a[5][2]), a[5][3]) - min(min(a[5][5], a[5][2]), a[5][3]));

	long long ans1 = 10000000000007;
	for (int i = 0; i < 8; i++) {
		if (ans1 > ans[i]) {
			ans1 = ans[i];
		}
	}
	cout << ans1 << endl;
	return 0;
}