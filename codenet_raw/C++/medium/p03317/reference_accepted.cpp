#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	int n, k; cin >> n >> k;
	int ans = 1;
	while (true) {
		int tmp = k + (k - 1) * (ans - 1);
		if (n <= tmp) {
			break;
		}
		ans++;
	}
	cout << ans << endl;
	return 0;
}