#include<iostream>
#include<algorithm>

using namespace std;

int n, W;
int v[10001], w[10001], m[10001];
int dp[20001][10001];
int ct = 0;

int main() {
	cin >> n >> W;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		//press
		while (c > 0) {
			for (int i = 1; i <= c; (i <<= 1)) {
				v[ct] = i * a, w[ct] = i * b;
				c -= i, ct++;
			}
		}
	}
	for (int i = 0; i < ct; i++) {
		for (int j = 0; j <= W; j++) {
			if (j < w[i])dp[i + 1][j] = dp[i][j];
			else dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
		}
	}
	cout << dp[ct][W] << endl;
	return 0;
}