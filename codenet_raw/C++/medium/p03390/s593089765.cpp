// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define ll long long
#define debug(a) cout<<#a<<": ";for(auto i:a)cout<<i<<" ";cout<<endl;
#define trace(a) cout<<#a<<": "<<a<<endl;
#define int ll
// int a[N];
signed main() {
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	int i,j,k,l,m,n,t;
	cin >> t;
	while(t--) {
		ll a,b;
		cin >> a >> b;
		if(a > b) swap(a,b);
		// assert(a*b > 0);
		if(a*b == 1) {
			cout << "0" << endl;
			continue;
		}
		ll sq = sqrt(a*b-1  + 0.1);
		ll an = 0;
		// an += min(sq,a*b-sq);
		int curr_last = b*a;
		int curr_front = 1;
		// while(curr_last >= 1) {
		// 	while(curr_front*curr_last >= a*b) {
		// 		curr_last--;
		// 	}
		// 	// cout << "Poss sol : " << curr_front << " " << curr_last << endl;
		// 	curr_last--;
		// 	curr_front++;
		// }
		an += sq;
		an *= 2;
		// trace(sq);
		if(a <= sq) {
			an--;
			// if(a == sq) an++;
		}
		// cout << a << " " << sq << " " << an << endl;
		// if(a <= sq)
			// an--;
		if(sq * (sq+1) >= a*b) {
			an--;
		}
		if(a == b || a == b-1)
			an = 2*a-2;
		cout << an << endl;
	}
}