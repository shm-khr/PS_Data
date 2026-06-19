#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
long long X, Y, Z, n, power[50], mod = 1000000007;
int M[42][262144];

string parse(int r, int bit) {
	int cnt = 1, c = -1; string Y = "";
	for (int i = 0; i < r; i++) {
		if ((bit / (1 << i)) % 2 == 1)c = i;
	}
	r = c + 1;
	for (int i = 0; i < r; i++) {
		if ((bit / (1 << i)) % 2 == 1) { Y += ('0' + cnt); cnt = 1; }
		else cnt++;
	}
	return Y;
}
int parse2(int r, string Y) {
	int cnt = 0, t = 0;
	for (int i = 0; i < Y.size(); i++) {
		t += (Y[i] - '0'); cnt += (1 << (t - 1));
	}
	return cnt;
}
long long solve(int depth, int bit) {
	if (M[depth][bit] >= 0)return M[depth][bit];
	string S = parse(X + Y + Z, bit);

	int G = 0, R = 0;
	for (int i = S.size() - 1; i >= 0; i--) {
		G += (S[i] - '0');
		if (G == X || G == X + Y || G == X + Y + Z)R++;
	}
	if (R == 3) {
		M[depth][bit] = power[n - depth];
		return power[n - depth];
	}
	if (depth == n) { M[depth][bit] = 0; return 0; }

	long long cnt = 0;
	for (int i = 1; i <= 10; i++) {
		int V = G + i, C = 0; string U = S; U += (char)('0' + i);
		while (V > X + Y + Z) { V -= (U[C] - '0'); C++; }

		U = U.substr(C, U.size() - C);
		int P = parse2(X + Y + Z, U);
		cnt += solve(depth + 1, P); cnt %= mod;
	}
	M[depth][bit] = cnt;
	return cnt;
}
int main() {
	cin >> n >> X >> Y >> Z;
	for (int i = 0; i <= n; i++) { for (int j = 0; j < (1 << (X + Y + Z)); j++) { M[i][j] = -1; } }
	power[0] = 1; for (int i = 1; i < 50; i++)power[i] = power[i - 1] * 10 % mod;
	cout << solve(0, 0) << endl;
	return 0;
}