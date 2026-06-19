#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

int main()
{
	int N; cin >> N;
	ll A[100010];
	ll sum1 = 0, sum2 = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sum2 += A[i];
	}
	ll ans = INF;
	for (int i = 0; i < N; i++) {
		sum1 += A[i];
		sum2 -= A[i];
		//cout << sum1 << " " << sum2 << endl;
		ans = min(ans, abs(sum1 - sum2));
	}
	cout << ans << endl;
}
