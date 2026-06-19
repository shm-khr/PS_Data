#include <set>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200100;
const int MOD = (int) 1e9 + 7;

int n;
char s[N];

long long fact(int n) {
	long long ret = 1;
	for (int i = 1; i <= n; i++) {
		ret = ret * i % MOD;
	}
	return ret;
}

int main() {

	scanf("%d %s", &n, s);

	int cnt = 0;
	long long res = 1;

	for (int i = 0; i < 2 * n; i++) {
		int k = cnt % 2;
		k ^= ((s[i] == 'B') ? 1 : 0);
		if (k == 1) {
			cnt++;
		} else if (cnt > 0) {
			res *= cnt;
			res %= MOD;
			cnt--;
		} else {
			puts("0");
			exit(0);
		}
	}

	if (cnt > 0) {
		puts("0");
		exit(0);
	}

	printf("%lld\n", res * fact(n));

	return 0;

}