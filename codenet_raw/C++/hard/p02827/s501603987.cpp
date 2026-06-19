#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 100005;

int n, m;
pi a[MAXN];
int dp[MAXN][3][3];

void solve(){
	if(n == 2){
		puts("-1");
		return;
	}
	for(int i=0; i<3; i++){
		for(int j=0; j<i; j++){
			dp[m][i][j] = 1;
			dp[m][j][i] = 1;
		}
	}
	for(int i=m-1; i>=0; i--){
		if(a[i].second >= 3){
			memcpy(dp[i], dp[i + 1], sizeof(dp[i]));
			continue;
		}
		for(int j=0; j<3; j++){
			for(int k=0; k<3; k++){
				if(j == k || pi(j, k) == a[i] || pi(k, j) == a[i]) continue;
				if(j == a[i].first || j == a[i].second){
					dp[i][j][k] |= dp[i + 1][j][k];
					dp[i][j][k] |= dp[i + 1][k][j];
					dp[i][j][k] |= dp[i + 1][a[i].first + a[i].second - j][k];
					dp[i][j][k] |= dp[i + 1][k][a[i].first + a[i].second - j];
				}
				if(k == a[i].first || k == a[i].second){
					dp[i][j][k] |= dp[i + 1][j][k];
					dp[i][j][k] |= dp[i + 1][k][j];
					dp[i][j][k] |= dp[i + 1][a[i].first + a[i].second - k][j];
					dp[i][j][k] |= dp[i + 1][j][a[i].first + a[i].second - k];
				}
			}
		}
	}
	int px = -1, py = -1;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(dp[0][i][j]){
				px = i, py = j;
			}
		}
	}
	if(px == -1) assert(0);
	for(int i=0; i<m; i++){
		if(a[i].second >= 3){
			if(px == a[i].first || py == a[i].first) putchar('^');
			else putchar('v');
			continue;
		}
		int j = px, k = py;
		if(j == a[i].first || j == a[i].second){
			bool val = (j == a[i].first) ^ (!dp[i + 1][j][k]);
			if(!val){
				putchar('v');
				if(j == a[i].first) j = a[i].second;
			}
			else{
				putchar('^');
				if(j == a[i].second) j = a[i].first;
			}
		}
		else if(k == a[i].first || k == a[i].second){
			bool val = (k == a[i].first) ^ (!dp[i + 1][j][k]);
			if(!val){
				putchar('v');
				if(k == a[i].first) k = a[i].second;
			}
			else{
				putchar('^');
				if(k == a[i].second) k = a[i].first;
			}
		}
		else putchar('^');
	}
	puts("");
}

bitset<50005> bs[50005];

void report(int x){
	bool chk[MAXN] = {};
	char ans[MAXN] = {};
	chk[x] = 1;
	for(int i=m-1; i>=0; i--){
		if(chk[a[i].first] == chk[a[i].second]){
			ans[i] = '^';
			continue;
		}
		if(chk[a[i].first]) ans[i] = '^';
		else ans[i] = 'v';
		chk[a[i].first] = chk[a[i].second] = 1;
	}
	cout << ans << endl;
}

int main(){
	int t;
	scanf("%d %d %d",&n,&m,&t);
	for(int i=0; i<m; i++){
		scanf("%d %d",&a[i].first,&a[i].second);
		a[i].first--;
		a[i].second--;
	}
	if(t == 1){
		for(int i=0; i<n; i++) bs[i].set(i);
		for(int i=0; i<m; i++){
			bs[a[i].first] = bs[a[i].second] = (bs[a[i].first] | bs[a[i].second]);
		}
		for(int i=0; i<n; i++){
			if(bs[i].count() == n){
				report(i);
				return 0;
			}
		}
		puts("-1");
		return 0;
	}
	if(t == 2){
		solve();
		return 0;
	}
}
