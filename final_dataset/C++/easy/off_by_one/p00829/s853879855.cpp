#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) rep(i, 0, n)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define int long long
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int mod = 1LL << 32;
const int INF = 1e12;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	rep(ij, 0, t){
		int a[9] = {}, b[8] = {}, k = 0, sum = 0;
		rep(i, 0, 9){
			scanf("%x", &a[i]);
		}
		rep(i, 0, 32){
			int tmp = 0;
			rep(j, 0, 8){
				if(a[j] & (1LL << i)) tmp++;
			}
			// cout << tmp % 2 << " " << !!(a[8] & (1LL << i)) << endl;
			int now = !!(a[8] & (1LL << i));
			if(sum & (1LL << i)) now = (now + 1) % 2;
			if(tmp % 2 == now){
				sum += tmp * (1LL << i);
				sum %= mod;
				//a[8] = (a[8] - tmp * (1LL << i) % mod + mod) % mod;
			}else{
				sum += (8 - tmp) * (1LL << i);
				sum %= mod;
				//a[8] = (a[8] - (8 - tmp) * (1LL << i) % mod + mod) % mod;
				k += (1LL << i);
			}
		}
		printf("%x\n", k);
	}
}
